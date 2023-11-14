#include <SFML/Graphics.hpp>
#include <math.h>
#include "GameObject.h"
#include "main.h"

int main(int argc, char** argv)
{
    
    //Création d'une fenêtre
    sf::RenderWindow oWindow(sf::VideoMode(800, 800), "SFML");

    gameObject* pbrick = new gameObject(400, 100, 50, 10, "rectangle");

	gameObject* pball = new gameObject(400, 750, 10, 10, "cercle");

	bool movement = 0;

    float xV = 0;
    float yV = 0;
	srand((unsigned int)time(0));

    
    sf::Clock oClock;
	float deltaTime;
    
    //GameLoop
    while (oWindow.isOpen())
    {
        //EVENT
        sf::Event oEvent;
        while (oWindow.pollEvent(oEvent))
        {
            if (oEvent.type == sf::Event::Closed)
                oWindow.close();
        }

        //UPDATE
		deltaTime = +
            oClock.restart().asSeconds();
        //DRAW
        oWindow.clear();

        if (pbrick != nullptr){
			pbrick->draw(&oWindow);
        }
        pball->draw(&oWindow);

        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) and movement == 0){
            movement = 1;
            float xM = sf::Mouse::getPosition(oWindow).x;
            float yM = sf::Mouse::getPosition(oWindow).y;
            xV = (xM - pball->x) / sqrtf((xM - pball->x) * (xM - pball->x) + (yM - pball->y) * (yM - pball->y));
            yV = (yM - pball->y) / sqrtf((xM - pball->x) * (xM - pball->x) + (yM - pball->y) * (yM - pball->y));
        }
        
        if (movement == 1){
			pball->move(deltaTime, xV, yV);
            if (pbrick != nullptr) {
                if (pball->collision(pbrick) == 'x') {
                    delete pbrick;
                    pbrick = nullptr;
                    float xM = pball->x;
                    float yM = pball->y - 2 * yV;
                    pball->x = pball->newX;
                    pball->y = pball->newY;
					xV = (xM - pball->x) / sqrtf((xM - pball->x) * (xM - pball->x) + (yM - pball->y) * (yM - pball->y));
					yV = (yM - pball->y) / sqrtf((xM - pball->x) * (xM - pball->x) + (yM - pball->y) * (yM - pball->y));
                }
                else if (pball->collision(pbrick) == 'y') {
					delete pbrick;
					pbrick = nullptr;
					float xM = pball->x - 2 * xV;
					float yM = pball->y;
					pball->x = pball->newX;
					pball->y = pball->newY;
					xV = (xM - pball->x) / sqrtf((xM - pball->x) * (xM - pball->x) + (yM - pball->y) * (yM - pball->y));
					yV = (yM - pball->y) / sqrtf((xM - pball->x) * (xM - pball->x) + (yM - pball->y) * (yM - pball->y));
				}
            }
            if (pball->windowCollision(&oWindow) == 'x') {
				float xM = pball->x;
				float yM = pball->y - 2 * yV;
				pball->x = pball->newX;
				pball->y = pball->newY;
				xV = (xM - pball->x) / sqrtf((xM - pball->x) * (xM - pball->x) + (yM - pball->y) * (yM - pball->y));
				yV = (yM - pball->y) / sqrtf((xM - pball->x) * (xM - pball->x) + (yM - pball->y) * (yM - pball->y));
            }
			else if (pball->windowCollision(&oWindow) == 'y') {
				float xM = pball->x - 2 * xV;
				float yM = pball->y;
				pball->x = pball->newX;
				pball->y = pball->newY;
				xV = (xM - pball->x) / sqrtf((xM - pball->x) * (xM - pball->x) + (yM - pball->y) * (yM - pball->y));
				yV = (yM - pball->y) / sqrtf((xM - pball->x) * (xM - pball->x) + (yM - pball->y) * (yM - pball->y));
			}
            
            
        }
        oWindow.display();

        
    }

    return 0;
}