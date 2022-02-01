//
// Created by Maxwell on 2022/1/31.
//

#ifndef TEST_GEOMETRY_H
#define TEST_GEOMETRY_H

#include <cmath>

template<typename T>
class Vec2
{
public:
    Vec2() : x(0), y(0) {}
    Vec2(T xx) : x(xx), y(xx) {}
    Vec2(T xx, T yy) : x(xx), y(yy) {}
    Vec2 operator + (const Vec2& v) const
    {
        return Vec2(x + v.x, y + v.y);
    }
    Vec2 operator / (const T& r) const
    {
        return Vec2(x / r, y / r);
    }
    Vec2 operator * (const T& r) const
    {
        return Vec2(x * r, y * r);
    }
    Vec2& operator /= (const T& r)
    {
        x /= r, y /= r; return *this;
    }
    Vec2& operator *= (const T& r)
    {
        x *= r, y *= r; return *this;
    }

    const T& operator [] (uint8_t i) const { return (&x)[i]; }
    T& operator [] (uint8_t i) { return (&x)[i]; }

    friend std::ostream& operator << (std::ostream& s, const Vec2<T>& v)
    {
        return s << '[' << v.x << ' ' << v.y << ']';
    }
    friend Vec2 operator * (const T& r, const Vec2<T>& v)
    {
        return Vec2(v.x * r, v.y * r);
    }
    T x, y;


};

typedef Vec2<float> Vec2f;
typedef Vec2<int> Vec2i;

template <class t> struct Vec3 {
    union {
        struct {t x, y, z;};
        struct { t ivert, iuv, inorm; };
        t raw[3];
    };
    Vec3() : x(0), y(0), z(0) {}
    Vec3(t _x, t _y, t _z) : x(_x),y(_y),z(_z) {}
    inline Vec3<t> operator ^(const Vec3<t> &v) const { return Vec3<t>(y*v.z-z*v.y, z*v.x-x*v.z, x*v.y-y*v.x); }
    inline Vec3<t> operator +(const Vec3<t> &v) const { return Vec3<t>(x+v.x, y+v.y, z+v.z); }
    inline Vec3<t> operator -(const Vec3<t> &v) const { return Vec3<t>(x-v.x, y-v.y, z-v.z); }
    inline Vec3<t> operator *(float f)          const { return Vec3<t>(x*f, y*f, z*f); }
    inline t       operator *(const Vec3<t> &v) const { return x*v.x + y*v.y + z*v.z; }
    inline t       operator [](int i)          const { return Vec3<t>(x , y, z)[i]; }
    float norm () const { return std::sqrt(x*x+y*y+z*z); }
    Vec3<t> & normalize(t l=1) { *this = (*this)*(l/norm()); return *this; }
    template <class > friend std::ostream& operator<<(std::ostream& s, Vec3<t>& v);
    template <class > friend Vec3<t> cross(Vec3<t> v1, Vec3<t> v2);
};

typedef Vec3<float> Vec3f;
typedef Vec3<int>   Vec3i;

#endif //TEST_GEOMETRY_H
