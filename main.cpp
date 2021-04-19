
/*-----------------Programowanie Obiektowe/AiR/Semestr 2/Grupa 5/Sekcja 5.9----------------------------- 
 ------------------Przemys�aw Papiernik/Jakub Wrzeszcz/Sebastian Liko�ski-------------------------------
Link do repozytorium: https://github.com/CPSLaboratories/PO_lab1.git                                  */

//Biblioteki
#include "main.h"
#include "car.h"
#include <ctime>
#include <string>
#include <iostream>
using namespace std;

//CFG
double ZatankujWszystkieDo = 80.0;    //Tankowanie do 80% baku, mo�na �atwo zmieni�
double OdlegloscZawody = 100.0;          //Ilo�� jednostek odleg�o�ci na zawodach, mo�na �atwo zmieni�
int IloscSamochodow = 0;			//Warto�� wpisywana przez u�ytkownika - ile samochod�w chce utworzy�
									
//Zmienne
int Menu = 0;						//Zmienna do obs�ugi menu
Car* Flota;							//Tablica obiekt�w typu Car

//Program
void main()
{
	while (IloscSamochodow < 5)		//Uniemo�liwienie wybrania mniejszej ilo�ci samochod�w ni� 5
	{
		cout << "Wprowadz liczbe samochodow (min.5)\n";
		cin >> IloscSamochodow;
	}

	UtworzFlote(IloscSamochodow);	//Utworzenie floty samochod�w o zadanym rozmiarze

	while (1)						//Menu
	{
		cout << "Wybierz opcje\n1.Zatankuj wszystkie samochody do 80% pojemnosci baku\n2.Rozpocznij zawody\n3.Wyswietl dane pojazdow\n4.Zamknij program\n";
		cin >> Menu;
		switch (Menu)
		{
		case 1:
			ZatankujWszystkie(ZatankujWszystkieDo);
			break;
		case 2:
			RozpocznijZawody(OdlegloscZawody);
			break;
		case 3:
			WyswietlDane();
			break;
		case 4:
			delete [] Flota;
			exit(0);
		default:
			break;
		}
	}
}

void UtworzFlote(int IleSamochodow)	//Utworzenie floty samochod�w o zadanym rozmiarze
{
	srand(time(NULL));				
	Flota = new Car[IleSamochodow];	//Utworzenie tablicy dynamicznej

	for (int i = 0; i < IloscSamochodow; i++)
	{
		Flota[i].Car::NadajNumerStartowy(i); //Nadanie indywidualnego numeru startowego - indeks zmiennej w tablicy jest unikalny
	}
}

void RozpocznijZawody(double Odleglosc)				//Rozpocz�cie zawod�w o okre�lonej liczbie jednostek odleg�o�ci
{
	double * StanLicznikow = new double[IloscSamochodow]; //Tablica na stan licznika obiekt�w Car przed zawodami
	int Zwyciezca = -1;

	for (int i = 0; i < IloscSamochodow; i++)
	{
		StanLicznikow[i] = Flota[i].Car::OdczytLicznika(); //Odczytujemy stan licznik�w do tablicy
	}

	//for (int i = 0; i < IloscSamochodow; i++)
	//{
	//	cout << to_string(StanLicznikow[i]);
	//}

	double PaliwoLacznie = 1.0;
	bool Sukces;

	while (PaliwoLacznie != 0.0) //Zawody b�d� trwa� dop�ki suma paliwa we wszystkich bakach b�dzie r�na od 0.
	{
		PaliwoLacznie = 0.0;
		for (int i = 0; i < IloscSamochodow; i++)
		{
			Sukces = Flota[i].Car::Jazda(Odleglosc);
			PaliwoLacznie += Flota[i].Car::OdczytStanuPaliwa();
		}
	}

	//Sprawdzamy stan licznik�w przed i po, obliczamy otrzymany dystans, wybieramy zwyci�zc�
	Zwyciezca = 0;
	double TempLicznik = Flota[0].Car::OdczytLicznika() - StanLicznikow[0];

	for (int i = 1; i < IloscSamochodow; i++) 
	{
		if (TempLicznik < (Flota[i].Car::OdczytLicznika() - StanLicznikow[i]))
		{
			Zwyciezca = i;
		}
	}

	string TempZwyciezca;
	Flota[Zwyciezca].Car::Info(TempZwyciezca, 1);

	cout << "Zwyciezca jest samochod z " << TempZwyciezca << endl;

	delete[] StanLicznikow;
}

void ZatankujWszystkie(double Ile)	//Zatankowanie wszystkich samochod�w do okre�lonej pojemno�ci baku w % - domy�lnie 80%
{
	for (int i = 0; i < IloscSamochodow; i++)
	{
		string Temp;
		Flota[i].Car::Info(Temp, 1);	//Pobranie numeru startowego
		double IleJestPaliwa = Flota[i].Car::OdczytStanuPaliwa();	//Sprawdzenie aktualnego stanu paliwa w danym obiekcie Car
		double ProcentBaku = Flota[i].Car::OdczytPojemnosciBaku() * (Ile / 100);	//Obliczenie ile wynosi 80% obj�to�ci baku danego obiektu Car
		double IleDolacPaliwa = ProcentBaku - IleJestPaliwa;	//Obliczenie ile paliwa nale�y dola�. Je�li paliwa w baku jest wi�cej ni� 80% to otrzymamy 
																//warto�� ujemn� i paliwo zostanie odlane.

		cout << "Do samochodu " << Temp << " dolano " << IleDolacPaliwa << " jednostek paliwa. Aktualny stan: " << to_string(Flota[i].Car::Tankuj(IleDolacPaliwa)) << endl;
		//Wy�wietlenie informacji i wykonanie operacji tankowania
	}
}

void WyswietlDane() //Wy�wietlenie danych o obiektach Car
{
	for (int i = 0; i < IloscSamochodow; i++)
	{
		string Temp;
		Flota[i].Car::Info(Temp, 6);
		cout << Temp << endl;
	}
}