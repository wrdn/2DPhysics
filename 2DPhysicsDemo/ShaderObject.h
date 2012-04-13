#pragma once

#include "ctypes.h"
#include <iosfwd>

#include "Mat44.h"
#include "float2.h"
#include "float3.h"
#include "float4.h"
#include "Texture.h"
#include "GameResource.h"
#include <GXBase.h>

class ShaderObject : public Resource, public glex
{
private:
	GLenum shaderType; // GL_VERTEX_SHADER or GL_FRAGMENT_SHADER. Default: GL_VERTEX_SHADER
	GLuint shaderID;

	void Unload();

protected:
	void SetShaderType(GLenum type) { shaderType = type; };
public:
	ShaderObject() : shaderType(GL_VERTEX_SHADER), shaderID(0)
	{
		glex::Load();
	};
	~ShaderObject()
	{
		Unload();
	};

	bool Valid()
	{
		return shaderID != 0;
	};

	GLuint GetShaderID() const { return shaderID; };

	bool HasCompiled();
	void PrintShaderLog(std::ostream &out);

	bool Compile(const c8 *src);
	bool CompileFromFile(const c8 *filename); // loads shader from file
};

class FragmentShaderObject : public ShaderObject
{
public:
	// only difference between vertex and fragment shader is the type variable used in glCreateShader(type)
	FragmentShaderObject() { SetShaderType(GL_FRAGMENT_SHADER); };
};

typedef ShaderObject VertexShaderObject;
typedef std::tr1::shared_ptr<ShaderObject> GenericShaderHandle;
typedef std::tr1::shared_ptr<VertexShaderObject> VertexShaderHandle;
typedef std::tr1::shared_ptr<FragmentShaderObject> FragmentShaderHandle;