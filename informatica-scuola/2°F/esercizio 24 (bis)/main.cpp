//esercizio 24(bis)
#include <iostream>
#include <conio.h>
using namespace std;
void Dec_Bin (int);
 main()
 {
 int x;
 cout<<"inserisci un numero da canvertire:\t";
 cin>>x;
 cout<<"\nil numero binario vale:\t";
 Dec_Bin(x);
 system("pause>nul");
 return 0;
 }
 
 
 void Dec_Bin(int a)
 {
 	if(a>0)
 	{	
 	Dec_Bin(a/2);
	 cout<<a%2;	
	}
 }
