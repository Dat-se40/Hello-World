#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
// Concept: last in first out
// Gan gan nhau, kieu kieu doi xung, kieu doi lap triet lan nhau
using namespace std;
bool isValid(string s)
{
    if (s.length() % 2 != 0)
        return false;
    vector<char> open;
    int i = 0;
    while (s[i] != '\0')
    {

        if (s[i] == '{' || s[i] == '[' || s[i] == '(')
        { // Open
            open.push_back(s[i]);
        }
        else if (open.empty() == false)
        { // Close

            char last = open[open.size() - 1];
            if (last == '{' && s[i] == '}' || last == '[' && s[i] == ']' || last == '(' && s[i] == ')')
                open.pop_back();
            else
                return false; // Not matching
        }
        else
            return false; // If the first idx is close

        i++;
    }
    return open.empty();
}
class StockSpanner
{
public:
    stack<pair<int, int>> s;

    StockSpanner() {}

    int next(int price)
    {
        int span = 1;

        while (!s.empty() && s.top().first <= price)
        {
            span += s.top().second;
            s.pop();
        }

        s.push({price, span});
        return span;
    }
};

vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{
    unordered_map<int,int> map;
    stack<int> s;

    for (int i = nums2.size() - 1; i >= 0; i--)
    {
        while( s.size() > 0  && nums2[i] > s.top() ){
            s.pop();
        }
        
        if( s.empty()){
            map[ nums2[i] ] = - 1; 
        }else{
            map[ nums2[i] ] = s.top();
        }

        s.push(nums2[i] );
    }

    vector<int> ans ; 
    for( int i : nums1){
        ans.push_back( map[i] ) ;
    }

    return ans;
}
vector<int> PreviousSmaller( vector<int> &nums ){
    vector<int> ans(nums.size() , 0 ) ; 
    stack<int> s;

    for ( int i = 0 ; i < nums.size() ; i++){

        while( s.size() > 0 && nums[i] < s.top() ){
            s.pop();
        }

        if( s.empty() ){
            ans[i] = -1 ; 
        }else{
            ans[i] = s.top();
        }

        s.push( nums[i] );
    }

    return ans ;  
} 

class MinStack {
   
    public:
        stack<int>  s ;
        int minVal ; 
        MinStack() {}
        
        void push(int val) {
            if ( s.empty()) {
                s.push(val);
                minVal = val ; 
            } else if ( val < miVal){
                s.push( 2*val - minVal) ; 
                minVal = val ;
            }else{
                s.push(val);
            }
        }
        
        void pop() {
            if ( s.top() <  minVal ) minVal = 2*minVal - s.top();
            s.pop();
        }
        
        int top() {
            if ( s.top() < minVal) return minVal ; 
            else return s.top();
        }
        
        int getMin() {
            return minVal;
        }
    };

int main()
{
    MinStack* obj = new MinStack() ; 

    obj->push(-2);
    obj->push(0);
    obj->push(2);
    
    cout<<obj->getMin();

    system("pause");
}
/*vector<DayInfo> update( vector<int> stock){
    vector<DayInfo> temp ;
    for( int val : stock){
        temp.push_back( DayInfo(val) );
    }
    return temp ;
}
int MaxSpan( vector<DayInfo>& StockSpan){ // Dùng tham chiếu cho đỡ bộ nhớ
    int maxSpan = 1 ;
    vector<DayInfo> stack ;
    stack.push_back( StockSpan[0] );
    cout<<StockSpan[0].val<<" "<<StockSpan[0].span<<endl ;
    for( int i = 1 ; i < StockSpan.size() ; i++){

        while( !stack.empty() && StockSpan[i].val >= stack.back().val){
            StockSpan[i].span += stack.back().span;
            stack.pop_back();
        }
        stack.push_back( StockSpan[i] );
        cout<<StockSpan[i].val<<"  "<<StockSpan[i].span<<endl ;
        maxSpan = max( maxSpan , StockSpan[i].span ) ;
    }

    return maxSpan ;
}
*/
/*
class MinStack {
public:
     stack< pair<int, int> >  s ;
    public:
        MinStack() {}
        
        void push(int val) {
            if ( !s.empty() ){
                s.push( {val , min( s.top().second , val ) } )  ;
            }else{
                s.push( {val ,val} ) ;
            }
        }
        
        void pop() {
            s.pop();
        }
        
        int top() {
            return s.top().first ;
        }
        
        int getMin() {
            return s.top().second;
        }

};*/