#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;
int main()
{
    int n, angle[1000], pos[1000], start = 0, end = 0, k = 1 ;
    cin >> n;
    pos[0] = 0;
    for (int i = 0; i < n; i++)
    {
        cin>>angle[i];
        end = start + angle[i];
        if ( end >= 360 ) end %= 360;
        pos[k] = end;
        start = end;
        k++;
    }
    int maxAngle = 0   ; 
    sort( pos , pos + k  ) ;
    for ( int i = 0  ; i < k - 1 ; i++)  maxAngle = max(maxAngle, pos[i+1] - pos[i]);   
    cout<<maxAngle<<endl; 
    return 0;
}