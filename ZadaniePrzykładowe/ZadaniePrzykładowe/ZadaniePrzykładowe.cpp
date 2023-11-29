#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

int main()
{
	setlocale(LC_ALL, "");
	int iloscliczb, liczba, najwieksza, najmniejsza, liczbyUjemne = 0, wypelnienie = 0, kopialiczby;
	bool pobieranie = true;
	srand(time(0));
	const size_t Rozmiar = 20;
	double tablica[Rozmiar]{};
	cout << "podaj ilość liczb(parzysta, naturalna): "; cin >> iloscliczb;
	if ((iloscliczb % 2 == 0 && iloscliczb > 0))
		pobieranie = false;
	else
		do
		{
			cout << "Podaj poprawną liczbę! \n"; cin >> iloscliczb;
			if (iloscliczb % 2 == 0 && iloscliczb > 0)
				pobieranie = false;
		} while (pobieranie == true);

		if (iloscliczb % 2 == 0 && iloscliczb >= 0)
		{
			cout << "Podaj liczbę całkowitą: "; cin >> liczba;
			if (liczba >= 0)
				wypelnienie++;
			else
				liczbyUjemne++;

			najmniejsza = najwieksza = liczba;
			while (wypelnienie < iloscliczb)
			{

				cout << "Podaj kolejną liczbę całkowitą: "; cin >> liczba;
				if (liczba >= 0)
					wypelnienie++;
				if (liczba < 0)
					liczbyUjemne++;
				if (liczbyUjemne == 2)
				{
					cout << "Podano 2 liczby ujemne. Przerywam pobieranie! ";
					return 0;
				}
			}
			if (liczba < najmniejsza)
			{
				najmniejsza = liczba;
			}
			if (liczba > najwieksza)
			{
				najwieksza = liczba;
			}
		}

		for (size_t i = 0; i < Rozmiar; i += 1)
		{
			tablica[i] = (double)(rand() % (najwieksza - najmniejsza) + najmniejsza);
		}

		double* wskazniki[3] = { nullptr,nullptr,nullptr };
		wskazniki[0] = &tablica[0];
		wskazniki[2] = &tablica[0];
		for (size_t i = 1; i < Rozmiar; i++)
		{
			if (tablica[i] < *wskazniki[0])
				wskazniki[0] = &tablica[i];
			if (tablica[i] > *wskazniki[2])
				wskazniki[2] = &tablica[i];
		}
		double tabkopia[Rozmiar]{};
		for (size_t i = 0; i < Rozmiar; i++)
			tabkopia[i] = tablica[i];

		for (size_t i = 0; i < Rozmiar - 1; i++)
			for (size_t j = 0; j < Rozmiar - i - 1; j++)
				if (tabkopia[j] > tabkopia[j + 1])
				{
					int kopia = tabkopia[j];
					tabkopia[j] = tabkopia[j + 1];
					tabkopia[j + 1] = kopia;
				}

		double* mediana1 = &tabkopia[Rozmiar / 2 - 1];
		double* mediana2 = &tabkopia[Rozmiar / 2];
		double mediana = (*mediana1 + *mediana2) / 2.0;
		wskazniki[1] = &mediana;

		cout << "Tablica wypełniona losowymi liczbami: \n";
		for (size_t i = 0; i < Rozmiar; i++)
			cout << tablica[i];

		cout << endl << "Najmniejszy element: " << *wskazniki[0] << endl;
		cout << "Mediana: " << *wskazniki[1] << endl;
		cout << "Największy element: " << *wskazniki[2] << endl;


}
