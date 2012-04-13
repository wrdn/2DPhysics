#pragma once

#include "color.h"
#include <vector>
#include "Texture.h"
#include "Shader.h"

class Material
{
private:
	color objectColor;

	std::vector<TextureHandle> textures;
	ShaderHandle activeShader;

public:
	Material() : objectColor(1.0f) {};
	Material(const color &_objectColor) : objectColor(_objectColor) {};

	color& GetObjectColor() { return objectColor; };
	void SetObjectColor(const color &col) { objectColor = col; };

	std::vector<TextureHandle> &GetTextures() { return textures; };

	void ClearTextures() { textures.clear(); };

	u32 AddTexture(TextureHandle t)
	{
		textures.push_back(t);
		return textures.size()-1;
	};

	void SetShader(ShaderHandle active_shader)
	{
		activeShader = active_shader;
	};

	ShaderHandle GetShader() { return activeShader; };
};