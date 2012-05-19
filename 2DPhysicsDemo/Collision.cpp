#include "Collision.h"
#include <math.h>

bool LineCircleCollision(const Line2D &line, const Circle &c, CollisionPoint2D &cp)
{
	float2 lineDir = line.end - line.start;

	f32 A = lineDir.dot(lineDir);
	f32 B = 2.0f * (lineDir.x * (line.start.x - c.center.x) + lineDir.y * (line.start.y - c.center.y));
	f32 C = (line.start.x - c.center.x) * (line.start.x - c.center.x) +
		(line.start.y - c.center.y) * (line.start.y - c.center.y) -
		c.radius * c.radius;

	f32 det = B*B - 4 * A * C;
	if(det < 0 || A < 0.0001f) { return false; }
	else if(det < 0)
	{
		// 1 solution
		cp.t1 = -B / (2 * A);
		cp.t2 = -1;
		cp.p1.x = line.start.x + cp.t1 * lineDir.x;
		cp.p1.y = line.start.y + cp.t1 * lineDir.y;
		return true;
	}
	else
	{
		// 2 solutions
		cp.t1 = (-B + sqrtf(det)) / (2*A);
		cp.t2 = (-B - sqrtf(det)) / (2*A);
		if(cp.t1 > cp.t2)
		{
			f32 tmp = cp.t1;
			cp.t1 = cp.t2;
			cp.t2 = tmp;
		}

		cp.p1.x = line.start.x + cp.t1 * lineDir.x;
		cp.p1.y = line.start.y + cp.t1 * lineDir.y;

		cp.p2.x = line.start.x + cp.t2 * lineDir.x;
		cp.p2.y = line.start.y + cp.t2 * lineDir.y;

		return true;
	}
};

bool Hit(const AABB &a, const AABB &b)
{
	if(abs(a.center.x - b.center.x) > (a.extents.x + b.extents.x)) return false;
	if(abs(a.center.y - b.center.y) > (a.extents.y + b.extents.y)) return false;
	return true;
};

bool Hit(const Circle &a, const Circle &b)
{
	f32 dist_squared = a.center.distance_squared(b.center); // use distance squared to avoid sqrt
	f32 radius_sum = a.radius + b.radius;
	return dist_squared < radius_sum*radius_sum;
};

bool BoundingCircleHit(const float2 &pos1, const float radius1, const float2 &pos2, const float radius2)
{
	return Hit(Circle(pos1, radius1), Circle(pos2, radius2));
};

bool Overlaps(MinMaxProjection &ax, MinMaxProjection &bx)
{
	f32 d0 = ax.min - bx.max;
	f32 d1 = bx.min - ax.max;
	if(d0 > 0.0f || d1 > 0.0f) { return false; }
	return true;
};

void ProjectPointOnSegment(const float2 &V, const float2 &A, const float2 &B, float2 &W, f32 &pt)
{
	float2 AV = V-A, AB = B-A;
	
	f32 t = AV.dot(AB) / AB.dot(AB);
	t = max(0.0f,t);
	t = min(1.0f,t);

	pt = t;

	W = A + (AB * t);
};

float2 TransformVector(const float2 &vertex, const float2 &p, const float2 &v, const Mat22 xOrient, f32 t)
{
	return p+(vertex*xOrient);
};

bool PointInCircle(const float2& point, Circle c)
{
	float xDiff = point.x - c.center.x;
	float yDiff = point.y - c.center.y;
	return ( (xDiff*xDiff) + (yDiff*yDiff) ) <= (c.radius*c.radius);
};

bool PointInBox(const float2 &point, float L, float R, float B, float T)
{
	if(point.x >= L && point.x <= R)
		if(point.y >= B && point.y <= T)
			return true;
	return false;
};