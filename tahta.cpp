#include "tahta.hpp"
#include <cstdlib>
#include <ctime>
#include <vector>
#include <iostream>

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

void Tahta::solaKaydir(){
    for(int satir=0; satir<4; satir++){ //boslukları sola kaydır
        int yazilacakYer=0;
         for(int sutun=0; sutun<4; sutun++){
            if(matris[satir][sutun]!=0){
                int sayi=matris[satir][sutun];
                matris[satir][sutun]=0;
                matris[satir][yazilacakYer]=sayi;
                yazilacakYer++;
            }
         }
         
         for(int sutun=0; sutun<3; sutun++){//yan yana iki kare aynıysa topla ve sola kaydır
            if(matris[satir][sutun]!=0 && matris[satir][sutun]==matris[satir][sutun+1]){
                matris[satir][sutun]=matris[satir][sutun]*2;
                skor+=matris[satir][sutun];
                matris[satir][sutun+1]=0;
            }
         }
          yazilacakYer=0;
            for(int sutun=0; sutun<4; sutun++){
                if(matris[satir][sutun]!=0){
                    int sayi=matris[satir][sutun];
                    matris[satir][sutun]=0;
                    matris[satir][yazilacakYer]=sayi;
                    yazilacakYer++;
                }
            }
         }
    }

void Tahta::sagaKaydir(){
    for(int satir=0; satir<4; satir++){ //boslukları saga kaydır

        int yazilacakYer=3;
         for(int sutun=3; sutun>=0; sutun--){
            if(matris[satir][sutun]!=0){
                int sayi=matris[satir][sutun];
                matris[satir][sutun]=0;
                matris[satir][yazilacakYer]=sayi;
                yazilacakYer--;
            }
         }
         
         for(int sutun=3; sutun>0; sutun--){//yan yana iki kare aynıysa topla ve saga kaydır
            if(matris[satir][sutun]!=0 && matris[satir][sutun]==matris[satir][sutun-1]){
                matris[satir][sutun]=matris[satir][sutun]*2;
                skor+=matris[satir][sutun];
                matris[satir][sutun-1]=0;
            }
         }
          yazilacakYer=3;
            for(int sutun=3; sutun>=0; sutun--){
                if(matris[satir][sutun]!=0){
                    int sayi=matris[satir][sutun];
                    matris[satir][sutun]=0;
                    matris[satir][yazilacakYer]=sayi;
                    yazilacakYer--;
                }
            }
         }
    }

void Tahta::yukariKaydir(){
    for(int sutun=0; sutun<4; sutun++){
         int yazilacakYer=0;

        for(int satir=0; satir<4; satir++){
            if(matris[satir][sutun]!=0){
                int sayi=matris[satir][sutun];
                matris[satir][sutun]=0;
                matris[yazilacakYer][sutun]=sayi;
                yazilacakYer++;
            }
        }

        for(int satir=0; satir<3; satir++){
            if(matris[satir][sutun]!=0 && matris[satir][sutun] == matris[satir+1][sutun]){
                int sayi=matris[satir][sutun];
                matris[satir][sutun]=sayi*2;
                skor+=matris[satir][sutun];
                matris[satir+1][sutun]=0;
            }
        }
         yazilacakYer=0;
        for(int satir=0; satir<4; satir++){
            if(matris[satir][sutun]!=0){
                int sayi=matris[satir][sutun];
                matris[satir][sutun]=0;
                matris[yazilacakYer][sutun]=sayi;
                yazilacakYer++;
            }
        }
    }
}

void Tahta::asagiKaydir(){
    for(int sutun=0; sutun<4; sutun++){
        int yazilacakYer=3;

        for(int satir=3; satir>=0; satir--){
            if(matris[satir][sutun]!=0){
                int sayi=matris[satir][sutun];
                matris[satir][sutun]=0;
                matris[yazilacakYer][sutun]=sayi;
                yazilacakYer--;
            }
        }

        for(int satir=3; satir>0; satir--){
            if(matris[satir][sutun]!=0 && matris[satir][sutun] == matris[satir-1][sutun]){
               int sayi=matris[satir][sutun];
               matris[satir][sutun]=sayi*2;
               matris[satir-1][sutun]=0;
               skor+=matris[satir][sutun];
            }
        }

        yazilacakYer=3;
        for(int satir=3; satir>=0; satir--){
            if(matris[satir][sutun]!=0){
                int sayi=matris[satir][sutun];
                matris[satir][sutun]=0;
                matris[yazilacakYer][sutun]=sayi;
                yazilacakYer--;
            }
        }
    }
}

bool Tahta::oyunBittiMi(){
    std::cout<<"sorgu"<<std::endl;
    for(int satir=0; satir<4; satir++){
        for(int sutun=0; sutun<4; sutun++){
            if(matris[satir][sutun]==0){
                return false;
            }
        }
    }

    for(int satir=0; satir<3; satir++){
        for(int sutun=0; sutun<3; sutun++){
            if(matris[satir][sutun]==matris[satir][sutun+1]){
                return false;
            }
            if(matris[satir][sutun]==matris[satir+1][sutun]){
                return false;
            }
        }
    }
    std::cout<<"game over"<<std::endl;
    return true;
}