#include <SFML/Graphics.hpp>
#include <linalg.hpp>

class Cam{
public:
    Cam();
    ~Cam();
    Vec *pos;
    Mat *rot;
    void set_pos(Vec *pos);
};

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "xD SFML works!");

    Vec v(3, 1.0, 2.0, 3.0);
    Mat m(3, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0);
    m.print();
    v.print();
    v.matmul(&m);
    v.print();

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