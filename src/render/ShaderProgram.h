#pragma once

#include <glad/glad.h>
#include <string>

namespace Render {
	class ShaderProgram {
	public:
			ShaderProgram(const std::string& vertexShader, const std::string& fregmentShader);
			~ShaderProgram();
			bool isComplited() const { return m_isCompiled;  }
			void use() const;

			ShaderProgram() = delete;
			ShaderProgram(ShaderProgram&) = delete;
			ShaderProgram& operator=(const ShaderProgram&) = delete;
			ShaderProgram& operator=(ShaderProgram&& shaderProgram) noexcept;
			ShaderProgram(ShaderProgram&& shaderProgram) noexcept;

	private:
		bool createShader(const std::string& source, const GLenum shaderType, GLuint& shaderID);

		bool m_isCompiled = false;
		GLuint m_ID = 0;
	};
}