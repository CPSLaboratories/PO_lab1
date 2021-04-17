
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
double ZatankujWszystkieDo = 80;
int OdlegloscZawody = 100;
int IloscSamochodow = 0;

//Zmienne
int Menu = 0;
Car* Flota;

//Program
void main()
{
	while (IloscSamochodow < 5)
	{
		cout << "Wprowadz liczbe samochodow (min.5)\n";
		cin >> IloscSamochodow;
	}

	UtworzFlote(IloscSamochodow);

	while (1)
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
			exit(0);
		default:
			break;
		}
	}
}

void UtworzFlote(int IleSamochodow)
{
	srand(time(NULL));
	Flota = new Car[IleSamochodow];
	for (int i = 0; i < IloscSamochodow; i++)
	{
		Flota[i].Car::NadajNumerStartowy((double)i);
	}
}

void RozpocznijZawody()
{

}

void ZatankujWszystkie(double Ile)
{
	for (int i = 0; i < IloscSamochodow; i++)
	{
		string Temp;
		Flota[i].Car::Info(Temp, "numer_startowy");
		double IleJestPaliwa = Flota[i].Car::OdczytStanuPaliwa(0);
		double ProcentBaku = Flota[i].Car::OdczytPojemnosciBaku() * (Ile / 100);
		double IleDolacPaliwa = ProcentBaku - IleJestPaliwa;

		cout << "Do samochodu " << Temp << " dolano " << IleDolacPaliwa << " jednostek paliwa. Aktualny stan: " << to_string(Flota[i].Car::Tankuj(IleDolacPaliwa)) << endl;
	}
}

void WyswietlDane()
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