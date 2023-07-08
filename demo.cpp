#include <SFML/Graphics.hpp>
#include <linalg.hpp>
#include <Vector4.hpp>
#include <iostream>

using namespace std;

#define SCREEN_W 640
#define SCREEN_H 480

/* ------------------------------------------------ */

//class Cam{
//public:
//    Cam();
//    ~Cam();
//    Vec *pos;
//    Mat *rot;
//    void set_pos(Vec *pos);
//};

/* ------------------------------------------------ */

//class Triangle{
//public:
//    Triangle(const Vec &v0, const Vec &v1, const Vec &v2){
//        for(int i=0; i<3; i++){
//            vertex[i] = new Vec(v0.d);
//            vertex[i] = new Vec(v0.d);
//        }
//    }
//    ~Triangle(){
//
//    }
//    int d;
//    Vec v0, v1, v2;
//};

/* ------------------------------------------------ */

int main()
{
    sf::RenderWindow window(sf::VideoMode(SCREEN_W, SCREEN_H), "Hyperverse");

    Vec v(3, 1.0, 2.0, 3.0);
    Mat m(3, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0);
    m.print();
    v.print();
    v.matmul(&m);
    v.print();

    Vector4 v4;
    cout << v4.x << " " << v4.y << " " << v4.z << " " << v4.w << endl;
 
    // create an array of 3 vertices that define a triangle primitive
    sf::VertexArray triangle(sf::Triangles, 3);

    // define the position of the triangle's points
    triangle[0].position = sf::Vector2f(10.f, 10.f);
    triangle[1].position = sf::Vector2f(100.f, 10.f);
    triangle[2].position = sf::Vector2f(100.f, 100.f);

    // define the color of the triangle's points
    triangle[0].color = sf::Color::Red;
    triangle[1].color = sf::Color::Blue;
    triangle[2].color = sf::Color::Green;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(triangle);
        window.display();
    }

    return 0;
}