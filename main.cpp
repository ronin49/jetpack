#include <SFML/Graphics.hpp>
#include <iostream>
int main()
{
    sf::RenderWindow window(sf::VideoMode(600, 400), "SFML works!");
    sf::CircleShape shape(20.f);
    shape.setFillColor(sf::Color(0,0,0));
	window.setFramerateLimit(60);
	sf::Clock clock;
	int speed = 1;
	while (window.isOpen())
    {
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			if(speed>-15) speed--;
		} else {
			if(speed<15) speed++;
		}
		shape.move(0,speed);
		if(shape.getPosition().y+shape.getGlobalBounds().height>
		window.getSize().y) {
			shape.setPosition(shape.getPosition().x,
			window.getSize().y-shape.getGlobalBounds().height);
			speed = 0;
		}
		if(shape.getPosition().y < 0) {
			shape.setPosition(shape.getPosition().x,0);
			speed = 0;
		}
		
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);
        window.draw(shape);
        window.display();
    }

    return 0;
}