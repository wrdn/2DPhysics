#include "Mesh.h"

const GLvoid* BUFFER_OFFSET(const u32 i)
{
	return ((c8 *)NULL + (i));
};

void Mesh::Unload()
{
	// Delete VBO buffers
	if(meshvbo.meshData) { glDeleteBuffers(1, &meshvbo.meshData); }
	if(meshvbo.indexData) { glDeleteBuffers(1, &meshvbo.indexData); }
	meshvbo.meshData = meshvbo.indexData = dbg_vertex_array_sz = dbg_index_array_sz = 0;
};

bool Mesh::BuildVBO(const VERTEX *vertexData, const u32 vertexArraySz, const u32 *indexData, const u32 indexArraySz)
{
	// Unload first to avoid memory leaks
	this->Unload();
	if(!vertexData || !vertexArraySz || !indexData || !indexArraySz) { return false; }

	// Create buffers
	glGenBuffers(1, &meshvbo.meshData);
	glGenBuffers(1, &meshvbo.indexData);
	if(!meshvbo.meshData || !meshvbo.indexData) { Unload(); return false; }

	// Bind buffers and send data
	glBindBuffer(GL_ARRAY_BUFFER, meshvbo.meshData);
	glBufferData(GL_ARRAY_BUFFER, sizeof(VERTEX) * vertexArraySz, vertexData, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, meshvbo.indexData);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(u32) * indexArraySz, indexData, GL_STATIC_DRAW);

	dbg_vertex_array_sz = vertexArraySz;
	dbg_index_array_sz = indexArraySz;

	// Unbind buffers (do not want to leave them enabled when we quit, want to leave a clean environment)
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	return true;
}

void Mesh::Draw()
{
	// bind VBO buffers
	glBindBuffer(GL_ARRAY_BUFFER, meshvbo.meshData);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, meshvbo.indexData);

	// enable vertex, normal and uv array
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);

	// set data pointers
	glVertexPointer(2, GL_FLOAT, sizeof(VERTEX), BUFFER_OFFSET(VERTEX_POSITION_BUFFER_OFFSET));
	glTexCoordPointer(2, GL_FLOAT, sizeof(VERTEX), BUFFER_OFFSET(VERTEX_UV_BUFFER_OFFSET));

	// draw mesh
	glDrawElements(geometryDataFormat, dbg_index_array_sz, GL_UNSIGNED_INT, BUFFER_OFFSET(0));

	// disable vertex, normal and uv array
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);

	// unbind VBO buffers
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
};