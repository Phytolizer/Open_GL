﻿#pragma once
#include "glm/glm.hpp"
#include <string>
#include <unordered_map>

struct shaderProgramSource {
    std::string vertexSource;
    std::string fragmentSource;
};

class Shader {
private:
    std::string m_FilePath;
    unsigned int m_RendererID;
    std::unordered_map<std::string, int> m_UniformLocationCache;

public:
    Shader(const std::string &filepath);
    ~Shader();

    void Bind() const;
    void Unbind() const;

    //set uniforms
    void SetUniform4f(const std::string &name, float v0, float v1, float v2, float v3);
    void SetUniform1f(const std::string &name, float v0);
    void SetUniform4i(const std::string &name, int value);
    void SetUniformMat4f(const std::string &name, const glm::mat4 &matrix);

private:
    shaderProgramSource ParseShader(const std::string &filepath);
    unsigned int CompileShader(unsigned int type, const std::string &source);
    unsigned int CreateShader(const std::string &vertexShader, const std::string &framentShader);
    int GetUniformLocation(const std::string &name);
};
