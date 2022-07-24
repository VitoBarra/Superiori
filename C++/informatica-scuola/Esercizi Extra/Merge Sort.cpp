#include <iostream>
#include <ctime>
using namespace std;

const int N = 100;
int Ve[N];


void swap(int a, int b)
{
	int VS = 0;
	if (Ve[a]>Ve[b])
	{
		VS = Ve[a];
		Ve[a] = Ve[b];
		Ve[b] = VS;
	}
}

int main()
{

	int a = 0, b = 1, res = 0;
	//INPUT
	/*for(int i=0;i<N;i++)
	{
	cout<<"riempi la "<<i+1<<" casella\t";
	cin>>Ve[i];
	}*/
	
	
	//input DEBUG
	srand(time(nullptr));
	for (int i = 0; i < N; i++)
		Ve[i] = rand() %100+1;
		
	//posizione TAPPO
	for (int i = 0; i<N; i++)
		res += Ve[i];
	for (int i = 0; i<=N+1; i++)
		Ve[N + i] = res;
		
	//SORT
	for (int i = 0; i <= N; i++)
	{
		//swap COPPIE
		a = 0;
		b = 1;
		for (int i = 0; i <= N / 2; i++)
		{
			swap(a, b);
			a += 2; b += 2;

		}
		//swap QUATERNA
		a = 0;
		b = 2;
		for (int i = 0; i <= N - 1; i++)
		{
			swap(a, b);
			a += 2; b += 2;
		}
		//swap 2 QUATERNA	
		a = 1;
		b = 2;
		for (int i = 0; i <= N - 1; i++)
		{
			swap(a, b);
			a += 2; b += 2;
		}
		//swap 3 QUATERNA
		a = 1;
		b = 3;
		for (int i = 0; i <= N - 1; i++)
		{
			swap(a, b);
			a += 2; b += 2;
		}
	}
	//STAMPA
	cout << "\nil vettore ordinato e:\n\n";
	for (int i = 0; i < N; i++)
		cout << Ve[i] << " ";
	system("pause>nul");
	return 0;
}