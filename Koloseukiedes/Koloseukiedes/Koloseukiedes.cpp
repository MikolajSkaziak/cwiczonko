#include <iostream>
#include <ctime>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
	setlocale(LC_ALL, "");
	//z1
	int x1, y1, x2, y2;
	double d;
	cout << "Podaj wartości (x1,y1): "; cin >> x1 >> y1;
	cout << "Podaj wartości (x2,y2): "; cin >> x2 >> y2;
	d = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
	cout << scientific << "Notacja naukowa: \n";
	cout << "Odległośc eukliedesowa wynosi: " << d << endl;
	//z2
	char znak = 42;
	srand(time(NULL));

	int l1 = rand() % (5 + 1);
	char obw;
	char** tablica = new char* [y1];
	for (int i = 0; i < y1; i++)
	{
		switch (l1)
		{
		case 0:
			obw = '#'; break;
		case 1:
			obw = '@'; break;
		case 2:
			obw = '$'; break;
		case 3:
			obw = '*'; break;
		case 4:
			obw = '&'; break;
		case 5:
			obw = '!'; break;
		}
		tablica[i] = new char[x1];
		for (int j = 0; j < x1; j++)
		{
			l1 = rand() % (5 + 1);
			tablica[i][j] = obw;
			cout << tablica[i][j];
		}
	}
	//z3
	int* wskaznik1;
	int* wskaznik2;
	for
}
