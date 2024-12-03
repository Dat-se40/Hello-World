#include<iostream>
using namespace std;
void inputArray(int *p, int sizee) {
    for (int i = 0; i < sizee; i++) {
        cin >> *(p+i);
    }
}
void Delete( int arr[] ,int &k , int &p ){
    for ( int i = p ; i < p + k ; i++){
        arr[i] = 0 ;
    }
}
int main (){
    int sizee , k , p;
    cin >> sizee;
    int arr[sizee];
    inputArray(arr, sizee);
    cin>>p>>k ;
    Delete( arr , k , p ) ;
    for ( int i = 0 ; i < sizee ; i++){
        if ( arr[i] == 0 ) continue ;
        else cout<< arr[i]<< " ";
    }
    return 0;
}

