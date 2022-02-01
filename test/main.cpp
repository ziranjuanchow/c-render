#include <vector>
#include <iostream>
#include "geometry.h"

float edgeFunction(const Vec2f &a, const Vec2f &b, const Vec2f &c)
{
    return (c.x - a.x) * (b.y - a.y) - (c.y - a.y) * (b.x - a.x);
}


int main() {

    Vec2f v0 = {0,0};
    Vec2f v1 = {0,1};
    Vec2f v2 = {1,0};
    Vec2f p = {0.3,0.4};

    float area = edgeFunction(v0, v1, v2); // area of the triangle multiplied by 2
    float w0 = edgeFunction(v1, v2, p); // signed area of the triangle v1v2p multiplied by 2
    float w1 = edgeFunction(v2, v0, p); // signed area of the triangle v2v0p multiplied by 2
    float w2 = edgeFunction(v0, v1, p); // signed area of the triangle v0v1p multiplied by 2

// if point p is inside triangles defined by vertices v0, v1, v2
    if (w0 >= 0 && w1 >= 0 && w2 >= 0) {
        // barycentric coordinates are the areas of the sub-triangles divided by the area of the main triangle
        w0 /= area;
        w1 /= area;
        w2 /= area;
    }
    std::cout<<area<<"\n"<<std::endl;
    std::cout<<w0<<"\n"<<w1<<"\n"<<w2<<std::endl;
    return 0;
}