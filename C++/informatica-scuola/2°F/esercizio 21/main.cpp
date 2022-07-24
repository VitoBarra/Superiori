//esercizio 21
#include <iostream>
using namespace std;
 main()
 {
 	int A,B,C,med;
 	
 cout<<"dammmi 3 numeri:\t";
 cin>>A;
 cout<<"\t";
 cin>>B;
 cout<<"\t";
 cin>>C;
 if (A>B)
 if (A>C)
 if(C>B)
 med=C;
 else
 med=B;
 else
 med=A;
 else
 if(B>C)
 if(C>A)
 med=C;
 else
 med=A;
 else
 med=B;
 cout<<"il medio e'\t"<<med;

 system("pause>nul");
 return 0;
 }
