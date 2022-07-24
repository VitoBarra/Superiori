//esercizio 19
#include <iostream>
using namespace std;
 main()
 {
 int n,P=1,K=0, i=1;
 cout<<"quanti numeri dispari vuoi:\t";
 cin>>n;
 while(K<n)
 {
 cout<<"\n numero "<<i<<" dispari:\t"<<P;
 P=P+2;
 K++;
 i++;
 }
 system("pause>nul");
 return 0;
 }
