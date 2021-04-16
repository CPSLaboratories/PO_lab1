
/*-----------------Programowanie Obiektowe/AiR/Semestr 2/Grupa 5/Sekcja 19------------------------------ 
 ------------------Przemys³aw Papiernik/Jakub Wrzeszcz/Sebastian Likoñski-----------------------------*/

//Biblioteki
#include "main.h"
#include <ctime>
#include <string>
#include <iostream>
using namespace std;

//Zmienne
int ZatankujDo = 80;
int OdlegloscZawody = 100;
int IDZwyciezcy = 0;
int IloscSamochodow = 0;
double BazaSamochodow[];

//Program
void main()
{
	cout << "Wprowadz liczbe samochodow\n";
	cin >> IloscSamochodow;
	cout << to_string(IloscSamochodow);
}

void UtworzBazeSamochodow(int Ilosc)
{
	srand(time(NULL));
	for (int i = 0; i < Ilosc; i++)
	{
		BazaSamochodow[i] = (double)rand() / RAND_MAX * (1000000 - 1) + 1;
	}
}