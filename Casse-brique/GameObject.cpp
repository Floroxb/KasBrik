#include <SFML/Graphics.hpp>
#include <math.h>
#include "GameObject.h"

gameObject::gameObject(float x, float y, float width, float height, const char* type)
{
	this->x = x;
	this->y = y;
	this->newX = x;
	this->newY = y;
	this->width = width;
	this->height = height;
	this->type = type;


	if (type == "rectangle") {
		oRectangle.setSize(sf::Vector2f(width, height));
		oRectangle.setPosition(x, y);
	}

	else if (type == "cercle") {
		oCircle.setRadius(width/2);
		oCircle.setPosition(x, y);
	}
}

void gameObject::draw(sf::RenderWindow* oWindow)
{
	if (type == "rectangle") {
		oWindow->draw(oRectangle);
	}

	else if (type == "cercle") {
		oWindow->draw(oCircle);
	}
}

void gameObject::move(float deltaTime, float xM, float yM)
{
	newX += xM * deltaTime * 500;
	newY += yM * deltaTime * 500;
	if (type == "rectangle") {
		oRectangle.setPosition(newX, newY);
	}

	else if (type == "cercle") {
		oCircle.setPosition(newX, newY);					
	}
}

bool isInside(float x, float min, float max)
{
	return x >= min and x <= max;
}

bool isOutside(float x, float min, float max)
{
	return !isInside(x, min, max);
}

char gameObject::collision(gameObject* other)
{
	bool colUp = isInside(newX + width / 2, other->newX, other->newX + other->width) and isInside(newY, other->newY, other->newY + other->height);
	bool colDown = isInside(newX + width / 2, other->newX, other->newX + other->width) and isInside(newY + height, other->newY, other->newY + other->height);
	bool colLeft = isInside(newY + height / 2, other->newY, other->newY + other->height) and isInside(newX, other->newX, other->newX + other->width);
	bool colRight = isInside(newY + height / 2, other->newY, other->newY + other->height) and isInside(newX + width, other->newX, other->newX + other->width);
	if (colUp or colDown){
		return 'y';
	}
	else if (colLeft or colRight){
		return 'x';
	}
}

char gameObject::windowCollision(sf::RenderWindow* window)
{
	bool colUp = isInside(newX + width / 2, 0, 800) and newY <= 0;
	bool colLeft = isInside(newY + height / 2, 0, 800) and isOutside(newX, 0, 800);
	bool colRight = isInside(newY + height / 2, 0, 800) and isOutside(newX + width, 0, 800);
	if (colUp){
		return 'y';
	}
	else if (colLeft or colRight) {
		return 'x';
	} 
}
