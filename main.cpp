
/*-----------------Programowanie Obiektowe/AiR/Semestr 2/Grupa 5/Sekcja 19------------------------------ 
 ------------------Przemys³aw Papiernik/Jakub Wrzeszcz/Sebastian Likoñski-----------------------------*/

//Biblioteki
#include "main.h"
#include "car.h"
#include <ctime>
#include <string>
#include <iostream>
using namespace std;

//CFG
double ZatankujWszystkieDo = 80;    //Tankowanie do 80% baku, mo¿na ³atwo zmieniæ
int OdlegloscZawody = 100;          //Iloœæ jednostek odleg³oœci na zawodach, mo¿na ³atwo zmieniæ
int IloscSamochodow = 0;			//Wartoœæ wpisywana przez u¿ytkownika - ile samochodów chce utworzyæ
									
//Zmienne
int Menu = 0;						//Zmienna do obs³ugi menu
Car* Flota;							//Tablica obiektów typu Car

//Program
void main()
{
	while (IloscSamochodow < 5)		//Uniemo¿liwienie wybrania mniejszej iloœci samochodów ni¿ 5
	{
		cout << "Wprowadz liczbe samochodow (min.5)\n";
		cin >> IloscSamochodow;
	}

	UtworzFlote(IloscSamochodow);	//Utworzenie floty samochodów o zadanym rozmiarze

	while (1)						//Menu
	{
		cout << "Wybierz opcje\n1.Zatankuj wszystkie samochody do 80% pojemnosci baku\n2.Rozpocznij zawody\n3.Wyswietl dane pojazdow\n4.Zamknij program";
		cin >> Menu;
		switch (Menu)
		{
		case 1:
			ZatankujWszystkie(ZatankujWszystkieDo);
			break;
		case 2:
			RozpocznijZawody();
			break;
		case 3:
			WyswietlDane();
			break;
		case 4:
			delete [] Flota;
			exit(0);
		default:
			break;
		}
	}
}

void UtworzFlote(int IleSamochodow)	//Utworzenie floty samochodów o zadanym rozmiarze
{
	srand(time(NULL));				
	Flota = new Car[IleSamochodow];	//Utworzenie tablicy dynamicznej

	for (int i = 0; i < IloscSamochodow; i++)
	{
		Flota[i].Car::NadajNumerStartowy(i); //Nadanie indywidualnego numeru startowego - indeks zmiennej w tablicy jest unikalny
	}
}

void RozpocznijZawody()				//Rozpoczêcie zawodów o okreœlonej liczbie jednostek odleg³oœci
{

}

void ZatankujWszystkie(double Ile)	//Zatankowanie wszystkich samochodów do okreœlonej pojemnoœci baku w % - domyœlnie 80%
{
	for (int i = 0; i < IloscSamochodow; i++)
	{
		string Temp;
		Flota[i].Car::Info(Temp, "numer_startowy");	//Pobranie numeru startowego
		double IleJestPaliwa = Flota[i].Car::OdczytStanuPaliwa(0);	//Sprawdzenie aktualnego stanu paliwa w danym obiekcie Car
		double ProcentBaku = Flota[i].Car::OdczytPojemnosciBaku() * (Ile / 100);	//Obliczenie ile wynosi 80% objêtoœci baku danego obiektu Car
		double IleDolacPaliwa = ProcentBaku - IleJestPaliwa;	//Obliczenie ile paliwa nale¿y dolaæ. Jeœli paliwa w baku jest wiêcej ni¿ 80% to otrzymamy 
																//wartoœæ ujemn¹ i paliwo zostanie odlane.

		cout << "Do samochodu " << Temp << " dolano " << IleDolacPaliwa << " jednostek paliwa. Aktualny stan: " << to_string(Flota[i].Car::Tankuj(IleDolacPaliwa)) << endl;
		//Wyœwietlenie informacji i wykonanie operacji tankowania
	}
}

void WyswietlDane() //Wyœwietlenie danych o obiektach Car
{
	for (int i = 0; i < IloscSamochodow; i++)
	{
		string Temp;
		Flota[i].Car::Info(Temp, "wszystko");
		cout << Temp << endl;
	}
}

//void NadajNumeryStartowe(int Ilosc)
//{
//	srand(time(NULL));
//	for (int i = 0; i < Ilosc; i++)
//	{
//		BazaSamochodow[i] = (double)rand() / RAND_MAX * (1000000 - 1) + 1;
//	}
//}