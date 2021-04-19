
/*-----------------Programowanie Obiektowe/AiR/Semestr 2/Grupa 5/Sekcja 19------------------------------
 ------------------Przemys³aw Papiernik/Jakub Wrzeszcz/Sebastian Likoñski-----------------------------*/

#pragma once
#include <string>

class Car
{
	public:
		bool Jazda(double);
		double Tankuj(double); 
		void NadajNumerStartowy(int);
		void Info(const std::string& Zmienna, int Typ);
		double OdczytLicznika();  // Funkcja informuj¹ca o obecnym przebiegu pojazdu
		double OdczytStanuPaliwa(double); 
		double OdczytPojemnosciBaku();
		double LosujDane(double, double);  // Funkcja losuj¹ca liczby z zadanego przedzia³u 
		Car();
		~Car();

	private:
		double PojemnoscBaku;
		double PozostalePaliwo;  // Paliwo, które pozosta³o po przejechaniu przebytego dystansu
		double SrednieSpalanie;
		double PrzebytyDystans; // Sumaryczny dystans, przebyty po danej liczbie wywo³añ funkcji "Jazda"
		unsigned int NumerStartowy;
		//informacja o pozosta³ym paliwie - dostanê j¹ z main

};