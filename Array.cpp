#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <algorithm>
using namespace std;
class SolutionArr
{
public:
    static vector<int> PairSum( vector<int> &nums , int target ){
        int i = 0 , j  = nums.size() - 1 ;
        vector<int> ans ; 
        while (  i < j ){// Vector sorted , di tu hai phia vao
            int sum = nums[i] + nums[j];
            if ( sum > target) j--;
            else if ( sum < target) i++;
            else{
                ans.push_back( nums[i] );
                ans.push_back( nums[j] );
                return ans;
            }
        } 
        vector<int> answer(2,0) ;
        return ans; 
    }    
    static int Maximum_Subarray_Sum(vector<int> &nums)
    {   //Kadane's Algorithm// Roi thu tu rat qua trong(1)
        int maxSum = INT_MIN, currSum = 0 ;
        for (int indi : nums)
        {
            currSum += indi;
            maxSum = max(maxSum, currSum);
            if (currSum < 0)
                currSum = 0;
        }
        return maxSum ;
    }
    static int singleNumber(vector<int> &nums)
    {//XOR
        int single_number = 0;
        for (int i : nums)
        {
            single_number ^= i;
        }
        return single_number;
    }
    static int MajorityElement( vector<int> nums){
        //Moore's Voting Algorithm //thu tu rat quan trong(2)
        int fre = 0, ans = nums[0];
        for( int i  : nums){
            if ( fre == 0 ) ans = i ;
            if ( ans == i ) fre++;
            else fre--;
        }
        return ans;
    }
    static vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size() ; 
        vector<int> result(2,0 ) ; 
        vector<int> fre(n*n  + 1 , 0 );
        int ExpectSum = 0 , RealSum = 0 ;
        for ( int i = 1 ; i <= n*n ; i++) ExpectSum +=i ; 
        for ( int  i  = 0 ; i < n ; i++){
            for ( int j = 0 ; j < n ; j++){
                RealSum += grid[i][j];
                fre[ grid[i][j] ] ++;
                if ( fre[ grid[i][j] ]== 2 ) result[0] = grid[i][j];
            }
        }
        result[1]= ExpectSum - RealSum + result[0]; 
        return result;
    }
};
int main()
{
    SolutionArr Solve1;
    vector<vector<int>>grid = { {2,3} , {2,1}} ;
    SolutionArr::findMissingAndRepeatedValues(grid);
    system("pause");
    return 0;
}
