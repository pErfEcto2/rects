#pragma once

#include <iostream>
#include <cstring>
#include <math.h>


struct vec2 {
    double x, y;
};

struct vec2 min(struct vec2 v1, struct vec2 v2);

class Rectangle {
    private:
        struct vec2 size;
        struct vec2 pos;
    public:
        Rectangle();
        Rectangle(struct vec2 p);
        struct vec2 getSize();
        void setSize(struct vec2 s);
        struct vec2 getPos();
        void setPos(struct vec2 p);
        Rectangle intersect(Rectangle r);
        Rectangle common(Rectangle r);
        ~Rectangle();
};
