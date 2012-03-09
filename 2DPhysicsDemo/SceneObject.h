#pragma once

#include "Mesh.h"
#include "float2.h"
#include "float3.h"
#include "Material.h"

//! Represents a 2D object in the scene
//! Textures are enabled by default. Shaders are disabled by default.
//! Use SetUsingShaders() or SetUsingTextures() to change these defaults on an object by object basis
//! Can globally disable shaders and textures using SetGlobalUseTextures() and SetGlobalUseShaders()
class SceneObject
{
private:
	
	static bool GLOBAL_USE_SHADERS;
	static bool GLOBAL_USE_TEXTURES;

	bool local_use_textures;
	bool local_use_shaders;

	float2 position, scale;
	Mat44 orientation; // can represent 3D rotations (using 4x4 matrix so its easy to pass to OpenGL)

	Material objectMaterial;

	MeshHandle mesh;
	
	GLenum polygonFillMode;

public:

	SceneObject() : scale(1.0f), polygonFillMode(GL_FILL), local_use_textures(true), local_use_shaders(false) {};
	~SceneObject(void);

	GLenum GetPolygonFillMode() const { return polygonFillMode; };
	void SetPolygonFillMode(const GLenum fillMode) { polygonFillMode = fillMode; };
	void SetUsingTextures(const bool useTextures) { local_use_textures = useTextures; };
	void SetUsingShaders(const bool useShaders) { local_use_shaders = useShaders; };
	bool UsingTextures() const { return local_use_textures; };
	bool UsingShaders() const { return local_use_shaders; };
	const MeshHandle GetMesh() const { return mesh; };
	void SetMesh(const MeshHandle m) { mesh = m; };
	const float2& GetPosition()const { return position; };
	void SetPosition(const float2 &pos) { position = pos; };
	const float2& GetScale() const { return scale; }
	void SetScale(const float2 &sc) { scale = sc; };
	const Mat44 &GetOrientationMatrix() { return orientation; };
	void SetOrientationMatrix(const Mat44 &mat) { orientation = mat; };

	void ClearTextures() { objectMaterial.ClearTextures(); };
	int AddTexture(TextureHandle t) { return objectMaterial.AddTexture(t); };
	void SetShader(ShaderHandle active_shader) { objectMaterial.SetShader(active_shader); };
	ShaderHandle GetShader() { return objectMaterial.GetShader(); };

	static void SetGlobalUseTextures(bool useTex) { GLOBAL_USE_TEXTURES = useTex; }
	static bool GetGlobalUseTextures() { return GLOBAL_USE_TEXTURES; };
	static void SetGlobalUseShaders(bool useShaders) { GLOBAL_USE_SHADERS = useShaders; }
	static bool GetGlobalUseShaders() { return GLOBAL_USE_SHADERS; };

	void Draw();
};

