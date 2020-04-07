#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct genelBilgiler
{
    char plaka[10];
    char model[50];
    char renk[10];
}arac[1000];
struct tarih
{
    int h;
    int dk;
    int sn;
}saat[1000];
void anaMenu(int*);
void aracEkle(int *aracSayisi);
void listele(int *aracSayisi);

int main() {
    int sayi=0;
    anaMenu(&sayi);
    return 0;
}
void anaMenu(int *sayi)
{
    system("CLS");
    printf("arac ekle icin\t\t1\narac listele icin\t2\ncikis\t\t\t3\nseciminiz\t:");
    int secim;
    scanf("%d",&secim);
    system("CLS");
    switch (secim)
    {
        case 1:
            aracEkle(sayi);
            break;
        case 2:
            listele(sayi);
            break;
        case 3:
            exit(1);
        default:
            printf("hatali giris!!\n");
            system("PAUSE");
            anaMenu(sayi);
    }
}
void aracEkle(int *aracSayisi)
{
    if(*aracSayisi>=1000)
    {
        printf("kapasite dolu!!!");
        anaMenu(&*aracSayisi);
    }
    char gereksiz;
    printf("plaka:");
    fflush(stdin);
    gets(arac[*aracSayisi].plaka);
    for (int i = 0; i <*aracSayisi ; ++i) {
        if(strcmp(arac[*aracSayisi].plaka,arac[i].plaka)==0)
        {
            printf("ayni plakali arac girdiniz hatali\n");
            aracEkle(&*aracSayisi);
        }
    }
    printf("model:");
    //fflush(stdin);
    gets(arac[*aracSayisi].model);
    printf("renk:");
    gets(arac[*aracSayisi].renk);
    printf("saat(lutfen arasina nokta koyunuz):");
    scanf("%d %c %d %c %d",&saat[*aracSayisi].h,&gereksiz,&saat[*aracSayisi].dk,&gereksiz,&saat[*aracSayisi].sn);
    for (int j = 0; j <1 ; ++j) {
        if(saat[*aracSayisi].h<24&&saat[*aracSayisi].h>=0&&saat[*aracSayisi].dk<60&&saat[*aracSayisi].dk>=0&&saat[*aracSayisi].sn<60&&saat[*aracSayisi].sn>=0)
        {
            *aracSayisi=*aracSayisi+1;
        }
        else{
            printf("saat bilgisi yanlis tekrar giriniz:");
            scanf("%d %c %d %c %d",&saat[*aracSayisi].h,&gereksiz,&saat[*aracSayisi].dk,&gereksiz,&saat[*aracSayisi].sn);
            j--;
        }}

    system("pause");
    anaMenu(aracSayisi);
}
void listele(int *aracSayisi)
{
    if(*aracSayisi==0)
    {
        printf("liste bos!!!\n");
        system("PAUSE");
        anaMenu(aracSayisi);
    }
    printf("plaka                         model                         renk                          saat\n");
    for (int i = 0; i <*aracSayisi ; ++i) {
        printf("%s",arac[i].plaka);
        for (int j = 0; j <30-(strlen(arac[i].plaka)) ; ++j)
            printf(" ");
        printf("%s",arac[i].model);
        for (int j = 0; j <30-(strlen(arac[i].model)) ; ++j)
            printf(" ");
        printf("%s",arac[i].renk);
        for (int j = 0; j <30-(strlen(arac[i].renk)) ; ++j)
            printf(" ");
        printf("%2d:%2d:%2d\n",saat[i].h,saat[i].dk,saat[i].sn);
    }
    printf("toplam %2d arac var\n",*aracSayisi);
system("pause");
anaMenu(aracSayisi);
}