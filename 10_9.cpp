#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
struct HANGTU{
    float heso;
    int bac;
};
struct DATHUC{
    int soHT;
    HANGTU *p;
};
void nhapHangTu( HANGTU &a ){
	cin>>a.heso>>a.bac;
}
DATHUC *Nhap(){
	DATHUC *b = new DATHUC ;
	cin>>b->soHT;
	b->p = new HANGTU[b->soHT  ];
	for ( int i = b->soHT - 1 ;  i >= 0 ;i--){
		nhapHangTu( b->p[i]);
}
    return b;
}
void Xuat(DATHUC D) {
    bool firstTerm = true;
    for (int i = D.soHT -1 ; i >= 0 ; i--) {
        if (D.p[i].heso != 0) {
            if (!firstTerm) {
                if (D.p[i].heso > 0) cout << "+";
                else cout << "-";
            } else {
                if (D.p[i].heso < 0) cout << "-";
                firstTerm = false;
            }
            if (abs(D.p[i].heso) != 1 || D.p[i].bac == 0) cout << abs(D.p[i].heso);
            if (D.p[i].bac > 0) cout << "x";
            if (D.p[i].bac > 1) cout << "^" << D.p[i].bac;
        }
    }
    if (firstTerm) cout << "0";
}
double TinhDaThuc( DATHUC A , float x){
    double f_x = 0 ;
    for ( int i = A.soHT - 1 ; i >= 0 ; i-- ) f_x += A.p[i].heso*pow(x,A.p[i].bac);
    return f_x;
}
