#include "intersection.h"
#include <iostream>

bool IsIntersect(const geometry_objects::Triangle &tr0, const geometry_objects::Triangle &tr1) {
    //check if one of triangles is degenerate
    if (tr0.isDegenerate() || tr1.isDegenerate()) return false;

    //compute signed distances from vertices of one triangle to the plane of another
    geometry_objects::Plane plane_tr0{tr0};
    float signed_distance10 = SignedDistancePointToPlane(tr1.GetPoint1(), plane_tr0);
    float signed_distance11 = SignedDistancePointToPlane(tr1.GetPoint2(), plane_tr0);
    float signed_distance12 = SignedDistancePointToPlane(tr1.GetPoint3(), plane_tr0);

    //check distances
    if (signed_distance10 * signed_distance11 > 0 && signed_distance11 * signed_distance12 > 0) return false;

    geometry_objects::Plane plane_tr1{tr1};
    if(geometry_objects::ComparePlanes(plane_tr0, plane_tr1)){
        if(geometry_objects::CheckParallelism(plane_tr0, plane_tr1))    return false;
        //here intersection in 2D space
    }

    float signed_distance00 = SignedDistancePointToPlane(tr0.GetPoint1(), plane_tr1);
    float signed_distance01 = SignedDistancePointToPlane(tr0.GetPoint2(), plane_tr1);
    float signed_distance02 = SignedDistancePointToPlane(tr0.GetPoint3(), plane_tr1);

    if (signed_distance00 * signed_distance01 > 0 && signed_distance01 * signed_distance02 > 0) return false;


}

float SignedDistancePointToPlane(const geometry_objects::Point &point, const geometry_objects::Plane &plane) {
    geometry_objects::Vector3D nv = plane.GetNormVector();

    return (nv.getX() * point.getX() + nv.getY() * point.getY() + nv.getZ() * point.getZ());
}

int sign(float a) {
    a < 0 ? -1 : 1;
}
