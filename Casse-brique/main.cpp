#include <SFML/Graphics.hpp>
#include "GameObject.h"

int main(int argc, char** argv)
{
    
    //Création d'une fenêtre
    sf::RenderWindow oWindow(sf::VideoMode(800, 800), "SFML");

    gameObject brick(400, 100, 50, 10, "rectangle");

    gameObject ball(400, 750, 10, 10, "cercle");

	bool movement = 0;

    int xM = 0;
    int yM = 0;
    
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
		deltaTime = oClock.restart().asSeconds();
        //DRAW
        oWindow.clear();

        brick.draw(&oWindow);
        ball.draw(&oWindow);

        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) and movement == 0){
            movement = 1;
            xM = sf::Mouse::getPosition(oWindow).x;
            yM = sf::Mouse::getPosition(oWindow).y;
        }
        
        if (movement == 1){
			ball.move(deltaTime, xM, yM);
        }
        oWindow.display();

        
    }

    return 0;
}