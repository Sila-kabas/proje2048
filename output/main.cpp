#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>

int main(){
    sf::RenderWindow window(sf::VideoMode(700,700), "2048 oyunu"); //pencere acma
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
    }
    window.clear(sf::Color(187, 173, 160)); // arka plan rengi
    for(int satir=0; satir<4; satir++){
       for(int sutun=0; sutun<4; sutun++){
          sf::RectangleShape kare(sf::Vector2f(150, 150)); // her kare 200e 200
          kare.setFillColor(sf::Color(205, 193, 180));     //  hücre rengi
          kare.setPosition(sutun * 170 + 25, satir * 170 + 25);    // kareler arası bosluk
          window.draw(kare);
    }
}
        window.display();
    }
    return 0;
}