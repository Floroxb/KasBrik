#pragma once

class gameObject
{
public:
	int x;
	int y;
	int width;
	int height;
	char* type;
	sf::RectangleShape oRectangle;
	sf::CircleShape oCircle;

	gameObject(int x, int y, int width, int height, char* type);

	void draw();
};