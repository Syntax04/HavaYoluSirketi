/*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*/

// Ad         : Ahmed Said
// Soyad      : YILDIRIMER
// ��renci no : 17110131002

/*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <iomanip>
#include <locale.h>
#include <ctype.h>

#include "menu.h"
#include "dosyalama.h"
#include "fonksiyon.h"
#include "listeleme.h"
#include "HavaYolu.h"

#define maxUcusSiniri 1500

using namespace std;

int main() 
{
	setlocale(LC_ALL,"Turkish");

	ucak ucuslar[maxUcusSiniri];
	musteri musteriler[16000];
	cout<<"BU PROGRAM W�NDOWS UYUMLU OLARAK HAZIRLANMI�TIR.\nL�NUX UYUMU ���N BA�ZI GETCHAR() fonksiyonlar�ndan dolay� sorunlar ��kabilir\nonlar�n gerekli olanlar�n� kald�r�p �al��t�rabilisiniz.\n\n\n";
	char islem;
	for(;1;)
	{
		islem=anaMenu();
		if(islem==1)//listelerin bulundu�u men�
		{
			
			for(;islem!=0;)
			{
				islem=ucusListeMenu();
				ucusOku(ucuslar);
				musteriOku(musteriler);
				if(islem==1)
				{
					clearScreen();
					ucusListele(ucuslar,musteriler);
				}
				else if(islem==2)
				{
					clearScreen();
					musteriListele(musteriler);
				}
				else if(islem==3)
				{
					clearScreen();
					genelListe(musteriler,ucuslar);
				}
				else if(islem==0)
				{
					clearScreen();
					cout<<"\n�st men�ye ��k�l�yor.\n";
				}
				else
				{
					clearScreen();
					cout<<"\nGe�ersiz i�lem girdiniz!\n";
				}
			}
		}
		else if(islem==2)//bilet i�lemleri men�s�
		{
			for(;islem!=0;)
			{
				
				islem=biletMenu();
				if(islem==1)
				{
					clearScreen();
					ucusOku(ucuslar);
					musteriOku(musteriler);
					biletSatis(musteriler,ucuslar);
				}
				else if(islem==2)
				{
					//bilet g�ncelleme 1
					clearScreen();
					ucusOku(ucuslar);
					musteriOku(musteriler);
					musteriGuncelle(ucuslar,musteriler,1);
				}
				else if(islem ==3)
				{
					//bilet silme 2
					clearScreen();
					ucusOku(ucuslar);
					musteriOku(musteriler);
					musteriGuncelle(ucuslar,musteriler,2);
				}
				else if(islem==0)
				{
					clearScreen();
					cout<<"\n�st men�ye ��k�l�yor.\n";
				}
				else
				{
					clearScreen();
					cout<<"Ge�ersiz i�lem girdiniz!\n";
				}
			}
		}
		else if(islem==3)//u�u� i�lemleri men�s�
		{
			for(;islem!=0;){
				islem=ucakMenu();
				if(islem==1)
				{
					clearScreen();
					ucusOku(ucuslar);
					ucusEkle(ucuslar);
				}
				else if(islem==2)
				{
					clearScreen();
					//u�u� g�ncelleme (1)
					ucusOku(ucuslar);
					musteriOku(musteriler);
					ucusGuncelle(ucuslar,musteriler,1);
				}
				else if(islem==3)
				{
					clearScreen();
					//u�u� silme (2)
					ucusOku(ucuslar);
					musteriOku(musteriler);
					ucusGuncelle(ucuslar,musteriler,2);
				}
				else if(islem==0)
				{
					clearScreen();
					cout<<"�st men�ye ��k�l�yor.\n";
				}
				else{
					cout<<"Ge�ersiz i�lem girdiniz!\n";
				}
				
			}
		}
		else if(islem==4)//dosyalar� silme
		{
			clearScreen();
			fabrikaAyarlari();
		}
		else if(islem==0)//programdan ��k��
		{
			clearScreen();
			ucusOku(ucuslar);
			musteriOku(musteriler);
			genelListeGuncelle(musteriler,ucuslar);
			
			cout<<"Program Sonland�r�ld�!";
			return 0;
		}
		else
		{
			clearScreen();
			cout<<"Ge�ersiz i�lem yapt�n�z!\n";
		}
	}

}
