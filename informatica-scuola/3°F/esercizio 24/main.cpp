//Vito barra
//esercizio 24
///gestione di un teatro di 3 livelli
///1)indicre i posti liberi
///2)prenotare un posto
///3)Stabiliri l incasso
///(piano 0:20, piano 1:15, piano 2:10)

#include <iostream>


using namespace std;


void StampaMat(int[][20][20], int ,int,int);
void ResetMat(int[][20][20], int ,int,int);
void PrenPos(int[][20][20], int ,int,int);
void CalInc(int, int&);

int main()
{
	int teatro[20][20][20];
	int scelta, z, y, x, incTot = 0;
	int zi = 0, yi = 0, xi = 0;
	char pren;

	do
	{
		cout << "-----------------BOOT DATA-----------------\n";
		cout << "numeri di piani(Max 20):\t"; cin >> zi;
		cout << "numeri di righe per piano(Max 20):\t"; cin >> yi;
		cout << "numeri di posti per per riga(Max 20):\t"; cin >> xi;
		system("cls");
	} while (zi <= 20 && yi <= 20 && xi <= 20);

	ResetMat(teatro, zi, yi, xi);

	do
	{
		cout << "1)Per prenotare \n2)Per visualizzare il teatro\n3)Exit\nCosa vuoi fare:\t";
		cin >> scelta;
		system("cls");


		switch (scelta)
		{

		case 1:
			do
			{
				pren = 'n';
				//visuzlizazione posti
				cout << "posti liberi:\n\n";
				StampaMat(teatro, zi, yi, xi);

				//prenotazione e incasso
				cout << "inserire il piano, la riga e il posto divisi da uno spazio:\n";
				cin >> z >> y >> x;

				if (teatro[z][y - 1][x - 1] != 1 && x <= xi && y <= yi && z <= zi)
				{
					PrenPos(teatro, z, y, x);
					CalInc(z, incTot);
					StampaMat(teatro, zi, yi, xi);
				}
				else if (x > xi || y > yi || z > zi)
					cout << "il posto non esiste\n";
				else
					cout << "il posto e' gia occupato\n";

				//se continuare	
				cout << "vuoi prenotare un altro posto (y/n):\t";
				cin >> pren;


				system("cls");
			} while (pren == 'y');

			break;


		case 2:
			StampaMat(teatro, zi, yi, xi);
			system("pause>nul");
			break;
		}

		system("cls");
	} while (scelta != 3);



	cout << "teatro finale:\n\n";
	StampaMat(teatro, zi, yi, xi);
	cout << "\nincasso finale: " << incTot;
	system("pause>nul");

	system("pause>nul");
	return 0;
}



void ResetMat(int mat[][20][20], int pian, int rig, int pos)
{
	for (int i = 0; i < pian; i++)
		for (int j = 0; j < rig; j++)
			for (int z = 0; z < pos; z++)
				mat[i][j][z] = 0;
}

void StampaMat(int mat[][20][20], int pian, int rig, int pos)
{
	for (int i = pian - 1; i >= 0; i--)
	{
		cout << i << " piano:\n\n";
		for (int j = 0; j < rig; j++)
		{
			cout << "R" << j + 1 << "\t\t";
			for (int z = 0; z < pos; z++)
				cout << mat[i][j][z] << " ";
			cout << endl;
		}
		cout << endl;
	}
}

void PrenPos(int mat[][20][20], int pian, int rig, int pos)
{
	mat[pian][rig - 1][pos - 1] = 1;
}

void CalInc(int pian, int& inc)
{
	switch (pian)
	{

	case 0:
		inc += 20;
		break;

	case 1:
		inc += 15;
		break;

	case 2:
		inc += 10;
		break;
	}
}