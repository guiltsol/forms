

#include <iostream>
#include "TBitField.h"
#include "TSet.h"

int main()
{
	TBitField A(103);
	
	TBitField C;
	
	A.Add(8);
	cout<<A.TString(103)<<endl;
	A.Add(2);
	cout << A.TString(103) << endl;
	A.Add(72);
	cout << A.TString(103) << endl;
	A.Add(32);
	cout << A.TString(103) << endl;
	A.Add(64);
	cout << A.TString(103) << endl;
    C = A;
	cout <<"C=A:" << C.TString(103) << endl;
	TBitField B(103);
	B.Add(8);
	
	B.Add(2);
	
	B.Add(79);
	
	B.Add(54);
	
	B.Add(9);
	cout <<"A: "<< A.TString(103) << endl;

	cout << "B: "<<B.TString(103) << endl;
	TBitField D;
	TBitField E;
	TBitField J;
	
	D = A.operatorV(B);
	cout << "AVB: " << D.TString(103)<< endl;
    E = A.operatorv(B);
	cout << "AvB: " << E.TString(103) << endl;
	J = ~A;
	cout << "~A: " << J.TString(103) << endl;
	////////////////////////////////////////////////////

	TSet K(30);
	K.Add(2);
	K.Add(17);
	cout << "K: " << K.TSetToString() << endl;
	TSet L(30);
	L.Add(2);
	L.Add(6);
	cout << "L: " << L.TSetToString() << endl;
	TSet P;
	P = K;
	cout << "P=K: " << P.TSetToString() << endl;
	P = K.operatorV(L);
	cout << "KVL: " << P.TSetToString() << endl;
	P = K.operatorv(L);
	cout << "KvL: " << P.TSetToString() << endl;
	P = ~K;
	cout << "~K: " << P.TSetToString() << endl;



	
	return 0;
}

