//esercizio 15
#include <iostream>
using namespace std;
 main()
 {
 int n,A,MI;
 cout<<"quantinumeri vuoi leggere:\t";
 cin>>n;
 cout<<"\ndammi un numero:\t";
 cin>>A;
 MI=A;
 while(n>1)
 {
 	cout<<"\ndammi un numero\t";
 	cin>>A;
 	if(A<MI)
 	MI=A;
 	n=n-1;
 }
 cout<<"\nil minore e ':\t"<<MI;
 system("pause>nul");
 return 0;
 }
