#include "geometry_objects.h"
#include <iostream>
#include <cmath>

geometry_objects::Point::Point(float x, float y, float z): _x(x), _y(y), _z(z) {
}

float geometry_objects::Point::get_x() const {
    return _x;
}

float geometry_objects::Point::get_y() const {
    return _y;
}

float geometry_objects::Point::get_z() const {
    return _z;
}

bool geometry_objects::Point::operator==(const geometry_objects::Point &other) const {
    return (_x == other._x && _y == other._y && _z == other._z);
}

void geometry_objects::Point::set_x(float new_x) {
    _x = new_x;
}

void geometry_objects::Point::set_y(float new_y) {
    _y = new_y;
}

void geometry_objects::Point::set_z(float new_z) {
    _z = new_z;
}

geometry_objects::Vector3D::Vector3D(float new_x, float new_y, float new_z): _x(new_x), _y(new_y), _z(new_z) {
}

geometry_objects::Vector3D::Vector3D(const geometry_objects::Point &point): _x(point.get_x()), _y(point.get_y()), _z(point.get_z()) {
}

geometry_objects::Vector3D::Vector3D(const geometry_objects::Point &point_1, const geometry_objects::Point &point_2):
_x(point_1.get_x() - point_2.get_x()), _y(point_1.get_y() - point_2.get_y()), _z(point_1.get_z() - point_2.get_z()) {}

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
    return (_x == other._x && _y == other._y && _z == other._z);
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
    return geometry_objects::Vector3D(_y * other._z - other._y * _z, other._x * _z - _x * other._z, _x * other._y - other._x * _y);
}


