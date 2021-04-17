
/*-----------------Programowanie Obiektowe/AiR/Semestr 2/Grupa 5/Sekcja 19------------------------------
 ------------------Przemys³aw Papiernik/Jakub Wrzeszcz/Sebastian Likoñski-----------------------------*/

#pragma once
#include <string>

class Car
{
	public:
		bool Jazda(double);
		double Tankuj(double); // Ta funkcja by³a void, zmieni³em na double i u¿y³em jej w tej postaci w kodzie
		void NadajNumerStartowy(int);
		void Info(const std::string& Zmienna, std::string Typ);
		double OdczytLicznika(); // Przebieg
		double OdczytStanuPaliwa(double);
		double OdczytPojemnosciBaku();
		double LosujDane(double, double);
		Car();
		~Car();

	private:
		double PojemnoscBaku;
		double PozostalePaliwo; // Paliwo, które pozosta³o po przejechaniu przebytego dystansu
		double SrednieSpalanie;
		double PrzebytyDystans; // sumaryczny dystans, przebyty po danej liczbie wywo³añ funkcji "Jazda"

		//informacja o pozosta³ym paliwie - dostanê j¹ z main

};