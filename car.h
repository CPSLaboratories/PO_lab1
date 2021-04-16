
/*-----------------Programowanie Obiektowe/AiR/Semestr 2/Grupa 5/Sekcja 19------------------------------
 ------------------Przemys³aw Papiernik/Jakub Wrzeszcz/Sebastian Likoñski-----------------------------*/

#pragma once

class Car
{
public:
	bool Jazda(double);
	void Tankuj(double);
	void NadajNumerStartowy(double);
	void Tankuj(double);
	void InfoAll();
	double OdczytLicznika();
	double OdczytStanuPaliwa();
	double OdczytPojemnosciBaku();

	Car();
	~Car();

private:

};