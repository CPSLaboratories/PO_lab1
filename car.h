
/*-----------------Programowanie Obiektowe/AiR/Semestr 2/Grupa 5/Sekcja 19------------------------------
 ------------------Przemys�aw Papiernik/Jakub Wrzeszcz/Sebastian Liko�ski-----------------------------*/

#pragma once

class Car
{
	public:
		bool Jazda(double);
		double Tankuj(double); // Ta funkcja by�a void, zmieni�em na double i u�y�em jej w tej postaci w kodzie
		void NadajNumerStartowy(double);
		void InfoAll();
		double OdczytLicznika(); // Przebieg
		double OdczytStanuPaliwa(double);
		double OdczytPojemnosciBaku();
		double LosujDane(double, double);
		Car();
		~Car();

	private:

		double PojemnoscBaku;
		double PozostalePaliwo; // Paliwo, kt�re pozosta�o po przejechaniu przebytego dystansu
		double SrednieSpalanie;
		double PrzebytyDystans; // sumaryczny dystans, przebyty po danej liczbie wywo�a� funkcji "Jazda"

		//informacja o pozosta�ym paliwie - dostan� j� z main




};