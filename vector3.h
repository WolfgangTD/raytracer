#ifndef VECTOR3_H
#define VECTOR3_H

#include <cmath>

class Vector3 {
    public:
        float x, y, z;

    Vector3() : x(0.0f), y(0.0f), z(0.0f) {}
    Vector3(float x, float y, float z) : x(x), y(y), z(z) {}

    //vector addition
    Vector3 operator+(const Vector3& yipee) const {
        return Vector3(x + yipee.x, y + yipee.y, z + yipee.z);
    }

    //vector subtraction
    Vector3 operator-(const Vector3& yipee) const {
        return Vector3(x - yipee.x, y - yipee.y, z - yipee.z);
    }

    //dot product
    float dot(const Vector3& yipee) const {
        return x * yipee.x + y * yipee.y + z * yipee.z;
    }

    //cross product
    Vector3 cross(const Vector3& yipee) const {
        return Vector3(
            y * yipee.z - z * yipee.y,
            z * yipee.x - x * yipee.z,
            x * yipee.y - y * yipee.x
        );
    }

    //scalar
    Vector3 operator*(float scalar) const {
        return Vector3(x * scalar, y * scalar, z * scalar);
    }

    //normalization
    Vector3 normalize() const {
        float Magnitude = sqrt(x * x + y * y + z * z);
        return Vector3(x / Magnitude, y / Magnitude, z / Magnitude);
    }
};
#endif