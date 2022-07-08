#pragma once

#include <String>
#include <memory>
#include <map>

namespace Renderer
{
	class ShaderProgram;
}


class ResourceManger {
public:
	ResourceManger(const std::string& executablePath);
	ResourceManger() = default;

	ResourceManger(const ResourceManger&) = delete;
	ResourceManger& operator=(const ResourceManger&) = delete;
	ResourceManger& operator=(ResourceManger&&) = delete;
	ResourceManger(ResourceManger&&) = delete;

	std::shared_ptr<Renderer::ShaderProgram> loadShaders(const std::string& shaderName, const std::string& vertexPath, const std::string& fragmentPath);
	std::shared_ptr<Renderer::ShaderProgram> getShaderProgram(const std::string& shaderName);

private:
	std::string getFileString(const std::string& relativeFilePath) const;

	typedef std::map<const std::string, std::shared_ptr<Renderer::ShaderProgram>> ShaderProgramsMap;
	ShaderProgramsMap m_shaderPrograms;

	std::string m_path;
};