#ifndef OYUN_HPP
#define OYUN_HPP
#include <SFML/Graphics.hpp>
#include "tahta.hpp"

class Oyun {
    public:
    sf::RenderWindow window;
    Tahta tahta;
    sf::Font font;

    Oyun();
    void calistir();
    void olaylar();
    void ciz();

};
#endif
