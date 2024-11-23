#include <iostream>
using namespace std ;
int main (){
    int h = 13;
    for ( int row = 1 ; row <= 2*h - 1  ; row ++){
        int aRow = ( row <= h ) ? row : abs( 2*h - row);
        //aRow : absolute row  1 st row have the same role as 9 th row
        for ( int column = 1  ; column <= aRow ; column ++ ) {
            if ( column == aRow) {
                cout<<"1";
            } else if ( column %2 == 0 && aRow %2 == 0){
                cout<<aRow + column - 1 ;
            } else if ( column %2 != 0 && aRow %2 != 0){
                if ( column == 1 ) cout <<aRow*2 + 1 ;
                else cout<< aRow - column +1;
            }else {
                cout<<" ";
            }
        }
        cout<<endl;
    }
return 0 ;
}
