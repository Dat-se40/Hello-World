#include <iostream>
#define MAXN 100
using namespace std;

struct PhanSo {
    int tu, mau;
};

int ucln(int a, int b) {
    if (b == 0) return a;
    return ucln(b, a % b);
}


void fomating(PhanSo &A) {
    int sochia = ucln(A.tu, A.mau);
    A.tu /= sochia;
    A.mau /= sochia;

    if (A.mau < 0) {
        A.tu = -A.tu;
        A.mau = -A.mau;
    }
}


void Nhap(PhanSo &a) {
    cin >> a.tu >> a.mau;
    fomating(a);
}
PhanSo Nhap(){
    PhanSo a;
    cin >> a.tu;
    cin >> a.mau;
    fomating(a);
    return a;
}

void xuatPS(PhanSo a) {
    if (a.mau == 0) cout << "Khong thoa yeu cau bai toan";
    else if (a.mau == 1) cout << a.tu;
    else if (a.tu == 0) cout << "0";
    else cout << a.tu << "/" << a.mau;
}

PhanSo congtru(PhanSo A, PhanSo B, int pheptinh) {
    PhanSo C;
    C.tu = A.tu * B.mau + (pheptinh == 1 ? 1 : -1) * B.tu * A.mau;
    C.mau = A.mau * B.mau;
    fomating(C);
    return C;
}


int SoSanh(PhanSo A, PhanSo B) {
    PhanSo C = congtru(A, B, 0); 
    if (C.tu > 0) return 1;     
    else if (C.tu < 0) return -1; 
    return 0;                    
}
int main() {
    PhanSo a, b;
    Nhap(a);
    b = Nhap();
    int kq = SoSanh(a, b);
    if (kq == 0)
        std::cout << "Hai phan so bang nhau.";
    else if (kq > 0)
        std::cout << "Phan so thu nhat LON hon phan so thu hai.";
    else
        std::cout << "Phan so thu nhat NHO hon phan so thu hai.";
    return 0;
}
