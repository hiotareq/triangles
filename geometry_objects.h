#ifndef TRIANGLES_GEOMETRY_OBJECTS_H
#define TRIANGLES_GEOMETRY_OBJECTS_H


namespace geometry_objects {

    struct Point {
        Point(float x, float y, float z);

        Point();

        ~Point() = default;

        Point(const Point &p) = default;

        Point &operator=(const Point &p) = default;

        float getX() const;

        float getY() const;

        float getZ() const;

        bool operator==(const Point &other) const;

        void setX(float new_x);

        void setY(float new_y);

        void setZ(float new_z);

    private:
        float _x, _y, _z;
    };

    class Vector3D {
    private:
        float _x, _y, _z;
    public:
        Vector3D();

        //vector with given axis directions
        Vector3D(float , float , float );

        //vector with the beginning in the point and with the ending in the origin
        Vector3D(const geometry_objects::Point &);

        Vector3D(const Vector3D &) = default;

        //vector with beginning in point_1 and ending in point 2
        Vector3D(const geometry_objects::Point &, const geometry_objects::Point &);

        ~Vector3D() = default;

        float getX() const;

        float getY() const;

        float getZ() const;

        void setX(float);

        void setY(float);

        void setZ(float);

        bool operator==(const Vector3D &) const;

        bool operator!=(const Vector3D &) const;

        Vector3D operator+(const Vector3D &) const;

        Vector3D operator-(const Vector3D &) const;

        Vector3D operator*(float) const;

        Vector3D &operator=(const Vector3D &) = default;

        //scalar product
        float operator*(const Vector3D &) const;

        float length() const;

        //cross product
        Vector3D operator%(const Vector3D &) const;
    };

    class Triangle {
        Point p_1, p_2, p_3;
    public:
        Triangle() = delete;

        Triangle(const Point &, const Point &, const Point &);

        ~Triangle() = default;

        bool isDegenerate() const;

        Point GetPoint1() const;

        Point GetPoint2() const;

        Point GetPoint3() const;
    };

    class Line {
        //point on the line
        Point line_point;

        //directing vector of the line
        Vector3D line_vector;
    public:
    };

    class Plane {
        //point on the plane
        Point plane_point;

        //normal vector to the plane
        Vector3D norm_vector;
    public:
        Plane(const geometry_objects::Triangle &);

        Vector3D GetNormVector() const;

        Point GetPlanePoint() const;
    };

    //searching for coincidence, true if planes are coincident
    bool ComparePlanes(const Plane &, const Plane &);

    //checking planes for parallelism
    bool CheckParallelism(const Plane&, const Plane&);

};

geometry_objects::Vector3D operator*(float number, const geometry_objects::Vector3D &);

#endif //TRIANGLES_GEOMETRY_OBJECTS_H

