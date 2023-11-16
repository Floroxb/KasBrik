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
	sf::Shape* pShape;


	gameObject(float x, float y, float width, float height);

	gameObject(float x, float y, float width);

	void draw(sf::RenderWindow* oWindow);

	void move(float deltaTime, float xM, float yM);

	char collision(gameObject* other);

	char windowCollision(sf::RenderWindow* window);

	void descend();
};