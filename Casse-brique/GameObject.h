#pragma once

class gameObject
{
public:
	float x;
	float y;
	float newX;
	float newY;
	float width;
	float height;
	const char* type;
	bool exist;
	sf::RectangleShape oRectangle;
	sf::CircleShape oCircle;

	gameObject(float x, float y, float width, float height, const char* type);

	void draw(sf::RenderWindow* oWindow);

	void move(float deltaTime, float xM, float yM);

	bool collision(gameObject* other);

	void windowCollision(sf::RenderWindow* window);

};