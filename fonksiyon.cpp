/*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*/

// Ad         : Ahmed Said
// Soyad      : YILDIRIMER
// ��renci no : 17110131002

/*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <iomanip>
#include <locale.h>
#include "HavaYolu.h"
#include "dosyalama.h"
#include "fonksiyon.h"
#define maxUcusSiniri 1500
#define minUcusSiniri 1348
using namespace std;

void belirleSeferNo(int s)
{
	
	//u�u� numaras�n� SistemBilgileri.txt ye kaydetmek i�in kullan�lan fonksiyon
	
	int k,m;
	fstream oku("SistemBilgileri.txt",ios::in);
	oku>>m>>k;
	oku.close();	
	fstream sefer("SistemBilgileri.txt",ios::out);
	sefer.setf(ios::left);
	sefer<<setw(6)<<s<<k;
	sefer.close();
}

void belirleMusteriId(int koltuk)
{
	
	//m��teri ID numaras�n� SistemBilgileri.txt ye kaydetmek i�in kullan�lan fonksiyon
	
	int k,m;
	fstream oku("SistemBilgileri.txt",ios::in);
	oku>>m>>k;
	oku.close();
	fstream sefer("SistemBilgileri.txt",ios::out);
	sefer.setf(ios::left);
	sefer<<setw(6)<<m<<koltuk;
	sefer.close();
}

string getirSeferNo()
{
	
	//u�u� numaras�n� SistemBilgileri.txt den  getirmek i�in kullan�lan fonksiyon
	
	string s;
	fstream sefer("SistemBilgileri.txt",ios::in);
	if(!sefer)
	{
		belirleSeferNo(minUcusSiniri);
		belirleMusteriId(1);
		return "1348";
	}
	else{
		sefer>>s;
		return s;
	}
}

string getirMusteriId()
{
	
	//m��teri ID numaras�n� SistemBilgileri.txt den getirmek i�in kullan�lan fonksiyon
	
	string s,k;
	fstream sefer("SistemBilgileri.txt",ios::in);
	if(!sefer)
	{
		belirleSeferNo(minUcusSiniri);
		belirleMusteriId(1);
		return "1";
	}
	else{
		sefer>>s>>k;
		return k;
	}
}

void fabrikaAyarlari()
{
	
	//txt dosyalar�n�n i�indeki verileri bo�altmak i�in kullan�lan fonskiyon
	
	string a;
		cout<<"Program� fabrika verilerine d�nd�rmek istiyorsan�z \"ONAYLIYORUM\" yaz�n�z = ";
		cin>>a;
	if(a=="ONAYLIYORUM"){	
		fstream d1( "Ucuslar.txt", ios::out );
		fstream d2( "SistemBilgileri.txt", ios::out);
		fstream d3("Yolcular.txt",ios::out);
		fstream d4("GenelListe.txt",ios::out);
		d2.setf(ios::left);
		d2<<setw(6)<<1348<<1;
		d1.close();
		d2.close();
		d3.close();
		d4.close();
		cout<<"Program fabrika verilenrine ba�ar�yla d�nd�r�lm��t�r."<<endl;
	}
	else cout<<"Program fabrika verilerine d�nd�rme i�lemi iptal edilmi�tir."<<endl;
}

void clearScreen()	
{
	
	//system("cls"); ekran� temizlemek i�in kullan�yorum(yaz�lar� yukar� kayd�r�yor temiz bir ekran g�r�n�yor)
	
	for(int i=0;i<100;i++)
	{
		cout<<"\n";
	}
}
