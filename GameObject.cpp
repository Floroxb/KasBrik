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
		oCircle.setRadius(width);
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
	newX += (xM-x)/sqrtf((xM - x) * (xM - x) + (yM - y) * (yM - y)) * deltaTime * 100;
	newY += (yM-y)/ sqrtf((xM - x) * (xM - x) + (yM - y) * (yM - y)) * deltaTime * 100;
	if (type == "rectangle") {
		oRectangle.setPosition(newX, newY);
	}

	else if (type == "cercle") {
		oCircle.setPosition(newX, newY);
	}
}
