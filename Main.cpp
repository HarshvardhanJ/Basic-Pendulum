#include "Pendulum.cpp"


int main() 
{

	sf::RenderWindow window(sf::VideoMode(1600, 1000), "Pendulum");
	window.setFramerateLimit(60);

	Pendulum pendulum(800, 500, 125);

	while (window.isOpen()) 
	{

		sf::Event event;
		while (window.pollEvent(event)) {

			if (event.type == sf::Event::Closed) window.close();

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::X)) window.close();
		}

		window.clear();
		pendulum.physics(1, 45, 0.075);  // Configure Pendulum here (float Amplitude, float angle, float deltaTime(smaller value for slow pendulum and vice-versa))
		pendulum.render(window);
		window.display();

	}

}