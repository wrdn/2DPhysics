#include "ResourceManager.h"
ResourceManager* ResourceManager::resMan = 0;
i32 ResourceManager::idProvider = 0;

ResourceManager& ResourceManager::get() // returns reference to help avoid mucking with pointers
{
	if(!ResourceManager::resMan)
	{
		ResourceManager::resMan = new ResourceManager();
	}
	return *ResourceManager::resMan;
};

void ResourceManager::AddResource(i32 id, const c8 *name, Resource *r)
{
	r->SetResourceID(id);
	r->SetName(name);
	resourceMap[id] = std::tr1::shared_ptr<Resource>(r);
};

TextureHandle LoadTextureNow(const c8 *filename, const c8 *textureResourceName) // if not provided, the default resource name used is the filename
{
	TextureHandle hnd = textureResourceName ? ResourceManager::get().CreateAndGetResource<Texture>(textureResourceName) : ResourceManager::get().CreateAndGetResource<Texture>(filename);
	if(hnd->GetGLTextureID()) { return hnd; }; // return resource if already loaded
	if(!hnd->Load(filename)) { ResourceManager::get().RemoveResource(hnd->GetResourceID()); }
	return hnd;
};

ShaderHandle LoadShaderNow(const c8 *vertexShaderFilename, const c8 *fragmentShaderFilename, const c8 *shaderResourceName) // if not provided, there is no default shader resource name
{
	if(!vertexShaderFilename || !fragmentShaderFilename) { return ShaderHandle((Shader*)0); };

	// Compile and check vertex shader
	VertexShaderHandle vsh = ResourceManager::get().CreateAndGetResource<VertexShaderObject>(vertexShaderFilename); // ASSUME WE WANT TO RELOAD SHADER (COULD CHECK IF ID ALREADY VALID)
	if(!vsh->Valid())
	{
		if(!vsh->CompileFromFile(vertexShaderFilename))
		{
			vsh->PrintShaderLog(std::cout);
			ResourceManager::get().RemoveResource(vsh->GetResourceID());
			return ShaderHandle((Shader*)0);
		}
	}
	
	// Compile and check fragment shader
	FragmentShaderHandle fsh = ResourceManager::get().CreateAndGetResource<FragmentShaderObject>(fragmentShaderFilename); // ASSUME WE WANT TO RELOAD SHADER (COULD CHECK IF ID ALREADY VALID)
	if(!fsh->Valid())
	{
		if(!fsh->CompileFromFile(fragmentShaderFilename))
		{
			fsh->PrintShaderLog(std::cout);
			ResourceManager::get().RemoveResource(vsh->GetResourceID());
			ResourceManager::get().RemoveResource(fsh->GetResourceID());
			return ShaderHandle((Shader*)0);
		}
	}

	// Compile and check program object
	ShaderHandle sh = shaderResourceName ? ResourceManager::get().CreateAndGetResource<Shader>(shaderResourceName) : ResourceManager::get().CreateAndGetResource<Shader>();

	if(sh->GetVS() && sh->GetFS()) // SAME SHADER
	{
		if(sh->GetVS()->GetResourceID() == vsh->GetResourceID() && sh->GetFS()->GetResourceID() == fsh->GetResourceID())
		{
			return sh;
		}
	};

	if(!sh->CreateProgram(vsh, fsh))
	{
		sh->PrintProgramLog(std::cout);
		ResourceManager::get().RemoveResource(vsh->GetResourceID());
		ResourceManager::get().RemoveResource(fsh->GetResourceID());
		ResourceManager::get().RemoveResource(sh->GetResourceID());
		return ShaderHandle((Shader*)0);
	}
	
	return sh;
};

RenderTargetHandle CreateRenderTarget(u32 width, u32 height, const c8 *renderTargetResourceName)
{
	RenderTargetHandle rth = renderTargetResourceName ? ResourceManager::get().CreateAndGetResource<RenderTarget>(renderTargetResourceName)
		: ResourceManager::get().CreateAndGetResource<RenderTarget>();
	rth->SetWidthAndHeight(width, height);
	return rth;
};

MeshHandle CreateMesh(const c8 *name)
{
	MeshHandle mh = ResourceManager::get().CreateAndGetResource<Mesh>();
	mh->SetName(name);
	return mh;
};