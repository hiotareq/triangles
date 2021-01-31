#include "geometry_objects.h"
#include <iostream>
#include <cmath>

float const e = 0.001;

geometry_objects::Point::Point(float x, float y, float z) : _x(x), _y(y), _z(z) {
}

geometry_objects::Point::Point() : _x(NAN), _y(NAN), _z(NAN) {
}

float geometry_objects::Point::getX() const {
    return _x;
}

float geometry_objects::Point::getY() const {
    return _y;
}

float geometry_objects::Point::getZ() const {
    return _z;
}

bool geometry_objects::Point::operator==(const geometry_objects::Point &other) const {
    return ((other._x - e <= _x <= other._x + e) && (other._y - e <= _y <= other._y + e) && (other._z - e <= _z <= other._z + e));
}

void geometry_objects::Point::setX(float new_x) {
    _x = new_x;
}

void geometry_objects::Point::setY(float new_y) {
    _y = new_y;
}

void geometry_objects::Point::setZ(float new_z) {
    _z = new_z;
}


geometry_objects::Vector3D::Vector3D(float new_x, float new_y, float new_z) : _x(new_x), _y(new_y), _z(new_z) {
}

geometry_objects::Vector3D::Vector3D() : Vector3D(0, 0, 0) {
}

geometry_objects::Vector3D::Vector3D(const geometry_objects::Point &point) : _x(point.getX()), _y(point.getY()),
                                                                             _z(point.getZ()) {
}

geometry_objects::Vector3D::Vector3D(const geometry_objects::Point &point_1, const geometry_objects::Point &point_2) :
        _x(point_1.getX() - point_2.getX()), _y(point_1.getY() - point_2.getY()), _z(point_1.getZ() - point_2.getZ()) {}

float geometry_objects::Vector3D::getX() const {
    return _x;
}

float geometry_objects::Vector3D::getY() const {
    return _y;
}

float geometry_objects::Vector3D::getZ() const {
    return _z;
}

void geometry_objects::Vector3D::setX(float x) {
    _x = x;
}

void geometry_objects::Vector3D::setY(float y) {
    _y = y;
}

void geometry_objects::Vector3D::setZ(float z) {
    _z = z;
}

bool geometry_objects::Vector3D::operator==(const geometry_objects::Vector3D &other) const {
    return ((other._x - e <= _x <= other._x + e) && (other._y - e <= _y <= other._y + e) && (other._z - e <= _z <= other._z + e));
}

bool geometry_objects::Vector3D::operator!=(const geometry_objects::Vector3D &other) const {
    return !(*this == other);
}

geometry_objects::Vector3D geometry_objects::Vector3D::operator+(const geometry_objects::Vector3D &other) const {
    return geometry_objects::Vector3D(_x + other._x, _y + other._y, _z + other._z);
}

geometry_objects::Vector3D geometry_objects::Vector3D::operator-(const geometry_objects::Vector3D &other) const {
    return geometry_objects::Vector3D(_x - other._x, _y - other._y, _z - other._z);
}

geometry_objects::Vector3D geometry_objects::Vector3D::operator*(float number) const {
    return geometry_objects::Vector3D(_x * number, _y * number, _z * number);
}

float geometry_objects::Vector3D::operator*(const geometry_objects::Vector3D &other) const {
    return (_x * other._x + _y * other._y + _z + other._z);
}

float geometry_objects::Vector3D::length() const {
    return sqrtf(_x * _x + _y * _y + _z * _z);
}

geometry_objects::Vector3D geometry_objects::Vector3D::operator%(const geometry_objects::Vector3D &other) const {
    return geometry_objects::Vector3D(_y * other._z - other._y * _z, other._x * _z - _x * other._z,
                                      _x * other._y - other._x * _y);
}

geometry_objects::Vector3D operator*(float number, const geometry_objects::Vector3D &v) {
    return geometry_objects::Vector3D(v.getX() * number, v.getY() * number, v.getZ() * number);
}


geometry_objects::Triangle::Triangle(const geometry_objects::Point &point_1, const geometry_objects::Point &point_2,
                                     const geometry_objects::Point &point_3) : p_1(point_1), p_2(point_2),
                                                                               p_3(point_3) {
}

bool geometry_objects::Triangle::isDegenerate() const {
    return (p_1 == p_2 || p_1 == p_3 || p_2 == p_3);
}

geometry_objects::Point geometry_objects::Triangle::GetPoint1() const {
    return geometry_objects::Point(p_1);
}

geometry_objects::Point geometry_objects::Triangle::GetPoint2() const {
    return geometry_objects::Point(p_2);
}

geometry_objects::Point geometry_objects::Triangle::GetPoint3() const {
    return geometry_objects::Point(p_3);
}

geometry_objects::Plane::Plane(const geometry_objects::Triangle &tr) {
    norm_vector = geometry_objects::Vector3D(tr.GetPoint1(), tr.GetPoint2()) %
                  geometry_objects::Vector3D(tr.GetPoint1(), tr.GetPoint3());
    plane_point = tr.GetPoint1();
}

geometry_objects::Vector3D geometry_objects::Plane::GetNormVector() const {
    return geometry_objects::Vector3D(norm_vector);
}

geometry_objects::Point geometry_objects::Plane::GetPlanePoint() const {
    return geometry_objects::Point{plane_point};
}

bool geometry_objects::ComparePlanes(const geometry_objects::Plane & pl1, const geometry_objects::Plane & pl2) {
    Vector3D nv1{pl1.GetNormVector()}, nv2{pl2.GetNormVector()};
    if(nv1 == nv2 || nv1 == -1 * nv2)   return true;
    return false;
}

bool geometry_objects::CheckParallelism(const Plane &pl1, const Plane &pl2) {
    Vector3D nv1{pl1.GetNormVector()}, nv2{pl2.GetNormVector()}, vp1{pl1.GetPlanePoint()}, vp2{pl2.GetPlanePoint()};

    if((vp2 * nv2 - e) <= vp1 * nv1 <= (vp2 * nv2 + e)) return false;
    return true;
}
