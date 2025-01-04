````cpp
#include <iostream>
#include <iostream>
using namespace std ;
struct  number {
    int tens ;
    int unit ;
    int val ;
};
int calcVal(number &a){
    return a.tens*10 + a.unit ;
}
void findAB( int h , int k  ,number n ){
    number a , b ; 
    int avg = (h+k)/2;
    bool printed[100][100]={false};
    for ( int iTens = 1 ; iTens <= avg ; iTens++ ){
            b.tens = iTens;
            a.tens = h - b.tens;
            b.unit = avg - b.tens ;
            a.unit = k - b.unit;
            a.val = calcVal(a);
            b.val = calcVal(b);
            bool checked = printed[a.val][b.val] || printed[b.val][a.val] ;
            if ( ( a.val + b.val ) == n.val && ( a.val > 9 && b.val > 9 ) && checked == false) {
                    cout<<"("<<a.val<<","<<b.val<<") ";
                   printed[a.val][b.val] = true ;
            }
    }
    cout<<endl;
}
int main(){
    number n;
    n.val =  ;
    n.tens = n.val/10 ;
    n.unit = n.val%10 ;
    int avgCase1 = n.tens + n.unit ;
    int avgCase2 = n.tens - 1 + n.unit ;
    if ( avgCase1 % 2 == 0 ) findAB(n.tens , n.unit , n );
    if ( avgCase2 % 2 == 0 ) findAB(n.tens - 1 , n.unit+10 , n);
return 0 ;
}
