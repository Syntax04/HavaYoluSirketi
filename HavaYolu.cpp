/*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*/

// Ad         : Ahmed Said
// Soyad      : YILDIRIMER
// ��renci no : 17110131002

/*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*/

#include "havayolu.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include "fonksiyon.h"
using namespace std;

///////////// Ucak Class� fonksiyon tan�mlamas� ba�lang�� /////////////////

void ucak::belirleKalkisYeri()
{
	
	// Bu fonksiyon u�a��n nerede kalk�� yapaca��n� belirlemek i�in kullan�l�r.	

	string ky;
	char character[31];
	for(int b=0,durum=0;durum==0;)
	{
		if(b==0)
		{
			cout<<"Kalk�� yeri: ";
			b=1;
		}
		else
		{
			cout<<"Tekrar Kalk�� yeri:";
		}
		getline(cin,ky);
		ky.copy(character,ky.size());
		if(ky.size()>30)
		{
			cout<<"Kalk�� yerini �ok uzun girdiniz!.(max 30 karakter)\n";
		}
		else{
			for(int i=0;i<ky.size();i++)
			{
				durum=1;
				if(!isalpha(character[i]))
				{
					if(character[i]!=' ')
					{
						durum=0;
						cout<<"Sadece harf giriniz!\n";
						break;
					}
				}
			}
		}
	}
	
	for(int i=ky.size();i<31;i++)
	{
		kalkisYeri[i]=0;
	}
	ky.copy(kalkisYeri,ky.size());
}

void ucak::belirleVarisYeri()
{
	
	//Bu fonksiyon u�a��n nereye gidece�ini belirlemek i�in kullan�l�r.
	
	string vy;
	char character[31];
	for(int b=0,durum=0;durum==0;)
	{
		if(b==0)
		{
			cout<<"Var�� yeri: ";
		}
		else
		{
			cout<<"Tekrar var�� yeri:";
		}
		getline(cin,vy);
		vy.copy(character,vy.size());
		if(vy.size()>30)
		{
			cout<<"Var�� yerini �ok uzun girdiniz!.(max 30 karakter)\n";
		}
		else{
			for(int i=0;i<vy.size();i++)
			{
				durum=1;
				if(!isalpha(character[i]))
				{
					if(character[i]!=' ')
					{
						durum=0;
						cout<<"Sadece harf giriniz!\n";
						break;
					}
				}
			}
		}
	}
	for(int i=vy.size();i<31;i++)
	{
		varisYeri[i]=0;
	}
	vy.copy(varisYeri,vy.size());
}

void ucak::belirleKoltukSayisi()
{
	
	//Bu fonksiyon u�a��n yolcu kapasitesini belirlemek i�in kullan�l�r.
	
	int i=0,sayimi=1;
	string kar;
	char character[3];
	for(;sayimi==1;)
	{
		for(int z=0;z<3;z++)
		{
			character[z]=0;
		}
		cout<<"Koltuk Say�s�: ";
		getline(cin,kar);
		kar.copy(character,3);
		for(sayimi=0,i=0;i<kar.size();i++)
		{
			if(!isdigit(character[i]))
			{
				sayimi=1;
				break;
			}
		}
		i=atoi(character);
		if(sayimi==1){
			
			cout<<"Sadece rakam giriniz!.\n";
		}
		else if(i>100 || i<1 || i%4!=0)
		{
			sayimi=1;
			cout<<"Girdi�iniz koltuk say�l� bir u�ak bulunamad�!.(4'�n kat� koltuk say�s� olmal� ve 100 den k���k olmal�)\n";
		}
		
	}
	for(int i=kar.size();i<3;i++)
	{
		koltukSayisi[i]=0;
	}
	koltukSayisi[0]=character[0];
	if(i>9)
	{
		koltukSayisi[1]=character[1];
	}
	else if(i==100)
	{
		koltukSayisi[2]=character[2];
	}
}

void ucak::belirleUcusNo()
{
	
	//Bu fonksiyon u�a��n u�u� numaras�n� belirlemek i�in kullan�l�r.
	
	string u = getirSeferNo();
	for(int i=u.size();i<6;i++)
	{
		ucusNo[i]=0;
	}
	u.copy(ucusNo,u.size());
}

void ucak::belirleKalkisYeri(string ky)
{
	
	//U�u�' un kalk�� yerini dosyadan okunup class'a aktarmak i�in kullan�lan fonksiyon.
	
	for(int i=ky.size();i<31;i++)
	{
		kalkisYeri[i]=0;
	}
	ky.copy(kalkisYeri,ky.size());
}

void ucak::belirleVarisYeri(string vy)
{
	
	//U�u�' un var�� yerini dosyadan okunup class'a aktarmak i�in kullan�lan fonksiyon.
	
	for(int i=vy.size();i<31;i++)
	{
		varisYeri[i]=0;
	}
	vy.copy(varisYeri,vy.size());
}

void ucak::belirleKoltukSayisi(string ks)
{
	
	//U�u�' un koltuk say�s�n� dosyadan okunup class'a aktarmak i�in kullan�lan fonksiyon.
	
	for(int i=ks.size();i<4;i++)
	{
		koltukSayisi[i]=0;
	}
	ks.copy(koltukSayisi,ks.size());
}

void ucak::belirleUcusNo(string un)
{
	
	//U�u�' un u�u� no sunu dosyadan okunup class'a aktarmak i�in kullan�lan fonksiyon.
	
	for(int i=un.size();i<6;i++)
	{
		ucusNo[i]=0;
	}
	un.copy(ucusNo,un.size());
}



string ucak::getirKalkisYeri()
{
	return kalkisYeri;
}

string ucak::getirVarisYeri()
{
	return varisYeri;
}

string ucak::getirUcusNo()
{
	return ucusNo;
}

string ucak::getirKoltukSayisi()
{
	return koltukSayisi;
}

ucak::ucak()
{
	belirleUcusNo("\0");
	belirleKalkisYeri("");
	belirleVarisYeri("");
	belirleKoltukSayisi("");
}


///////////// Ucak Class� fonksiyon tan�mlamas� biti� /////////////////

///////////// M��teri Class� fonksiyon tan�mlamas� ba�lang�� /////////////////

void musteri::belirleAd()
{
	
	//Bu fonksiyon m��terinin ad�n� belirlemek i�in kullan�l�r.
	
	string a;
	char character[21];
	for(int b=0,durum=0;durum==0;)
	{
		if(b==0)
		{
			cout<<"Ad�: ";
		}
		else
		{
			cout<<"Tekrar Ad�:";
		}
		getline(cin,a);
		a.copy(character,a.size());
		if(a.size()>20)
		{
			cout<<"Ad�n� �ok uzun girdiniz!.(max 20 karakter)\n";
		}
		else{
			for(int i=0;i<a.size();i++)
			{
				durum=1;
				if(!isalpha(character[i]))
				{
					if(character[i]!=' ')
					{
						durum=0;
						cout<<"Sadece harf giriniz!\n";
						break;
					}
				}
			}
		}
	}
	for(int i=a.size();i<21;i++)
	{
		ad[i]=0;
	}
	a.copy(ad,a.size());
}

void musteri::belirleSoyad()
{
	
	//Bu fonksiyon m��terinin soyad�n� belirlemek i�in kullan�l�r.
	
	string s;
	char character[21];
	for(int b=0,durum=0;durum==0;)
	{
		if(b==0)
		{
			cout<<"Soyad�: ";
		}
		else
		{
			cout<<"Tekrar Soyad�:";
		}
		getline(cin,s);
		s.copy(character,s.size());
		if(s.size()>20)
		{
			cout<<"Soyad�n� �ok uzun girdiniz!.(max 20 karakter)\n";
		}
		else{
			for(int i=0;i<s.size();i++)
			{
				durum=1;
				if(!isalpha(character[i]))
				{
					if(character[i]!=' ')
					{
						durum=0;
						cout<<"Sadece harf giriniz!\n";
						break;
					}
				}
			}
		}
	}
	for(int i=s.size();i<21;i++)
	{
		soyad[i]=0;
	}
	s.copy(soyad,s.size());
}

void musteri::belirleAd(string a)
{
	
	//Bu fonksiyon m��terinin ad�n� belirlemek i�in kullan�l�r.
	
	for(int i=a.size();i<21;i++)
	{
		ad[i]=0;
	}
	a.copy(ad,a.size());
}

void musteri::belirleSoyad(string s)
{
	
	//Bu fonksiyon m��terinin soyad�n� belirlemek i�in kullan�l�r.
	
	for(int i=s.size();i<21;i++)
	{
		soyad[i]=0;
	}
	s.copy(soyad,s.size());
}


void musteri::belirleMusteriId(string m)
{
	
	//M��teriye belirli bir id vermek i�in kullan�l�r.
	
	for(int i=m.size();i<5;i++)
	{
		musteriId[i]=0;
	}
	m.copy(musteriId,m.size());
}

void musteri::belirleKoltukNo(string k)
{	

	//M��terinin koltuk numaras�n� belirlemek i�in kullan�l�r.
	
	for(int i=k.size();i<4;i++)
	{
		koltukNo[i]=0;
	}
	k.copy(koltukNo,k.size());
}

void musteri::belirleUcusNoMusteri(string u)
{
	
	//M��terinin hangi u�u�'a ait oldu�unu belirlemek i�in kullan�l�r.
	for(int i=u.size();i<6;i++)
	{
		ucusNoM[i]=0;
	}
	u.copy(ucusNoM,u.size());
}

string musteri::getirAd()
{
	return ad;
}

string musteri::getirSoyad()
{
	return soyad;
}

string musteri::getirKoltukNo()
{
	return koltukNo;
}

string musteri::getirUcusNo()
{
	return ucusNoM;
}

string musteri::getirMusteriId()
{
	return musteriId;
}


musteri::musteri()
{
	belirleAd("\0");
	belirleSoyad("");
	belirleKoltukNo("");
	belirleUcusNoMusteri("");
	belirleMusteriId("");
}

///////////// M��teri Class� fonksiyon tan�mlamas� biti� /////////////////
