/*
Platform :- GeeksforGeeks
Approach :- This is classical unbounded knapsack problem . We will first write bruteforce recursion then we will optimise it using memoisation.
*/
// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int dp[1001];
    int find(int len,vector<int>&prices){
        if(len == 0)return 0;
        if(dp[len])return  dp[len];
        int ans = 0;
        
        for(int cut_length = 1;cut_length<=prices.size();++cut_length){
            if((len-cut_length)>=0){
                ans = max(ans,find(len-cut_length,prices)+prices[cut_length-1]);
                ;
            }
        }
        
        return dp[len] = ans;
    }
    
    int cutRod(int price[], int n) {
        //code here
        memset(dp,0,sizeof(dp));
        vector<int>prices(price,price+n);
        return find(n,prices);
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}  // } Driver Code Ends
