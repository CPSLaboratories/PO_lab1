
/*-----------------Programowanie Obiektowe/AiR/Semestr 2/Grupa 5/Sekcja 19------------------------------
 ------------------Przemys�aw Papiernik/Jakub Wrzeszcz/Sebastian Liko�ski-----------------------------*/

#pragma once
#include <string>

class Car
{
	public:
		bool Jazda(double);
		double Tankuj(double); 
		void NadajNumerStartowy(int);
		void Info(const std::string& Zmienna, int Typ);
		double OdczytLicznika();  // Funkcja informuj�ca o obecnym przebiegu pojazdu
		double OdczytStanuPaliwa(double); 
		double OdczytPojemnosciBaku();
		double LosujDane(double, double);  // Funkcja losuj�ca liczby z zadanego przedzia�u 
		Car();
		~Car();

	private:
		double PojemnoscBaku;
		double PozostalePaliwo;  // Paliwo, kt�re pozosta�o po przejechaniu przebytego dystansu
		double SrednieSpalanie;
		double PrzebytyDystans; // Sumaryczny dystans, przebyty po danej liczbie wywo�a� funkcji "Jazda"
		unsigned int NumerStartowy;
		//informacja o pozosta�ym paliwie - dostan� j� z main

};