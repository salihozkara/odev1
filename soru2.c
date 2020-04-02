#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    char plaka[10];
    char model[50];
    char renk[10];
}genelBilgiler;
typedef struct
{
    int saat;
    int dk;
    int saniye;
}tarih;
tarih giris[1000];
genelBilgiler araba[1000];
int sayi=0;
void sayial(int *palinan,int ust);
void anaEkran();
void aracEkle();
void aracListele();
void duzenle();
void aracCikar();
//---------------------------------------------ana fonksiyon------------------------------------------------------------
int main() {
    printf("------------------------------------------------OTOPARK ARAC BILGI SISTEMI----------------------------------------------\n");
    anaEkran();
    return 0;
}
//---------------------------------------------sayı alma----------------------------------------------------------------
void sayial(int *palinan,int ust) {
    int sayac = 0, gecici = 0,alinan;
    do {
        while (scanf("%d", &gecici) == 0)//scanf de hatalı giriş yapıldı ise döngüye giriyor
        {
            printf("lutfen sadece sayi girin!!!\n");
            int c;
            while ((c = getchar()) != '\n' && c != EOF);//sonsuz döngüye dönüşmesini engelliyor
        }
        if (gecici < 1 || gecici > ust) {//girilicek aralığı belirliyor
            printf("lutfen 1 ile %d arasi girin\n", ust);
        }
        else{
            *palinan = gecici;//alınan sayı diziye atılıyor
            sayac++;
        }
    } while (sayac < 1);
    system("CLS");//ekranı temizler
}
//---------------------------------------------ana ekran----------------------------------------------------------------
void anaEkran(){
    printf("ne yapmak istersiniz :\narac ekle icin \t1\nliste icin \t2\nduzenleme icin \t3\narac cikar icin\t4\ncikmak icin \t5\nseciminiz\t:");
    int secim;
    sayial(&secim,5);
    switch (secim) {
        case 1:
            system("CLS");
            aracEkle();
            break;
        case 2:
            system("CLS");
            aracListele();
            break;
        case 3:
            system("CLS");
            duzenle();
            break;
        case 4:
            system("CLS");
            aracCikar();
            break;
        case 5:
            system("CLS");
            exit(5);
            break;
        default:
            printf("hatali secim!!!\n");
            anaEkran();
    }
}
//---------------------------------------------arac ekle----------------------------------------------------------------
void aracEkle(){
    if(sayi>=1000) {
        printf("otopark dolu");
        anaEkran();
    }
    printf("lutfen eklemek istediginiz aracin plakasini giriniz          :");
    scanf("%s",araba[sayi].plaka);
    for (int i = 0; i <sayi ; ++i) {
        if(strcmp(araba[sayi].plaka,araba[i].plaka)==0)
        {
            printf("ayni plakali arac girdiniz hatali\n");
            aracEkle();
        }
    }

    printf("lutfen eklemek istediginiz aracin modelini giriniz           :");
    scanf("%s",araba[sayi].model);
    printf("lutfen eklemek istediginiz aracin rengini giriniz            :");
    scanf("%s",araba[sayi].renk);
    printf("giris saatini giriniz(lutfen araya nokta yada virgul koyunuz):");
    char gereksiz;//araya konulan işaretleri pas geccmesi için
    scanf("%d %c %d %c %d",&giris[sayi].saat,&gereksiz,&giris[sayi].dk,&gereksiz,&giris[sayi].saniye);
    for (int j = 0; j <1 ; ++j) {
        if(giris[sayi].saat<24&&giris[sayi].saat>=0&&giris[sayi].dk<60&&giris[sayi].dk>=0&&giris[sayi].saniye<60&&giris[sayi].saniye>=0)
        {
            sayi++;
        }
        else{
            printf("saat bilgisi yanlis tekrar giriniz\t:");
            scanf("%d %c %d %c %d",&giris[sayi].saat,&gereksiz,&giris[sayi].dk,&gereksiz,&giris[sayi].saniye);
            j--;
        }}
    system("CLS");
    anaEkran();
}
//---------------------------------------------arac listele-------------------------------------------------------------
void aracListele(){
    if(sayi==0)
        printf("liste bos!\n");
    else{
        for (int i = 0; i <sayi ; ++i) {
            printf("%s\t%s\t%s\tgiris saati=%2d:%2d:%2d\n", araba[i].plaka, araba[i].model, araba[i].renk,giris[i].saat,giris[i].dk,giris[i].saniye);
        }
        printf("toplam %2d arac var\n",sayi);
    }
    anaEkran();
}
//---------------------------------------------düzenle------------------------------------------------------------------
void duzenle()
{
    if((sayi>0)==0)
    {
        printf("arac yok\n");
        anaEkran();
    }
    char dizi[10];
    printf("duzenlenecek arac plakasini giriniz:");
    scanf("%s",dizi);
    int a=0;
    do {
        if (strcmp(dizi, araba[a].plaka))
            a++;
        else{
            printf("duzenlemek istediginiz bilgi plaka icin 1,model icin 2,renk icin 3,saat icin 4:");
            int duzen;
            scanf("%d",&duzen);
            switch(duzen){
                case 1:
                    scanf("%s",araba[a].plaka);
                    break;
                case 2:
                    scanf("%s",araba[a].model);
                    break;
                case 3:
                    scanf("%s",araba[a].renk);
                    break;
                case 4:
                    scanf("%d %d %d",&giris[sayi].saat,&giris[sayi].dk,&giris[sayi].saniye);
                    break;
            }
            break;}
    }while(a<1000);
    if(a==1000)
        printf("plaka yanlis!!!\n");
    else
        system("CLS");
    anaEkran();
}
//---------------------------------------------arac cıkar---------------------------------------------------------------
void aracCikar()
{
    if((sayi>0)==0)
    {
        printf("arac yok\n");
        anaEkran();
    }
    char dizi[10];
    printf("cikarilicak arac plakasini giriniz:");
    scanf("%s",dizi);
    int a=0;
    do {
        if (strcmp(dizi, araba[a].plaka))
            a++;
        else{
            araba[a]=araba[sayi-1];
            giris[a]=giris[sayi-1];
            sayi--;
            break;}
    }while(a<1000);
    if(a==1000)
        printf("plaka yanlis!!!\n");
    else
        system("CLS");
    anaEkran();
}