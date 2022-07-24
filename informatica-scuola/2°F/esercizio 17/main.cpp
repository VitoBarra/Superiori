//esercizio 17
#include <iostream>
using namespace std;
 main()
 {
 int N,K,P;
 do
 {
 cout<<"dammiun numero:\t";
 cin>>N;
 K=N%2;
 if(K==0)
 P=P+1;
 }while(N!=0);
  cout<<"\ni numeripari sono:\t"<<P;
 system("pause>nul");
 return 0;
 }
