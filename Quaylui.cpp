//BackTrack
#include<iostream>
#include<vector>
using namespace std;

vector<int> Container(1001,0);  // Tăng size lên 1001
vector<bool> used(1001,false); 
class Solution {   
public:      
    void PrintContainer(int n) {         
        for (int t = 1; t <= n; t++) 
            cout << Container[t];             
        cout << endl;     
    }
    void BinCode( int i , int n ){         
        for ( int j = 0 ; j <= 1 ; j++){             
            Container[i] = j ;             
            if (  i == n  ) PrintContainer(n) ;             
            else  BinCode( i + 1  , n );         
        }     
    }
    void List_NPK(int i, int k, int n) {         
    for (int j = 1; j <= n; j++) { 
        if (!used[j]) {
            used[j] = true;
            Container[i] = j;
            if (i == k) 
                PrintContainer(k);            
            else 
                List_NPK(i + 1, k, n);
            used[j] = false;
            }
        }        
    }
    void List_NCK(int i, int k, int n) {         
        for (int j = Container[i-1] + 1 ; j <= n; j++) { 
            Container[i] = j;
            if (i == k) 
                PrintContainer(k);            
            else 
                List_NCK(i + 1, k, n);         
        }     
    }        
};  

int main() {     
    Solution Problem1;      
    Problem1.List_NPK(1, 3, 4);  
    system("pause") ;  
    return 0; 
}