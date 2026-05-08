#include "oyun.hpp"

Oyun::Oyun() : window(sf::VideoMode(700,700), "2048 oyunu"){ //pencere acma
    window.setFramerateLimit(60);
    }

    void Oyun::olaylar(){
        sf:: Event event;
        while(window.pollEvent(event)){
            if(event.type==sf::Event::Closed){
                window.close();
            }
        }
    }

    
    //cizdiren fonk
     void Oyun::ciz(){
     window.clear(sf::Color(187, 173, 160)); // arka plan rengi
    for(int satir=0; satir<4; satir++){
       for(int sutun=0; sutun<4; sutun++){
          sf::RectangleShape kare(sf::Vector2f(150, 150)); // her karenin boyutu
          kare.setFillColor(sf::Color(205, 193, 180));     // karelerin rengi
          kare.setPosition(sutun * 170 + 25, satir * 170 + 25);   // kareler arası bosluk
          window.draw(kare);
    }
    }
    window.display();//cizilenleri ekranda gosterir
}
    

    // Oyunu başlatan burası
void Oyun::calistir() {
    while (window.isOpen()) {
        olaylar(); 
        ciz();          
    }
}
    
