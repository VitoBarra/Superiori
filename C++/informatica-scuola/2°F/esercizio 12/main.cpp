//esercizio 9
#include <iostream>
using namespace std;
 main()
 {
 float SP,SC;
 cout<<"prezzo iniziale:\t";
 cin>>SP;
 if(SP>100)
 {
 	SC=SP*15/100;
 	SP=SP-SC;
 }
 cout<<"\nil prezzo finale e'\t"<<SP;
 system("pause>nul");
 return 0;
 }
