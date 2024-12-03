#include <iostream>
using namespace std;

void inputArray(int *p, int sizee) {
    for (int i = 0; i < sizee; i++) {
        cin >> *(p+i);
    }
}
int main() {
    int sizee;
    cin >> sizee;
    int arr[sizee];
    inputArray(arr, sizee);
    int maxx = 0 , target = 0 ;
    for ( int i  = 0 ; i < sizee ; i++) maxx = (maxx >= arr[i]) ? maxx : arr[i];
    for ( int i  = 0 ; i < sizee ; i++) {
        if( arr[i] == maxx ) continue ;
        else target = ( target >= arr[i] ) ? target : arr[i];
    }
    cout<<target ;
    return 0;
}
