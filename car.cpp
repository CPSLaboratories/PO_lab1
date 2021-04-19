
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
	Car::PojemnoscBaku = LosujDane(40,100);       // Wylosowanie pojemnoœci baku 
	Car::SrednieSpalanie = LosujDane(0.04,0.10);  // Wylosowanie œredniego spalania
	Car::PrzebytyDystans = 0.0;
	Car::PozostalePaliwo = 0.0;
}

Car::~Car() {}

double Car::LosujDane(double ValStart, double ValStop)  // Implementacja funkcji losuj¹cej liczby z zadanego przedzia³u
{
	return (double)rand() / RAND_MAX * (ValStop - ValStart) + ValStart;
}

//Jakub
bool Car::Jazda(double Odleglosc)
{
	bool Sukces = false;  // Ustawienie domyœlnej wartoœci zwracanej

	if (Car::PozostalePaliwo == 0.0)
	{
		cout << "Brak paliwa";
		return Sukces;
	}
	else
	{
		if ((Car::SrednieSpalanie * Odleglosc) > Car::PozostalePaliwo)  // Funkcja wykonywana, jeœli pozosta³ego paliwa nie wystarczy na przejechanie zadanej odleg³oœci
		{
			Car::PrzebytyDystans = Car::PrzebytyDystans + (Car::PozostalePaliwo / Car::SrednieSpalanie);
			Car::PozostalePaliwo = 0.0; 

			return Sukces;
		}
		else
		{
			Car::PrzebytyDystans = Car::PrzebytyDystans + Odleglosc;   // Funkcja wykonywana, jeœli pozosta³ego paliwa jest wystarczaj¹co, by przejechaæ zadan¹ odleg³oœæ
			Car::PozostalePaliwo = Car::PozostalePaliwo - (Car::PrzebytyDystans * Car::SrednieSpalanie);

			Sukces = true;
			return Sukces;
		}
	}
}

double Car::Tankuj(double Ilosc)  // zmienna "Ilosc" mo¿e byc ujemna; przyjmyjemy wtedy, ¿e paliwo jest wylewane z baku
{
	if (Car::PozostalePaliwo + Ilosc > Car::PojemnoscBaku)  // Funkcja wykonywana, jeœli polecono zatankowaæ wiêcej paliwa, ni¿ zmieœci siê w baku
	{
		Car::PozostalePaliwo = Car::PojemnoscBaku;
		cout << "Nie mozesz dolac wiecej paliwa, niz wynosi pojemnosc baku. Bak pelny.";
	}
	else
	{
		if (Car::PozostalePaliwo + Ilosc < 0.0)  // Funkcja wykonywana, jeœli polecono wylaæ z baku wiêcej paliwa, ni¿ znajduje siê w nim obecnie
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

double Car::OdczytStanuPaliwa(double dystans)  // Funkcja s³u¿¹ca do odczytania obecnego stanu paliwa w baku
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
	//ma obs³ugiwaæ case'y "numer_startowy", "spalanie", "przebieg", "pojemnosc_baku", "stan_paliwa", "wszystko"
}