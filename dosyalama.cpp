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
#include "listeleme.h"
#define maxUcusSiniri 1500
#define minUcusSiniri 1348

using namespace std;

////////////////////////////////////////////// U�U� G�NCELLEME BA�LANGI� //////////////////////////////////////////////

void ucusGuncelle(ucak ucakListesi[],musteri musteriListesi[],int islemTuru) 
{
	
	//u�u� verilerini g�ncelleyen-silen fonksiyon
	
	// islem 1 g�ncelleme islem 2 silme
	int bos=ucusListele(ucakListesi,musteriListesi);
	if(bos==1) 
	{
		int liste[200]= {0};
		int islem=0;
		string sefer;
		
		for(int i=minUcusSiniri,s=0; i<atoi(getirSeferNo().c_str()); i++) 
		{
			if(ucakListesi[i].getirUcusNo()!="\0") 		//t�m u�u�lar�n u�ul no lar�n� listeye at�yorum
			{
				liste[s]=atoi(ucakListesi[i].getirUcusNo().c_str());
				s++;
			}
		}
		
		if(islemTuru==1) 
		{
			cout<<"G�ncelleme istedi�iniz u�u� no:";
		}
		else 
		{
			cout<<"Silmek istedi�iniz u�u� no:";
		}
		getchar();
		getline(cin,sefer);
		for(int i=0; liste[i]!=0; i++) 
		{
			if(liste[i]==atoi(sefer.c_str())) 
			{
				islem=1;
				break;
			}
		}
		
		if(islem==0) 
		{
			cout<<"Ge�ersiz u�u� no girdiniz!\n";
			return;
		}
		
		int is=atoi(sefer.c_str());
		
		if(islemTuru==2) 
		{
			cout<<"Silme i�lemine devam etmek i�in \"ONAYLIYORUM\" yaz�n�z(bu u�u�a ait t�m yolcu kay�tlar�n�da silmi� olursunuz!):";
			string o;
			getline(cin,o);
			if(o=="ONAYLIYORUM")		//u�u� kayd�n� siliyorum
			{
				ucakListesi[is].belirleUcusNo("00000");
			} 
			else 
			{
				cout<<"Silme i�lemi iptal edildi!";
				return;
			}
		} 
		else if(islemTuru==1) 
		{
			int musteriMax=0;
				
			cout<<"\n\n"<<setw(10)<<"U�U� NO"<<setw(35)<<"KALKI� YER�"<<setw(35)<<"VARI� YER�"<<setw(15)<<"KOLTUK SAYISI"<<"\n";
			cout<<setw(10)<<ucakListesi[is].getirUcusNo()
			<<setw(35)<<ucakListesi[is].getirKalkisYeri()
			<<setw(35)<<ucakListesi[is].getirVarisYeri()
			<<setw(15)<<ucakListesi[is].getirKoltukSayisi()	
			<<"\nolan u�u�un yeni bilgileri:\n\n";
			ucakListesi[is].belirleUcusNo(ucakListesi[is].getirUcusNo());
			ucakListesi[is].belirleKalkisYeri();
			ucakListesi[is].belirleVarisYeri();
						
						//u�u� kayd�n� g�ncelliyorum	

			for(int i=0;i<atoi(getirMusteriId().c_str()); i++) 
			{
				if( musteriListesi[i].getirUcusNo()==sefer && atoi(musteriListesi[i].getirKoltukNo().c_str())>musteriMax) 
				{
					musteriMax= atoi(musteriListesi[i].getirKoltukNo().c_str());	//se�ilen u�u�un ka��nc� koltu�a kadar sat�ld���n� buluyorum
				}
			}
			
			if(musteriMax<100) //koltuk g�ncelliyorum
			{
				string ks;

				if(musteriMax!=0) 
				{
					cout<<"Yeni koltuk say�s�n� giriniz ("<<musteriMax<<". koltu�a kadar bilet sat��� yap�lm��t�r):";
				} 
				else 
				{
					cout<<"Yeni koltuk say�s�n� giriniz:";
				}
				getline(cin,ks);
				if(atoi(ks.c_str())>0 && atoi(ks.c_str())<=100 && atoi(ks.c_str())%4==0 && musteriMax<atoi(ks.c_str())) 
				{
					ucakListesi[is].belirleKoltukSayisi(ks);
					islem=1;
				} 
				else 
				{
					for(int islem=0; islem==0 || atoi(ks.c_str())%4!=0;) 
					{
						if(musteriMax>atoi(ks.c_str())) 
						{
							cout<<musteriMax<<". koltu�a kadar bilet sat�lm��t�r!\nBilet say�s�n� "<<ks.c_str()<<" e d���remezsiniz!\nTekrar giriniz:";
							getline(cin,ks);
						}
						else if(atoi(ks.c_str())%4!=0 || atoi(ks.c_str())<0 || atoi(ks.c_str())>100  ) 
						{
							cout<<"Girdi�iniz koltuk say�l� bir u�ak bulunamad�!.(4'�n kat� koltuk say�s� olmal� ve 100 den k���k olmal�)\nTekrar giriniz:";
							getline(cin,ks);
						}
						if(atoi(ks.c_str())>0 && atoi(ks.c_str())<=100 && atoi(ks.c_str())%4==0 && musteriMax<=atoi(ks.c_str())) 
						{
							ucakListesi[is].belirleKoltukSayisi(ks);
							islem=1;
						}
					}
				}
			}
		}

		fstream yazma("Ucuslar.txt",ios::out);
		for(int i=minUcusSiniri; i<atoi(getirSeferNo().c_str()); i++) 
		{
			if(ucakListesi[i].getirUcusNo()!="00000" && i!=is && ucakListesi[i].getirUcusNo()!="") 
			{
				yazma.setf(ios::left);
				string a,b,c,d;
				if(ucakListesi[i].getirUcusNo()!="")
				{
					a=ucakListesi[i].getirUcusNo()+";";
					b=ucakListesi[i].getirKalkisYeri()+";";
					c=ucakListesi[i].getirVarisYeri()+";";
					d=ucakListesi[i].getirKoltukSayisi();
					yazma<<a<<b<<c<<d<<endl;
				}
				
			}
		}
		
		if(islemTuru==1) 
		{
			string a,b,c,d;
			a=ucakListesi[is].getirUcusNo()+";";
			b=ucakListesi[is].getirKalkisYeri()+";";
			c=ucakListesi[is].getirVarisYeri()+";";
			d=ucakListesi[is].getirKoltukSayisi();
			yazma<<a<<b<<c<<d<<endl;
			cout<<"Kay�t ba�ar�yla g�ncelendi!\n";
		}
		else 
		{
			fstream musteriSilme("Yolcular.txt",ios::out);
			for(int i=1;i<atoi(getirMusteriId().c_str());i++)
			{
				if(musteriListesi[i].getirUcusNo()!=sefer)
				{
					string a,b,c,d,e;
					if(musteriListesi[i].getirAd()!="")
					{
						a=musteriListesi[i].getirMusteriId()+";";
						b=musteriListesi[i].getirUcusNo()+";";
						c=musteriListesi[i].getirSoyad()+";";
						d=musteriListesi[i].getirAd()+";";
						e=musteriListesi[i].getirKoltukNo();
						musteriSilme<<a<<b<<c<<d<<e<<endl;
					}
					
				}
			}
			
			musteriSilme.close();
			cout<<"U�u� ve yolcu kay�tlar� ba�ar�yla silindi!\n";
		}
		yazma.close();
	}

}

////////////////////////////////////////////// U�U� G�NCELLEME B�T�� //////////////////////////////////////////////



///////////////////////////////////////// GENEL L�STE G�NCELLEME BA�LANGI� ////////////////////////////////////////

void genelListeGuncelle(musteri musteriListesi[],ucak ucakListesi[])
{
	
	//GenelListe.txt sine u�u� ve m��teri bilgilerini yazan fonksiyon
	
	fstream genelListeDosyalama("GenelListe.txt",ios::out);
	genelListeDosyalama.setf(ios::left);
	for(int i=minUcusSiniri;i<atoi(getirSeferNo().c_str());i++)
	{
		if(ucakListesi[i].getirKalkisYeri()!="")
		{
			genelListeDosyalama<<setw(10)<<"U�U� NO"<<setw(31)<<"KALKI� YER�"<<setw(31)<<"VARI� YER�"<<setw(15)<<"KOLTUK SAYISI"<<setw(15)<<"YOLCU SAYISI"<<"\n";
			fstream musteriAdet("Yolcular.txt",ios::in);
			int adetDizi[100]={0};
			int adet=0;
			for(int m=1;m<atoi(getirMusteriId().c_str());m++)
			{
				if(musteriListesi[m].getirUcusNo()==ucakListesi[i].getirUcusNo())
				{
					adetDizi[adet]=atoi(musteriListesi[m].getirMusteriId().c_str());
					adet++;
				}
			} 
			genelListeDosyalama<<setw(10)<<ucakListesi[i].getirUcusNo()
			<<setw(31)<<ucakListesi[i].getirKalkisYeri()
			<<setw(31)<<ucakListesi[i].getirVarisYeri()
			<<setw(15)<<ucakListesi[i].getirKoltukSayisi()
			<<setw(15)<<adet<<"\n\n";
			if(adet==0)
			{
				genelListeDosyalama<<"                            Bu u�u�da yolcu kayd� bulunmamaktad�r!"<<endl;
			}
			else
			{
				genelListeDosyalama<<setw(15)<<"KOLTUK NO"<<setw(25)<<"SOYAD"<<setw(25)<<"AD"<<endl;
			}
			for(int k=0;k<adet;k++)
			{
				genelListeDosyalama<<setw(15)<<musteriListesi[adetDizi[k]].getirKoltukNo()
				<<setw(25)<<musteriListesi[adetDizi[k]].getirSoyad()
				<<setw(25)<<musteriListesi[adetDizi[k]].getirAd()<<endl;
			}
			genelListeDosyalama<<"***************************************************************************************************"<<endl;
		}
	}
	genelListeDosyalama.close();
}

///////////////////////////////////////// GENEL L�STE G�NCELLEME B�T�� ////////////////////////////////////////



///////////////////////////////////////// M��TER� G�NCELLEME BA�LANGI� ////////////////////////////////////////

void musteriGuncelle(ucak ucakListesi[],musteri musteriListesi[],int islemTuru)	
{	

	//m��teri bilgierini g�ncelleme-silme i�in kullan�lan fonksiyon
	
	
	int b1=ucusListele(ucakListesi,musteriListesi);	
	if(b1==1)
	{
		cout<<"D�zenleyece�iniz m��teri'nin sefer numaras�n� giriniz:";
		string ucusNoGiris;
		getchar();
		getline(cin,ucusNoGiris);
		int islem=0;
		for(int i=minUcusSiniri;i<atoi(getirSeferNo().c_str()) && islem==0;i++)
		{
			if(ucakListesi[i].getirUcusNo()==ucusNoGiris)
			{
				islem=1;
			}
		}
		if(islem==1)
		{
			int yolcu=0;
			
			for(int i=1;i<atoi(getirMusteriId().c_str());i++)
			{
				if(musteriListesi[i].getirUcusNo()==ucusNoGiris)
				{
					cout.setf(ios::left);
					if(yolcu==0)
					{
						cout<<setw(5)<<"ID"<<setw(10)<<"U�U� NO"<<setw(35)<<"ADI"<<setw(35)<<"SOYADI"<<setw(15)<<"KOLTUK NO"<<"\n";
						yolcu=1;
					}
					cout<<setw(5)<<musteriListesi[i].getirMusteriId()
					<<setw(10)<<musteriListesi[i].getirUcusNo()
					<<setw(35)<<musteriListesi[i].getirAd()
					<<setw(35)<<musteriListesi[i].getirSoyad()
					<<setw(15)<<musteriListesi[i].getirKoltukNo()<<endl;
				}
			}
			
			if(yolcu==0)
			{
				cout<<"Girdi�iniz Sefer numaras�nda hi�bir yolcu bulunmamaktad�r!\n";
			}
			else{
				cout<<"M��terinin id'sini giriniz:";
				string musteriGncllm;
				getline(cin,musteriGncllm);
				int s= atoi(musteriGncllm.c_str());
				int is = atoi(ucusNoGiris.c_str());
				
				if(musteriListesi[s].getirMusteriId()==musteriGncllm && musteriListesi[s].getirUcusNo()==ucusNoGiris)
				{
					if(islemTuru==1)
					{
						//g�ncelleme
						cout<<"\nAd�:          "<<musteriListesi[s].getirAd()
						<<"\nSoyad�:       "<<musteriListesi[s].getirSoyad()
						<<"\nKoltuk no'su: "<<musteriListesi[s].getirKoltukNo()
						<<"\nolan m��terinin yeni\n";
						string a;
						cout<<"Ad�: ";
						getline(cin,a);
						for(;a.size()>20;)
						{
							cout<<"Ad�n� �ok uzun girdiniz!.(max 20 karakter)\nTekrar ad�:";
							getline(cin,a);
						}
						musteriListesi[s].belirleAd(a);
						musteriListesi[s].belirleSoyad();
						string koltukSonuc=koltukListe(ucakListesi[is].getirUcusNo(),musteriListesi,atoi(ucakListesi[is].getirKoltukSayisi().c_str()),atoi(musteriListesi[s].getirKoltukNo().c_str()));
						musteriListesi[s].belirleKoltukNo(koltukSonuc);
					}
					else
					{
						//silme
						cout<<"U�u� numaras�:"<<musteriListesi[s].getirUcusNo()
						<<"\nAd�:          "<<musteriListesi[s].getirAd()
						<<"\nSoyad�:       "<<musteriListesi[s].getirSoyad()
						<<"\nKoltuk no'su: "<<musteriListesi[s].getirKoltukNo()
						<<"\nolan m��teriyi silmek i�in \"ONAYLIYORUM\" yaz�n�z:";
						string as;
						getline(cin,as);
						
						if(as=="ONAYLIYORUM")
						{
							musteriListesi[s].belirleUcusNoMusteri("00000");
						}
					}
					fstream yazici("Yolcular.txt",ios::out);
					
					for(int z=1;z<atoi(getirMusteriId().c_str());z++)
					{
						if(musteriListesi[z].getirUcusNo()!="00000" && musteriListesi[z].getirAd()!="")
						{
							string a,b,c,d,e;
							a=musteriListesi[z].getirMusteriId()+";";
							b=musteriListesi[z].getirUcusNo()+";";
							c=musteriListesi[z].getirSoyad()+";";
							d=musteriListesi[z].getirAd()+";";
							e=musteriListesi[z].getirKoltukNo();
							yazici<<a<<b<<c<<d<<e<<endl;
						}
					}
					
					yazici.close();	
					
					if(islemTuru==1)
					{
						cout<<"Kay�t ba�ar�yla g�ncellendi!\n";
					}
					else if(musteriListesi[s].getirUcusNo()=="00000"){
						cout<<"Kay�t ba�ar�yla silindi!\n";
					}
					else{
						cout<<"Silme i�lemi iptal edildi!";
					}	
				}
				else
				{
					cout<<"Ge�ersiz m��teri ID si!\n";
				}
			}
		}
		else
		{
			cout<<"girdi�iniz sefer numaral� u�u� bulunamad�!\n";
		}
	}
}

/////////////////////////////////////////// M��TER� G�NCELLEME B�T�� //////////////////////////////////////////



//////////////////////////////////////////// U�U� EKLEME BA�LANGI� ///////////////////////////////////////////

void ucusEkle(ucak ucakListesi[]) 
{
	
	//yeni u�u� kayd� olu�turmak i�in kullan�lan fonksiyon
	
	int indi;
	indi=atoi(getirSeferNo().c_str());

	if(maxUcusSiniri>indi) 
	{

		cout<<"U�u� numaras�: "<<indi<<" olan u�u�un:\n";

		ucakListesi[indi].belirleUcusNo();
		getchar();
		ucakListesi[indi].belirleKalkisYeri();
		ucakListesi[indi].belirleVarisYeri();
		ucakListesi[indi].belirleKoltukSayisi();

		cout<<"\n\nYeni u�u� kayd� olu�turuldu.\n";

		belirleSeferNo(indi+1);
		fstream ucuslar("Ucuslar.txt", ios::app);
		
		ucuslar.setf(ios::left);
		string a,b,c,d;
		
		a=ucakListesi[indi].getirUcusNo()+";";
		b=ucakListesi[indi].getirKalkisYeri()+";";
		c=ucakListesi[indi].getirVarisYeri()+";";
		d=ucakListesi[indi].getirKoltukSayisi();
		
		ucuslar<<a<<b<<c<<d<<endl;
		ucuslar.close();
	} 
	else 
	{
		cout<<"\n\nmaximum u�u� say�s�na ula��ld�!.\n\n";
	}
}

////////////////////////////////////////////// U�U� EKLEME B�T�� /////////////////////////////////////////////


//////////////////////////////////////////// U�U� OKUMA BA�LANGI�  ///////////////////////////////////////////

void ucusOku(ucak ucakListesi[]) 
{
	
	//txt dosyas�ndaki u�u� verilerini diziye aktarmak i�in olan fonksiyon
	
	fstream ucuslarOku("Ucuslar.txt",ios::in);
	if(!ucuslarOku) 
	{
		return;
	}
	for(int i=minUcusSiniri; ucuslarOku &&!ucuslarOku.eof(); i++) 
	{
		string un,ky,vy,ks;
		getline(ucuslarOku,un,';');
		getline(ucuslarOku,ky,';');
		getline(ucuslarOku,vy,';');
		getline(ucuslarOku,ks,'\n');
		int s=atoi(un.c_str());
		ucakListesi[s].belirleUcusNo(un);
		ucakListesi[s].belirleKalkisYeri(ky);
		ucakListesi[s].belirleVarisYeri(vy);
		ucakListesi[s].belirleKoltukSayisi(ks);
	}
	ucuslarOku.close();
}

////////////////////////////////////////////// U�U� OKUMA B�T��  /////////////////////////////////////////////



/////////////////////////////////////////// M��TER� OKUMA BA�LANGI� //////////////////////////////////////////

void musteriOku(musteri musteriListesi[]) 
{
	
	//txt dosyas�ndaki m��teri verilerini diziye aktarmak i�in olan fonksiyon
	
	fstream okumaMusteri("Yolcular.txt",ios::in);
	if(!okumaMusteri) 
	{
		return;
	}
	for(int i=0; !okumaMusteri.eof(); i++) 
	{

		string mId,ad,soy,un,kn;
		getline(okumaMusteri,mId,';');
		getline(okumaMusteri,un,';');
		getline(okumaMusteri,soy,';');
		getline(okumaMusteri,ad,';');
		getline(okumaMusteri,kn,'\n');
		int s=atoi(mId.c_str());
		musteriListesi[s].belirleMusteriId(mId);
		musteriListesi[s].belirleAd(ad);
		musteriListesi[s].belirleSoyad(soy);
		musteriListesi[s].belirleUcusNoMusteri(un);
		musteriListesi[s].belirleKoltukNo(kn);
	}
	okumaMusteri.close();
}

///////////////////////////////////////////// M��TER� OKUMA B�T�� ////////////////////////////////////////////



//////////////////////////////////////////// B�LET SATI� BA�LANGI� ///////////////////////////////////////////

void biletSatis(musteri musteriListesi[],ucak ucakListesi[]) 
{
	
	//m��teriye bilet sat��� yapmak i�in kullan�lan fonksiyon
	
	int durum = ucusListele(ucakListesi,musteriListesi);
	if(durum==1) 
	{
		string ky,vy;
		cout<<"Kalk�� yeri: ";
		getchar();
		getline(cin,ky);
		
		for(;ky.size()>30;) 
		{
			cout<<"Kalk�� yerini �ok uzun girdiniz!.(max 30 karakter)\nTekrar kalk�� yeri giriniz:";
			getline(cin,ky);
		}
		
		cout<<"Var�� yeri: ";
		getline(cin,vy);
		
		for(; vy.size()>30;) 
		{
			cout<<"Var�� yerini �ok uzun girdiniz!.(max 30 karakter)\nTekrar var�� yeri giriniz:";
			getline(cin,vy);
		}
		
		int bulundu=0;
		string bulunanUcus[maxUcusSiniri-minUcusSiniri];
		
		for(int k=minUcusSiniri,s=0; k<atoi(getirSeferNo().c_str()); k++) 
		{
			if(ky==ucakListesi[k].getirKalkisYeri() && vy==ucakListesi[k].getirVarisYeri()) 
			{
				bulundu++;
				bulunanUcus[s]=ucakListesi[k].getirUcusNo();
				s++;
			}
		}
		
		if(bulundu>0) 
		{
			int sonuc=0;
			string ucus;
			
			cout<<"Arad���n�z kriterlerde "<<bulundu<<" adet u�u� bulunmu�tur.\n";
			cout<<"\n\n* * * * * * * * * * * * * * * * * * * * U�U�  L�STES� * * * * * * * * * * * * * * * * * * *\n";
			cout<<setw(10)<<"U�U� NO"<<setw(35)<<"KALKI� YER�"<<setw(35)<<"VARI� YER�"<<setw(15)<<"KOLTUK SAYISI"<<setw(15)<<"BO� KOLTUK SAYISI"<<"\n";
			for(int l=0; l<bulundu; l++) 
			{
				int i=atoi(bulunanUcus[l].c_str());
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
			
			cout<<"\n\n";
			cout<<"��leme devam etmek i�in u�u� numaras�n� giriniz: ";
			getline(cin,ucus);
			
			for(int l=0; l<bulundu; l++) 
			{
				int i=atoi(getirMusteriId().c_str());
				int s=atoi(bulunanUcus[l].c_str());

				if(ucus==bulunanUcus[l].c_str()) 
				{
					string koltukSonuc=koltukListe(ucakListesi[s].getirUcusNo(),musteriListesi,atoi(ucakListesi[s].getirKoltukSayisi().c_str()),0);
					
					if(koltukSonuc!="0") 
					{
						int indi = atoi(ucakListesi[s].getirUcusNo().c_str());

						musteriListesi[i].belirleMusteriId(getirMusteriId());
						musteriListesi[i].belirleKoltukNo(koltukSonuc);
						getchar();
						musteriListesi[i].belirleAd();
						musteriListesi[i].belirleSoyad();
						musteriListesi[i].belirleUcusNoMusteri(ucakListesi[s].getirUcusNo());

						fstream yolcu("Yolcular.txt", ios::app);
						yolcu.setf(ios::left);
						string a,b,c,d,e;
						
						a=musteriListesi[i].getirMusteriId()+";";
						b=musteriListesi[i].getirUcusNo()+";";
						c=musteriListesi[i].getirSoyad()+";";
						d=musteriListesi[i].getirAd()+";";
						e=musteriListesi[i].getirKoltukNo();
						
						yolcu<<a<<b<<c<<d<<e<<endl;
						yolcu.close();

						belirleMusteriId(i+1);
						cout<<"\nYeni yolcu kayd� olu�turuldu.\n\n";
						cout<<"U�u� numaras�: "<<indi<<" olan u�u�un:\nKalk�� yeri: "<<ucakListesi[s].getirKalkisYeri()
						<<"\nVar�� yeri: "<<ucakListesi[s].getirVarisYeri()
						<<"\nM��teri ad�: "<<musteriListesi[i].getirAd()
						<<"\nM��teri Soyad�: "<<musteriListesi[i].getirSoyad()
						<<"\nKoltuk nosu:"<<musteriListesi[i].getirKoltukNo()<<endl;
					} 
					else 
					{
						cout<<"\nSe�ti�iniz u�u�da bo� koltuk bulunmamaktad�r!\n";
					}
					return;
				}
			}
		} 
		else 
		{
			cout<<"\nArad���n�z kriterlerde u�u� bulunamam��t�r!\n";
			return;
		}
	}
}
////////////////////////////////////////////// B�LET SATI� B�T�� /////////////////////////////////////////////
