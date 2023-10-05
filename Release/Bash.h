#ifndef Bash
#define Bash
#include <SFML/Graphics.hpp>
#include <algorithm>
#include <iostream>

class Zm {
private:
	sf::RectangleShape* zm;
	sf::RectangleShape ed;
	 
	float* x;
	float* y;
	float x1, y1;
	int napr;
public:
	Zm() {
		srand(time(0));
		zm = new sf::RectangleShape[1];
		zm[0].setSize(sf::Vector2f(20.0f,20.0f));
		zm[0].setFillColor(sf::Color::Red);

		x = new float[1];
		x[0] = 340.0f;
		y = new float[1];
		y[0] = 240.f;
		zm[0].setPosition(sf::Vector2f(x[0],y[0]));

		ed.setSize(sf::Vector2f(20.0f, 20.0f));
		x1= rand() % 8 * 100;
		y1 = rand() % 6 * 100;
		pereschet(x[0], y[0]);
		ed.setPosition(sf::Vector2f(x1, y1));
		
		ed.setFillColor(sf::Color::Blue);
	}
	~Zm() {
		delete[] x;
		delete[] y;
		delete[] zm;
	}
	void pereschet(const int& x, const int& y) {
		if (x1 == x || y1 == y) {
			x1 = rand() % 8 * 100;
			y1 = rand() % 6 * 100;;
			pereschet(x, y);
		}
	}
	sf::RectangleShape& vozvrat() {
		return ed;
	}

	sf::RectangleShape& vozvrat(int ind) {
		return zm[ind];
	}

	void peremshen( sf::Event& ev) {
		if (ev.type == sf::Event::KeyReleased) {
			if (ev.key.scancode == sf::Keyboard::D) {
				napr = 1;
				x[0] += 20.0f;
				if (x1 == x[0] && y1 == y[0]) {
					pereschet(x[0], y[0]);
				}
				zm[0].setPosition(sf::Vector2f(x[0], y[0]));
				ed.setPosition(sf::Vector2f(x1, y1));
			}else if (ev.key.scancode == sf::Keyboard::W) {
				napr = 2;
				y[0] -= 20.0f;
				if (x1 == x[0] && y1 == y[0]) {
					pereschet(x[0], y[0]);
				}
				zm[0].setPosition(sf::Vector2f(x[0], y[0]));
				ed.setPosition(sf::Vector2f(x1, y1));
			}
			else if (ev.key.scancode == sf::Keyboard::A) {
				napr = 3;
				x[0] -= 20.0f;
				if (x1 == x[0] && y1 == y[0]) {
					pereschet(x[0], y[0]);
				}
				zm[0].setPosition(sf::Vector2f(x[0], y[0]));
				ed.setPosition(sf::Vector2f(x1, y1));
			}
			else if (ev.key.scancode == sf::Keyboard::S) {
				napr = 4;
				y[0] += 20.0f;
				if (x1 == x[0] && y1 == y[0]) {
					pereschet(x[0], y[0]);
				}
				zm[0].setPosition(sf::Vector2f(x[0], y[0]));
				ed.setPosition(sf::Vector2f(x1, y1));
			}

		}
		
	}
	void uprav() {
		if (napr == 1) {
			x[0] += 20.0f;
			if (x[0]>800.0f) {
				x[0] = 0;
			}
			if (x1 == x[0] && y1 == y[0]) {
			
				pereschet(x[0], y[0]);
			}
			zm[0].setPosition(sf::Vector2f(x[0], y[0]));
			ed.setPosition(sf::Vector2f(x1, y1));
		}
		else if (napr == 2) {
			y[0] -= 20.0f;
			if (y[0] < 0.f) {
				y[0] = 600.f;
			}
			if (x1 == x[0] && y1 == y[0]) {
			
				pereschet(x[0], y[0]);
			}

			zm[0].setPosition(sf::Vector2f(x[0], y[0]));
			ed.setPosition(sf::Vector2f(x1, y1));
		}
		else if (napr == 3) {
		
			x[0] -= 20.0f;
			if (x[0] <0.0f) {
				x[0] = 800.0f;
			}
			if (x1 == x[0] && y1 == y[0]) {
		
				pereschet(x[0], y[0]);
			
			}

			zm[0].setPosition(sf::Vector2f(x[0], y[0]));
			ed.setPosition(sf::Vector2f(x1, y1));
		}
		else if(napr==4) {
			y[0] += 20.0f;
			if (y[0] > 600.f) {
				y[0] = 0.f;
			}
			if (x1 == x[0] && y1 == y[0]) {
			
				pereschet(x[0], y[0]);
			}

			zm[0].setPosition(sf::Vector2f(x[0], y[0]));
			ed.setPosition(sf::Vector2f(x1, y1));
		}
	}

};


#endif // !Bash
