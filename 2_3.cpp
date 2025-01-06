#include <iostream>
#include <vector>
#define MOD 1000000007
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> arr(n);
    long long sum = 0, sumMultiple = 0;

   
    for (auto &x : arr) {
        cin >> x;
        sum = (sum + x) % MOD;  
    }

   
    for (int i = 0; i < n; i++) {
        sum = (sum - arr[i] + MOD) % MOD;  
        sumMultiple = (sumMultiple + arr[i] * sum % MOD) % MOD; 
    }

    cout << sumMultiple << endl;

    return 0;
}