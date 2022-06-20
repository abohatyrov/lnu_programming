#pragma once
#include <cmath>
using namespace std;

template <typename T>
class Vector3
{
    T x;
    T y;
    T z;
public:
    Vector3()
    {
        x = 0;
        y = 0;
        z = 0;
    }

    Vector3(T _x, T _y, T _z)
    {
        x = _x;
        y = _y;
        z = _z;
    }

    Vector3(Vector3<T>& v)
    {
        y = v.y;
        z = v.z;
        x = v.x;
    }

    T length()
    {
        return sqrt(x*x + y*y + z*z);
    }

    Vector3<T> operator+(Vector3<T> v)
    {
        Vector3 temp = *this;

        temp.x += v.x;
        temp.y += v.y;
        temp.z += v.z;

        return temp;
    }

    Vector3<T> operator-(Vector3<T> v)
    {
        Vector3<T> temp = *this;

        temp.x -= v.x;
        temp.y -= v.y;
        temp.z -= v.z;

        return temp;
    }

    Vector3<T> operator*(T scalar)
    {
        Vector3<T> temp = *this;

        temp.x *= scalar;
        temp.y *= scalar;
        temp.z *= scalar;

        return temp;
    }

    T operator*(Vector3<T> v)
    {
        return x * v.x + y * v.y + z * v.z;
    }

    friend istream& operator>>(istream& is, Vector3<T>& v)
    {
        is >> v.x;
        is >> v.y;
        is >> v.z;

        return is;
    }

    friend ostream& operator<<(ostream& os, Vector3<T>& v)
    {
        // os << "Vector3: ";
        os << "(" << v.x;
        os << ", " << v.y;
        os << ", " << v.z << ")";

        return os;
    }
};

template <typename T>
class NormalizedVector : public Vector3<T>
{
    T x;
    T y;
    T z;
public:
    NormalizedVector()
    {
        x = 0;
        y = 0;
        z = 0;
    }

    NormalizedVector(T _x, T _y, T _z)
    {
        T l = sqrt(_x*_x + _y*_y + _z*_z);
        x = _x / l;
        y = _y / l;
        z = _z / l;
    }

    NormalizedVector(NormalizedVector& nv)
    {
        x = nv.x;
        y = nv.y;
        z = nv.z;
    }

    NormalizedVector(Vector3<T>& v)
    {
        x = v.x / v.length();
        y = v.y / v.length();
        z = v.z / v.length();
    }

    friend ostream& operator<<(ostream& os, Vector3<T>& v)
    {
        os << "(" << v.x;
        os << ", " << v.y;
        os << ", " << v.z << ")";

        return os;
    }
};

