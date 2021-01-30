#ifndef TRIANGLES_GEOMETRY_OBJECTS_H
#define TRIANGLES_GEOMETRY_OBJECTS_H


namespace geometry_objects {

    struct Point{
        Point(float x,float y,float z);
        Point() = delete;
        ~Point() = default;

        Point(const Point& p) = default;
        Point& operator=(const Point& p) = default;

        float getX() const;
        float getY() const;
        float getZ() const;

        bool operator==(const Point& other) const;

        void setX(float new_x);
        void setY(float new_y);
        void setZ(float new_z);

    private:
        float _x,_y,_z;
    };

    class triangle{
        Point p_1, p_2, p_3;
    public:
        triangle() = delete;
        triangle(const Point& point_1, const Point& point_2, const Point& point_3);
        ~triangle() = default;
        
        bool isDegenerate();
    };

    class Vector3D {
    private:
        float _x, _y, _z;
    public:
        Vector3D() = delete;

        //vector with given axis directions
        Vector3D(float new_x, float new_y, float new_z);

        //vector with the beginning in the point and with the ending in the origin
        Vector3D(const geometry_objects::Point& point);

        //vector with beginning in point_1 and ending in point 2
        Vector3D(const geometry_objects::Point& point_1, const geometry_objects::Point& point_2);

        ~Vector3D() = default;

        float getX() const;

        float getY() const;

        float getZ() const;

        void setX(float x);

        void setY(float y);

        void setZ(float z);

        bool operator==(const Vector3D &other) const;

        bool operator!=(const Vector3D &other) const;

        Vector3D operator+(const Vector3D &other) const;

        Vector3D operator-(const Vector3D &other) const;

        Vector3D operator*(float number) const;

        //scalar product
        float operator*(const Vector3D &other) const;

        float length() const;

        //cross product
        Vector3D operator%(const Vector3D &other) const;
    };

    class Line{
        //point on the line
        Point line_point;

        //directing vector of the line
        Vector3D line_vector;
    };

    class Plane{
        //point on the plane
        Point plane_point;

        //normal vector to the plane
        Vector3D norm_vector;
    };


};

geometry_objects::Vector3D operator*(float number, const geometry_objects::Vector3D& v);


#endif //TRIANGLES_GEOMETRY_OBJECTS_H
