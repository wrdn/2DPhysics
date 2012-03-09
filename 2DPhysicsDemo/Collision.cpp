#include "Collision.h"
#include <math.h>

bool LineCircleCollision(const Line2D &line, const Circle &c, CollisionPoint2D &cp)
{
	float2 lineDir = line.end - line.start;

	f32 A = lineDir.dot(lineDir);
	f32 B = 2.0f * (lineDir.x() * (line.start.x() - c.pos.x()) + lineDir.y() * (line.start.y() - c.pos.y()));
	f32 C = (line.start.x() - c.pos.x()) * (line.start.x() - c.pos.x()) +
		(line.start.y() - c.pos.y()) * (line.start.y() - c.pos.y()) -
		c.radius * c.radius;

	f32 det = B*B - 4 * A * C;
	if(det < 0 || A < 0.0001f) { return false; }
	else if(det < 0)
	{
		// 1 solution
		cp.t1 = -B / (2 * A);
		cp.t2 = -1;
		cp.p1.x(line.start.x() + cp.t1 * lineDir.x());
		cp.p1.y(line.start.y() + cp.t1 * lineDir.y());
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

		cp.p1.x(line.start.x() + cp.t1 * lineDir.x());
		cp.p1.y(line.start.y() + cp.t1 * lineDir.y());

		cp.p2.x(line.start.x() + cp.t2 * lineDir.x());
		cp.p2.y(line.start.y() + cp.t2 * lineDir.y());

		return true;
	}
};