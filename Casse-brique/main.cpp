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

    int xM = 0;
    int yM = 0;
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
            xM = sf::Mouse::getPosition(oWindow).x;
            yM = sf::Mouse::getPosition(oWindow).y;
        }
        
        if (movement == 1){
			pball->move(deltaTime, xM, yM);
            if (pbrick != nullptr) {
                if (pball->collision(pbrick) == 'x') {
                    delete pbrick;
                    pbrick = nullptr;
                    pball->x = pball->newX;
                    pball->y = pball->newY;
                    xM = -xM;
                    yM = -yM;
                }
                else if (pball->collision(pbrick) == 'y') {
					delete pbrick;
					pbrick = nullptr;
					pball->x = pball->newX;
					pball->y = pball->newY;
					xM = -xM;
                    yM = -yM;
				}
            }
            if (pball->windowCollision(&oWindow) == 'x') {
				pball->x = pball->newX;
				pball->y = pball->newY;
				xM = -xM;
                yM = -yM;
            }
			else if (pball->windowCollision(&oWindow) == 'y') {
				pball->x = pball->newX;
				pball->y = pball->newY;
				xM = -xM;
                yM = -yM;
			}
            
        }
        oWindow.display();

        
    }

    return 0;
}