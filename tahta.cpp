#include "tahta.hpp"
#include <cstdlib>
#include <ctime>
#include <vector>

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
    rastgeleSayiEkle();
    rastgeleSayiEkle();
}
void Tahta::rastgeleSayiEkle(){
    int bosKareSayisi=0;
    int sayac=0;
    for(int satir=0; satir<4; satir++){
        for(int sutun=0; sutun<4; sutun++){
            if(matris[satir][sutun]==0){
                bosKareSayisi++;
            }
        }
    }
    if (bosKareSayisi==0){
        return; //bos kare yoksa fonk cık
    }
    int secilenBosKare= rand()% bosKareSayisi;

    for(int satir=0; satir<4; satir++){
        for(int sutun=0; sutun<4; sutun++){
            if(matris[satir][sutun]==0){
                if(sayac==secilenBosKare){
                    matris[satir][sutun]= (rand()%90==0)? 4 : 2;
                    return;
                }
                sayac++;
            }
        }
    }
}