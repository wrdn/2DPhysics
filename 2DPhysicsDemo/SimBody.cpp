#include "SimBody.h"

float2 SimBody::gravity = float2(0, meters(-9.81f));

int SimBody::GUID_GEN = 0;

int SimBody::whoami = 1;

SimBody::SimBody(void)
{
	position.zero();
	velocity.zero();
	force.zero();

	dragCoefficient = 0.1f;
	friction = 0.2f;
	density = inertia = invInertia = rotation_in_rads = angularVelocity = torque = 0;
	rotation_matrix.Identity();

	mass = I = 10;
	invMass = invI = 1.0f/mass;

	fillMode = GL_FILL;
	mesh = MeshHandle(0);
	
	lastAxis = 0;

	isbox=true;

	hashid = GUID_GEN++;

	use_textures = use_shaders = draw = update = true;

	owner=1;
};

void SimBody::Draw()
{
	//if(!draw) return;

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
	//glTranslatef(position.x, position.y, 0);

	//if(isbox)
	//{
	//	glRotatef(RADTODEG(rotation_in_rads), 0,0, 1);
	//}
	//else
	//{
	//	glRotatef(RADTODEG(rotation_in_rads), 0,0, -1);
	//}

	// draw
	glDisable(GL_CULL_FACE);

	if(owner == SimBody::whoami)
	{
		//glColor3fv(objectMaterial.GetObjectColor().GetVec());
		glColor3f(1,0,0);
	}
	else
	{
		glColor3f(0,1,0);
	}
	
	glPolygonMode(GL_FRONT_AND_BACK, fillMode);

	glBegin(GL_LINE_LOOP);
	for(u32 i=0;i<transformedVertices.size();++i)
	{
		glVertex2f(transformedVertices[i].x, transformedVertices[i].y);
	}
	glEnd();

	//mesh->Draw();

	glPopMatrix();

	// cleanup state
	glColor3fv(Color::WHITE.GetVec());
	//mesh->glUseProgram(0);
	//mesh->glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, 0);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
};

#include "SAT.h"
#include "Contact.h"
bool SimBody::Collide(SimBody &other, f32 dt)
{
	f32 t = dt;
	float2 N;

	//this->CalculateRotationMatrix();
	//other.CalculateRotationMatrix();

	if(SAT::Collide(*this, other, N, t))
	{
		float2 CA[4];
		float2 CB[4];
		u32 Cnum=0;

		FindContacts(*this, other, N, t, CA, CB, Cnum);

		DContact cont(CA, CB, Cnum, N, t, this, &other);
		cont.Solve();
		return true;
	}
	return false;
};