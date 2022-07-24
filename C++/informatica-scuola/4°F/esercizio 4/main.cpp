//Vito Barra
//esercizio 4
///leggere i numeri contenuti nel file "tutti.txt" e stampare quelli pari nel file "pari.txt" e quelli dispari nel file "dispari.txt"
#include <iostream>
#include <fstream>

using namespace std;


fstream f;
fstream fo1;
fstream fo2;

void NumberSeparator();

int main()
{
	NumberSeparator();
	cout << "i numeri sono stati separati con successo";
	system("pause>nul");
	return 0;
}

void NumberSeparator()
{
    f.open("numeri.txt", ios::in);
	fo1.open("pari.txt", ios::out|ios::trunc);
	fo2.open("dispari.txt", ios::out | ios::trunc);
	int som = 0, numEle = 0, temp = 0;


	if (f.is_open())
	{
		while (!f.eof())
		{
			f >> temp;
			if (!(temp % 2))
				fo1 << temp <<" ";
			else
				fo2 << temp << " ";
		}
	}


	f.close(); f.clear();
	fo1.close(); fo1.clear();
	fo2.close(); fo2.clear();
}
