/* Give a number X has n digits , changes only one digit among n digits to make a new Number Z which is div 3 == 0 , find maxZ */
// Y tuong : bai toan xac suat tao thanh so chia het cho 3 
#include <iostream>
using namespace std;
int numDig( int x) ;
int main (){
 int x ,tempX, div , k = 0;
 cin>> x ;
 tempX = x;
 int maxZ= x , currZ;
 int arr[ numDig(x)]={};
 for ( int i = 0 ; i < numDig(x) ; i++){
    arr[i]= tempX%10;
    tempX /=10;
 }
 div = x%3;
 //Lay phan du => tim phan con thieu ( 3 - div ) 
for ( int i = numDig(x)-1 ; i >= 0 ; i--){
    if ( arr[i] + 3 - div <= 9){
        k = arr[i] + 3 - div;
        while ( k + 3 <= 9) {
            k+=3;
        }
        // Tim gia tri K ma arr[i] se tro thanh
        // Cong luong ( k - arr[i]) de tu arr[i] thanh K
        int factor = 1;
            for (int j = 0; j < i; j++) {
                factor *= 10;
            }
        currZ = x + ( k - arr[i] )*factor;
       /* cout<<"Loop thu "<< i <<" : "<< currZ <<" = " <<x<< " + "<<( k - arr[i] )<<"*"<<factor<<endl; : //print debug */
        if ( currZ > maxZ){
        maxZ = currZ;
        break;
    }
    }
}
    cout<<maxZ;
    return 0 ;
 }
int numDig( int x) {
    int cnt = 0 ;
    while ( x!=0){
        x/=10;
        cnt++;
    }
return cnt ;
}

