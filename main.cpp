#include "rect.h"


int main(int argc, char** argv) {
    /*
    я использую систему координат с началом в левом верхнем углу экрана, с осью ОХ, направленной вправо, и осью ОУ, направленной вниз
    прямоугольники хранятся как координаты верхней левой точки прямоугольника + его размеры
    */

    Rectangle r1({0, 0});
    Rectangle r2({0, 1});

    r1.setSize({1, 1});
    r2.setSize({1, 1});

    // Rectangle res = r1.common(r2);

    // наименьший общий прямоугольник, который содержит оба исходных
    // std::cout << res.getPos().x << " " << res.getPos().y << std::endl;
    // std::cout << res.getSize().x << " " << res.getSize().y << std::endl;


    Rectangle res = r1.intersect(r2);

    std::cout << res.getPos().x << " " << res.getPos().y << std::endl;
    std::cout << res.getSize().x << " " << res.getSize().y << std::endl;

    return 0;
}
