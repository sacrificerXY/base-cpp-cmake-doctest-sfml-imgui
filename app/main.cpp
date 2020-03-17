#include <iostream>
#include <_sample/_sample.h>
#include <SFML/Graphics.hpp>

int main()
{
    foo f(50);
    f.add(50);

    sf::RenderWindow window(sf::VideoMode(f.bar * 2, f.bar * 2), "SFML works!");
    sf::CircleShape shape(f.bar);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}
