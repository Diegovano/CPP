#pragma once

namespace GLabs
{

	class Buffer
	{
		GLenum m_bindPoint = NULL;
	protected:
		GLuint m_bufferID;
	public:

		Buffer() : m_bindPoint(NULL)
		{
			glGenBuffers(1, &m_bufferID);
		}

		~Buffer() { }

		void Bind(GLenum bindPoint);
		template<typename _Ty>
		void Data(GLenum bindPoint, uint32_t size, _Ty* data, GLenum usage)
		{
			Bind(bindPoint);
			glBufferData(bindPoint, size, data, usage);
		}
		template<typename _Ty>
		void SubData(GLenum bindPoint, uint32_t offset, uint32_t size, _Ty* data)
		{
			glBufferSubData(bindPoint, offset, size, data);
		}
		const GLuint BufferID();
	};

	class Shader
	{
		friend class ShaderProgram;
		GLenum m_shaderType;
	protected:
		GLuint m_shaderID;
		const char** m_shaderSource;
		bool m_compiled;
	public:

		Shader(GLenum shaderType) : m_shaderType(shaderType), m_compiled(0)
		{
			m_shaderID = glCreateShader(shaderType);
		}

		void AttachSource(const char** src);

		bool Compile();
		const GLuint ShaderID();
	};

	class ShaderProgram
	{
	protected:
		GLuint m_programID;
		bool m_linked;
	public:

		ShaderProgram() : m_linked(false)
		{
			m_programID = glCreateProgram();
		}

		void AttachShader(Shader shaderToAttach);
		void AddAttribute(GLuint attributeNumber, const char* attributeName);
		bool Link();
		void UseProgram();
		const GLuint ProgramID();
	};
}