//esercizio 14
#include <iostream>
using namespace std;
 main()
 {
 int n, k,i=1,NU,S;
 float M;
 
 cout<<"di quanti numeri vuoi fare la media?\t";
 cin>>n;
 k=n;
 while(k!=0)
 {
 cout<<"\n dammi il "<<i<<" numero :\t";
 cin>>NU;
 S=S+NU;
 k=k-1;
 i=i+1;
 }
 M=S/n;
 cout<<"\nla media e ':\t"<<M;
 system("pause>nul");
 return 0;
 }
