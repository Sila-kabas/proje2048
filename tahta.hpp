#ifndef TAHTA_HPP
#define TAHTA_HPP
#include <vector>

class Tahta{
    public:
    int matris[4][4];
    int skor;

    Tahta();
    void sifirla();
    void rastgeleSayiEkle();
    void solaKaydir();
    void sagaKaydir();
    void yukariKaydir();
    void asagiKaydir();
    bool oyunBittiMi();

};
#endif