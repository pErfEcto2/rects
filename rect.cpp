#include "rect.h"


bool operator<=(struct vec2 v1, struct vec2 v2) {
    return v1.x <= v2.x && v1.y <= v2.y;
}

bool operator>=(struct vec2 v1, struct vec2 v2) {
    return v1.x >= v2.x && v1.y >= v2.y;
}

bool operator<(struct vec2 v1, struct vec2 v2) {
    return v1.x < v2.x && v1.y < v2.y;
}

bool operator>(struct vec2 v1, struct vec2 v2) {
    return v1.x > v2.x && v1.y > v2.y;
}

bool operator==(struct vec2 v1, struct vec2 v2) {
    return v1.x == v2.x && v1.y == v2.y;
}

struct vec2 operator+(struct vec2 v1, struct vec2 v2) {
    return {v1.x + v2.x, v1.y + v2.y};
}


struct vec2 min(struct vec2 v1, struct vec2 v2) {
    return {std::min(v1.x, v2.x), std::min(v1.y, v2.y)};
}

Rectangle::Rectangle() {
    size = {10, 10};
    pos = {0, 0};
}

Rectangle::Rectangle(struct vec2 p) {
    size = {10, 10};
    pos = p;
}

struct vec2 Rectangle::getSize() {
    return size;
};

void Rectangle::setSize(struct vec2 s) {
    size = s;
};

struct vec2 Rectangle::getPos() {
    return pos;
};

void Rectangle::setPos(struct vec2 p) {
    pos = p;
};

Rectangle Rectangle::common(Rectangle r) {
    struct vec2 otherPos = r.getPos();
    struct vec2 otherSize = r.getSize();

    Rectangle resRect({std::min(otherPos.x, pos.x),
                       std::min(otherPos.y, pos.y)});

    resRect.setSize({std::max(otherSize.x + otherPos.x, size.x + pos.x) - size.x,
                     std::max(otherSize.y + otherPos.y, size.y + pos.y) - size.y});
    
    return resRect;
};

Rectangle Rectangle::intersect(Rectangle r) {
    struct vec2 otherPos = r.getPos();
    struct vec2 otherSize = r.getSize();

    struct vec2 p = {std::max(pos.x, otherPos.x),
                     std::max(pos.y, otherPos.y)};

    struct vec2 s = {std::min(pos.x + size.x, otherPos.x + otherSize.x) - p.x,
                     std::min(pos.y + size.y, otherPos.y + otherSize.y) - p.y};
    
    if (p > min(pos + size, otherPos + otherSize))
        s = {-1, -1};
    
    Rectangle resRect(p);
    resRect.setSize(s);

    return resRect;
};

Rectangle::~Rectangle() {};
