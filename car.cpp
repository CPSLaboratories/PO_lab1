
/*-----------------Programowanie Obiektowe/AiR/Semestr 2/Grupa 5/Sekcja 19------------------------------
 ------------------Przemys³aw Papiernik/Jakub Wrzeszcz/Sebastian Likoñski-----------------------------*/


//Milej zabawy ~ Przemys³aw

//Biblioteki
#include "car.h"
#include <ctime>
#include <string>
#include <iostream>
using namespace std;

Car::Car() 
{
	Car::PojemnoscBaku = LosujDane(40,100);
	Car::SrednieSpalanie = LosujDane(0.04,0.10);
	Car::PrzebytyDystans = 0.0;
	Car::PozostalePaliwo = 0.0;
}

Car::~Car() {}

double Car::LosujDane(double ValStart, double ValStop)
{
	return (double)rand() / RAND_MAX * (ValStop - ValStart) + ValStart;
}

//Jakub
bool Car::Jazda(double Odleglosc)
{
	// Trzeba zadbaæ, aby Odleglosc by³a nieujemna
	bool Sukces = false;

	if (Car::PozostalePaliwo == 0.0)
	{
		cout << "Brak paliwa";
	}
	else
	{
		if ((Car::SrednieSpalanie * Odleglosc) > Car::PozostalePaliwo)
		{
			Car::PrzebytyDystans = Car::PrzebytyDystans + (Car::PozostalePaliwo / Car::SrednieSpalanie);
			Car::OdczytStanuPaliwa(Car::PozostalePaliwo / Car::SrednieSpalanie); // Tutaj równoznaczne bêdzie wyzerowanie paliwa komend¹ Car::PozostalePaliwo = 0.0;  

			//bool Porazka = true; // Nie wiem, czy tutaj powinno byæ true czy false
			//return Porazka;
			Sukces = false; //Drobna poprawka ~ Przemek
			return Sukces;
		}
		else
		{
			Car::PrzebytyDystans = Car::PrzebytyDystans + Odleglosc;
			Car::OdczytStanuPaliwa(Odleglosc);

			Sukces = true;
			return Sukces;
		}
	}
}

double Car::Tankuj(double Ilosc)
{
	if (Car::PozostalePaliwo + Ilosc > Car::PojemnoscBaku)
	{
		Car::PozostalePaliwo = Car::PojemnoscBaku;
		cout << "Nie mozesz dolac wiecej paliwa, niz wynosi pojemnosc baku. Bak pelny.";
	}
	else
	{
		if (Car::PozostalePaliwo + Ilosc < 0.0)
		{
			Car::PozostalePaliwo = 0.0;
			cout << "Nie mozesz wylac wiecej paliwa, niz obecnie znajduje sie w baku. Bak pusty.";
		}
		else
		{
			Car::PozostalePaliwo = Car::PozostalePaliwo + Ilosc;
		}
	}
	return(Car::PozostalePaliwo);
}

double Car::OdczytStanuPaliwa(double dystans)
{
	if ((Car::PozostalePaliwo - (dystans * Car::SrednieSpalanie)) < 0.0)
	{
		Car::PozostalePaliwo = 0.0;
	}
	else
	{
		Car::PozostalePaliwo = Car::PozostalePaliwo - (Car::PrzebytyDystans * Car::SrednieSpalanie);
	}

	//return Car::PozostalePaliwo;
}

//Sebastian
void Car::NadajNumerStartowy(double Numer)
{

}


double Car::OdczytLicznika()
{

}

double Car::OdczytPojemnosciBaku()
{

}

void Car::Info(const string& Zmienna, string Typ)
{
	//ma obs³ugiwaæ case'y "numer_startowy", "spalanie", "przebieg", "pojemnosc_baku", "stan_paliwa", "wszystko"
}