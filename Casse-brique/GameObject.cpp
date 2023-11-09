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
	this->exist = 1;

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
	newX += (xM-x)/sqrtf((xM - x) * (xM - x) + (yM - y) * (yM - y)) * deltaTime * 500;
	newY += (yM-y)/ sqrtf((xM - x) * (xM - x) + (yM - y) * (yM - y)) * deltaTime * 500;
	if (type == "rectangle") {
		oRectangle.setPosition(newX, newY);
	}

	else if (type == "cercle") {
		oCircle.setPosition(newX, newY);					
	}
}

bool isInside(int x, int min, int max)
{
	return x >= min and x <= max;
}

bool gameObject::collision(gameObject* other)
{
	return (isInside(newX + width / 2, other->newX, other->newX + other->width) and isInside(newY, other->newY, other->newY + other->height)) or (isInside(newX + width / 2, other->newX, other->newX + other->width) and isInside(newY + height, other->newY, other->newY + other->height)) or (isInside(newY + height / 2, other->newY, other->newY + other->height) and isInside(newX, other->newX, other->newX + other->width)) or (isInside(newY + height / 2, other->newY, other->newY + other->height) and isInside(newX + width, other->newX, other->newX + other->width));
}