#include <SFML/Graphics.hpp>
#include <math.h>
#include "GameObject.h"
#include "main.h"
#include <list>
std::list<gameObject*> bricks;

void niveau1()
{
    gameObject* pbrick1 = new gameObject(400, 100, 50, 10);
    gameObject* pbrick2 = new gameObject(450, 100, 50, 10);
    gameObject* pbrick3 = new gameObject(500, 100, 50, 10);
    gameObject* pbrick4 = new gameObject(350, 100, 50, 10);
    gameObject* pbrick5 = new gameObject(300, 100, 50, 10);
    bricks.push_back(pbrick1);
    bricks.push_back(pbrick2);
    bricks.push_back(pbrick3);
    bricks.push_back(pbrick4);
    bricks.push_back(pbrick5);
}

int main(int argc, char** argv)
{
    //Création d'une fenêtre
    sf::RenderWindow oWindow(sf::VideoMode(800, 800), "SFML");
    //Creation de la liste 
    gameObject* pball = new gameObject(400, 790, 10);
	bool movement = 0;
    float xV = 0;
    float yV = 0;
	srand((unsigned int)time(0));
    sf::Clock oClock;
	float deltaTime;
    niveau1();


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
        for (const auto& elem : bricks) {
            elem->draw(&oWindow);
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
			for (const auto& elem : bricks) {
                if (pball->collision(elem) == 'x') {
                    bricks.remove(elem);
					delete elem;
					xV *= -1;
                }
                else if (pball->collision(elem) == 'y') {
					bricks.remove(elem);
					delete elem;
					yV *= -1;
				}
            }
            if (pball->windowCollision(&oWindow) == 'x') {
				xV *= -1;
            }
			else if (pball->windowCollision(&oWindow) == 'y') {
                yV *= -1;
			}
           else if (pball->windowCollision(&oWindow) == 'd'){
                movement = 0;
                pball->newX = pball->x;
                pball->newY = pball->y;
				pball->pShape->setPosition(pball->x, pball->y);
           }
        }
        oWindow.display();
    }
    return 0;
}