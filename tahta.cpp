#include "tahta.hpp"
#include <cstdlib>
#include <ctime>

Tahta::Tahta(){
    srand(time(0)); // Rastgele sayı 
    sifirla();
}

void Tahta::sifirla() {
    skor = 0;
    for(int satir = 0; satir < 4; satir++) {
        for(int sutun = 0; sutun < 4; sutun++) {
            matris[satir][sutun] = 0;
        }
    }
}
void Tahta::rastgeleSayiEkle()