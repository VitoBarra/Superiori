//esercizio 24
#include <iostream>
using namespace std;
 main()
 {
 int A=1,N;
 cout<<"dammi il numero da convertire:\t";
 cin>>N;
 cout<<endl;
 while (A<=N)
 A=A*2;
 A=A/2;
 do
 {
 if(N>=A)
 {		
 cout<<"1";	
 N=N-A;
 }
 else
 cout<<"0";
 A=A/2;	
 }while(A!=0);
 system("pause>nul");
 return 0;
 }
