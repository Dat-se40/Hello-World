#include <iostream>
#include <vector>
#define ST static int
    // Binary Search tequnique using 2 pointers  start and end to determine range of searching 
    // Time complexity O(logn) , Space complexity O(1)
    // Using for sorted container or rotated
    // Handle edge case  arr[0] / arr[ arr.size() - 1 ]
using namespace std;
class PointerSolution
{
public:
    ST BinarySearch(vector<int>& nums, int target)
    {
        int start = 0, end = nums.size() - 1;
        if (target < nums[start] || target > nums[end])
            return -1;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (nums[mid] > target)
                end = mid - 1;
            else if (nums[mid] < target)
                start = mid + 1;
            else
                return mid;
        }
    }
    ST SearchRotatedSortedArr(vector<int>& nums, int target) {
        int start = 0, end = nums.size() - 1 ;
        while (start <= end ){
            int mid = start + (end - start) / 2;
            if ( target == nums[mid] ) return mid ;
            if ( nums[start] <= nums[mid]){
                if ( (target <= nums[mid] && target >= nums[start]) ){
                    end = mid - 1 ;
                } else start = mid + 1;  
            }else {
                if ( (target <= nums[end] && target >= nums[mid]) ){
                    start = mid + 1 ; 
                } else  end = mid - 1;
            }
        }
        return -1 ;     
    }
    ST peakIndexInMountainArray(vector<int>& arr) {
       int start = 0 , end = arr.size() - 1 ; 
       while (start <= end){
            int mid = start + (end - start) / 2 ;
            if( arr[mid] > arr[mid + 1] && arr[mid] > arr[mid - 1] ) return mid ;
            if ( arr[mid] < arr[mid +1] )
                start = mid ;
            else if ( arr[mid] < arr[mid -1])
                end = mid ; 
       }
       return -1 ; 
    }
    ST singleNonDuplicate(vector<int>& nums) {
        int start = 0 , end = nums.size() - 1 , mid = 0   ;
        if ( nums[0] != nums[1] || end == 0  ) return nums[0];
        if ( nums[end] != nums[end - 1] ) return nums[end];
        while ( start <= end){
            mid = start + (end - start) / 2 ;
            int LeftSize = mid - start , RightSize = end - mid ;
            if ( nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1] ) return nums[mid] ;
            if (  mid % 2 == 0 ){
                if ( nums[mid] == nums[mid  - 1]) end = mid - 1 ; 
                else start = mid + 1;
            }else{
                if ( nums[mid] == nums[mid - 1 ]) start = mid + 1 ; 
                else end = mid - 1; 
            }
        }
        return mid;
    }
};
int main()
{
    vector<int> vec = {1,2,2,3,3};
    cout << PointerSolution().singleNonDuplicate(vec) << endl;  
    system("pause");
    return 0;
}