#pragma once

#include "Arbiter.h"
#include "Body.h"
#include <list>
using namespace std;

class ProjectedVertex
{
public:
	int vertex;
	bool isA;
	float distance;

	ProjectedVertex *next;
	ProjectedVertex *previous;

	ProjectedVertex()
	{
	};

	ProjectedVertex(int vertex, boolean isA, float distance)
	{
		vertex = vertex;
		isA = isA;
		distance = distance;
	};
};

class EdgePair
{
public:
	int a;
	int b;
	EdgePair *next;

	EdgePair(int a, int b, EdgePair next)
	{
		a = a;
		b = b;
		next = next;
	}
};

class EdgePairs
{
public:
	EdgePair first;
	int size;

	EdgePairs() : size(0) {};

	void add(int idA, int idB)
	{
		first = new EdgePair(idA, idB, first);
		size++;
	}

	public int** toList()
	{
		//int[][] list = new int[size][2];
		int **list = new int[size][2];

		EdgePair *current = &first;
		for ( int i = 0; i < size; i++ ) {
			list[i][0] = current->a;
			list[i][1] = current->b;

			current = current->next;
		}

		return list;
	}
}

class EdgeSweep
{
public:
	ProjectedVertex *current;

	// stores all the ProjectedVertex objects (that are also in current).
	// used so we can properly free memory later
	vector<ProjectedVertex*> v;

	float2 sweepDir;

	EdgeSweep(float2 _sweepDir) : current(0)
	{
		sweepDir = _sweepDir;
	};

	void insertBackwards(int vertex, boolean isA, float distance) {
		ProjectedVertex *svl = new ProjectedVertex(vertex, isA, distance);
		v.push_back(svl);

		if ( current == 0 )
		{
			current = svl;
			return;
		}
		
		while ( current->distance > svl->distance ) {
			if ( current->previous == 0 ) {
				// insert before current
				current->previous = svl;
				svl->next = current;
				current = svl;
				return;
			}
			
			current = current->previous;
		}
		
		// insert after current
		svl->next = current->next;
		svl->previous = current;
		current->next = svl;
		
		if ( svl->next != 0 )
			svl->next->previous = svl;
			
		current = svl;
	};

	void insertForwards(int vertex, boolean isA, float distance)
	{
		ProjectedVertex *svl = new ProjectedVertex(vertex, isA, distance);
		v.push_back(svl);

		if ( current == 0 ) {
			current = svl;
			return;
		}
		
		while ( current->distance <= svl->distance ) {
			if ( current->next == 0 ) {
				// insert after current
				current->next = svl;
				svl->previous = current;
				current = svl;
				return;
			}
			
			current = current->next;
		}
		
		// insert before current
		svl->next = current;
		svl->previous = current->previous;
		current->previous = svl;
		
		if ( svl->previous != 0 )
			svl->previous->next = svl;
			
		current = svl;
	};

	void insert(int vertex, bool isA, float distance)
	{
		if ( current == 0 || current->distance <= distance )
			insertForwards(vertex, isA, distance);
		else
			insertBackwards(vertex, isA, distance);
	}

	void goToStart()
	{
		// get the first vertex
		while ( current->previous != 0 )
			current = current->previous;
	}
};