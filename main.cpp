#include<iostream>
#include<cmath>
#include<SFML/Graphics.hpp>

void main(int argc, char** argv[]) {

	//Initializations
	bool gameStart = false;
	bool aiming = false;
	bool release = false;
	float xx, yy, tempx, tempy;

	//Drawings
	sf::RectangleShape line(sf::Vector2f(2.6f, 300.0f));
	line.setOrigin(1.3, 0);
	line.setPosition(100, 200);
	line.setFillColor(sf::Color::White);

	sf::CircleShape tri(12, 3);
	tri.setOrigin(12, 12*0.98803);
	tri.setPosition(100, 200);
	tri.setFillColor(sf::Color::White);



	//Window Setup
	sf::RenderWindow win(sf::VideoMode(1000, 720), "Second Try");

	while (win.isOpen()) {
		sf::Event event;
		while (win.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				win.close();
			}
			else if (event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::Space) {
					gameStart = true;
				}
			}
			else if (event.type==sf::Event::MouseButtonPressed and event.type!=sf::Event::MouseButtonReleased) {
				tempx = sf::Mouse::getPosition(win).x;
				tempy = sf::Mouse::getPosition(win).y;
				release = false;
				aiming = true;
			}
			else if (event.type!=sf::Event::MouseButtonPressed and event.type==sf::Event::MouseButtonReleased) {
				aiming = false;
				release = true;
			}
		}//pollevent

		if (sf::Event::MouseMoved and aiming == false and release == false) {
			tri.setPosition(sf::Mouse::getPosition(win).x, sf::Mouse::getPosition(win).y);
		}

		xx = sf::Mouse::getPosition(win).x;
		yy = sf::Mouse::getPosition(win).y;

		if (aiming == true) {
			tri.setPosition(tempx, tempy);
			line.setPosition(tempx, tempy);
			line.setSize(sf::Vector2f(2.6f,(yy-tempy)));
		}
    
    //Action
		if (release == true) {
			tri.move(0, -1);
			line.move(0, -1);
		}
		



		win.clear(sf::Color::Black);
		win.draw(tri);
		win.draw(line);
		win.display();
	}//IsOpen
}
