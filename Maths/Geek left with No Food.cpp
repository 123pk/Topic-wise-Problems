/*
Job-A-thon
*/
// { Driver Code Starts


#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution {
  public:
    int solve(int N) {
        // code here
        int ans = 0;
        
        while(N){
            if(N%2){
                int val = (N+1)/2;
                N -= val;
            }
            else N/=2;
            ans++;
        }
        return ans;
    }
};


// { Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        Solution obj;
        int res = obj.solve(N);
        
        cout<<res<<endl;
        
    }
}
  // } Driver Code Ends
