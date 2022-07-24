//esercizio 18
#include <iostream>
using namespace std;
 main()
 {
 float n,k=0,S,NU;
 cout<<"dammi il numero dei numeri:\t";
 cin>>n;
 for(;k<n;k=k+1)
 {
 	cout<<"\ndammi un numero:\t";
 	cin>>NU;
 	S=S+NU;
 }
 S=S/n;
 cout<<"\nla media e':\t"<<S;;
 system("pause>nul");
 return 0;
 }
