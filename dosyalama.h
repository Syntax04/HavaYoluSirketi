/*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*/

// Ad         : Ahmed Said
// Soyad      : YILDIRIMER
// ��renci no : 17110131002

/*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*/

#ifndef DOSYALAMA_H_
#define DOSYALAMA_H_
#include <iostream>
#include "havayolu.h"
using namespace std;

void ucusGuncelle(ucak ucakListesi[],musteri musteriListesi[],int islemTuru);
		//u�u� verilerini g�ncelleyen-silen fonksiyon
		
		
void genelListeGuncelle(musteri musteriListesi[],ucak ucakListesi[]);
		//GenelListe.txt sine u�u� ve m��teri bilgilerini yazan fonksiyon
		
		
void musteriGuncelle(ucak ucakListesi[],musteri musteriListesi[],int islemTuru);
		//m��teri bilgierini g�ncelleme-silme i�in kullan�lan fonksiyon
		
		
void ucusEkle(ucak ucakListesi[]);
		//yeni u�u� kayd� olu�turmak i�in kullan�lan fonksiyon
		
		
void ucusOku(ucak ucakListesi[]);
		//txt dosyas�ndaki u�u� verilerini diziye aktarmak i�in olan fonksiyon
		
		
void musteriOku(musteri musteriListesi[]);
		//txt dosyas�ndaki m��teri verilerini diziye aktarmak i�in olan fonksiyon
		

void biletSatis(musteri musteriListesi[],ucak ucakListesi[]);		
		//m��teriye bilet sat��� yapmak i�in kullan�lan fonksiyon
		
#endif
