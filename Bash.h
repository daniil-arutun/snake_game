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
	int kol;
	bool up, down, right, left;
	bool error;
public:
	Zm() {
		srand(time(0));
		zm = new sf::RectangleShape[1];
		kol = 1;
		zm[0].setSize(sf::Vector2f(20.0f,20.0f));
		zm[0].setFillColor(sf::Color::Red);
		napr = 1;
		left = false;
		up = true;
		down = true;
		right = true;
		error = false;
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
		if (ev.type == sf::Event::KeyPressed) {
			if (ev.key.scancode == sf::Keyboard::D || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
				if (right) {
					up = true;
					down = true;
					left = false;


					napr = 1;

					if (kol >= 2) {
						x[kol - 1] = x[0] + 20.f;
						for (int zxc = 0; zxc < kol - 1; zxc++) {
							float tem = x[zxc];
							x[zxc] = x[kol - 1];
							x[kol - 1] = tem;

						}
					}
					else {
						x[0] += 20;
					}


					if (kol >= 2) {
						y[kol - 1] = y[0];
						for (int zxc = 0; zxc < kol - 1; zxc++) {
							float tem = y[zxc];
							y[zxc] = y[kol - 1];
							y[kol - 1] = tem;
						}
					}


					if (kol >= 2) {
						if ((x1 == x[0] && y1 == y[0]) || (x1 == x[1] && y1 == y[1])) {
							sozdat(-20.f, 0.f);
							for (int qwe = 0; qwe < kol; qwe++) {
								pereschet(x[qwe], y[qwe]);
							}
						}
					}
						else {
							if (x1 == x[0] && y1 == y[0]) {
								sozdat(-20.f, 0.f);
								for (int qwe = 0; qwe < kol; qwe++) {
									pereschet(x[qwe], y[qwe]);
								}
						}		
					}
					for (int cc = 0; cc < kol; cc++) {
						if (x[cc] > 780) {
							x[cc] = 0;
						}
						zm[cc].setPosition(sf::Vector2f(x[cc], y[cc]));
					}
					ed.setPosition(sf::Vector2f(x1, y1));
				}
			}
			else if (ev.key.scancode == sf::Keyboard::W || sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
				if (up) {
					right = true;
					down = false;
					left = true;


					napr = 2;

					if (kol >= 2) {
						x[kol - 1] = x[0];
						for (int zxc = 0; zxc < kol - 1; zxc++) {
							float tem = x[zxc];
							x[zxc] = x[kol - 1];
							x[kol - 1] = tem;
						}
					}

					if (kol >= 2) {
						y[kol - 1] = y[0] - 20.f;
						for (int zxc = 0; zxc < kol - 1; zxc++) {
							float tem = y[zxc];
							y[zxc] = y[kol - 1];
							y[kol - 1] = tem;
						}
					}
					else {
						y[0] -= 20.f;
					}




					if (kol >= 2) {
						if ((x1 == x[0] && y1 == y[0]) || (x1 == x[1] && y1 == y[1])) {
							sozdat(-20.f, 0.f);
							for (int qwe = 0; qwe < kol; qwe++) {
								pereschet(x[qwe], y[qwe]);
							}
						}
					}
					else {
						if (x1 == x[0] && y1 == y[0]) {
							sozdat(-20.f, 0.f);
							for (int qwe = 0; qwe < kol; qwe++) {
								pereschet(x[qwe], y[qwe]);
							}
						}
					}


					for (int cc = 0; cc < kol; cc++){
						if (y[cc] < 0.0f) {
							y[cc] = 580.0f;
						}
						zm[cc].setPosition(sf::Vector2f(x[cc], y[cc]));
				}ed.setPosition(sf::Vector2f(x1, y1));
				}
			}
			else if (ev.key.scancode == sf::Keyboard::A || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
				if (left) {
					up = true;
					down = true;
					right = false;


					napr = 3;

					if (kol >= 2) {
						x[kol - 1] = x[0] - 20.f;
						for (int zxc = 0; zxc < kol - 1; zxc++) {
							float tem = x[zxc];
							x[zxc] = x[kol - 1];
							x[kol - 1] = tem;
						}
					}
					else {
						x[0] -= 20.f;
					}

					if (kol >= 2) {
						y[kol - 1] = y[0];
						for (int zxc = 0; zxc < kol - 1; zxc++) {
							float tem = y[zxc];
							y[zxc] = y[kol - 1];
							y[kol - 1] = tem;
						}
					}


					if (kol >= 2) {
						if ((x1 == x[0] && y1 == y[0]) || (x1 == x[1] && y1 == y[1])) {
							sozdat(-20.f, 0.f);
							for (int qwe = 0; qwe < kol; qwe++) {
								pereschet(x[qwe], y[qwe]);
							}
						}
					}
					else {
						if (x1 == x[0] && y1 == y[0]) {
							sozdat(-20.f, 0.f);
							for (int qwe = 0; qwe < kol; qwe++) {
								pereschet(x[qwe], y[qwe]);
							}
						}
					}


					for (int cc = 0; cc < kol; cc++){
						if (x[cc] < 0.0f) {
							x[cc] = 780.0f;
						}
						zm[cc].setPosition(sf::Vector2f(x[cc], y[cc]));
				}ed.setPosition(sf::Vector2f(x1, y1));
				}
			}
			else if (ev.key.scancode == sf::Keyboard::S || sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
				if (down) {
					up = false;
					right = true;
					left = true;


					napr = 4;

					if (kol >= 2) {
						x[kol - 1] = x[0];
						for (int zxc = 0; zxc < kol - 1; zxc++) {
							float tem = x[zxc];
							x[zxc] = x[kol - 1];
							x[kol - 1] = tem;
						}
					}

					if (kol >= 2) {
						y[kol - 1] = y[0] + 20.f;
						for (int zxc = 0; zxc < kol - 1; zxc++) {
							float tem = y[zxc];
							y[zxc] = y[kol - 1];
							y[kol - 1] = tem;
						}
					}
					else {
						y[0] += 20.f;
					}



					if (kol >= 2) {
						if ((x1 == x[0] && y1 == y[0]) || (x1 == x[1] && y1 == y[1])) {
							sozdat(-20.f, 0.f);
							for (int qwe = 0; qwe < kol; qwe++) {
								pereschet(x[qwe], y[qwe]);
							}
						}
					}
					else {
						if (x1 == x[0] && y1 == y[0]) {
							sozdat(-20.f, 0.f);
							for (int qwe = 0; qwe < kol; qwe++) {
								pereschet(x[qwe], y[qwe]);
							}
						}
					}



					for (int cc = 0; cc < kol; cc++) {
						if (y[cc] > 580) {
							y[cc] = 0;
					}
						zm[cc].setPosition(sf::Vector2f(x[cc], y[cc]));
					}
						ed.setPosition(sf::Vector2f(x1, y1));
				}

			}
		}
	}
	void uprav() {
		if (napr == 1) {
			
			if (kol >= 2) {
				x[kol - 1] = x[0] + 20.f;
				for (int zxc = 0; zxc < kol - 1; zxc++) {
					float tem = x[zxc];
			
					x[zxc] = x[kol - 1];
					x[kol - 1] = tem;
				
				}
			}
			else {
				x[0] += 20.f;
			}
			
			if (kol >= 2) {
				y[kol - 1] = y[0];
				for (int zxc = 0; zxc < kol - 1; zxc++) {
					float tem = y[zxc];
					y[zxc] = y[kol - 1];
					y[kol - 1] = tem;
				}
			}

			if (kol >= 4) {
				for (int zxc = 3; zxc < kol - 1; zxc++) {
					if (x[zxc] == x[0] && y[zxc] == y[0]) {
						error = true;
					}
				}
			}


			if (kol >= 2) {
				if ((x1 == x[0] && y1 == y[0]) || (x1 == x[1] && y1 == y[1])) {
					sozdat(-20.f, 0.f);
					for (int qwe = 0; qwe < kol; qwe++) {
						pereschet(x[qwe], y[qwe]);
					}
				}
			}
			else {
				if (x1 == x[0] && y1 == y[0]) {
					sozdat(-20.f, 0.f);
					for (int qwe = 0; qwe < kol; qwe++) {
						pereschet(x[qwe], y[qwe]);
					}
				}
			}


			for (int cc = 0; cc < kol ; cc++) {
				if (x[cc] > 780.0f) {
					x[cc] = 0;
				}
				zm[cc].setPosition(sf::Vector2f(x[cc], y[cc]));
			}

			
			ed.setPosition(sf::Vector2f(x1, y1));
		}
		else if (napr == 2) {
		
			if (kol >= 2) {
				x[kol - 1] = x[0];
				for (int zxc = 0; zxc < kol - 1; zxc++) {
					float tem = x[zxc];
					x[zxc] = x[kol - 1];
					x[kol - 1] = tem;
				}
			}
			
			if (kol >= 2) {
				y[kol - 1] = y[0] - 20.f;
				for (int zxc = 0; zxc < kol - 1; zxc++) {
					float tem = y[zxc];
					y[zxc] = y[kol - 1];
					y[kol - 1] = tem;
				}
			}
			else {
				y[0] -= 20.f;
			}
			
			if (kol >= 4) {
				for (int zxc = 3; zxc < kol - 1; zxc++) {
					if (x[zxc] == x[0] && y[zxc] == y[0]) {
						error = true;
					}
				}
			}


			if (kol >= 2) {
				if ((x1 == x[0] && y1 == y[0]) || (x1 == x[1] && y1 == y[1])) {
					sozdat(-20.f, 0.f);
					for (int qwe = 0; qwe < kol; qwe++) {
						pereschet(x[qwe], y[qwe]);
					}
				}
			}
			else {
				if (x1 == x[0] && y1 == y[0]) {
					sozdat(-20.f, 0.f);
					for (int qwe = 0; qwe < kol; qwe++) {
						pereschet(x[qwe], y[qwe]);
					}
				}
			}


			for (int cc = 0; cc < kol ; cc++) {
				if (y[cc] < 0.f) {
					y[cc] = 580.f;
				}
				zm[cc].setPosition(sf::Vector2f(x[cc], y[cc]));
			}

		
			ed.setPosition(sf::Vector2f(x1, y1));
		}
		else if (napr == 3) {
		
			
			if (kol >= 2) {
				x[kol - 1] = x[0] - 20.f;
				for (int zxc = 0; zxc < kol - 1; zxc++) {
					float tem = x[zxc];
					x[zxc] = x[kol - 1];
					x[kol - 1] = tem;
				}
			}
			else {
				x[0] -= 20.f;
			}
			
			if (kol >= 2) {
				y[kol - 1] = y[0];
				for (int zxc = 0; zxc < kol - 1; zxc++) {
					float tem = y[zxc];
					y[zxc] = y[kol - 1];
					y[kol - 1] = tem;
				}
			}

			if (kol >= 4) {
				for (int zxc = 3; zxc < kol - 1; zxc++) {
					if (x[zxc] == x[0] && y[zxc] == y[0]) {
						error = true;
					}
				}
			}


			if (kol >= 2) {
				if ((x1 == x[0] && y1 == y[0]) || (x1 == x[1] && y1 == y[1])) {
					sozdat(-20.f, 0.f);
					for (int qwe = 0; qwe < kol; qwe++) {
						pereschet(x[qwe], y[qwe]);
					}
				}
			}
			else {
				if (x1 == x[0] && y1 == y[0]) {
					sozdat(-20.f, 0.f);
					for (int qwe = 0; qwe < kol; qwe++) {
						pereschet(x[qwe], y[qwe]);
					}
				}
			}


			for (int cc = 0; cc < kol ; cc++) {
				if (x[cc] < 0.0f) {
					x[cc] = 780.0f;
				}
				zm[cc].setPosition(sf::Vector2f(x[cc], y[cc]));
			}
			ed.setPosition(sf::Vector2f(x1, y1));
		}
		else if(napr==4) {
			
			if (kol >= 2) {
				x[kol - 1] = x[0];
				for (int zxc = 0; zxc < kol - 1; zxc++) {
					float tem = x[zxc];
					x[zxc] = x[kol - 1];
					x[kol - 1] = tem;
				}
			}
			
			if (kol >= 2) {
				y[kol - 1] = y[0] + 20.f;
				for (int zxc = 0; zxc < kol - 1; zxc++) {
					float tem = y[zxc];
					y[zxc] = y[kol - 1];
					y[kol - 1] = tem;
				}
			}
			else {
				y[0] += 20.f;
			}

			if (kol >= 4) {
				for (int zxc = 3; zxc < kol - 1; zxc++) {
					if (x[zxc] == x[0] && y[zxc] == y[0]) {
						error = true;
					}
				}
			}

			

			if (kol >= 2) {
				if ((x1 == x[0] && y1 == y[0]) || (x1 == x[1] && y1 == y[1])) {
					sozdat(-20.f, 0.f);
					for (int qwe = 0; qwe < kol; qwe++) {
						pereschet(x[qwe], y[qwe]);
					}
				}
			}
			else {
				if (x1 == x[0] && y1 == y[0]) {
					sozdat(-20.f, 0.f);
					for (int qwe = 0; qwe < kol; qwe++) {
						pereschet(x[qwe], y[qwe]);
					}
				}
			}

			for (int cc = 0; cc < kol ; cc++) {
				if (y[cc] > 580.f) {
					y[cc] = 0.f;
				}
				zm[cc].setPosition(sf::Vector2f(x[cc], y[cc]));
			}
			ed.setPosition(sf::Vector2f(x1, y1));
			
		}
	}



	void sozdat(float uprx,  float upry) {
		std::cout << "Oshibka sozdat\n";
		kol++;
		
		float* x2 = new float[kol];
		for (int zxc = 0; zxc < kol-1; zxc++) {
			x2[zxc] = x[zxc];
		}
		x2[kol - 1] = x2[kol - 2] + uprx;
		delete[] x;
		x = x2;
		float* y2 = new float[kol];
		for (int zxc = 0; zxc < kol-1; zxc++) {
			y2[zxc] = y[zxc];
		}
		y2[kol - 1] = y2[kol - 2] + upry;
		delete[] y;
		y = y2;

		sf::RectangleShape* zm2 = new sf::RectangleShape[kol];
		for (int zxc = 0; zxc < kol - 1; zxc++) {
			zm2[zxc] = zm[zxc];
		}
		zm2[kol - 1].setSize(sf::Vector2f(20.0f, 20.0f));
		zm2[kol - 1].setFillColor(sf::Color::Red);
		delete[] zm;
		zm = zm2;

	}
	inline int retkol() { return kol; }

	bool reter() {
		return error;
	}
};


#endif // !Bash
