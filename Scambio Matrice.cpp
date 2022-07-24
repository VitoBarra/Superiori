#include <iostream>

using namespace std;

void Input(int[][10],int,int);
void Sort(int[][10],int,int);
void Stampa(int[][10],int,int);


int FunctionTest()
{
	int mat[10][10];
	int x, y;
	cout << "dammi ilnumero di colonne:\t";
	cin >> x;
	cout << "\ndammi ilnumero di righe:\t";
	cin >> y;

	Input(mat, x, y);
	Sort(mat, x, y);
	Stampa(mat, x, y);


	system("pause>nul");


	return 0;
}

void Input(int Mat[][10],int x,int y)
{
	for (int j = 0;j<y;j++)
	{
		for(int i = 0;i<x;i++)
		{
		cout<<"dammi la "<<j<<", "<<i<<" casella:  ";
		cin>>Mat[j][i];
		}
	
	}
}

void Sort(int Mat[][10], int x, int y)
{
	int temp;
	int scambio = 1;


	while (scambio == 1)
	{
		scambio = 0;
		for (int j = 0; j < y; j++)
		{
			for (int i = 0; i<x - 1; i++)
			{
				if (Mat[j][i]> Mat[j][i + 1])
				{
					cout << "\nstampa temporanea:"<<j<<","<<i<<"\n ";
					Stampa(Mat, x, y);
					temp = Mat[j][i + 1];
					Mat[j][i + 1] = Mat[j][i];
					Mat[j][i] = temp;
					scambio = 1;
				}
				if (Mat[j][i] > Mat[j + 1][i] && i == x - 2)
				{
					temp = Mat[j + 1][i];
					Mat[j + 1][i] = Mat[j][i];
					Mat[j][i] = temp;
					scambio = 1;
				}
			}
			j++;
			for (int i = x - 1; i > 0; i--)
			{
				if (Mat[j][i] > Mat[j][i - 1])
				{
					temp = Mat[j][i - 1];
					Mat[j][i - 1] = Mat[j][i];
					Mat[j][i] = temp;
					scambio = 1;
				}
				if (Mat[j][i - 1] > Mat[j + 1][i - 1] && i == 1)
				{
					temp = Mat[j + 1][i - 1];
					Mat[j + 1][i - 1] = Mat[j][i - 1];
					Mat[j][i - 1] = temp;
					scambio = 1;
				}
			}
		}
		
	}
}


void Stampa(int Mat[][10],int x,int y)
{
	for (int j = 0;j<y;j++)
	{
		for(int i = 0;i<x;i++)
			cout<<Mat[j][i]<<"  "; 
	cout<<endl;
	}
}
