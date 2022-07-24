//Vito Barra
//esercizio 3
///Costruire la media degli elementi contenuti nel file "numeri.txt" e stampare il risultato
#include <iostream>
#include <fstream>

using namespace std;


fstream f;

float AverageFromFile();

int main()
{
	float media = AverageFromFile();
	cout << "la media dei numeri nel file numeri.txt e': " << media;
	system("pause>nul");
	return 0;
}

float AverageFromFile()
{
    f.open("numeri.txt", ios::in);
	int som = 0, numEle = 0, temp = 0;
	if (f.is_open())
	{
		while (!f.eof())
		{
			f >> temp;
			som += temp;
			numEle++;
		}
	}
	else 
		return 0;

    f.close(); f.clear();
	return som*1.0 / numEle;
}

