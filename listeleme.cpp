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
#include "HavaYolu.h"
#include "dosyalama.h"
#include "fonksiyon.h"
#include "listeleme.h"
#define maxUcusSiniri 1500
#define minUcusSiniri 1348

using namespace std;

int musteriListele(musteri musteriListesi[])
{
	
	//m��terileri ekranda g�stermek i�in kullan�lan fonksiyon.
	
	int islem=0;
	for(int i=0;i<atoi(getirMusteriId().c_str());i++)
	{			
		if(musteriListesi[i].getirUcusNo()!="\0")
		{
			cout.setf(ios::left);
			if(islem==0)
			{
				cout<<"\n\n* * * * * * * * * * * * * * * * * * * * M��TER�  L�STES� * * * * * * * * * * * * * * * * * * *\n";
				cout<<setw(10)<<"U�U� NO"<<setw(35)<<"ADI"<<setw(35)<<"SOYADI"<<setw(15)<<"KOLTUK NO"<<"\n";
				islem=1;
			}
			cout<<setw(10)<<musteriListesi[i].getirUcusNo()
			<<setw(35)<<musteriListesi[i].getirAd()
			<<setw(35)<<musteriListesi[i].getirSoyad()
			<<setw(15)<<musteriListesi[i].getirKoltukNo()<<"\n";
		}
		
	}
	if(islem==0)
	{
		cout<<"Hi�bir yolcu verisi bulunmaktad�r!\n";
		return 0;
	}
	else
	{
		return 1;
	}
}

int ucusListele(ucak ucakListesi[],musteri musteriListesi[])
{
	
	//u�u�lar� ekranda listelemek i�in kullan�lan fonksiyon
	
	int giris=0;
	
	for(int i=minUcusSiniri;i<atoi(getirSeferNo().c_str());i++)
	{
		if(ucakListesi[i].getirUcusNo()!="\0")
		{
			if(giris==0)
			{
				cout<<"\n\n* * * * * * * * * * * * * * * * * * * * U�U�  L�STES� * * * * * * * * * * * * * * * * * * *\n";
				cout.setf(ios::left);
				cout<<setw(10)<<"U�U� NO"<<setw(35)<<"KALKI� YER�"<<setw(35)<<"VARI� YER�"<<setw(15)<<"KOLTUK SAYISI"<<setw(15)<<"BO� KOLTUK SAYISI"<<"\n";
				giris=1;
			}
			int adet=0;
			for(int m=1;m<atoi(getirMusteriId().c_str());m++)
			{
				if(musteriListesi[m].getirUcusNo()==ucakListesi[i].getirUcusNo())
				{
					adet++;
				}
			} 
			cout<<setw(10)<<ucakListesi[i].getirUcusNo()
			<<setw(35)<<ucakListesi[i].getirKalkisYeri()
			<<setw(35)<<ucakListesi[i].getirVarisYeri()
			<<setw(15)<<ucakListesi[i].getirKoltukSayisi()
			<<setw(15)<<atoi(ucakListesi[i].getirKoltukSayisi().c_str())-adet<<endl;
		}
	}
	if(giris==0)
	{
		cout<<"U�u� verisi bulunmamaktad�r!\n";
		return 0;
	}
	else{
		return 1;
	}
	cout<<"\n";
}


void genelListe(musteri musteriListesi[],ucak ucakListesi[])
{
	
	//u�u�lara g�re yolcular� d�zenli bir �ekilde ekrana yazd�rmak i�in kullan�lan fonksiyon
	
	int liste[200]={0};
	for(int i=1348,s=0;i<atoi(getirSeferNo().c_str());i++)
	{
		if(ucakListesi[i].getirUcusNo()!="\0")
		{
			liste[s]=atoi(ucakListesi[i].getirUcusNo().c_str());
			s++;
		}
	}
	if(liste[0]!=0)
	{
		cout<<"\n\n* * * * * * * * * * * * * * * * * * * * U�U�  L�STES� * * * * * * * * * * * * * * * * * * * *\n";
		for(int i=0;liste[i]!=0;i++)
		{
			cout.setf(ios::left);
			cout<<setw(10)<<"U�U� NO"<<setw(35)<<"KALKI� YER�"<<setw(35)<<"VARI� YER�"<<setw(15)<<"KOLTUK SAYISI"<<"\n";	
			cout<<setw(10)<<ucakListesi[liste[i]].getirUcusNo()
			<<setw(35)<<ucakListesi[liste[i]].getirKalkisYeri()
			<<setw(35)<<ucakListesi[liste[i]].getirVarisYeri()
			<<setw(15)<<ucakListesi[liste[i]].getirKoltukSayisi()<<"\n\n";
			int s=0;
			for(int l=0;l<atoi(getirMusteriId().c_str());l++)
			{
				
				if(ucakListesi[liste[i]].getirUcusNo()==musteriListesi[l].getirUcusNo())
				{
					if(s==0)
					{
						cout<<setw(35)<<"ADI"<<setw(35)<<"SOYADI"<<setw(15)<<"KOLTUK NO"<<"\n";
						s=1;
					}
					cout<<setw(35)<<musteriListesi[l].getirAd()
					<<setw(35)<<musteriListesi[l].getirSoyad()
					<<setw(15)<<musteriListesi[l].getirKoltukNo()<<"\n";
				}
			}
			if(s==0)
			{
				cout<<"\t\t\tBu u�u� da hi�bir yolcu bulunmamaktad�r.";
			}
			cout<<"\n*********************************************************************************************\n";
		}
	}
	else
	{
		cout<<"Hi�bir u�u� verisi bulunmamaktad�r!\n";
	}
	
}


string koltukListe(string sefer,musteri musteriListesi[],int koltukSayisi,int l)
{
	
	//U�u�un bo� koltuklar�n� bulmak ve ekran da g�stermek i�in kullan�lan fonksiyon
	
	int dizi[101]={};
	
	for(int i=0;i<atoi(getirMusteriId().c_str());i++)
	{	
		if(musteriListesi[i].getirUcusNo()==sefer)
		{
			dizi[atoi(musteriListesi[i].getirKoltukNo().c_str())]= atoi(musteriListesi[i].getirKoltukNo().c_str());
		}
	} 
	dizi[l]=0;
		
	int boy=1,sonuc=0;
	
	for (int m=1;m<=koltukSayisi;m++)
	{
		if(m!=dizi[m])
		{
			sonuc=1;
			break;
		}
	}
	
	if(sonuc==1)
	{
		cout<<"\n\nKOLTUK D�ZEN�\n\n";
		for(int k=1;k<=koltukSayisi;k++)
		{
			if(k!=dizi[k])
			{
				if(k==100)
				{
					cout<<"| "<<k<<" |";
				}
				else
				{
					if(k<10)
					{
						if(boy==1)
						{
							cout<<"|   "<<k<<" |";
						}
						else if(boy==2)
						{
							cout<<"|   "<<k<<" |   ";
						}
						else if(boy==3)
						{
							cout<<"   |   "<<k<<" |";
						}
						else if(boy==4){
							cout<<"|   "<<k<<" |";
						}
					}
				
					else
					{
						if(boy==1)
						{
							cout<<"|  "<<k<<" |";
						}
						else if(boy==2)
						{
							cout<<"|  "<<k<<" |   ";
						}
						else if(boy==3)
						{
							cout<<"   |  "<<k<<" |";
						}
						else if(boy==4){
							cout<<"|  "<<k<<" |";
						}
					}
				}
			}
			else
			{
				if(k<10)
				{
					if(boy==1)
					{
						cout<<"|     |";
					}
					else if(boy==2)
					{
						cout<<"|     |   ";
					}
					else if(boy==3)
					{
						cout<<"   |     |";
					}
					else if(boy==4){
						cout<<"|     |";
					}
				}	
				else
				{
					if(boy==1)
					{
						cout<<"|     |";
					}
					else if(boy==2)
					{
						cout<<"|     |   ";
					}
					else if(boy==3)
					{
						cout<<"   |     |";
					}
					else if(boy==4){
						cout<<"|     |";
					}
				}
			}
			boy++;
			if(k%4==0)
			{
				cout<<"\n";
				boy=1;
			}
		
		}
		int koltuk;
	
		cout<<"\n\nKoltuk se�iniz:";
		cin>>koltuk;
		for(;koltuk==dizi[koltuk];)
		{
			cout<<"Se�ti�iniz koltuk dolu!\nTekrar koltuk se�iniz:";
			cin>>koltuk;
		}
		string skoltuk;
		stringstream donustur;
		donustur << koltuk;
		skoltuk = donustur.str();
	
		return skoltuk;
	}
	else
	{
		int koltuk=0;
		string skoltuk;
		stringstream donustur;
		donustur<<koltuk;
		skoltuk = donustur.str();
	
		return skoltuk;
	}
}
