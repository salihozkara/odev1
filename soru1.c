#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
    srand(time(NULL));
    int dizi[10],diziTek[10],diziCift[10];
    int *diziptr,*diziTekptr,*diziCiftptr;
   diziptr=dizi;
   diziTekptr=diziTek;
   diziCiftptr=diziCift;
    for (int i = 0; i <10 ; ++i) {
        *(diziptr+i)=rand()%100+1;
    }
    int tek = 0, cift=0;
    for (int i = 0; i <10 ; ++i) {

        if(*(diziptr+i)%2) {
            *(diziTekptr + tek) = *(diziptr + i);
            tek++;
        }
        else {
            *(diziCiftptr + cift) = *(diziptr + i);
            cift++;
        }
    }
    for (int i = 0; i <tek ; ++i) {
        printf("tek sayilar=%d\n",*(diziTekptr+i));
    }
    for (int i = 0; i <cift ; ++i) {
        printf("cift sayilar=%d\n",*(diziCiftptr+i));
    }
    return 0;
}
