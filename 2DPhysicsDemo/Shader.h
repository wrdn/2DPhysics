#pragma once

#include "ctypes.h"
#include <iosfwd>

#include "Mat44.h"
#include "float2.h"
#include "float3.h"
#include "float4.h"
#include "Texture.h"
#include "ShaderObject.h"

class Shader : public Resource, public glex
{
private:
	GLuint shaderProgramID;
	
	VertexShaderHandle vs;
	FragmentShaderHandle fs;

	void Unload();
	bool HasLinked();

public:
	Shader() : shaderProgramID(0), vs((VertexShaderObject*)0), fs((FragmentShaderObject*)0)
	{
		glex::Load();
	};
	~Shader()
	{
		Unload();
	};

	bool CreateProgram(VertexShaderHandle vs_handle, FragmentShaderHandle fs_handle);

	VertexShaderHandle GetVS() const { return vs; };
	FragmentShaderHandle GetFS() const { return fs; };


	void Activate();
	void Deactivate();

	GLint GetUniformLocation(const GLchar* name);

	void SetUniform(const c8 * const name, const GLint val);
	void SetUniform(const c8 * const name, const TextureHandle tex);
	void SetUniform(const c8 * const name, const f32 val);
	void SetUniform(const c8 * const name, const float2 &val);
	void SetUniform(const c8 * const name, const float3 &val);
	void SetUniform(const c8 * const name, const float4 &val);
	void SetUniform(const c8 * const name, const Mat44 &val);
	
	bool Valid();

	void PrintProgramLog(std::ostream &out);
	void PrintActiveUniforms(std::ostream &out);
};

typedef std::tr1::shared_ptr<Shader> ShaderHandle;