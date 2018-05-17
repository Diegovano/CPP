#include <iostream>
#include <fstream>
#include <vector>
#include "../Dependencies/GLEW/include/GL/glew.h"
#include "../Dependencies/GLFW/include/GLFW/glfw3.h"
#include "../Dependencies/glm/glm.hpp"
#include "../rsc/abs/GLabs.h"

const float X_DELTA = 0.1f;
const unsigned int NUM_VERTS_TRI = 3;
const unsigned int NUM_FLOATS_VERTS = 6;
const unsigned int TRIANGLE_BYTE_SIZE = NUM_FLOATS_VERTS * NUM_VERTS_TRI * sizeof(float);
const unsigned int MAX_TRIS = 20;
unsigned int numTris;

void sendDataToOpenGL() 
{
	GLabs::Buffer vertexBuffer;
	vertexBuffer.Bind(GL_ARRAY_BUFFER);
	glBufferData(GL_ARRAY_BUFFER, MAX_TRIS*TRIANGLE_BYTE_SIZE, NULL, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), nullptr);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
}

GLuint ShaderProgram()
{
	std::ifstream vshFileStream("D:\\Program Files (x86)\\msdev\\dev\\OpenGL rewrite\\OpenGL rewrite\\rsc\\sh\\vsh.shader");
	std::ifstream fshFileStream("D:\\Program Files (x86)\\msdev\\dev\\OpenGL rewrite\\OpenGL rewrite\\rsc\\sh\\fsh.shader");

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

void sendTri()
{
	if (numTris == MAX_TRIS)
	{
		return;
	}
	const float TRI_X = -1 + numTris * X_DELTA;
	struct Vertex
	{
		glm::vec3 position;
		glm::vec3 colour;
	};

	Vertex thisTri[]
	{
		Vertex{ glm::vec3(TRI_X, +1.0f, +0.0f), glm::vec3(+1.0f, +0.0f, +0.0f) },
		Vertex{ glm::vec3(TRI_X + X_DELTA, +1.0f, +0.0f), glm::vec3(+1.0f, +0.0f, +0.0f) },
		Vertex{ glm::vec3(TRI_X, +0.0f, +0.0f), glm::vec3(+1.0f, +0.0f, +0.0f) }
	};
	glBufferSubData(GL_ARRAY_BUFFER, numTris*TRIANGLE_BYTE_SIZE, TRIANGLE_BYTE_SIZE, thisTri);
	numTris++;
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

	glEnable(GL_DEPTH_TEST);

	sendDataToOpenGL();
	GLuint program = ShaderProgram();

	while (!glfwWindowShouldClose(window))
	{
		int height, width;
		glfwGetWindowSize(window, &width, &height);
		glViewport(0, 0, width, height);

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(+0.0f, +0.0f, +0.0f, +1.0f);

		sendTri();

		glDrawArrays(GL_TRIANGLES, (numTris-1)*NUM_VERTS_TRI, numTris * NUM_VERTS_TRI);

		glfwSwapBuffers(window);
		glfwPollEvents();

		system("pause");
	}

	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}