#include <SFML/Graphics.hpp>
#include <math.h>
#include "GameObject.h"
#include "main.h"
#include <iostream>
#include <vector>
std::vector<gameObject*> bricks;
sf::Texture losText;
sf::Sprite losSprite;
sf::Texture vicText;
sf::Sprite vicSprite;
sf::Texture gunText;
sf::Sprite gunSprite;

void niveau1()
{
    gameObject* pbrick1 = new gameObject(375, 100, 100, 40);
    gameObject* pbrick2 = new gameObject(475, 100, 100, 40);
    gameObject* pbrick3 = new gameObject(575, 100, 100, 40);
    gameObject* pbrick4 = new gameObject(275, 100, 100, 40);
    gameObject* pbrick5 = new gameObject(175, 100, 100, 40);
    bricks.push_back(pbrick1);
    bricks.push_back(pbrick2);
    bricks.push_back(pbrick3);
    bricks.push_back(pbrick4);
    bricks.push_back(pbrick5);
}

void niveau2()
{
    gameObject* pbrick1 = new gameObject(375, 100, 100, 40);
    gameObject* pbrick2 = new gameObject(475, 100, 100, 40);
    gameObject* pbrick3 = new gameObject(575, 100, 100, 40);
    gameObject* pbrick4 = new gameObject(275, 100, 100, 40);
    gameObject* pbrick5 = new gameObject(175, 100, 100, 40);
    gameObject* pbrick6 = new gameObject(375, 140, 100, 40);
    gameObject* pbrick7 = new gameObject(475, 140, 100, 40);
    gameObject* pbrick8 = new gameObject(575, 140, 100, 40);
    gameObject* pbrick9 = new gameObject(275, 140, 100, 40);
    gameObject* pbrick10 = new gameObject(175, 140, 100, 40);
    bricks.push_back(pbrick1);
    bricks.push_back(pbrick2);
    bricks.push_back(pbrick3);
    bricks.push_back(pbrick4);
    bricks.push_back(pbrick5);
    bricks.push_back(pbrick6);
    bricks.push_back(pbrick7);
    bricks.push_back(pbrick8);
    bricks.push_back(pbrick9);
    bricks.push_back(pbrick10);

}

void niveau3()
{
    gameObject* pbrick1 = new gameObject(300, 100, 100, 40);
    gameObject* pbrick2 = new gameObject(400, 100, 100, 40);
    gameObject* pbrick3 = new gameObject(350, 220, 100, 40);    
    gameObject* pbrick4 = new gameObject(500, 100, 100, 40);
    gameObject* pbrick5 = new gameObject(200, 100, 100, 40);
    gameObject* pbrick6 = new gameObject(450, 140, 100, 40);
    gameObject* pbrick7 = new gameObject(350, 140, 100, 40);
    gameObject* pbrick8 = new gameObject(250, 140, 100, 40);
    gameObject* pbrick9 = new gameObject(250, 60, 100, 40);
    gameObject* pbrick10 = new gameObject(450, 60, 100, 40);
    gameObject* pbrick11 = new gameObject(300, 180, 100, 40);
    gameObject* pbrick12 = new gameObject(400, 180, 100, 40);
    bricks.push_back(pbrick1);
    bricks.push_back(pbrick2);
    bricks.push_back(pbrick3);
    bricks.push_back(pbrick4);
    bricks.push_back(pbrick5);
    bricks.push_back(pbrick6);
    bricks.push_back(pbrick7);
    bricks.push_back(pbrick8);
    bricks.push_back(pbrick9);
    bricks.push_back(pbrick10);
    bricks.push_back(pbrick11);
    bricks.push_back(pbrick12);
}

int main(int argc, char** argv)
{
    //Création d'une fenêtre
    sf::RenderWindow oWindow(sf::VideoMode(800, 800), "SFML");
    //Creation de la liste 
    gameObject* pball = new gameObject(400, 750, 10);
    bool movement = 0;
    float xV = 0;
    float yV = 0;
    srand((unsigned int)time(0));
    sf::Clock oClock;
    float deltaTime;
    int niveau = 1;
    bool victory = 0;
    bool lose = 0;
    niveau1();
    if (!losText.loadFromFile("lose.png"))
    {
        std::cout << "loading error";
    }
    losSprite.setTexture(losText);
	losSprite.setPosition(sf::Vector2f(0, 225));
    if (!vicText.loadFromFile("victory.png"))
    {
        std::cout << "loading error";
    }
    vicSprite.setTexture(vicText);
	vicSprite.setPosition(sf::Vector2f(0, 225));
    if (!gunText.loadFromFile("gun.png"))
    {
        std::cout << "loading error";
    }
    gunSprite.setTexture(gunText);
    gunSprite.setOrigin(25, 25);
    gunSprite.setPosition(sf::Vector2f(400, 775));

    //GameLoop
    while (!victory and !lose)
    {
        //EVENT
        sf::Event oEvent;


        //UPDATE
        deltaTime = oClock.restart().asSeconds();
        //DRAW
        oWindow.clear();
        int tabLength = bricks.size();
        for (int i = 0; i < tabLength; i++) {
            bricks[i]->draw(&oWindow);
        }
        oWindow.draw(gunSprite);
        
        
        if (movement == 0) {
            float xM = sf::Mouse::getPosition(oWindow).x;
            float yM = sf::Mouse::getPosition(oWindow).y;
            gunSprite.setRotation(acos((-400 * (xM - 400)) / (sqrtf(-400 * -400) * sqrtf((xM - 400) * (xM - 400) + (yM - 775) * (yM - 775) ) ) ) );
            oWindow.draw(gunSprite);
            if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
                movement = 1;
                xV = (xM - pball->x) / sqrtf((xM - pball->x) * (xM - pball->x) + (yM - pball->y) * (yM - pball->y));
                yV = (yM - pball->y) / sqrtf((xM - pball->x) * (xM - pball->x) + (yM - pball->y) * (yM - pball->y));
                pball->draw(&oWindow);
            }
        }

        if (movement == 1) {
            pball->move(deltaTime, xV, yV);
            pball->draw(&oWindow);
            for (int i = 0; i < tabLength; i++) {
                if (pball->collision(bricks[i]) == 'x') {
                    bricks.erase(bricks.begin() + i);
                    tabLength = bricks.size();
                    xV *= -1;
                }
                else if (pball->collision(bricks[i]) == 'y') {
                    bricks.erase(bricks.begin() + i);
                    tabLength = bricks.size();
                    yV *= -1;
                }
            }
            if (pball->windowCollision(&oWindow) == 'x') {
                xV *= -1;
            }
            else if (pball->windowCollision(&oWindow) == 'y') {
                yV *= -1;
            }
            else if (pball->windowCollision(&oWindow) == 'd') {
                movement = 0;
                pball->newX = pball->x;
                pball->newY = pball->y;
                pball->pShape->setPosition(pball->x, pball->y);
                for (int i = 0; i < tabLength; i++) {
                    bricks[i]->descend();
                }
            }
        }
        oWindow.display();
        if (tabLength == 0) {
            if (niveau == 1) {
                niveau2();
                niveau += 1;
				movement = 0;
				pball->newX = pball->x;
				pball->newY = pball->y;
				pball->pShape->setPosition(pball->x, pball->y);
				oWindow.display();
            }
            else if (niveau == 2) {
                niveau3();
                niveau += 1;
				movement = 0;
				pball->newX = pball->x;
				pball->newY = pball->y;
				pball->pShape->setPosition(pball->x, pball->y);
				oWindow.display();
            }
            else if (niveau == 3) {
                victory = 1;
            }
        }
        for (int i = 0; i < tabLength; i++) {
            if (bricks[i]->windowCollision(&oWindow) == 'd') {
                lose = 1;
            }
        }
    }
    if (lose) {
		oWindow.clear();
        oWindow.draw(losSprite);
    }
    if (victory) {
		oWindow.clear();
        oWindow.draw(vicSprite);
    }
	oWindow.display();

    while (oClock.getElapsedTime().asSeconds() < 3);

    return 0;
}