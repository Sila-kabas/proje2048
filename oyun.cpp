#include "oyun.hpp"
#include <string>
#include <iostream>

Oyun::Oyun() : window(sf::VideoMode(700,700), "2048 oyunu"){ //pencere acma
    window.setFramerateLimit(60);
    // Önce bir üst klasörde ara, bulamazsa olduğu klasörde ara
if (!font.loadFromFile("../arial.ttf")) {
    if (!font.loadFromFile("arial.ttf")) {
    }
}
    font.loadFromFile("arial.ttf");
    tahta.sifirla();
    }

    void Oyun::olaylar(){
        sf:: Event event;
        while(window.pollEvent(event)){
            if(event.type==sf::Event::Closed){
                window.close();
            }   
        

                if(event.type==sf::Event::KeyPressed){
                    if(event.key.code==sf::Keyboard::Left){
                        tahta.solaKaydir();
                        tahta.rastgeleSayiEkle();

                    }
                    else if(event.key.code==sf::Keyboard::Right){
                        tahta.sagaKaydir();
                        tahta.rastgeleSayiEkle();
                    }
                    else if(event.key.code==sf::Keyboard::Down){
                        tahta.asagiKaydir();
                        tahta.rastgeleSayiEkle();
                    }
                    else if(event.key.code==sf::Keyboard::Up){
                        tahta.yukariKaydir();
                        tahta.rastgeleSayiEkle();
                    }
                if(tahta.oyunBittiMi()){
                    std::cout<<"game over"<<std::endl;
                    bittiMi=true;
                }
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
     
          if(tahta.matris[satir][sutun]!=0){
            sf::Text yazi;
            yazi.setFont(font);
            yazi.setString(std::to_string(tahta.matris[satir][sutun]));
            yazi.setCharacterSize(75);
            yazi.setFillColor(sf::Color::Black);
            yazi.setStyle(sf::Text::Bold);
            yazi.setPosition(sutun*170+75, satir*170+40);
            window.draw(yazi);
          }
    }
    }
    if(bittiMi){
        sf::RectangleShape ekran(sf::Vector2f(1200, 1200)); // 
          ekran.setFillColor(sf::Color(205, 193, 180));     // 
          window.draw(ekran);
     
            sf::Text bitisyazisi;
            bitisyazisi.setFont(font);
            bitisyazisi.setString("game over");
            bitisyazisi.setCharacterSize(75);
            bitisyazisi.setFillColor(sf::Color::Black);
            bitisyazisi.setStyle(sf::Text::Bold);
            bitisyazisi.setPosition(190,200);
            window.draw(bitisyazisi);

     
            sf::Text skoryazisi;
            skoryazisi.setFont(font);
            skoryazisi.setString("skor "+ std::to_string(tahta.skor));
            skoryazisi.setCharacterSize(75);
            skoryazisi.setFillColor(sf::Color::Black);
            skoryazisi.setStyle(sf::Text::Bold);
            skoryazisi.setPosition(150,350);
            window.draw(skoryazisi);
    }

    window.display();//cizilenleri ekranda gosterir
}
    
    // Oyunu başlatan burası
void Oyun::calistir(){
    while (window.isOpen()) {
        olaylar(); 
        ciz();          
    }
}
    
