#include "SimBody.h"

float2 SimBody::gravity = float2(0, meters(-9.81f));

SimBody::SimBody(void)
{
	position = float2(0.0f);
	rotation = 0.0f;
	velocity = float2(0.0f);
	angularVelocity = 0.0f;
	force = float2(0.0f);
	torque = 0.0f;
	friction = 0.2f;

	mass = I = 10;
	invMass = invI = 1.0f/mass;

	fillMode = GL_FILL;
	mesh = MeshHandle(0);

	dragCoefficient = 0.1f;

	use_textures = use_shaders = draw = update = true;
};

void SimBody::Draw()
{
	if(!mesh || !draw) return;

	// activate shader and textures
	if(use_shaders && objectMaterial.GetShader())
		objectMaterial.GetShader()->Activate();
	if(use_textures && fillMode == GL_FILL) // only enable textures when GL_FILL is the fill mode, otherwise the object gets darker as it gets closer to the screen
	{
		for(u32 i=0;i<objectMaterial.GetTextures().size();++i)
			objectMaterial.GetTextures()[i]->Activate();
	}
	else
	{
		glDisable(GL_TEXTURE_2D);
	}

	glPushMatrix();

	// translate and rotate
	glTranslatef(position.x(), position.y(), 0);
	glRotatef(rotation, 0,0,1);

	// draw
	glDisable(GL_CULL_FACE);
	glColor3fv(objectMaterial.GetObjectColor().GetVec());
	glPolygonMode(GL_FRONT_AND_BACK, fillMode);

	mesh->Draw();

	glPopMatrix();

	// cleanup state
	glColor3fv(Color::WHITE.GetVec());
	mesh->glUseProgram(0);
	mesh->glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, 0);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
};

void Triangle::CalculateVerticesAndSeperatingAxis()
{
	vertices.resize(3);
	seperatingAxis.resize(3);

	const f32 l2 = sideLength;
	const float2 vT(0, l2);
	const float2 vBL(-l2,-l2);
	const float2 vBR(l2,-l2);

	vertices[0] = float2(0, l2);
	vertices[2] = float2(l2, -l2);
	vertices[1] = float2(-l2, -l2);

	const float2 firstAxis =  (vT - vBL).perp().normalize();
	const float2 secondAxis = (vT - vBR).perp().normalize();
	const float2 thirdAxis =  (vBL - vBR).perp().normalize();

	seperatingAxis[0] = firstAxis;
	seperatingAxis[1] = secondAxis;
	seperatingAxis[2] = thirdAxis;
};

void Box::CalculateVerticesAndSeperatingAxis()
{
	vertices.resize(4);
	seperatingAxis.resize(2);

	const float2 vBL(-extents.x(), -extents.y());
	const float2 vBR(extents.x(), -extents.y());
	const float2 vTL(-extents.x(), extents.y());
	const float2 vTR(extents.x(), extents.y());

	vertices[BL] = vBL;
	vertices[BR] = vBR;
	vertices[TL] = vTR;
	vertices[TR] = vTL;

	// For a box, there are only ever 2 seperating axis (4 possible, but 2 of the 4 are redundant)
	const float2 firstAxis =  (vTL - vBL).perp().normalize();
	const float2 secondAxis = (vBL - vBR).perp().normalize();

	seperatingAxis[0] = firstAxis;
	seperatingAxis[1] = secondAxis;
};