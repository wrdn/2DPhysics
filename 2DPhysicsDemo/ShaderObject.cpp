#include "ShaderObject.h"
#include "strutils.h"
#include <iostream>

void ShaderObject::Unload()
{
	if(shaderID)
	{
		glDeleteShader(shaderID);
		shaderID = 0;
	};
};

bool ShaderObject::HasCompiled()
{
	if(!Valid()) { return false; }
	i32 shaderOK = 0;
	glGetShaderiv(shaderID, GL_COMPILE_STATUS, &shaderOK);
	return shaderOK == GL_TRUE;
};

void ShaderObject::PrintShaderLog(std::ostream &out)
{
	const int LOG_SZ = 4096;
	char log[LOG_SZ];
	glGetShaderInfoLog(shaderID, LOG_SZ, NULL, log);
	out << log << std::endl;
};

bool ShaderObject::Compile(const c8 *src)
{
	if(!src) { return false; }
	if(!Valid()) { shaderID = glCreateShader(shaderType); }; // create shader object

	glShaderSource(shaderID, 1, (const GLchar**)&src, 0);
	glCompileShader(shaderID);

	return HasCompiled();
};

bool ShaderObject::CompileFromFile(const char *filename)
{
	c8* shader_src = read_src_fast(filename);
	bool compiled = Compile(shader_src);
	delete [] shader_src;
	return compiled;
};