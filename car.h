
/*-----------------Programowanie Obiektowe/AiR/Semestr 2/Grupa 5/Sekcja 5.9-----------------------------
 ------------------Przemys�aw Papiernik/Jakub Wrzeszcz/Sebastian Liko�ski-------------------------------
Link do repozytorium: https://github.com/CPSLaboratories/PO_lab1.git                                  */

#pragma once
#include <string>

class Car
{
	public:
		bool Jazda(double);
		double Tankuj(double); 
		void NadajNumerStartowy(int);
		void Info(std::string& Zmienna, int Typ);
		double OdczytLicznika();  // Funkcja informuj�ca o obecnym przebiegu pojazdu
		double OdczytStanuPaliwa(); 
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

};