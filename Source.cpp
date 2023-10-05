#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include "Bash.h"
using namespace sf;
int main()
{
    RenderWindow* window = new RenderWindow(VideoMode(800, 600), "Zmeyka");
    int y = 0;
    RectangleShape* rec = new RectangleShape(Vector2f(150.0f, 100.0f));
    RectangleShape* rec2 = new RectangleShape(Vector2f(150.0f, 100.0f));

    Font font;
    if (!font.loadFromFile("arial.ttf"))
    {
        std::cout << "Fignya\n";
    }
  
    Text* t = new Text;
    t->setFont(font);
    t->setString("Exit");
    t->setCharacterSize(30);
    

    Text* t2 = new Text;
    t2->setFont(font);
    t2->setString("Play");
    t2->setCharacterSize(30);

    Text* tu = new Text;
    tu->setFont(font);
    tu->setString("W/Up-turn up");
    tu->setCharacterSize(30);
    
    Text* tr = new Text;
    tr->setFont(font);
    tr->setString("D/Right-turn Right");
    tr->setCharacterSize(30);

    Text* tl = new Text;
    tl->setFont(font);
    tl->setString("A/Left-turn Left");
    tl->setCharacterSize(30);

    Text* ts = new Text;
    ts->setFont(font);
    ts->setString("S/Down-turn Down");
    ts->setCharacterSize(30);

    Texture te;
    if (!te.loadFromFile("zmeyka.png"))
    {
        std::cout << "problema s texturoy\n";
    }

    

    Sprite sprite;
    sprite.setTexture(te);
    sprite.setPosition(Vector2f(1.f, 50.f));
   
    Color col(37,118,98);

    while (true&&y!=4)
    {
        if (y == 0) {
            std::cout << "Comeback\n";
            rec->setPosition(Vector2f(350.0f, 150.0f));
            rec->setFillColor(Color::Yellow);


            rec2->setPosition(Vector2f(350.0f, 300.0f));
            rec2->setFillColor(Color::Yellow);



            t->setFillColor(Color::Black);
            t->setPosition(Vector2f(390.0f, 330.0f));

            t2->setFillColor(Color::Black);
            t2->setPosition(Vector2f(390.0f, 183.0f));

            tu->setFillColor(Color::Black);
            tu->setPosition(Vector2f(10.0f, 300.0f));

            tr->setFillColor(Color::Black);
            tr->setPosition(Vector2f(10.0f, 340.0f));

            tl->setFillColor(Color::Black);
            tl->setPosition(Vector2f(10.0f, 380.0f));

            ts->setFillColor(Color::Black);
            ts->setPosition(Vector2f(10.0f, 420.0f));
            while (window->isOpen())
            {
                if (y == 1) {
                  
                    std::cout << y << " win\n";
                    break;
                }
                Event event;
                while (window->pollEvent(event))
                {
                    if (y == 1) {
                        break;
                        std::cout << y << " ev\n";
                    }
                    window->clear(col);
                    if (event.type == Event::Closed) {//конпка закрытия
                        window->close();
                    }
                    if (event.type == Event::MouseMoved) {
                        if ((event.mouseMove.x >= 350.0f && event.mouseMove.x <= 500.0f) && (event.mouseMove.y >= 150.0f && event.mouseMove.y <= 250.0f)) {
                            rec->setFillColor(Color::Red);

                        }
                        else if ((event.mouseMove.x >= 350.0f && event.mouseMove.x <= 500.0f) && (event.mouseMove.y >= 300.0f && event.mouseMove.y <= 400.0f)) {
                            rec2->setFillColor(Color::Red);

                        }
                        else {
                            rec->setFillColor(Color::Yellow);
                            rec2->setFillColor(Color::Yellow);
                        }
                    }

                    if (event.type == Event::MouseButtonPressed) {
                        if (event.mouseButton.button == Mouse::Left) {

                            if ((event.mouseButton.x >= 350.0f && event.mouseButton.x <= 500.0f) && (event.mouseButton.y >= 150.0f && event.mouseButton.y <= 250.0f)) {

                                rec->setFillColor(Color::Cyan);
                                y = 1;
                                std::cout << y << " ev\n";
                                
                              

                            }
                            if ((event.mouseButton.x >= 350.0f && event.mouseButton.x <= 500.0f) && (event.mouseButton.y >= 300.0f && event.mouseButton.y <= 400.0f)) {

                                rec2->setFillColor(Color::Cyan);
                                y = 4;
                                window->close();

                            }
                        }
                    }

                    if (event.type == Event::MouseButtonReleased) {
                        if (event.mouseButton.button == Mouse::Left) {

                            if ((event.mouseButton.x >= 350.0f && event.mouseButton.x <= 500.0f) && (event.mouseButton.y >= 150.0f && event.mouseButton.y <= 250.0f)) {

                                rec->setFillColor(Color::Red);


                            }
                            if ((event.mouseButton.x >= 350.0f && event.mouseButton.x <= 500.0f) && (event.mouseButton.y >= 300.0f && event.mouseButton.y <= 400.0f)) {

                                rec2->setFillColor(Color::Red);


                            }
                        }
                    }

                    window->draw(sprite);
                    window->draw(*rec);
                    window->draw(*rec2);
                    window->draw(*t);
                    window->draw(*t2);
                    window->draw(*tu);
                    window->draw(*tr);
                    window->draw(*tl);
                    window->draw(*ts);
                    window->display();
                  
                }
            }
        }
        else {
         
            Zm b;
            
                while (window->isOpen())
                {
                    if (y == 0){
                        std::cout << "Game over win\n";
                        break;
                    }
                    Event event;
                     window->clear(col);
                    while (window->pollEvent(event))
                    {
                        if (y == 0) {
                            std::cout << "Game over ev\n";
                            break;
                        }
                        if (event.type == Event::Closed) {//конпка закрытия
                            window->close();
                        }
                        
                        b.peremshen( event);
                     
                    }
                  sleep(seconds(0.13));
                    b.uprav();

                    for (int zxc = 0; zxc < b.retkol(); zxc++) {
                        if (b.reter()) {
                            Text* t3 = new Text;
                            t3->setFont(font);
                            t3->setString("Game Over");
                            t3->setCharacterSize(90);
                            t3->setFillColor(Color::Black);
                            t3->setPosition(Vector2f(150.0f, 100.0f));
                            window->draw(*t3);
                            window->display();
                            sleep(seconds(3));
                            delete t3;
                            y = 0;
                            break;
                        }
                        window->draw(b.vozvrat(zxc));
                    }

                 
                        window->draw(b.vozvrat());
                        window->display();
                        if (y == 0) {
                            std::cout << "Rizusnok\n";
                        }
            }
            
      }
    }
    delete window;
    return 0;
}
