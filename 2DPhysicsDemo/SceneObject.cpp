#include "SceneObject.h"
#include "color.h"

bool SceneObject::GLOBAL_USE_SHADERS = false;
bool SceneObject::GLOBAL_USE_TEXTURES = true;

SceneObject::~SceneObject(void)
{
}

void SceneObject::Draw()
{
	if(!mesh) return;

	// Activate shader
	if(GLOBAL_USE_SHADERS && local_use_shaders && objectMaterial.GetShader())
		objectMaterial.GetShader()->Activate();

	// Activate textures
	if(GLOBAL_USE_TEXTURES && local_use_textures)
	{
		for(u32 i=0;i<objectMaterial.GetTextures().size();++i)
		{
			TextureHandle t = objectMaterial.GetTextures()[i];
			mesh->glActiveTexture(t->GetTextureSlot());
			t->Activate();
		}
	}

	glPushMatrix();

	// Transform model
	glTranslatef(position.x(), position.y(), 0.0f); // apply translation (2D)
	glMultMatrixf(orientation.GetMatrix()); // apply rotation by multiplying by orientation 4x4 matrix
	glScalef(scale.x(), scale.y(), 1.0f); // apply scale (2D)

	// Draw model
	glColor3fv(objectMaterial.GetObjectColor().GetVec());
	glPolygonMode(GL_FRONT_AND_BACK, polygonFillMode);
	mesh->Draw();

	glPopMatrix();

	// Deactivate shader and textures
	glColor3fv(Color::WHITE.GetVec());
	mesh->glUseProgram(0);
	mesh->glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, 0);
};