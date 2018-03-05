#include <stdio.h>
#include <stdlib.h>

int main()
{
    /************ PROGRAMI KODLAYAN KISI EMRE OZ CELAL BAYAR UNIVERSITESI YAZILIM MUHENDISLIGI BIRINCI SINIF ORGUN OGRETIM OGRENCISI *************/
    /********************************************************BILGILENDIRME************************************************************************/
    /*********YORUM SATIRLARI SADECE SONBAHAR STANDART ODA TIPI ICIN MEVCUTTUR DIGER KODLAR AYNISI OLDUGU ICIN YORUM SATIRI EKLENMEMISTIR.********/
    /*********************************************************************************************************************************************/
    /*********************************UCRETLER GUNLUK OLARAK HESAPLANMISTIR.1 HAFTA(7) ILE CARPILMAMIS HALIDIR.***********************************/
    /*********************************************************************************************************************************************/
    /*********************************************PROGRAM ICERISINDEKI CIKABILCEK HATALAR*********************************************************/
    /*** 1-)YANLIS MEVSIM SECILME DURUMU (+) ***/
    /*** 2-)BELIRLENEN HAFTA ARALIGININ DISINA CIKMA DURUMU (+) ***/
    /*** 3-)YANLIS ODA TIPI SECILME DURUMU (+) ***/
    /*** 4-)YANLIS ODA NUMARASI SECILME DURUMU (+) ***/
    /*** 5-)DAHA ONCEDEN REZERVE EDILMIS ODA NUMARASI SECILME DURUMU (+) ***/
    /*** 6-)ODA KAPASITESINI ASAN MISAFIR SAYISINDA TEKRARDAN MISAFIR SAYISI ISTEMEME DURUMU (+) ***/
    /*** 7-)YANLIS ODEME TIPI SECILME DURUMU (+) ***/
    /*** 8-)YANLIS PROGRAM TEKRAR TUSU SECILME DURUMU (+) ***/
    /*******************************************************TUM DIZILERIN TANIMI******************************************************************/
    /*** SONBAHAR ***/
    int Sonbahar[12][100],Dolu[12]= {0,0,0,0,0,0,0,0,0,0,0,0},SDolu[12]= {0,0,0,0,0,0,0,0,0,0,0,0},DDolu[12]= {0,0,0,0,0,0,0,0,0,0,0,0};
    int LDolu[12]={0,0,0,0,0,0,0,0,0,0,0,0};

    /*** BAHAR ***/
    int Bahar[12][100],BDolu[12]= {0,0,0,0,0,0,0,0,0,0,0,0},BSDolu[12]= {0,0,0,0,0,0,0,0,0,0,0,0},BDDolu[12]= {0,0,0,0,0,0,0,0,0,0,0,0};
    int BLDolu[12]={0,0,0,0,0,0,0,0,0,0,0,0};

    /*** YAZ ***/
    int Yaz[12][100],YDolu[12]= {0,0,0,0,0,0,0,0,0,0,0,0},YSDolu[12]= {0,0,0,0,0,0,0,0,0,0,0,0},YDDolu[12]= {0,0,0,0,0,0,0,0,0,0,0,0};
    int YLDolu[12]={0,0,0,0,0,0,0,0,0,0,0,0};

    /******************************************************VERI GIRISLERIN TANIMI****************************************************************/

    int Hafta,OdaKayit,KisiSayisi;

    /******************************************************TUM SAYACLARIN TANIMI*****************************************************************/

    int Sayac=0,OdaTekrar=1,BosOdaTekrar=1,Bilgi=0,DoluSaydir=0,Secim=1,FazlaMisafir=0,KKisiSayisi=5,FSaydir=0;
    int OdemeSekilTekrar=1,SonlandirmaKontrol=1,Baslangic=1,i,j,LDoluSaydir=0,DDoluSaydir=0,SDoluSaydir=0;
    int BSDoluSaydir=0,BDDoluSaydir=0,BLDoluSaydir=0,YSDoluSaydir=0,YDDoluSaydir=0,YLDoluSaydir=0;

    /******************************************************MATEMATIKSEL ISLEMLERIN TANIMI*******************************************************/

    float Toplam=0;
    int ToplamKisi=0;

    /*****************************************************KARAKTER ISLEMLERIN TANIMI***********************************************************/

    char Mevsim_Secim,Oda,OdemeSekil,Sonlandirma;

    /*****************************************************DEGER ATAMALARI**********************************************************************/

    for(i=0; i<12; i++)
    {
        for(j=0; j<100; j++)
        {
            Sonbahar[i][j]=0;
        }
    }

    for(i=0; i<12; i++)
    {
        for(j=0; j<100; j++)
        {
            Bahar[i][j]=0;
        }
    }

    for(i=0; i<12; i++)
    {
        for(j=0; j<100; j++)
        {
            Yaz[i][j]=0;
        }
    }

    /**********************************************************************************************************************************************/
    /*******WHILE DONGULERIN BASINDAKI DEGISKENLERE TEKRAR DEGER ATAMA PROGRAM BASA DONDUGU ZAMAN WHILE DONGUSU ICERISINE GIREBILMESI ICIN********/

    while(Baslangic==1) /*** DEVAM ETTIRMEK ISTIYORMUSUNUZ DONGUSU ICIN BASLANGIC NOKTASI ***/
    {
        fflush(stdin);
        printf("\nHangi Mevsimde Konaklamak istersiniz:\n");
        printf("Sonbahar icin 'S',Bahar icin 'B',Yaz icin 'Y' tusuna basiniz: ");
        scanf("%c",&Mevsim_Secim);
        switch(Mevsim_Secim)
        {
        case 'S':
            Secim=1;
            Sayac=0;
            while(Secim==1) /*** YANLIS HAFTA BILGISI GIRILDIGINDE DONDURULECEK DONGU BASLANGIC NOKTASI ***/
            {
                printf("\nSonbahar Ayinin kacinci haftasinda konaklama yapmak istiyorsunuz : ");
                scanf("%d",&Hafta);
                Sayac++;
                if(Hafta>=1 && Hafta<=12) /*** GIRILEN DEGERIN 1. VE 12. HAFTA ARASINDA OLUP-OLMADIGINI DONDURECEK OLAN BASLANGIC NOKTASI  ***/
                {
                    Secim=0;
                    OdaTekrar=1;
                    while(OdaTekrar==1) /*** YANLIS ODA TIPI BILGISI GIRILDIGINDE DONDURULECEK DONGU BASLANGIC NOKTASI ***/
                    {
                        fflush(stdin);
                        printf("\nLutfen Oda Tipini Seciniz\n");
                        printf("Standart Oda icin 'S',Deluxe Oda icin 'D',Large Deluxe Oda icin 'L' tusuna basiniz : ");
                        scanf("%c",&Oda);
                        if(Oda=='S') /*** STANDART ODA TIPI ICIN YAPILACAK ISLEMLER ICIN BASLANGIC NOKTASI ***/
                        {
                            if(SDolu[Hafta-1]==50) /*** STANDART ODA TIPI DOLDUGUNDA HATA MESAJI VERECEK OLAN BLOK ***/
                            {
                                printf("\nStandart Odalarimiz Dolmustur.Lutfen Farkli Oda Tipi Seciniz\n");
                                BosOdaTekrar=0;
                                OdaTekrar=1;
                            }
                            else
                            {
                                OdaTekrar=0;
                                BosOdaTekrar=1;
                            }
                            Bilgi=0;
                            while(BosOdaTekrar==1) /*** YANLIS ODA BILGISI GIRILDIGINDE DONDURULECEK DONGU BASLANGIC NOKTASI ***/
                            {
                                if(Bilgi==50)
                                {
                                    printf("\nYanlis Oda Sectiniz.Tekrar Seciniz!\n");
                                }
                                for(i=Hafta-1; i<Hafta; i++)
                                {
                                    printf("\n");
                                    for(j=1; j<100; j+=2)
                                    {
                                        if(Sonbahar[i][j]==0) /*** SONBAHAR DIZISINDEKI STANDART TIPLI ODALARIN BOS OLMA DURUMUNA GORE LISTELENMESI ***/
                                        {
                                            printf("-[%d]-",j);
                                        }
                                    }
                                    printf("\n");
                                }
                                Bilgi=0;
                                printf("\nYukardaki odalar Standart Odalara dahildir.Birini Seciniz : ");
                                scanf("%d",&OdaKayit);
                                for(i=Hafta-1; i<Hafta; i++)
                                {
                                    for(j=1; j<100; j+=2)
                                    {
                                        if(OdaKayit==j) /*** ODA NUMARASI ALINAN BILGININ STANDART ODA TIPLERI ILE ESLENMESI DURUMUNDA YAPILACAKLAR ***/
                                        {
                                            if(Sonbahar[i][j]==1) /*** ODA NUMARASI ALINAN BILGININ DAHA ONCEDEN SECILME DURUMU ***/
                                            {
                                                printf("\nSecilen Oda Daha Onceden Rezerve Edilmistir.\n");
                                            }
                                            else
                                            {
                                                BosOdaTekrar=0;
                                                if(FSaydir>=1) /*** ODA KAPASITESINDEN FAZLA GIRILDIGINDE TEKRAR MISAFIR GIRISININ ONLENMESI ICIN TEDBIR ***/
                                                {
                                                    FazlaMisafir=1;
                                                }
                                                else
                                                {
                                                    FazlaMisafir=0;
                                                }
                                                if(FazlaMisafir==0) /*** ODA KAPASITESINI ASINCA TEKRAR MISAFIR GIRISININ ISTENMEMESINI SAGLAYAN BLOK ***/
                                                {
                                                    printf("\nMisafir Sayisini Giriniz :");
                                                    scanf("%d",&KisiSayisi);
                                                    ToplamKisi=KisiSayisi;
                                                }
                                                if(KisiSayisi>4) /*** ODA KAPASITESINI ASINCA ISLEMLERIN YAPILACAGI DONGU BLOGU ***/
                                                {
                                                    Sonbahar[i][OdaKayit]=1; /*** ORNEGIN:SONBAHAR[1][3]=1; 1. HAFTA 3. ODA NUMARASINI DOLU YAP ***/
                                                    if(Dolu[Hafta-1]==0) /*** ORN:DOLU[1]=0 DOLU DIZISININ 1.HAFTASINDA DEGER YOKSA YAPILACAK ISLEMLER ***/
                                                    {
                                                        Dolu[Hafta-1]=++DoluSaydir;
                                                        SDolu[Hafta-1]=++SDoluSaydir;
                                                        DoluSaydir=0;
                                                        SDoluSaydir=0;
                                                    }
                                                    else
                                                    {
                                                        Dolu[Hafta-1]+=(++DoluSaydir);
                                                        SDolu[Hafta-1]+=(++SDoluSaydir);
                                                    }
                                                    DoluSaydir=0;
                                                    SDoluSaydir=0;
                                                    KKisiSayisi=KisiSayisi-4;
                                                    KisiSayisi=KisiSayisi-4;
                                                    FazlaMisafir=1;
                                                    FSaydir++;
                                                    printf("\nStandart Odalarimiz 4 Kisi Oldugundan Kalan %d Kisi icin tekrar oda seciniz\n",KisiSayisi);
                                                    BosOdaTekrar=1;
                                                }
                                                else
                                                {
                                                    if(KKisiSayisi<5)
                                                        /*** MISAFIR SAYISI ORNEGIN:7 GIRILDIGINDE ODA KAPASITESI 4 OLDUGU ICIN KALAN 3 MISAFIR ICIN ***/
                                                        /***  TEKRAR MISAFIR GIRISINI ENGELLEMEK ICIN ALINAN DONGU TEDBIRI ***/
                                                    {
                                                        FazlaMisafir=1;
                                                        FSaydir++;
                                                    }
                                                    else
                                                    {
                                                        KKisiSayisi=5;
                                                    }
                                                    DoluSaydir=0;
                                                    SDoluSaydir=0;
                                                    Sonbahar[i][OdaKayit]=1;
                                                    if(Dolu[Hafta-1]==0) /*** ODALARIN DOLULUK ORANI ICIN TUTULAN SAYAC DONGU BLOGU ***/
                                                    {
                                                        Dolu[Hafta-1]=++DoluSaydir;
                                                        SDolu[Hafta-1]=++SDoluSaydir;
                                                    }
                                                    else
                                                    {
                                                        Dolu[Hafta-1]+=(++DoluSaydir);
                                                        SDolu[Hafta-1]+=(++SDoluSaydir);
                                                    }
                                                    OdemeSekilTekrar=1;
                                                    while(OdemeSekilTekrar==1) /*** UCRET ISLEMLERI YAPILABILMESI ICIN ACILAN DONGU BLOGU ***/
                                                    {
                                                        fflush(stdin);
                                                        printf("\nLutfen Odeme Seklini Seciniz\n");
                                                        printf("\nOn Havale islemi icin 'O' Hava islemi icin 'H' Standart islemi icin 'S' tusuna basiniz : ");
                                                        scanf("%c",&OdemeSekil);
                                                        if(OdemeSekil=='O')
                                                        {
                                                            OdemeSekilTekrar=0;
                                                            Toplam=((ToplamKisi*25)-((ToplamKisi*25)*0.15));
                                                            printf("\nOdenemeniz Gereken Tutar : %.2f$ \n",Toplam);
                                                        }
                                                        else if(OdemeSekil=='H')
                                                        {
                                                            OdemeSekilTekrar=0;
                                                            if(ToplamKisi>3)
                                                            {
                                                                Toplam=((ToplamKisi-1)*25)-((1*25)*0.5);
                                                            }
                                                            else if(ToplamKisi>5)
                                                            {
                                                                Toplam=((ToplamKisi-1)*25)-((1*25)*0.75);
                                                            }
                                                            else
                                                            {
                                                                Toplam=ToplamKisi*25;
                                                            }
                                                            printf("\nOdenemeniz Gereken Tutar : %.2f$ \n",Toplam);
                                                        }
                                                        else if(OdemeSekil=='S')
                                                        {
                                                            OdemeSekilTekrar=0;
                                                            Toplam=ToplamKisi*25;
                                                            printf("\nOdenemeniz Gereken Tutar : %.2f$ \n",Toplam);
                                                        }
                                                        else
                                                        {
                                                            OdemeSekilTekrar=1;
                                                            printf("\nYanlis Odeme Seklini Sectiniz Yaptiniz!\n");
                                                            fflush(stdin);
                                                        }
                                                    }
                                                    for(i=0; i<12; i++) /*** HAFTALARDAKI DOLULUK ORANINI GOSTEREN DONGU BLOGU ***/
                                                    {
                                                        printf("%d.Haftadaki Oteldeki Odalarin %c %d Doludur.",i+1,(char)37,Dolu[i]);
                                                        printf("\n");
                                                        DoluSaydir=0;
                                                        SDoluSaydir=0;
                                                        FSaydir=0;
                                                        KKisiSayisi=5;
                                                    }
                                                }
                                            }
                                        }
                                        else
                                        {
                                            Bilgi++;
                                        }
                                    }
                                }
                            }
                        }
                        else if(Oda=='D') /*** DELUX ODA TIPI ICIN YAPILACAK ISLEMLER ICIN BASLANGIC NOKTASI ***/
                        {
                            if(DDolu[Hafta-1]==34)
                            {
                                printf("\nDeluxe Odalarimiz Dolmustur.Lutfen Farkli Oda Tipi Seciniz\n");
                                BosOdaTekrar=0;
                                OdaTekrar=1;
                            }
                            else
                            {
                                OdaTekrar=0;
                                BosOdaTekrar=1;
                            }
                            Bilgi=0;
                            while(BosOdaTekrar==1)
                            {
                                if(Bilgi==34)
                                {
                                    printf("\nYanlis Oda Sectiniz.Tekrar Seciniz!\n");
                                }
                                for(i=Hafta-1; i<Hafta; i++)
                                {
                                    printf("\n");
                                    for(j=0; j<100; j+=2)
                                    {
                                        if((j+2)%6==0)
                                        {
                                            continue;
                                        }
                                        if(Sonbahar[i][j+2]==0)
                                        {
                                            printf("-[%d]-",j+2);
                                        }
                                    }
                                    printf("\n");
                                }
                                Bilgi=0;
                                printf("\nYukardaki odalar Delux Odalara dahildir.Birini Seciniz : ");
                                scanf("%d",&OdaKayit);
                                for(i=Hafta-1; i<Hafta; i++)
                                {
                                    for(j=0; j<100; j+=2)
                                    {
                                        if((j+2)%6==0)
                                        {
                                            continue;
                                        }
                                        if(OdaKayit==j+2)
                                        {
                                            if(Sonbahar[i][j+2]==1)
                                            {
                                                printf("\nSecilen Oda Daha Onceden Rezerve Edilmistir.\n");
                                            }
                                            else
                                            {
                                                BosOdaTekrar=0;
                                                if(FSaydir>=1)
                                                {
                                                    FazlaMisafir=1;
                                                }
                                                else
                                                {
                                                    FazlaMisafir=0;
                                                }
                                                if(FazlaMisafir==0)
                                                {
                                                    printf("\nMisafir Sayisini Giriniz :");
                                                    scanf("%d",&KisiSayisi);
                                                    ToplamKisi=KisiSayisi;
                                                }
                                                if(KisiSayisi>4)
                                                {
                                                    Sonbahar[i][OdaKayit]=1;
                                                    if(Dolu[Hafta-1]==0)
                                                    {
                                                        Dolu[Hafta-1]=++DoluSaydir;
                                                        DDolu[Hafta-1]=++DDoluSaydir;
                                                        DoluSaydir=0;
                                                        DDoluSaydir=0;
                                                    }
                                                    else
                                                    {
                                                        Dolu[Hafta-1]+=(++DoluSaydir);
                                                        DDolu[Hafta-1]+=(++DDoluSaydir);
                                                    }
                                                    DoluSaydir=0;
                                                    DDoluSaydir=0;
                                                    KKisiSayisi=KisiSayisi-4;
                                                    KisiSayisi=KisiSayisi-4;
                                                    FazlaMisafir=1;
                                                    FSaydir++;
                                                    printf("\nDeluxe Odalarimiz 4 Kisi Oldugundan Kalan %d Kisi icin tekrar oda seciniz\n",KisiSayisi);
                                                    BosOdaTekrar=1;
                                                }
                                                else
                                                {
                                                    if(KKisiSayisi<5)
                                                    {
                                                        FazlaMisafir=1;
                                                        FSaydir++;
                                                    }
                                                    else
                                                    {
                                                        KKisiSayisi=5;
                                                    }
                                                    DoluSaydir=0;
                                                    DDoluSaydir=0;
                                                    Sonbahar[i][OdaKayit]=1;
                                                    if(Dolu[Hafta-1]==0)
                                                    {
                                                        Dolu[Hafta-1]=++DoluSaydir;
                                                        DDolu[Hafta-1]=++DDoluSaydir;
                                                    }
                                                    else
                                                    {
                                                        Dolu[Hafta-1]+=(++DoluSaydir);
                                                        DDolu[Hafta-1]+=(++DDoluSaydir);
                                                    }
                                                    OdemeSekilTekrar=1;
                                                    while(OdemeSekilTekrar==1)
                                                    {
                                                        fflush(stdin);
                                                        printf("\nLutfen Odeme Seklini Seciniz\n");
                                                        printf("\nOn Havale islemi icin 'O' Hava islemi icin 'H' Standart islemi icin 'S' tusuna basiniz : ");
                                                        scanf("%c",&OdemeSekil);
                                                        if(OdemeSekil=='O')
                                                        {
                                                            OdemeSekilTekrar=0;
                                                            Toplam=((ToplamKisi*50)-((ToplamKisi*50)*0.15));
                                                            printf("\nOdenemeniz Gereken Tutar : %.2f$ \n",Toplam);
                                                        }
                                                        else if(OdemeSekil=='H')
                                                        {
                                                            OdemeSekilTekrar=0;
                                                            if(ToplamKisi>3)
                                                            {
                                                                Toplam=((ToplamKisi-1)*50)-((1*50)*0.5);
                                                            }
                                                            else if(ToplamKisi>5)
                                                            {
                                                                Toplam=((ToplamKisi-1)*50)-((1*50)*0.75);
                                                            }
                                                            else
                                                            {
                                                                Toplam=ToplamKisi*50;
                                                            }
                                                            printf("\nOdenemeniz Gereken Tutar : %.2f$ \n",Toplam);
                                                        }
                                                        else if(OdemeSekil=='S')
                                                        {
                                                            OdemeSekilTekrar=0;
                                                            Toplam=ToplamKisi*50;
                                                            printf("\nOdenemeniz Gereken Tutar : %.2f$ \n",Toplam);
                                                        }
                                                        else
                                                        {
                                                            OdemeSekilTekrar=1;
                                                            printf("\nYanlis Odeme Seklini Sectiniz Yaptiniz!\n");
                                                            fflush(stdin);
                                                        }
                                                    }
                                                    for(i=0; i<12; i++)
                                                    {
                                                        printf("%d.Haftadaki Oteldeki Odalarin %c %d Doludur.",i+1,(char)37,Dolu[i]);
                                                        printf("\n");
                                                        DoluSaydir=0;
                                                        DDoluSaydir=0;
                                                        FSaydir=0;
                                                        KKisiSayisi=5;
                                                    }
                                                }
                                            }
                                        }
                                        else
                                        {
                                            Bilgi++;
                                        }
                                    }
                                }
                            }
                        }
                        else if(Oda=='L') /*** LARGE-DELUX ODA TIPI YAPILACAK ISLEMLER ICIN BASLANGIC NOKTASI ***/
                        {
                            if(LDolu[Hafta-1]==16)
                            {
                                printf("\nLarge-Deluxe Odalarimiz Dolmustur.Lutfen Farkli Oda Tipi Seciniz\n");
                                BosOdaTekrar=0;
                                OdaTekrar=1;
                            }
                            else
                            {
                                OdaTekrar=0;
                                BosOdaTekrar=1;
                            }
                            Bilgi=0;
                            while(BosOdaTekrar==1)
                            {
                                if(Bilgi==16)
                                {
                                    printf("\nYanlis Oda Sectiniz.Tekrar Seciniz!\n");
                                }
                                for(i=Hafta-1; i<Hafta; i++)
                                {
                                    printf("\n");
                                    for(j=6; j<100; j+=6)
                                    {
                                        if(Sonbahar[i][j]==0)
                                        {
                                            printf("-[%d]-",j);
                                        }
                                    }
                                    printf("\n");
                                }
                                Bilgi=0;
                                printf("\nYukardaki odalar Large-Delux Odalara dahildir.Birini Seciniz : ");
                                scanf("%d",&OdaKayit);
                                for(i=Hafta-1; i<Hafta; i++)
                                {
                                    for(j=6; j<100; j+=6)
                                    {
                                        if(OdaKayit==j)
                                        {
                                            if(Sonbahar[i][j]==1)
                                            {
                                                printf("\nSecilen Oda Daha Onceden Rezerve Edilmistir.\n");
                                            }
                                            else
                                            {
                                                BosOdaTekrar=0;
                                                if(FSaydir>=1)
                                                {
                                                    FazlaMisafir=1;
                                                }
                                                else
                                                {
                                                    FazlaMisafir=0;
                                                }
                                                if(FazlaMisafir==0)
                                                {
                                                    printf("\nMisafir Sayisini Giriniz :");
                                                    scanf("%d",&KisiSayisi);
                                                    ToplamKisi=KisiSayisi;
                                                }
                                                if(KisiSayisi>7)
                                                {
                                                    Sonbahar[i][OdaKayit]=1;
                                                    if(Dolu[Hafta-1]==0)
                                                    {
                                                        Dolu[Hafta-1]=++DoluSaydir;
                                                        LDolu[Hafta-1]=++LDoluSaydir;
                                                        DoluSaydir=0;
                                                        LDoluSaydir=0;
                                                    }
                                                    else
                                                    {
                                                        Dolu[Hafta-1]+=(++DoluSaydir);
                                                        LDolu[Hafta-1]+=(++LDoluSaydir);
                                                    }
                                                    DoluSaydir=0;
                                                    LDoluSaydir=0;
                                                    KKisiSayisi=KisiSayisi-7;
                                                    KisiSayisi=KisiSayisi-7;
                                                    FazlaMisafir=1;
                                                    FSaydir++;
                                                    printf("\nLarge-Deluxe Odalarimiz 7 Kisi Oldugundan Kalan %d Kisi icin tekrar oda seciniz\n",KisiSayisi);
                                                    BosOdaTekrar=1;
                                                }
                                                else
                                                {
                                                    if(KKisiSayisi<8)
                                                    {
                                                        FazlaMisafir=1;
                                                        FSaydir++;
                                                    }
                                                    else
                                                    {
                                                        KKisiSayisi=8;
                                                    }
                                                    DoluSaydir=0;
                                                    LDoluSaydir=0;
                                                    Sonbahar[i][OdaKayit]=1;
                                                    if(Dolu[Hafta-1]==0)
                                                    {
                                                        Dolu[Hafta-1]=++DoluSaydir;
                                                        LDolu[Hafta-1]=++LDoluSaydir;
                                                    }
                                                    else
                                                    {
                                                        Dolu[Hafta-1]+=(++DoluSaydir);
                                                        LDolu[Hafta-1]+=(++LDoluSaydir);
                                                    }
                                                    OdemeSekilTekrar=1;
                                                     while(OdemeSekilTekrar==1)
                                                     {
                                                         fflush(stdin);
                                                         printf("\nLutfen Odeme Seklini Seciniz\n");
                                                         printf("\nOn Havale islemi icin 'O' Hava islemi icin 'H' Standart islemi icin 'S' tusuna basiniz : ");
                                                         scanf("%c",&OdemeSekil);
                                                         if(OdemeSekil=='O')
                                                         {
                                                             OdemeSekilTekrar=0;
                                                             Toplam=((ToplamKisi*250)-((ToplamKisi*250)*0.15));
                                                             printf("\nOdenemeniz Gereken Tutar : %.2f$ \n",Toplam);
                                                         }
                                                         else if(OdemeSekil=='H')
                                                         {
                                                             OdemeSekilTekrar=0;
                                                             if(ToplamKisi>3)
                                                             {
                                                                 Toplam=((ToplamKisi-1)*250)-((1*250)*0.5);
                                                             }
                                                             else if(ToplamKisi>5)
                                                             {
                                                                 Toplam=((ToplamKisi-1)*250)-((1*250)*0.75);
                                                             }
                                                             else
                                                             {
                                                                 Toplam=ToplamKisi*250;
                                                             }
                                                             printf("\nOdenemeniz Gereken Tutar : %.2f$ \n",Toplam);
                                                         }
                                                         else if(OdemeSekil=='S')
                                                         {
                                                             OdemeSekilTekrar=0;
                                                             Toplam=250;
                                                             printf("\nOdenemeniz Gereken Tutar : %.2f$ \n",Toplam);
                                                         }
                                                         else
                                                         {
                                                             OdemeSekilTekrar=1;
                                                             printf("\nYanlis Odeme Seklini Sectiniz Yaptiniz\n");
                                                             fflush(stdin);
                                                         }
                                                     }
                                                    for(i=0; i<12; i++)
                                                    {
                                                        printf("%d.Haftadaki Oteldeki Odalarin %c %d Doludur.",i+1,(char)37,Dolu[i]);
                                                        printf("\n");
                                                        DoluSaydir=0;
                                                        LDoluSaydir=0;
                                                        FSaydir=0;
                                                        KKisiSayisi=5;
                                                    }
                                                }
                                            }
                                        }
                                        else
                                        {
                                            Bilgi++;
                                        }
                                    }
                                }
                            }
                        }
                        else
                        {
                            OdaTekrar=1;
                            printf("\n Yanlis Oda Tipini Sectiniz!\n");
                            fflush(stdin);
                        }
                    }
                }
                else /*** HAFTA 1 ILE 12 ARASINDA DEGILSE YAPILACAK OLAN ISLEMLERIN BASLANGIC NOKTASI ***/
                {
                    if(Sayac==3)
                    {
                        printf("\n3 Defa Yanlis Oda Sectiniz.Sistemden Cikiliyor!\n");
                        return 0;
                    }
                    else
                    {
                        Secim=1; /*** HAFTA SECIM MENUSUNE GERI GONDERIYOR ***/
                    }
                }
            }
            SonlandirmaKontrol=1;
            while(SonlandirmaKontrol==1) /*** PROGRAMIN DEVAMLILIGINI SORMAK ICIN KULLANILAN DONGU BLOGU ***/
            {
                fflush(stdin);
                printf("\nDevam Etmek istiyormusunuz<E/H>:");
                scanf("%c",&Sonlandirma);
                if(Sonlandirma=='E')
                {
                    fflush(stdin);
                    SonlandirmaKontrol=0;
                }
                else if(Sonlandirma=='H')
                {
                    Baslangic=0;
                    SonlandirmaKontrol=0;
                    return 0;
                }
                else
                {
                    SonlandirmaKontrol=1;
                    fflush(stdin);
                }
            }
            break;
        case 'B':
            Secim=1;
            Sayac=0;
            while(Secim==1)
            {
                printf("\nBahar Ayinin kacinci haftasinda konaklama yapmak istiyorsunuz : ");
                scanf("%d",&Hafta);
                Sayac++;
                if(Hafta>=1 && Hafta<=12)
                {
                    Secim=0;
                    OdaTekrar=1;
                    while(OdaTekrar==1)
                    {
                        fflush(stdin);
                        printf("\nLutfen Oda Tipini Seciniz\n");
                        printf("Standart Oda icin 'S',Deluxe Oda icin 'D',Large Deluxe Oda icin 'L' tusuna basiniz : ");
                        scanf("%c",&Oda);
                        if(Oda=='S')
                        {
                            if(BSDolu[Hafta-1]==50)
                            {
                                printf("\nStandart Odalarimiz Dolmustur.Lutfen Farkli Oda Tipi Seciniz\n");
                                BosOdaTekrar=0;
                                OdaTekrar=1;
                            }
                            else
                            {
                                OdaTekrar=0;
                                BosOdaTekrar=1;
                            }
                            Bilgi=0;
                            while(BosOdaTekrar==1)
                            {
                                if(Bilgi==50)
                                {
                                    printf("\nYanlis Oda Sectiniz.Tekrar Seciniz!\n");
                                }
                                for(i=Hafta-1; i<Hafta; i++)
                                {
                                    printf("\n");
                                    for(j=1; j<100; j+=2)
                                    {
                                        if(Bahar[i][j]==0)
                                        {
                                            printf("-[%d]-",j);
                                        }
                                    }
                                    printf("\n");
                                }
                                Bilgi=0;
                                printf("\nYukardaki odalar Standart Odalara dahildir.Birini Seciniz : ");
                                scanf("%d",&OdaKayit);
                                for(i=Hafta-1; i<Hafta; i++)
                                {
                                    for(j=1; j<100; j+=2)
                                    {
                                        if(OdaKayit==j)
                                        {
                                            if(Bahar[i][j]==1)
                                            {
                                                printf("\nSecilen Oda Daha Onceden Rezerve Edilmistir.\n");
                                            }
                                            else
                                            {
                                                BosOdaTekrar=0;
                                                if(FSaydir>=1)
                                                {
                                                    FazlaMisafir=1;
                                                }
                                                else
                                                {
                                                    FazlaMisafir=0;
                                                }
                                                if(FazlaMisafir==0)
                                                {
                                                    printf("\nMisafir Sayisini Giriniz :");
                                                    scanf("%d",&KisiSayisi);
                                                    ToplamKisi=KisiSayisi;
                                                }
                                                if(KisiSayisi>4)
                                                {
                                                    Bahar[i][OdaKayit]=1;
                                                    if(BDolu[Hafta-1]==0)
                                                    {
                                                        BDolu[Hafta-1]=++DoluSaydir;
                                                        BSDolu[Hafta-1]=++BSDoluSaydir;
                                                        DoluSaydir=0;
                                                        BSDoluSaydir=0;
                                                    }
                                                    else
                                                    {
                                                        BDolu[Hafta-1]+=(++DoluSaydir);
                                                        BSDolu[Hafta-1]+=(++BSDoluSaydir);
                                                    }
                                                    DoluSaydir=0;
                                                    BSDoluSaydir=0;
                                                    KKisiSayisi=KisiSayisi-4;
                                                    KisiSayisi=KisiSayisi-4;
                                                    FazlaMisafir=1;
                                                    FSaydir++;
                                                    printf("\nStandart Odalarimiz 4 Kisi Oldugundan Kalan %d Kisi icin tekrar oda seciniz\n",KisiSayisi);
                                                    BosOdaTekrar=1;
                                                }
                                                else
                                                {
                                                    if(KKisiSayisi<5)
                                                    {
                                                        FazlaMisafir=1;
                                                        FSaydir++;
                                                    }
                                                    else
                                                    {
                                                        KKisiSayisi=5;
                                                    }
                                                    DoluSaydir=0;
                                                    BSDoluSaydir=0;
                                                    Bahar[i][OdaKayit]=1;
                                                    if(BDolu[Hafta-1]==0)
                                                    {
                                                        BDolu[Hafta-1]=++DoluSaydir;
                                                        BSDolu[Hafta-1]=++BSDoluSaydir;
                                                    }
                                                    else
                                                    {
                                                        BDolu[Hafta-1]+=(++DoluSaydir);
                                                        BSDolu[Hafta-1]+=(++BSDoluSaydir);
                                                    }
                                                    OdemeSekilTekrar=1;
                                                    while(OdemeSekilTekrar==1)
                                                    {
                                                        fflush(stdin);
                                                        printf("\nLutfen Odeme Seklini Seciniz\n");
                                                        printf("\nOn Havale islemi icin 'O' Hava islemi icin 'H' Standart islemi icin 'S' tusuna basiniz : ");
                                                        scanf("%c",&OdemeSekil);
                                                        if(OdemeSekil=='O')
                                                        {
                                                            OdemeSekilTekrar=0;
                                                            Toplam=((ToplamKisi*40)-((ToplamKisi*40)*0.15));
                                                            printf("\nOdenemeniz Gereken Tutar : %.2f$ \n",Toplam);
                                                        }
                                                        else if(OdemeSekil=='H')
                                                        {
                                                            OdemeSekilTekrar=0;
                                                            if(ToplamKisi>3)
                                                            {
                                                                Toplam=((ToplamKisi-1)*40)-((1*40)*0.5);
                                                            }
                                                            else if(ToplamKisi>5)
                                                            {
                                                                Toplam=((ToplamKisi-1)*40)-((1*40)*0.75);
                                                            }
                                                            else
                                                            {
                                                                Toplam=ToplamKisi*40;
                                                            }
                                                            printf("\nOdenemeniz Gereken Tutar : %.2f$ \n",Toplam);
                                                        }
                                                        else if(OdemeSekil=='S')
                                                        {
                                                            OdemeSekilTekrar=0;
                                                            Toplam=ToplamKisi*40;
                                                            printf("\nOdenemeniz Gereken Tutar : %.2f$ \n",Toplam);
                                                        }
                                                        else
                                                        {
                                                            OdemeSekilTekrar=1;
                                                            printf("\nYanlis Odeme Seklini Sectiniz Yaptiniz!\n");
                                                            fflush(stdin);
                                                        }
                                                    }
                                                    for(i=0; i<12; i++)
                                                    {
                                                        printf("%d.Haftadaki Oteldeki Odalarin %c %d Doludur.",i+1,(char)37,BDolu[i]);
                                                        printf("\n");
                                                        DoluSaydir=0;
                                                        BSDoluSaydir=0;
                                                        FSaydir=0;
                                                        KKisiSayisi=5;
                                                    }
                                                }
                                            }
                                        }
                                        else
                                        {
                                            Bilgi++;
                                        }
                                    }
                                }
                            }
                        }
                        else if(Oda=='D')
                        {
                            if(BDDolu[Hafta-1]==34)
                            {
                                printf("\nDeluxe Odalarimiz Dolmustur.Lutfen Farkli Oda Tipi Seciniz\n");
                                BosOdaTekrar=0;
                                OdaTekrar=1;
                            }
                            else
                            {
                                OdaTekrar=0;
                                BosOdaTekrar=1;
                            }
                            Bilgi=0;
                            while(BosOdaTekrar==1)
                            {
                                if(Bilgi==34)
                                {
                                    printf("\nYanlis Oda Sectiniz.Tekrar Seciniz.\n");
                                }
                                for(i=Hafta-1; i<Hafta; i++)
                                {
                                    printf("\n");
                                    for(j=0; j<100; j+=2)
                                    {
                                        if((j+2)%6==0)
                                        {
                                            continue;
                                        }
                                        if(Bahar[i][j+2]==0)
                                        {
                                            printf("-[%d]-",j+2);
                                        }
                                    }
                                    printf("\n");
                                }
                                Bilgi=0;
                                printf("\nYukardaki odalar Delux Odalara dahildir.Birini Seciniz : ");
                                scanf("%d",&OdaKayit);
                                for(i=Hafta-1; i<Hafta; i++)
                                {
                                    for(j=0; j<100; j+=2)
                                    {
                                        if((j+2)%6==0)
                                        {
                                            continue;
                                        }
                                        if(OdaKayit==j+2)
                                        {
                                            if(Bahar[i][j+2]==1)
                                            {
                                                printf("\nSecilen Oda Daha Onceden Rezerve Edilmistir.\n");
                                            }
                                            else
                                            {
                                                BosOdaTekrar=0;
                                                if(FSaydir>=1)
                                                {
                                                    FazlaMisafir=1;
                                                }
                                                else
                                                {
                                                    FazlaMisafir=0;
                                                }
                                                if(FazlaMisafir==0)
                                                {
                                                    printf("\nMisafir Sayisini Giriniz :");
                                                    scanf("%d",&KisiSayisi);
                                                    ToplamKisi=KisiSayisi;
                                                }
                                                if(KisiSayisi>4)
                                                {
                                                    Bahar[i][OdaKayit]=1;
                                                    if(BDolu[Hafta-1]==0)
                                                    {
                                                        BDolu[Hafta-1]=++DoluSaydir;
                                                        BDDolu[Hafta-1]=++BDDoluSaydir;
                                                        DoluSaydir=0;
                                                        BDDoluSaydir=0;
                                                    }
                                                    else
                                                    {
                                                        BDolu[Hafta-1]+=(++DoluSaydir);
                                                        BDDolu[Hafta-1]+=(++BDDoluSaydir);
                                                    }
                                                    DoluSaydir=0;
                                                    BDDoluSaydir=0;
                                                    KKisiSayisi=KisiSayisi-4;
                                                    KisiSayisi=KisiSayisi-4;
                                                    FazlaMisafir=1;
                                                    FSaydir++;
                                                    printf("\nDeluxe Odalarimiz 4 Kisi Oldugundan Kalan %d Kisi icin tekrar oda seciniz\n",KisiSayisi);
                                                    BosOdaTekrar=1;
                                                }
                                                else
                                                {
                                                    if(KKisiSayisi<5)
                                                    {
                                                        FazlaMisafir=1;
                                                        FSaydir++;
                                                    }
                                                    else
                                                    {
                                                        KKisiSayisi=5;
                                                    }
                                                    DoluSaydir=0;
                                                    BDDoluSaydir=0;
                                                    Bahar[i][OdaKayit]=1;
                                                    if(BDolu[Hafta-1]==0)
                                                    {
                                                        BDolu[Hafta-1]=++DoluSaydir;
                                                        BDDolu[Hafta-1]=++BDDoluSaydir;
                                                    }
                                                    else
                                                    {
                                                        BDolu[Hafta-1]+=(++DoluSaydir);
                                                        BDDolu[Hafta-1]+=(++BDDoluSaydir);
                                                    }
                                                    OdemeSekilTekrar=1;
                                                    while(OdemeSekilTekrar==1)
                                                    {
                                                        fflush(stdin);
                                                        printf("\nLutfen Odeme Seklini Seciniz\n");
                                                        printf("\nOn Havale islemi icin 'O' Hava islemi icin 'H' Standart islemi icin 'S' tusuna basiniz : ");
                                                        scanf("%c",&OdemeSekil);
                                                        if(OdemeSekil=='O')
                                                        {
                                                            OdemeSekilTekrar=0;
                                                            Toplam=((ToplamKisi*75)-((ToplamKisi*75)*0.15));
                                                            printf("\nOdenemeniz Gereken Tutar : %.2f$ \n",Toplam);
                                                        }
                                                        else if(OdemeSekil=='H')
                                                        {
                                                            OdemeSekilTekrar=0;
                                                            if(ToplamKisi>3)
                                                            {
                                                                Toplam=((ToplamKisi-1)*75)-((1*75)*0.5);
                                                            }
                                                            else if(ToplamKisi>5)
                                                            {
                                                                Toplam=((ToplamKisi-1)*75)-((1*75)*0.75);
                                                            }
                                                            else
                                                            {
                                                                Toplam=ToplamKisi*75;
                                                            }
                                                            printf("\nOdenemeniz Gereken Tutar : %.2f$ \n",Toplam);
                                                        }
                                                        else if(OdemeSekil=='S')
                                                        {
                                                            OdemeSekilTekrar=0;
                                                            Toplam=ToplamKisi*75;
                                                            printf("\nOdenemeniz Gereken Tutar : %.2f$ \n",Toplam);
                                                        }
                                                        else
                                                        {
                                                            OdemeSekilTekrar=1;
                                                            printf("\nYanlis Odeme Seklini Sectiniz Yaptiniz!\n");
                                                            fflush(stdin);
                                                        }
                                                    }
                                                    for(i=0; i<12; i++)
                                                    {
                                                        printf("%d.Haftadaki Oteldeki Odalarin %c %d Doludur.",i+1,(char)37,BDolu[i]);
                                                        printf("\n");
                                                        DoluSaydir=0;
                                                        BDDoluSaydir=0;
                                                        FSaydir=0;
                                                        KKisiSayisi=5;
                                                    }
                                                }
                                            }
                                        }
                                        else
                                        {
                                            Bilgi++;
                                        }
                                    }
                                }
                            }
                        }
                        else if(Oda=='L')
                        {
                            if(BLDolu[Hafta-1]==16)
                            {
                                printf("\nLarge-Deluxe Odalarimiz Dolmustur.Lutfen Farkli Oda Tipi Seciniz\n");
                                BosOdaTekrar=0;
                                OdaTekrar=1;
                            }
                            else
                            {
                                OdaTekrar=0;
                                BosOdaTekrar=1;
                            }
                            Bilgi=0;
                            while(BosOdaTekrar==1)
                            {
                                if(Bilgi==16)
                                {
                                    printf("\nYanlis Oda Sectiniz.Tekrar Seciniz!\n");
                                }
                                for(i=Hafta-1; i<Hafta; i++)
                                {
                                    printf("\n");
                                    for(j=6; j<100; j+=6)
                                    {
                                        if(Bahar[i][j]==0)
                                        {
                                            printf("-[%d]-",j);
                                        }
                                    }
                                    printf("\n");
                                }
                                Bilgi=0;
                                printf("\nYukardaki odalar Large-Delux Odalara dahildir.Birini Seciniz : ");
                                scanf("%d",&OdaKayit);
                                for(i=Hafta-1; i<Hafta; i++)
                                {
                                    for(j=6; j<100; j+=6)
                                    {
                                        if(OdaKayit==j)
                                        {
                                            if(Bahar[i][j]==1)
                                            {
                                                printf("\nSecilen Oda Daha Onceden Rezerve Edilmistir.\n");
                                            }
                                            else
                                            {
                                                BosOdaTekrar=0;
                                                if(FSaydir>=1)
                                                {
                                                    FazlaMisafir=1;
                                                }
                                                else
                                                {
                                                    FazlaMisafir=0;
                                                }
                                                if(FazlaMisafir==0)
                                                {
                                                    printf("\nMisafir Sayisini Giriniz :");
                                                    scanf("%d",&KisiSayisi);
                                                    ToplamKisi=KisiSayisi;
                                                }
                                                if(KisiSayisi>7)
                                                {
                                                    Bahar[i][OdaKayit]=1;
                                                    if(BDolu[Hafta-1]==0)
                                                    {
                                                        BDolu[Hafta-1]=++DoluSaydir;
                                                        BLDolu[Hafta-1]=++BLDoluSaydir;
                                                        DoluSaydir=0;
                                                        BLDoluSaydir=0;
                                                    }
                                                    else
                                                    {
                                                        BDolu[Hafta-1]+=(++DoluSaydir);
                                                        BLDolu[Hafta-1]+=(++BLDoluSaydir);
                                                    }
                                                    DoluSaydir=0;
                                                    BLDoluSaydir=0;
                                                    KKisiSayisi=KisiSayisi-7;
                                                    KisiSayisi=KisiSayisi-7;
                                                    FazlaMisafir=1;
                                                    FSaydir++;
                                                    printf("\nLarge-Deluxe Odalarimiz 7 Kisi Oldugundan Kalan %d Kisi icin tekrar oda seciniz\n",KisiSayisi);
                                                    BosOdaTekrar=1;
                                                }
                                                else
                                                {
                                                    if(KKisiSayisi<8)
                                                    {
                                                        FazlaMisafir=1;
                                                        FSaydir++;
                                                    }
                                                    else
                                                    {
                                                        KKisiSayisi=8;
                                                    }
                                                    DoluSaydir=0;
                                                    BLDoluSaydir=0;
                                                    Bahar[i][OdaKayit]=1;
                                                    if(BDolu[Hafta-1]==0)
                                                    {
                                                        BDolu[Hafta-1]=++DoluSaydir;
                                                        BLDolu[Hafta-1]=++BLDoluSaydir;
                                                    }
                                                    else
                                                    {
                                                        BDolu[Hafta-1]+=(++DoluSaydir);
                                                        BLDolu[Hafta-1]+=(++BLDoluSaydir);
                                                    }

                                                    OdemeSekilTekrar=1;
                                                     while(OdemeSekilTekrar==1)
                                                     {
                                                         fflush(stdin);
                                                         printf("\nLutfen Odeme Seklini Seciniz\n");
                                                         printf("\nOn Havale islemi icin 'O' Hava islemi icin 'H' Standart islemi icin 'S' tusuna basiniz : ");
                                                         scanf("%c",&OdemeSekil);
                                                         if(OdemeSekil=='O')
                                                         {
                                                             OdemeSekilTekrar=0;
                                                             Toplam=((ToplamKisi*300)-((ToplamKisi*300)*0.15));
                                                             printf("\nOdenemeniz Gereken Tutar : %.2f$ \n",Toplam);
                                                         }
                                                         else if(OdemeSekil=='H')
                                                         {
                                                             OdemeSekilTekrar=0;
                                                             if(ToplamKisi>3)
                                                             {
                                                                 Toplam=((ToplamKisi-1)*300)-((1*300)*0.5);
                                                             }
                                                             else if(ToplamKisi>5)
                                                             {
                                                                 Toplam=((ToplamKisi-1)*300)-((1*300)*0.75);
                                                             }
                                                             else
                                                             {
                                                                 Toplam=ToplamKisi*300;
                                                             }
                                                             printf("\nOdenemeniz Gereken Tutar : %.2f$ \n",Toplam);
                                                         }
                                                         else if(OdemeSekil=='S')
                                                         {
                                                             OdemeSekilTekrar=0;
                                                             Toplam=300;
                                                             printf("\nOdenemeniz Gereken Tutar : %.2f$ \n",Toplam);
                                                         }
                                                         else
                                                         {
                                                             OdemeSekilTekrar=1;
                                                             printf("\nYanlis Odeme Seklini Sectiniz Yaptiniz\n");
                                                             fflush(stdin);
                                                         }
                                                     }
                                                    for(i=0; i<12; i++)
                                                    {
                                                        printf("%d.Haftadaki Oteldeki Odalarin %c %d Doludur.",i+1,(char)37,BDolu[i]);
                                                        printf("\n");
                                                        DoluSaydir=0;
                                                        BLDoluSaydir=0;
                                                        FSaydir=0;
                                                        KKisiSayisi=5;
                                                    }
                                                }
                                            }
                                        }
                                        else
                                        {
                                            Bilgi++;
                                        }
                                    }
                                }
                            }
                        }
                        else
                        {
                            OdaTekrar=1;
                            printf("\nYanlis Oda Tipi Sectiniz!\n");
                            fflush(stdin);
                        }
                    }
                }
                else
                {
                    if(Sayac==3)
                    {
                        printf("\n3 Defa Yanlis Oda Sectiniz.Sistemden Cikiliyor!\n");
                        return 0;
                    }
                    else
                    {
                        Secim=1;
                    }
                }
            }
            SonlandirmaKontrol=1;
            while(SonlandirmaKontrol==1)
            {
                fflush(stdin);
                printf("\nDevam Etmek istiyormusunuz<E/H>:");
                scanf("%c",&Sonlandirma);
                if(Sonlandirma=='E')
                {
                    fflush(stdin);
                    SonlandirmaKontrol=0;
                }
                else if(Sonlandirma=='H')
                {
                    Baslangic=0;
                    SonlandirmaKontrol=0;
                    return 0;
                }
                else
                {
                    SonlandirmaKontrol=1;
                    fflush(stdin);
                }
            }
            break;
        case 'Y':
            Secim=1;
            Sayac=0;
            while(Secim==1)
            {
                printf("\nYaz Ayinin kacinci haftasinda konaklama yapmak istiyorsunuz : ");
                scanf("%d",&Hafta);
                Sayac++;
                if(Hafta>=1 && Hafta<=12)
                {
                    Secim=0;
                    OdaTekrar=1;
                    while(OdaTekrar==1)
                    {
                        fflush(stdin);
                        printf("\nLutfen Oda Tipini Seciniz\n");
                        printf("Standart Oda icin 'S',Deluxe Oda icin 'D',Large Deluxe Oda icin 'L' tusuna basiniz : ");
                        scanf("%c",&Oda);
                        if(Oda=='S')
                        {
                            if(YSDolu[Hafta-1]==50)
                            {
                                printf("\nStandart Odalarimiz Dolmustur.Lutfen Farkli Oda Tipi Seciniz\n");
                                BosOdaTekrar=0;
                                OdaTekrar=1;
                            }
                            else
                            {
                                OdaTekrar=0;
                                BosOdaTekrar=1;

                            }
                            Bilgi=0;
                            while(BosOdaTekrar==1)
                            {
                                if(Bilgi==50)
                                {
                                    printf("\nYanlis Oda Sectiniz.Tekrar Seciniz!\n");
                                }
                                for(i=Hafta-1; i<Hafta; i++)
                                {
                                    printf("\n");
                                    for(j=1; j<100; j+=2)
                                    {
                                        if(Yaz[i][j]==0)
                                        {
                                            printf("-[%d]-",j);
                                        }
                                    }
                                    printf("\n");
                                }
                                Bilgi=0;
                                printf("\nYukardaki odalar Standart Odalara dahildir.Birini Seciniz : ");
                                scanf("%d",&OdaKayit);
                                for(i=Hafta-1; i<Hafta; i++)
                                {
                                    for(j=1; j<100; j+=2)
                                    {
                                        if(OdaKayit==j)
                                        {
                                            if(Yaz[i][j]==1)
                                            {
                                                printf("\nSecilen Oda Daha Onceden Rezerve Edilmistir.\n");
                                            }
                                            else
                                            {
                                                BosOdaTekrar=0;
                                                if(FSaydir>=1)
                                                {
                                                    FazlaMisafir=1;
                                                }
                                                else
                                                {
                                                    FazlaMisafir=0;
                                                }
                                                if(FazlaMisafir==0)
                                                {
                                                    printf("\nMisafir Sayisini Giriniz :");
                                                    scanf("%d",&KisiSayisi);
                                                    ToplamKisi=KisiSayisi;
                                                }
                                                if(KisiSayisi>4)
                                                {
                                                    Yaz[i][OdaKayit]=1;
                                                    if(YDolu[Hafta-1]==0)
                                                    {
                                                        YDolu[Hafta-1]=++DoluSaydir;
                                                        YSDolu[Hafta-1]=++YSDoluSaydir;
                                                        DoluSaydir=0;
                                                        YSDoluSaydir=0;
                                                    }
                                                    else
                                                    {
                                                        YDolu[Hafta-1]+=(++DoluSaydir);
                                                        YSDolu[Hafta-1]+=(++YSDoluSaydir);
                                                    }
                                                    DoluSaydir=0;
                                                    YSDoluSaydir=0;
                                                    KKisiSayisi=KisiSayisi-4;
                                                    KisiSayisi=KisiSayisi-4;
                                                    FazlaMisafir=1;
                                                    FSaydir++;
                                                    printf("\nStandart Odalarimiz 4 Kisi Oldugundan Kalan %d Kisi icin tekrar oda seciniz\n",KisiSayisi);
                                                    BosOdaTekrar=1;
                                                }
                                                else
                                                {
                                                    if(KKisiSayisi<5)
                                                    {
                                                        FazlaMisafir=1;
                                                        FSaydir++;
                                                    }
                                                    else
                                                    {
                                                        KKisiSayisi=5;
                                                    }
                                                    DoluSaydir=0;
                                                    YSDoluSaydir=0;
                                                    Yaz[i][OdaKayit]=1;
                                                    if(YDolu[Hafta-1]==0)
                                                    {
                                                        YDolu[Hafta-1]=++DoluSaydir;
                                                        YSDolu[Hafta-1]=++YSDoluSaydir;
                                                    }
                                                    else
                                                    {
                                                        YDolu[Hafta-1]+=(++DoluSaydir);
                                                        YSDolu[Hafta-1]+=(++YSDoluSaydir);
                                                    }
                                                    OdemeSekilTekrar=1;
                                                    while(OdemeSekilTekrar==1)
                                                    {
                                                        fflush(stdin);
                                                        printf("\nLutfen Odeme Seklini Seciniz\n");
                                                        printf("\nOn Havale islemi icin 'O' Hava islemi icin 'H' Standart islemi icin 'S' tusuna basiniz : ");
                                                        scanf("%c",&OdemeSekil);
                                                        if(OdemeSekil=='O')
                                                        {
                                                            OdemeSekilTekrar=0;
                                                            Toplam=((ToplamKisi*60)-((ToplamKisi*60)*0.15));
                                                            printf("\nOdenemeniz Gereken Tutar : %.2f$ \n",Toplam);
                                                        }
                                                        else if(OdemeSekil=='H')
                                                        {
                                                            OdemeSekilTekrar=0;
                                                            if(ToplamKisi>3)
                                                            {
                                                                Toplam=((ToplamKisi-1)*60)-((1*60)*0.5);
                                                            }
                                                            else if(ToplamKisi>5)
                                                            {
                                                                Toplam=((ToplamKisi-1)*60)-((1*60)*0.75);
                                                            }
                                                            else
                                                            {
                                                                Toplam=ToplamKisi*60;
                                                            }
                                                            printf("\nOdenemeniz Gereken Tutar : %.2f$ \n",Toplam);
                                                        }
                                                        else if(OdemeSekil=='S')
                                                        {
                                                            OdemeSekilTekrar=0;
                                                            Toplam=ToplamKisi*60;
                                                            printf("\nOdenemeniz Gereken Tutar : %.2f$ \n",Toplam);
                                                        }
                                                        else
                                                        {
                                                            OdemeSekilTekrar=1;
                                                            printf("\nYanlis Odeme Seklini Sectiniz Yaptiniz!\n");
                                                            fflush(stdin);
                                                        }
                                                    }
                                                    for(i=0; i<12; i++)
                                                    {
                                                        printf("%d.Haftadaki Oteldeki Odalarin %c %d Doludur.",i+1,(char)37,YDolu[i]);
                                                        printf("\n");
                                                        DoluSaydir=0;
                                                        YSDoluSaydir=0;
                                                        FSaydir=0;
                                                        KKisiSayisi=5;
                                                    }
                                                }
                                            }
                                        }
                                        else
                                        {
                                            Bilgi++;
                                        }
                                    }
                                }
                            }
                        }
                        else if(Oda=='D')
                        {
                            if(YDDolu[Hafta-1]==34)
                            {
                                printf("\nDeluxe Odalarimiz Dolmustur.Lutfen Farkli Oda Tipi Seciniz\n");
                                BosOdaTekrar=0;
                                OdaTekrar=1;
                            }
                            else
                            {
                                OdaTekrar=0;
                                BosOdaTekrar=1;
                            }
                            Bilgi=0;
                            while(BosOdaTekrar==1)
                            {
                                if(Bilgi==34)
                                {
                                    printf("\nYanlis Oda Sectiniz.Tekrar Seciniz!\n");
                                }
                                for(i=Hafta-1; i<Hafta; i++)
                                {
                                    printf("\n");
                                    for(j=0; j<100; j+=2)
                                    {
                                        if((j+2)%6==0)
                                        {
                                            continue;
                                        }
                                        if(Yaz[i][j+2]==0)
                                        {
                                            printf("-[%d]-",j+2);
                                        }
                                    }
                                    printf("\n");
                                }
                                Bilgi=0;
                                printf("\nYukardaki odalar Delux Odalara dahildir.Birini Seciniz : ");
                                scanf("%d",&OdaKayit);
                                for(i=Hafta-1; i<Hafta; i++)
                                {
                                    for(j=0; j<100; j+=2)
                                    {
                                        if((j+2)%6==0)
                                        {
                                            continue;
                                        }
                                        if(OdaKayit==j+2)
                                        {
                                            if(Yaz[i][j+2]==1)
                                            {
                                                printf("\nSecilen Oda Daha Onceden Rezerve Edilmistir.\n");
                                            }
                                            else
                                            {
                                                BosOdaTekrar=0;
                                                if(FSaydir>=1)
                                                {
                                                    FazlaMisafir=1;
                                                }
                                                else
                                                {
                                                    FazlaMisafir=0;
                                                }
                                                if(FazlaMisafir==0)
                                                {
                                                    printf("\nMisafir Sayisini Giriniz :");
                                                    scanf("%d",&KisiSayisi);
                                                    ToplamKisi=KisiSayisi;
                                                }
                                                if(KisiSayisi>4)
                                                {
                                                    Yaz[i][OdaKayit]=1;
                                                    if(YDolu[Hafta-1]==0)
                                                    {
                                                        YDolu[Hafta-1]=++DoluSaydir;
                                                        YDDolu[Hafta-1]=++YDDoluSaydir;
                                                        DoluSaydir=0;
                                                        YDDoluSaydir=0;
                                                    }
                                                    else
                                                    {
                                                        YDolu[Hafta-1]+=(++DoluSaydir);
                                                        YDDolu[Hafta-1]+=(++YDDoluSaydir);
                                                    }
                                                    DoluSaydir=0;
                                                    YDDoluSaydir=0;
                                                    KKisiSayisi=KisiSayisi-4;
                                                    KisiSayisi=KisiSayisi-4;
                                                    FazlaMisafir=1;
                                                    FSaydir++;
                                                    printf("\nDeluxe Odalarimiz 4 Kisi Oldugundan Kalan %d Kisi icin tekrar oda seciniz\n",KisiSayisi);
                                                    BosOdaTekrar=1;
                                                }
                                                else
                                                {
                                                    if(KKisiSayisi<5)
                                                    {
                                                        FazlaMisafir=1;
                                                        FSaydir++;
                                                    }
                                                    else
                                                    {
                                                        KKisiSayisi=5;
                                                    }
                                                    DoluSaydir=0;
                                                    YDDoluSaydir=0;
                                                    Yaz[i][OdaKayit]=1;
                                                    if(YDolu[Hafta-1]==0)
                                                    {
                                                        YDolu[Hafta-1]=++DoluSaydir;
                                                        YDDolu[Hafta-1]=++YDDoluSaydir;
                                                    }
                                                    else
                                                    {
                                                        YDolu[Hafta-1]+=(++DoluSaydir);
                                                        YDDolu[Hafta-1]+=(++YDDoluSaydir);
                                                    }
                                                    OdemeSekilTekrar=1;
                                                    while(OdemeSekilTekrar==1)
                                                    {
                                                        fflush(stdin);
                                                        printf("\nLutfen Odeme Seklini Seciniz\n");
                                                        printf("\nOn Havale islemi icin 'O' Hava islemi icin 'H' Standart islemi icin 'S' tusuna basiniz : ");
                                                        scanf("%c",&OdemeSekil);
                                                        if(OdemeSekil=='O')
                                                        {
                                                            OdemeSekilTekrar=0;
                                                            Toplam=((ToplamKisi*90)-((ToplamKisi*90)*0.15));
                                                            printf("\nOdenemeniz Gereken Tutar : %.2f$ \n",Toplam);
                                                        }
                                                        else if(OdemeSekil=='H')
                                                        {
                                                            OdemeSekilTekrar=0;
                                                            if(ToplamKisi>3)
                                                            {
                                                                Toplam=((ToplamKisi-1)*90)-((1*90)*0.5);
                                                            }
                                                            else if(ToplamKisi>5)
                                                            {
                                                                Toplam=((ToplamKisi-1)*90)-((1*90)*0.75);
                                                            }
                                                            else
                                                            {
                                                                Toplam=ToplamKisi*90;
                                                            }
                                                            printf("\nOdenemeniz Gereken Tutar : %.2f$ \n",Toplam);
                                                        }
                                                        else if(OdemeSekil=='S')
                                                        {
                                                            OdemeSekilTekrar=0;
                                                            Toplam=ToplamKisi*90;
                                                            printf("\nOdenemeniz Gereken Tutar : %.2f$ \n",Toplam);
                                                        }
                                                        else
                                                        {
                                                            OdemeSekilTekrar=1;
                                                            printf("\nYanlis Odeme Seklini Sectiniz Yaptiniz!\n");
                                                            fflush(stdin);
                                                        }
                                                    }
                                                    for(i=0; i<12; i++)
                                                    {
                                                        printf("%d.Haftadaki Oteldeki Odalarin %c %d Doludur.",i+1,(char)37,YDolu[i]);
                                                        printf("\n");
                                                        DoluSaydir=0;
                                                        YDDoluSaydir=0;
                                                        FSaydir=0;
                                                        KKisiSayisi=5;
                                                    }
                                                }
                                            }
                                        }
                                        else
                                        {
                                            Bilgi++;
                                        }
                                    }
                                }
                            }
                        }
                        else if(Oda=='L')
                        {
                            if(YLDolu[Hafta-1]==16)
                            {
                                printf("\nLarge-Deluxe Odalarimiz Dolmustur.Lutfen Farkli Oda Tipi Seciniz\n");
                                BosOdaTekrar=0;
                                OdaTekrar=1;
                            }
                            else
                            {
                                OdaTekrar=0;
                                BosOdaTekrar=1;
                            }
                            Bilgi=0;
                            while(BosOdaTekrar==1)
                            {
                                if(Bilgi==16)
                                {
                                    printf("\nYanlis Oda Sectiniz.Tekrar Seciniz!\n");
                                }
                                for(i=Hafta-1; i<Hafta; i++)
                                {
                                    printf("\n");
                                    for(j=6; j<100; j+=6)
                                    {
                                        if(Yaz[i][j]==0)
                                        {
                                            printf("-[%d]-",j);
                                        }
                                    }
                                    printf("\n");
                                }
                                Bilgi=0;
                                printf("\nYukardaki odalar Large-Delux Odalara dahildir.Birini Seciniz : ");
                                scanf("%d",&OdaKayit);
                                for(i=Hafta-1; i<Hafta; i++)
                                {
                                    for(j=6; j<100; j+=6)
                                    {
                                        if(OdaKayit==j)
                                        {
                                            if(Yaz[i][j]==1)
                                            {
                                                printf("\nSecilen Oda Daha Onceden Rezerve Edilmistir.\n");
                                            }
                                            else
                                            {
                                                BosOdaTekrar=0;
                                                if(FSaydir>=1)
                                                {
                                                    FazlaMisafir=1;
                                                }
                                                else
                                                {
                                                    FazlaMisafir=0;
                                                }
                                                if(FazlaMisafir==0)
                                                {
                                                    printf("\nMisafir Sayisini Giriniz :");
                                                    scanf("%d",&KisiSayisi);
                                                    ToplamKisi=KisiSayisi;
                                                }
                                                if(KisiSayisi>7)
                                                {
                                                    Yaz[i][OdaKayit]=1;
                                                    if(YDolu[Hafta-1]==0)
                                                    {
                                                        YDolu[Hafta-1]=++DoluSaydir;
                                                        YLDolu[Hafta-1]=++YLDoluSaydir;
                                                        DoluSaydir=0;
                                                        YLDoluSaydir=0;
                                                    }
                                                    else
                                                    {
                                                        YDolu[Hafta-1]+=(++DoluSaydir);
                                                        YLDolu[Hafta-1]+=(++YLDoluSaydir);
                                                    }
                                                    DoluSaydir=0;
                                                    YLDoluSaydir=0;
                                                    KKisiSayisi=KisiSayisi-7;
                                                    KisiSayisi=KisiSayisi-7;
                                                    FazlaMisafir=1;
                                                    FSaydir++;
                                                    printf("\nLarge-Deluxe Odalarimiz 7 Kisi Oldugundan Kalan %d Kisi icin tekrar oda seciniz\n",KisiSayisi);
                                                    BosOdaTekrar=1;
                                                }
                                                else
                                                {
                                                    if(KKisiSayisi<8)
                                                    {
                                                        FazlaMisafir=1;
                                                        FSaydir++;
                                                    }
                                                    else
                                                    {
                                                        KKisiSayisi=8;
                                                    }
                                                    DoluSaydir=0;
                                                    YLDoluSaydir=0;
                                                    Yaz[i][OdaKayit]=1;
                                                    if(YDolu[Hafta-1]==0)
                                                    {
                                                        YDolu[Hafta-1]=++DoluSaydir;
                                                        YLDolu[Hafta-1]=++YLDoluSaydir;
                                                    }
                                                    else
                                                    {
                                                        YDolu[Hafta-1]+=(++DoluSaydir);
                                                        YLDolu[Hafta-1]+=(++YLDoluSaydir);
                                                    }
                                                    OdemeSekilTekrar=1;
                                                    while(OdemeSekilTekrar==1)
                                                     {
                                                         fflush(stdin);
                                                         printf("\nLutfen Odeme Seklini Seciniz\n");
                                                         printf("\nOn Havale islemi icin 'O' Hava islemi icin 'H' Standart islemi icin 'S' tusuna basiniz : ");
                                                         scanf("%c",&OdemeSekil);
                                                         if(OdemeSekil=='O')
                                                         {
                                                             OdemeSekilTekrar=0;
                                                             Toplam=((ToplamKisi*400)-((ToplamKisi*400)*0.15));
                                                             printf("\nOdenemeniz Gereken Tutar : %.2f$ \n",Toplam);
                                                         }
                                                         else if(OdemeSekil=='H')
                                                         {
                                                             OdemeSekilTekrar=0;
                                                             if(ToplamKisi>3)
                                                             {
                                                                 Toplam=((ToplamKisi-1)*400)-((1*400)*0.5);
                                                             }
                                                             else if(ToplamKisi>5)
                                                             {
                                                                 Toplam=((ToplamKisi-1)*400)-((1*400)*0.75);
                                                             }
                                                             else
                                                             {
                                                                 Toplam=ToplamKisi*400;
                                                             }
                                                             printf("\nOdenemeniz Gereken Tutar : %.2f$ \n",Toplam);
                                                         }
                                                         else if(OdemeSekil=='S')
                                                         {
                                                             OdemeSekilTekrar=0;
                                                             Toplam=400;
                                                             printf("\nOdenemeniz Gereken Tutar : %.2f$ \n",Toplam);
                                                         }
                                                         else
                                                         {
                                                             OdemeSekilTekrar=1;
                                                             printf("\nYanlis Odeme Seklini Sectiniz Yaptiniz\n");
                                                             fflush(stdin);
                                                         }
                                                     }
                                                    for(i=0; i<12; i++)
                                                    {
                                                        printf("%d.Haftadaki Oteldeki Odalarin %c %d Doludur.",i+1,(char)37,YDolu[i]);
                                                        printf("\n");
                                                        DoluSaydir=0;
                                                        YLDoluSaydir=0;
                                                        FSaydir=0;
                                                        KKisiSayisi=5;
                                                    }
                                                }
                                            }
                                        }
                                        else
                                        {
                                            Bilgi++;
                                        }
                                    }
                                }
                            }
                        }
                        else
                        {
                            OdaTekrar=1;
                            printf("\nYanlis Oda Tip Sectiniz!\n");
                            fflush(stdin);
                        }
                    }
                }
                else
                {
                    if(Sayac==3)
                    {
                        printf("\n3 Defa Yanlis Oda Sectiniz.Sistemden Cikiliyor!\n");
                        return 0;
                    }
                    else
                    {
                        Secim=1;
                    }
                }
            }
            SonlandirmaKontrol=1;
            while(SonlandirmaKontrol==1)
            {
                fflush(stdin);
                printf("\nDevam Etmek istiyormusunuz<E/H>:");
                scanf("%c",&Sonlandirma);
                if(Sonlandirma=='E')
                {
                    fflush(stdin);
                    SonlandirmaKontrol=0;
                }
                else if(Sonlandirma=='H')
                {
                    Baslangic=0;
                    SonlandirmaKontrol=0;
                    return 0;
                }
                else
                {
                    SonlandirmaKontrol=1;
                    fflush(stdin);
                }
            }
            break;
        default:
        {
            printf("\nYanlis Mevsim Tusu Bastiniz!\n");
            fflush(stdin);
            Baslangic=1;
        }
        }
    }
    return 0;
}
