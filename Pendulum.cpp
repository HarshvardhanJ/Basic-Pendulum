#include <SFML/Graphics.hpp>
#include <iostream>

const float PI = 3.14159265359f;
const float g = 9.8;

class Pendulum 
{
	sf::Vector2f pos;
	float length;
	sf::CircleShape Bob;
	sf::VertexArray wire;
	float currentTime;
	float angle;
	float angular_velocity;
	bool released;

	
	float get_wire_pos_x() {

		return wire[1].position.x;

	}

	float get_wire_pos_y() {

		return wire[1].position.y;

	}


public:
	Pendulum(float xpos, float ypos, const float length)
	{
		pos.x = xpos;
		pos.y = ypos;
		this->length = length;

		create_line();

		Bob.setFillColor(sf::Color::Red);
		Bob.setOutlineColor(sf::Color::White);
		Bob.setRadius(25);
		Bob.setOrigin(0, 0);
		Bob.setPosition(get_wire_pos_x() - 25 , get_wire_pos_y() );
		angle = 0.0f;
		angular_velocity = 0.0f;
		currentTime = 0;
	
	}

	void create_line() {

		wire = sf::VertexArray(sf::LineStrip, 2);
		wire[0].position = pos;
		wire[1].position = sf::Vector2f(pos.x, pos.y + length);

	}

	// x = Asin(w*t)
	// T = 2π√(l/g)
	void physics(float amplitude, float angle, float deltaTime)
	{
		angle *= PI / 180;
		float Timeperiod = (2 * PI) * sqrt(length / g);
		float angularFreq = (2 * PI) / Timeperiod;
		float currentAngle = amplitude * sin(angularFreq * currentTime);
		float angularVelocity = angularFreq * amplitude * cos(angularFreq * currentTime);
		float x = length * sin(currentAngle);
		float y = length * cos(currentAngle);
		Bob.setPosition(x + pos.x, y + pos.y);
		Bob.setRotation(currentAngle);
		wire[1].position = sf::Vector2f(x + pos.x + 25 , y + pos.y);
		currentTime += deltaTime;
	}
	

	
	void render(sf::RenderWindow& window)
	{
		window.draw(Bob);
		window.draw(wire);
	}

};