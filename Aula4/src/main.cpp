#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(300, 300), "SFML works fine!");
    sf::CircleShape shape(300.f);
    shape.setFillColor(sf::Color::Blue);
    shape.setRadius(400);

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