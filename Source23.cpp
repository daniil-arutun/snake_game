#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
int main()
{
    RenderWindow* window = new RenderWindow(VideoMode(800, 600), "Game");
    int y = 0;
    RectangleShape* rec = new RectangleShape(Vector2f(150.0f, 100.0f));
    RectangleShape* rec2 = new RectangleShape(Vector2f(150.0f, 100.0f));
  
    while (window->isOpen())
    {
        if (y == 0) {
           
            rec->setPosition(Vector2f(350.0f, 150.0f));
            rec->setFillColor(Color::Yellow);

            
            rec2->setPosition(Vector2f(350.0f, 300.0f));
            rec2->setFillColor(Color::Yellow);
            Event event;
            while (window->pollEvent(event))
            {
                window->clear(Color::White);
                if (event.type == Event::Closed) {//конпка закрытия
                    window->close();
                }
                if (event.type == Event::MouseMoved) {
                    if ((event.mouseMove.x >= 350.0f && event.mouseMove.x <= 500.0f) && (event.mouseMove.y >= 150.0f && event.mouseMove.y <= 250.0f)) {
                        rec->setFillColor(Color::Red);
                        std::cout << "Problema move 1\n";
                    }
                    else if ((event.mouseMove.x >= 350.0f && event.mouseMove.x <= 500.0f) && (event.mouseMove.y >= 300.0f && event.mouseMove.y <= 400.0f)) {
                        rec2->setFillColor(Color::Red);
                        std::cout << "Problema move 2\n";
                    }
                    else {
                        rec->setFillColor(Color::Yellow);
                       rec2->setFillColor(Color::Yellow);
                    }
                }
                /*
                if (event.type == Event::MouseButtonPressed) {
                    if (event.mouseButton.button == Mouse::Left) {
                        std::cout << "vidit li press\n";
                        if ((event.mouseMove.x >= 350.0f && event.mouseMove.x <= 500.0f) && (event.mouseMove.y >= 150.0f && event.mouseMove.y <= 250.0f)) {
                            std::cout << "Problema press 1\n";
                            rec->setFillColor(Color::Cyan);
                         //   y = 1;
                           // break;

                        }
                        else  if ((event.mouseMove.x >= 350.0f && event.mouseMove.x <= 500.0f) && (event.mouseMove.y >= 300.0f && event.mouseMove.y <= 400.0f)) {
                            std::cout << "Problema press 2\n";
                            rec2->setFillColor(Color::Cyan);
                            window->close();

                        }
                    }
                }
                if (event.type == Event::MouseButtonReleased) {
                    if (event.mouseButton.button == Mouse::Left) {
                        std::cout << "vidit li rele\n";
                        if ((event.mouseMove.x >= 350.0f && event.mouseMove.x <= 500.0f) && (event.mouseMove.y >= 150.0f && event.mouseMove.y <= 250.0f)) {
                            std::cout << "Problema relese 1\n";
                            rec->setFillColor(Color::Red);


                        }
                        else   if ((event.mouseMove.x >= 350.0f && event.mouseMove.x <= 500.0f) && (event.mouseMove.y >= 300.0f && event.mouseMove.y <= 400.0f)) {
                            std::cout << "Problema relese 2\n";
                            rec2->setFillColor(Color::Red);


                        }
                    }
                }
               */
                window->draw(*rec);
                window->draw(*rec2);
                window->display();
            }
        }
        else {
           
            delete rec;
            delete rec2;
                while (window->isOpen())
                {
                    Event event;
                    while (window->pollEvent(event))
                    {
                        std::cout << "Uje nachalos\n";
                        window->clear(Color::White);
                        if (event.type == Event::Closed) {//конпка закрытия
                            window->close();
                        }
                        window->clear(Color::White);
                        window->display();


                    }

            }
            
        }
    }
    delete window;
    return 0;
}
