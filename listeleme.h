/*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*/

// Ad         : Ahmed Said
// Soyad      : YILDIRIMER
// ��renci no : 17110131002

/*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*/
#ifndef LISTELEME_H
#define LISTELEME_H
#include <iostream>
#include "havayolu.h"
using namespace std;

int musteriListele(musteri musteriListesi[]);
	//m��terileri ekranda g�stermek i�in kullan�lan fonksiyon.
	
int ucusListele(ucak ucakListesi[],musteri musteriListesi[]);
	//u�u�lar� ekranda listelemek i�in kullan�lan fonksiyon
	
void genelListe(musteri musteriListesi[],ucak ucakListesi[]);
	//u�u�lara g�re yolcular� d�zenli bir �ekilde ekrana yazd�rmak i�in kullan�lan fonksiyon
	
string koltukListe(string sefer,musteri musteriListesi[],int koltukSayisi,int l);
	//U�u�un bo� koltuklar�n� bulmak ve ekran da g�stermek i�in kullan�lan fonksiyon
	
#endif
