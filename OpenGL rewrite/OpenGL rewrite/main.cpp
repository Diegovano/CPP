#include <iostream>
#include <fstream>
#include <vector>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

namespace GLabs
{

	class Buffer
	{
		GLenum m_bindPoint = NULL;
	protected:
		GLuint m_bufferID;
	public:
		Buffer()
		{
			glGenBuffers(1, &m_bufferID);
		}
		~Buffer()
		{
			glDeleteBuffers(1, &m_bufferID);
		}
		void Bind(GLenum bindPoint)
		{
			glBindBuffer(bindPoint, m_bufferID);
			m_bindPoint = bindPoint;
		}
		template<typename _Ty>
		void Data(GLenum bindPoint, uint32_t size, _Ty* data, GLenum usage)
		{
			Bind(bindPoint);
			glBufferData(bindPoint, size, data, usage);
		}
		const GLuint BufferID()
		{
			return m_bufferID;
		}
	};

	class Shader
	{
		friend class ShaderProgram;
		GLenum m_shaderType;
	protected:
		GLuint m_shaderID;
		const char** m_shaderSource;
		bool m_compiled = 0;
	public:
		Shader(GLenum shaderType) : m_shaderType(shaderType)
		{
			m_shaderID = glCreateShader(shaderType);
		}
		void AttachSource(const char** src)
		{
			m_shaderSource = src;
			glShaderSource(m_shaderID, 1, m_shaderSource, 0);
		}

		bool Compile()
		{
			glCompileShader(m_shaderID);
			GLint status;
			glGetShaderiv(m_shaderID, GL_COMPILE_STATUS, &status);
			if (status != GL_TRUE)
			{
				GLint infoLogLength = 0;
				glGetProgramiv(m_shaderID, GL_INFO_LOG_LENGTH, &infoLogLength);
				GLchar* buffer = (GLchar*)alloca(infoLogLength * sizeof(GLchar));
				GLsizei bufferSize;
				glGetProgramInfoLog(m_shaderID, infoLogLength * sizeof(GLchar), &bufferSize, buffer);
				std::cout << "Compile Error: " << buffer << std::endl;
				return false;
			}
			m_compiled = 1;
			return true;
		}
		const GLuint ShaderID()
		{
			return m_shaderID;
		}
	};

	class ShaderProgram
	{
	protected:
		GLuint m_programID;
		bool m_linked = false;
	public:
		ShaderProgram()
		{
			m_programID = glCreateProgram();
		}
		void AttachShader(Shader shaderToAttach)
		{
			if (shaderToAttach.m_compiled)
			{
				glAttachShader(m_programID, shaderToAttach.m_shaderID);
			}
		}
		void AddAttribute(GLuint attributeNumber, const char* attributeName)
		{
			glBindAttribLocation(m_programID, attributeNumber, attributeName);
		}
		bool Link()
		{
			glLinkProgram(m_programID);
			GLint status;
			glGetProgramiv(m_programID, GL_LINK_STATUS, &status);
			if (status != GL_TRUE)
			{
				GLint infoLogLength = 0;
				glGetProgramiv(m_programID, GL_INFO_LOG_LENGTH, &infoLogLength);
				GLchar* buffer = (GLchar*)alloca(infoLogLength * sizeof(GLchar));
				GLsizei bufferSize;
				glGetProgramInfoLog(m_programID, infoLogLength * sizeof(GLchar), &bufferSize, buffer);
				std::cout << "Link Error: " << (buffer) << std::endl;
				return false;
			}
			m_linked = true;
			return true;
		}
		void UseProgram()
		{
			if (!m_linked)
			{
				std::cerr << "Program Not Linked!" << std::endl;
				return;
			}
			glUseProgram(m_programID);
		}
		const GLuint ProgramID()
		{
			return m_programID;
		}
	};

}

GLint Triangle(unsigned int height, unsigned int base, unsigned int posOnBase) //each value is from 0 to 100.
{
	
	struct Vertex
	{
		glm::vec2 position;
		glm::vec3 colour;
	};
/*	Vertex vertices[]
	{
		Vertex{ glm::vec2(0.0f + 0.01f*(posOnBase % 100), 0.0f - 0.01f*(height % 100) / 2), glm::vec3(+1.0f, +1.0f, +1.0f) },
		Vertex{ glm::vec2(0.0f, 0.0f + (height % 100) / 2), glm::vec3(+0.5f, +0.25f, +0.0f) },
		Vertex{ glm::vec2(0.0f - 0.01f*(base % 100 - posOnBase % 100)), glm::vec3(+0.0f, +0.25f, +0.5f) }
	}; */
	Vertex vertices[]
	{
		Vertex{ glm::vec2(+1.0f, -1.0f), glm::vec3(+1.0f, +0.0f, +0.0f) },
		Vertex{ glm::vec2(+0.0f, +1.0f), glm::vec3(+0.0f, +1.0f, +0.0f) },
		Vertex{ glm::vec2(-1.0f, -1.0f), glm::vec3(+0.0f, +0.0f, +1.0f) },

		Vertex{ glm::vec2(-1.0f, +1.0f), glm::vec3(+0.0f, +0.0f, +1.0f) },
		Vertex{ glm::vec2(+1.0f, +1.0f), glm::vec3(+0.0f, +1.0f, +0.0f) },
		Vertex{ glm::vec2(+0.0f, -1.0f), glm::vec3(+1.0f, +0.0f, +0.0f) }
	};

	GLabs::Buffer arrayBuffer;
	arrayBuffer.Data(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	GLuint tempArrayBuffer;
	glGenBuffers(1, &tempArrayBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, tempArrayBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	GLushort indices[]
	{
		0,1,2, 3,4,5
	};

	GLabs::Buffer elementArrayBuffer;
	elementArrayBuffer.Data(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	GLuint tempElemArrayBuffer;
	glGenBuffers(1, &tempElemArrayBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, tempElemArrayBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

//	arrayBuffer.Bind(GL_ARRAY_BUFFER);

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);

	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), nullptr);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(2 * sizeof(float)));

	return tempElemArrayBuffer;
//	return elementArrayBuffer.BufferID();
//	return arrayBuffer.BufferID();
}

GLuint ShaderProgram()
{
	std::ifstream vshFileStream("D:\\Program Files (x86)\\msdev\\dev\\OpenGL rewrite\\OpenGL rewrite\\vsh.shader");
	std::ifstream fshFileStream("D:\\Program Files (x86)\\msdev\\dev\\OpenGL rewrite\\OpenGL rewrite\\fsh.shader");

	std::string StrVertex = std::string(std::istreambuf_iterator<char>(vshFileStream), std::istreambuf_iterator<char>());
	std::string StrFragment = std::string(std::istreambuf_iterator<char>(fshFileStream), std::istreambuf_iterator<char>());
	
	const char* vshCStr[1] = { StrVertex.c_str() };
	const char* fshCStr[1] = { StrFragment.c_str() };

	GLabs::Shader VertexShader(GL_VERTEX_SHADER), FragmentShader(GL_FRAGMENT_SHADER);

	VertexShader.AttachSource(vshCStr);
	FragmentShader.AttachSource(fshCStr);

	VertexShader.Compile();
	FragmentShader.Compile();

	GLabs::ShaderProgram Program;
	Program.AttachShader(VertexShader);
	Program.AttachShader(FragmentShader);

	Program.AddAttribute(0, "vertex_position");
	Program.AddAttribute(1, "vertex_colour");

	Program.Link();
	Program.UseProgram();

	return Program.ProgramID();
}

int main()
{
	if (!glfwInit())
	{
		std::cerr << "GLFW Initialisation failure!" << std::endl;
	}

	GLFWwindow* window;
	window = glfwCreateWindow(1280, 720, "Superb Window", 0, 0);
	glfwMakeContextCurrent(window);

	GLFWimage images[1];
	images[0] = load_icon("my_icon.png");
	glfwSetWindowIcon(window, 1, images);

	GLenum errCode = glewInit();
	if (errCode != GLEW_OK)
	{
		std::cerr << "GLEW Intialisation failure!" << std::endl;
		glfwTerminate();
		return -1;
	}

	GLuint triangleBuffer = Triangle(50, 50, 25);
	GLuint program = ShaderProgram();

	while (!glfwWindowShouldClose(window))
	{
		int height, width;
		glfwGetWindowSize(window, &width, &height);
		glViewport(0, 0, width, height);

		glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(0.0f, 0.0f, 0.5f, +1.0f);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, triangleBuffer);
//		glBindBuffer(GL_ARRAY_BUFFER, triangleBuffer);

		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_SHORT, 0);
//		glDrawArrays(GL_TRIANGLES, 0, 3);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}