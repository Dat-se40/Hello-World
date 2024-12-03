#include<iostream>
using namespace std;
void inputArray(int *p, int sizee) {
    for (int i = 0; i < sizee; i++) {
        cin >> *(p+i);
    }
}

int main (){
    int sizee , k , p;
    cin >> sizee;
    int arr[sizee];
    inputArray(arr, sizee);
    cin>>p>>k ;
    int j = 0  ;
    for ( int i = 0 ; i < sizee ; i++){
        if ( i >= p && i < (p+k)) continue ;
        else {
            arr[j]= arr[i];
            j++;
        }
    }
    for ( int i = 0 ; i < ( sizee - k ) ; i++) cout<<arr[i]<< " ";
   return 0 ;
}
