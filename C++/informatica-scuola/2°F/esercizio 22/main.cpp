//esercizio 22
#include <iostream>
using namespace std;
 main()
 {
 int n,A,B,M,MA=0,i=0;
 cout<<"dammi un numero delle coppie:\t";
 cin>>n;
 for(;n>0;n=n-1)
 {
 i++;
 cout<<"\ndammi la "<<i<<" coppia di numeri:\t";
 cin>>A;
 cin>>B;
 if (A>B)
 M=A;
 else
 M=B;
 cout<<"\nil maggiore della coppia e'\t\t"<<M;
 if(M>MA)
 MA=M;
 cout<<endl;
 }
 cout<<"\nil magiore in assoluto e':\t"<<MA;
 system("pause>nul");
 return 0;
 }
