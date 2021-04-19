
/*-----------------Programowanie Obiektowe/AiR/Semestr 2/Grupa 5/Sekcja 19------------------------------
 ------------------Przemys�aw Papiernik/Jakub Wrzeszcz/Sebastian Liko�ski-----------------------------*/


//Milej zabawy ~ Przemys�aw

//Biblioteki
#include "car.h"
#include <ctime>
#include <string>
#include <iostream>
using namespace std;

Car::Car() 
{
	Car::PojemnoscBaku = LosujDane(40,100);       // Wylosowanie pojemno�ci baku 
	Car::SrednieSpalanie = LosujDane(0.04,0.10);  // Wylosowanie �redniego spalania
	Car::PrzebytyDystans = 0.0;
	Car::PozostalePaliwo = 0.0;
}

Car::~Car() {}

double Car::LosujDane(double ValStart, double ValStop)  // Implementacja funkcji losuj�cej liczby z zadanego przedzia�u
{
	return (double)rand() / RAND_MAX * (ValStop - ValStart) + ValStart;
}

//Jakub
bool Car::Jazda(double Odleglosc)
{
	bool Sukces = false;  // Ustawienie domy�lnej warto�ci zwracanej

	if (Car::PozostalePaliwo == 0.0)
	{
		cout << "Brak paliwa";
		return Sukces;
	}
	else
	{
		if ((Car::SrednieSpalanie * Odleglosc) > Car::PozostalePaliwo)  // Funkcja wykonywana, je�li pozosta�ego paliwa nie wystarczy na przejechanie zadanej odleg�o�ci
		{
			Car::PrzebytyDystans = Car::PrzebytyDystans + (Car::PozostalePaliwo / Car::SrednieSpalanie);
			Car::PozostalePaliwo = 0.0; 

			return Sukces;
		}
		else
		{
			Car::PrzebytyDystans = Car::PrzebytyDystans + Odleglosc;   // Funkcja wykonywana, je�li pozosta�ego paliwa jest wystarczaj�co, by przejecha� zadan� odleg�o��
			Car::PozostalePaliwo = Car::PozostalePaliwo - (Car::PrzebytyDystans * Car::SrednieSpalanie);

			Sukces = true;
			return Sukces;
		}
	}
}

double Car::Tankuj(double Ilosc)  // zmienna "Ilosc" mo�e byc ujemna; przyjmyjemy wtedy, �e paliwo jest wylewane z baku
{
	if (Car::PozostalePaliwo + Ilosc > Car::PojemnoscBaku)  // Funkcja wykonywana, je�li polecono zatankowa� wi�cej paliwa, ni� zmie�ci si� w baku
	{
		Car::PozostalePaliwo = Car::PojemnoscBaku;
		cout << "Nie mozesz dolac wiecej paliwa, niz wynosi pojemnosc baku. Bak pelny.";
	}
	else
	{
		if (Car::PozostalePaliwo + Ilosc < 0.0)  // Funkcja wykonywana, je�li polecono wyla� z baku wi�cej paliwa, ni� znajduje si� w nim obecnie
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

double Car::OdczytStanuPaliwa(double dystans)  // Funkcja s�u��ca do odczytania obecnego stanu paliwa w baku
{
	return Car::PozostalePaliwo;
}

//Sebastian
void Car::NadajNumerStartowy(int Numer)
{

}


double Car::OdczytLicznika()
{
	return 0;
}

double Car::OdczytPojemnosciBaku()
{
	return 0;
}

void Car::Info(const string& Zmienna, string Typ)
{
	//ma obs�ugiwa� case'y "numer_startowy", "spalanie", "przebieg", "pojemnosc_baku", "stan_paliwa", "wszystko"
}