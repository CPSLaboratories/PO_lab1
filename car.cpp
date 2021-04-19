
/*-----------------Programowanie Obiektowe/AiR/Semestr 2/Grupa 5/Sekcja 19------------------------------
 ------------------Przemys³aw Papiernik/Jakub Wrzeszcz/Sebastian Likoñski-----------------------------*/



//Biblioteki
#include "car.h"
#include <ctime>
#include <string>
#include <iostream>
using namespace std;

//Konstruktor
Car::Car() 
{
	Car::PojemnoscBaku = LosujDane(40,100);			// Wylosowanie pojemnoœci baku 
	Car::SrednieSpalanie = LosujDane(0.04,0.10);	// Wylosowanie œredniego spalania
	Car::PrzebytyDystans = 0.0;						// Zerowanie wartoœci
	Car::PozostalePaliwo = 0.0;
	Car::NumerStartowy = 0;
}

//Dekonstruktor
Car::~Car() {}

double Car::LosujDane(double ValStart, double ValStop)  // Implementacja funkcji losuj¹cej liczby z zadanego przedzia³u
{
	return (double)rand() / RAND_MAX * (ValStop - ValStart) + ValStart;
}

bool Car::Jazda(double Odleglosc)
{
	bool Sukces = false;  // Ustawienie domyœlnej wartoœci zwracanej

	if (Car::PozostalePaliwo == 0.0)
	{
		//cout << "Brak paliwa";
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

double Car::Tankuj(double Ilosc)  // zmienna "Ilosc" mo¿e byc ujemna; przyjmujemy wtedy, ¿e paliwo jest wylewane z baku
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

void Car::NadajNumerStartowy(int Numer) //Funkcja s³u¿¹ca do nadawania numeru startowego obiektu Car
{
	Car::NumerStartowy = Numer;
}

//Metody dostêpowe
void Car::Info(string& Zmienna, int Typ) //Przygotowana pod zwracanie gotowych napisów wszystkich wartoœci w zale¿noœci od argumentu Typ, chocia¿ wykorzystujemy tylko 1 i 6
{
	switch (Typ)
	{
	case 1:
		Zmienna = "numer_startowy: " + to_string(Car::NumerStartowy);
		break;
	case 2:
		Zmienna = "spalanie: " + to_string(Car::SrednieSpalanie);
		break;
	case 3:
		Zmienna = "przebieg: " + to_string(Car::PrzebytyDystans);
		break;
	case 4:
		Zmienna = "pojemnosc_baku: " + to_string(Car::PojemnoscBaku);
		break;
	case 5:
		Zmienna = "stan_paliwa: " + to_string(Car::PozostalePaliwo);
		break;
	case 6:
		Zmienna = "numer_startowy: " + to_string(Car::NumerStartowy) + " spalanie: " + to_string(Car::SrednieSpalanie) + " przebieg: " + to_string(Car::PrzebytyDystans) + " pojemnosc_baku: " + to_string(Car::PojemnoscBaku) + " stan_paliwa: " + to_string(Car::PozostalePaliwo);
		break;
	default:
		break;
	}
}

double Car::OdczytStanuPaliwa(double dystans)
{
	return Car::PozostalePaliwo;
}

double Car::OdczytPojemnosciBaku()
{
	return Car::PojemnoscBaku;
}

double Car::OdczytLicznika()
{
	return Car::PrzebytyDystans;
}