#include <SFML/Graphics.hpp>
#include "GameObject.h"

gameObject::gameObject(int x, int y, int width, int height, char* type)
{
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	this->type = type;

	if (type == "rectangle") {
		oRectangle.setSize(sf::Vector2f(width, height));
		oRectangle.setPosition(x, y);
	}

	else if (type == "cercle") {
		oCircle.setRadius(width / 2);
		oCircle.setPosition(x, y);
	}
}

void gameObject::draw()
{
	if (type == "rectangle") {
		oWindow.draw(oRectangle);
	}

	else if (type == "cercle") {
		oWindow.draw(oCircle);
	}
}
