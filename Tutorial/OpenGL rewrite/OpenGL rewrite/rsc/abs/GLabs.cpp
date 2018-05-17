#include <iostream>
#include "../Dependencies/GLEW/include/GL/glew.h"
#include "GLabs.h"



void GLabs::Buffer::Bind(GLenum bindPoint)
{
	glBindBuffer(bindPoint, m_bufferID);
	m_bindPoint = bindPoint;
}
const GLuint GLabs::Buffer::BufferID()
{
	return m_bufferID;
}



void GLabs::Shader::AttachSource(const char** src)
{
	m_shaderSource = src;
	glShaderSource(m_shaderID, 1, m_shaderSource, 0);
}

bool GLabs::Shader::Compile()
{
	std::cout << "Compiling shader " << m_shaderID << ".\n";
	glCompileShader(m_shaderID);
	GLint status;
	glGetShaderiv(m_shaderID, GL_COMPILE_STATUS, &status);
	if (status != GL_TRUE)
	{
		GLint infoLogLength = 0;
		glGetShaderiv(m_shaderID, GL_INFO_LOG_LENGTH, &infoLogLength);
		GLchar* buffer = (GLchar*)alloca(infoLogLength * sizeof(GLchar));
		GLsizei bufferSize;
		glGetShaderInfoLog(m_shaderID, infoLogLength * sizeof(GLchar), &bufferSize, buffer);
		std::cout << "Compile Error: " << buffer << std::endl;
		return false;
	}
	m_compiled = 1;
	return true;
}
const GLuint GLabs::Shader::ShaderID()
{
	return m_shaderID;
}



void GLabs::ShaderProgram::AttachShader(Shader shaderToAttach)
{
	if (shaderToAttach.m_compiled)
	{
		glAttachShader(m_programID, shaderToAttach.m_shaderID);
	}
}
void GLabs::ShaderProgram::AddAttribute(GLuint attributeNumber, const char* attributeName)
{
	glBindAttribLocation(m_programID, attributeNumber, attributeName);
}
bool GLabs::ShaderProgram::Link()
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
void GLabs::ShaderProgram::UseProgram()
{
	if (!m_linked)
	{
		std::cerr << "Program Not Linked!" << std::endl;
		return;
	}
	glUseProgram(m_programID);
}
const GLuint GLabs::ShaderProgram::ProgramID()
{
	return m_programID;
}