#include <GL/gl3w.h>
#include <Shader.h>
#include <vector>
#include <iostream>
#include <fstream>

Shader::Shader(string name) {
    this->name = name;
}

Shader::~Shader() {}

void Shader::load() {
    string vertexFile = "../resources/shader/" + this->name + ".vert";
    ifstream vertex(vertexFile.c_str());
    string vertexSource((istreambuf_iterator<char>(vertex)), istreambuf_iterator<char>());
    const GLchar * vSrc = vertexSource.c_str();
    GLuint vertexShaderId = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShaderId, 1, &vSrc, NULL);
    glCompileShader(vertexShaderId);
    GLint isCompiled = 0;
    glGetShaderiv(vertexShaderId, GL_COMPILE_STATUS, &isCompiled);
    if (isCompiled == GL_FALSE) {
        GLint maxLength = 0;
        glGetShaderiv(vertexShaderId, GL_INFO_LOG_LENGTH, &maxLength);
        vector<GLchar> errorLog(maxLength);
        glGetShaderInfoLog(vertexShaderId, maxLength, &maxLength, &errorLog[0]);
        glDeleteShader(vertexShaderId);
        cout << "Vertex shader compilation failed" << endl;
        throw errorLog[0];
    }
    cout << this->name + ".vert compiled..." << endl;

    string fragmentFile = "../resources/shader/" + this->name + ".frag";
    ifstream fragment(fragmentFile.c_str());
    string fragmentSource((istreambuf_iterator<char>(fragment)), istreambuf_iterator<char>());
    const GLchar * fSrc = fragmentSource.c_str();
    GLuint fragmentShaderId = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShaderId, 1, &fSrc, NULL);
    glCompileShader(fragmentShaderId);
    isCompiled = 0;
    glGetShaderiv(fragmentShaderId, GL_COMPILE_STATUS, &isCompiled);
    if (isCompiled == GL_FALSE) {
        GLint maxLength = 0;
        glGetShaderiv(fragmentShaderId, GL_INFO_LOG_LENGTH, &maxLength);
        vector<GLchar> errorLog(maxLength);
        glGetShaderInfoLog(fragmentShaderId, maxLength, &maxLength, &errorLog[0]);
        glDeleteShader(vertexShaderId);
        glDeleteShader(fragmentShaderId);
        cout << "Fragment shader compilation failed" << endl;
        throw errorLog[0];
    }
    cout << this->name + ".frag compiled..." << endl;

    this->id = glCreateProgram();
    glAttachShader(this->id, vertexShaderId);
    glAttachShader(this->id, fragmentShaderId);
    glLinkProgram(this->id);
    GLint isLinked = 0;
    glGetProgramiv(this->id, GL_LINK_STATUS, &isLinked);
    if (isLinked == GL_FALSE) {
        GLint maxLength = 0;
        glGetProgramiv(this->id, GL_INFO_LOG_LENGTH, &maxLength);
        vector<GLchar> infoLog(maxLength);
        glGetProgramInfoLog(this->id, maxLength, &maxLength, &infoLog[0]);
        glDeleteProgram(this->id);
        glDeleteShader(vertexShaderId);
        glDeleteShader(fragmentShaderId);
        cout << "Program linking compilation failed" << endl;
        throw infoLog[0];
    }
    glDetachShader(this->id, vertexShaderId);
    glDetachShader(this->id, fragmentShaderId);
    cout << "Program '" + this->name + "' linked!" << endl;
}

Shader & Shader::use() {
    glUseProgram(this->id);
    return *this;
}

void Shader::setMatrix4(const GLchar * name, const glm::mat4 & matrix) {
    glUniformMatrix4fv(glGetUniformLocation(this->id, name), 1, GL_FALSE, glm::value_ptr(matrix));
}
