#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

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

GLint triangle(unsigned int height, unsigned int base, unsigned int posOnBase)
{
	struct Vertex
	{
		glm::vec2 position;
		glm::vec3 colour;
	};

	Vertex vertices
	{
		Vertex{ glm::vec2(+1.0f, -1.0f), glm::vec3(+1.0f, 1.0f, 1.0f) }
		Vertex
		Vertex
	}
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

	GLenum errCode = glewInit();
	if (errCode != GLEW_OK)
	{
		std::cerr << "GLEW Intialisation failure!" << std::endl;
		glfwTerminate();
		return -1;
	}



	while (!glfwWindowShouldClose(window))
	{
		int height, width;
		glfwGetWindowSize(window, &width, &height);
		glViewport(0, 0, width, height);

		glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(0.0f, 0.0f, 0.0f, +1.0f);

		glBindBuffer();

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}