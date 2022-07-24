//Vito Barra
//esercizio 2
/// costruzione tab compressa da una matrice sparsa quadrata
#include <iostream>
#include <time.h>

using namespace std;


struct tab
{
	char car;
	int y;
	int x;
};

const int NELE = 20;


void Carica(char[][NELE],int);
void Stampa(char[][NELE], int);
int CreateTab(char[][NELE], int, tab[]);
void StampaTab(tab[], int);


int main()
{
	char mChar[NELE][NELE]{};
	tab charTab[NELE*NELE];

	Carica(mChar,NELE);
	cout << "-----------------matrice sparsa-----------------\n";
	Stampa(mChar, NELE);
	cout << "-----------------matrice sparsa-----------------\n";



	int ele = CreateTab(mChar, NELE, charTab);
	StampaTab(charTab, ele);
	system("pause>nul");
	return 0;
}

void Carica(char M[][NELE],int lenght)
{
	srand(time(NULL));
	for(int i = 0;i<lenght;i++)
		for (int j = 0; j < lenght; j++)
			if (i == rand() % lenght || j == rand() % lenght)
			{
				switch (rand() % 21)
				{
				case 0: M[i][j] = 'a'; break;
				case 1: M[i][j] = 'b'; break;
				case 2: M[i][j] = 'c'; break;
				case 3: M[i][j] = 'd'; break;
				case 4: M[i][j] = 'e'; break;
				case 5: M[i][j] = 'f'; break;
				case 6: M[i][j] = 'g'; break;
				case 7: M[i][j] = 'h'; break;
				case 8: M[i][j] = 'i'; break;
				case 9: M[i][j] = 'l'; break;
				case 10: M[i][j] = 'm'; break;
				case 11: M[i][j] = 'n'; break;
				case 12: M[i][j] = 'o'; break;
				case 13: M[i][j] = 'p'; break;
				case 14: M[i][j] = 'q'; break;
				case 15: M[i][j] = 'r'; break;
				case 16: M[i][j] = 's'; break;
				case 17: M[i][j] = 't'; break;
				case 18: M[i][j] = 'u'; break;
				case 19: M[i][j] = 'v'; break;
				case 20: M[i][j] = 'z'; break;
				}
			}
}
void Stampa(char M[][NELE], int lenght)
{
	for (int i = 0; i < lenght; i++)
	{
		for (int j = 0; j < lenght; j++)
			cout << M[i][j] << " ";
		cout << endl;
	}
}


int CreateTab(char M[][NELE], int lenght,tab T[])
{
	int numEle = 0;
	for (int i = 0; i<lenght; i++)
		for (int j = 0; j < lenght; j++)
			if (M[i][j] != '\0')
			{
				T[numEle].car = M[i][j];
				T[numEle].y = i;
				T[numEle].x = j;
				numEle++;
			}
	return numEle;
}
void StampaTab(tab T[], int lenght)
{
	for (int i = 0; i < lenght; i++)
	{
		cout << T[i].car << " " << T[i].y << " " << T[i].x;
		cout << endl;
	}
}

