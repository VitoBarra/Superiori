//Vito Barra
//esercizio 25
///Data una matrice sparsa, rappresentata da pochi numeri interi, rappresentare le informazioni in un array di triplette. Ciascuna tripletta è costituita da valore da rappresentare, dalla sua riga e dalla sua colonna


#include <iostream>
#include <time.h>
#include <windows.h>

using namespace std;



int main()
{
	int Mat[50][50]{ 0 };
	int MatRid[100][3]{ 0 };
	int yRid = 0;

	srand(time(NULL));

	for (int j = 0; j < 50; j++)
		Mat[rand() % 51][rand() % 51] = (rand() % 100) + 1;




	for (int y = 0; y < 50; y++)
	{
		for (int x = 0; x < 50; x++)
			if (Mat[y][x] > 0)
			{
				MatRid[yRid][0] = y;
				MatRid[yRid][1] = x;
				MatRid[yRid][2] = Mat[y][x];
				yRid++;
			}
	}

	int n=0;
	for (int y = 0; y < 50; y++)
	{
		cout << ++n << ": ";
		for (int x = 0; x < 3; x++)
			cout<<MatRid[y][x] << " ";
		cout << endl;
	}
	system("pause>nul");
	return 0;
}
