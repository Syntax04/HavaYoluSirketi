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
#include <time.h>
#include "menu.h"
using namespace std;

int anaMenu()
{
	cout<<"***********Created by Syntax04*********\n"
		<<"* * * * * * *   ANA MEN�  * * * * * * *\n"
		<<"*   1 - U�U� L�STELER�                *\n"
		<<"*   2 - B�LET ��LEMLER�               *\n"
		<<"*   3 - U�AK ��LEMLER�                *\n"
		<<"*   4 - FABR�KA VER�LER�NE D�ND�R     *\n"
		<<"*   0 - PROGRAMDAN �IKI�              *\n"
		<<"* * * * * * * * * * * * * * * * * * * *\n";
		
	int islem=0,sayimi=1;
	char character[2];
	for(;sayimi==1;){
		cout<<"Yapmak istedi�iniz i�lem: ";
		cin>>character;
		for(sayimi=0,islem=0;islem<2;islem++)
		{
			if(character[islem]!='\0')
			{
					if(!isdigit(character[islem]))
				{
					sayimi=1;
					break;
				}
			}
		}
		islem=atoi(character);
		if(sayimi==1){
			cout<<"Ge�ersiz karakter!\n";
		}
		
	}
	return islem;
}


int ucakMenu()
{
	cout<<"* * * * * * *  U�AK MEN�S�  * * * * * * *\n"
		<<"*   1 - YEN� U�U� KAYDI                 *\n"
		<<"*   2 - U�U� D�ZENLEME                  *\n"
		<<"*   3 - U�U� S�LME                      *\n"
		<<"*   0 - �ST MEN�YE D�N                  *\n"
		<<"* * * * * * * * * * * * * * * * * * * * *\n";
	int islem=0,sayimi=1;
	char character[2];
	for(;sayimi==1;){
		cout<<"Yapmak istedi�iniz i�lem: ";
		cin>>character;
		for(sayimi=0,islem=0;islem<2;islem++)
		{
			if(character[islem]!='\0')
			{
					if(!isdigit(character[islem]))
				{
					sayimi=1;
					break;
				}
			}
		}
		islem=atoi(character);
		if(sayimi==1){
			cout<<"Ge�ersiz karakter!\n";
		}
		
	}
	return islem;
}
int biletMenu()
{
	cout<<"* * * * * * *  B�LET MEN�S� * * * * * * *\n"
		<<"*   1 - YEN� B�LET SATI�I               *\n"
		<<"*   2 - B�LET DE���T�RME                *\n"
		<<"*   3 - B�LET �PTAL ETME                *\n"
		<<"*   0 - �ST MEN�YE D�N                  *\n"
		<<"* * * * * * * * * * * * * * * * * * * * *\n";
	int islem=0,sayimi=1;
	char character[2];
	for(;sayimi==1;){
		cout<<"Yapmak istedi�iniz i�lem: ";
		cin>>character;
		for(sayimi=0,islem=0;islem<2;islem++)
		{
			if(character[islem]!='\0')
			{
					if(!isdigit(character[islem]))
				{
					sayimi=1;
					break;
				}
			}
		}
		islem=atoi(character);
		if(sayimi==1){
			cout<<"Ge�ersiz karakter!\n";
		}
		
	}
	return islem;
}
int ucusListeMenu()
{
	cout<<"* * * * * U�U� L�STELER� MEN�S� * * * * *\n"
		<<"*   1 - SEFER L�STES�                   *\n"
		<<"*   2 - T�M YOLCULAR'IN L�STES�         *\n"
		<<"*   3 - U�U�LARA G�RE YOLCU L�STES�     *\n"
		<<"*   0 - �ST MEN�YE D�N                  *\n"
		<<"* * * * * * * * * * * * * * * * * * * * *\n";
	int islem=0,sayimi=1;
	char character[2];
	for(;sayimi==1;){
		cout<<"Yapmak istedi�iniz i�lem: ";
		cin>>character;
		for(sayimi=0,islem=0;islem<2;islem++)
		{
			if(character[islem]!='\0')
			{
					if(!isdigit(character[islem]))
				{
					sayimi=1;
					break;
				}
			}
		}
		islem=atoi(character);
		if(sayimi==1){
			cout<<"Ge�ersiz karakter!\n";
		}
		
	}
	return islem;
}

int musteriMenu()
{
	cout<<"* * * *  M��TER� D�ZENLEME MEN�S� * * * *\n"
		<<"*   1 - U�U� G�NCELLEME                 *\n"
		<<"*   2 - �S�M-SOY�S�M G�NCELLEME         *\n"
		<<"*   3 - KOLTUK G�NCELLEME               *\n"
		<<"*   0 - �ST MEN�YE D�N                  *\n"
		<<"* * * * * * * * * * * * * * * * * * * * *\n";
	int islem=0,sayimi=1;
	char character[2];
	string a;
	getline(cin,a);
	a.copy(character,1);
	for(;sayimi==1;){
		cout<<"Yapmak istedi�iniz i�lem: ";
		cin>>character;
		for(sayimi=0,islem=0;islem<2;islem++)
		{
			if(character[islem]!='\0')
			{
					if(!isdigit(character[islem]))
				{
					sayimi=1;
					break;
				}
			}
		}
		islem=atoi(character);
		if(sayimi==1){
			cout<<"Ge�ersiz karakter!\n";
		}
		
	}
	return islem;
}
