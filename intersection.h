#ifndef TRIANGLES_INTERSECTION_H
#define TRIANGLES_INTERSECTION_H

#include "geometry_objects.h"

bool IsIntersect(const geometry_objects::Triangle &tr1, const geometry_objects::Triangle &tr2);

static int sign(float a);

//that is the distance multiplied by the length of the norm vector
static float SignedDistancePointToPlane(const geometry_objects::Point &point, const geometry_objects::Plane &plane);


#endif //TRIANGLES_INTERSECTION_H
