/*
Platform :- Geeksforgeeks
Contest :- Codefiesta by IIIT Nagpur
Approach :- We store the frequency array of each string , now we traverse through the query and then look for in frequency array ,the 
            smallest index where each of character of query are available that is our answer,if we couldnot find any we add -1 as there is no solution.
Time Complexity :- O(n*m)
*/
// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    vector<int> solve(int N, vector<string> &S, int Q, vector<string> &Query) {
        // code here
        
        vector<vector<int>>store;
        
        
        for(auto&x:S){
            vector<int>fre(26);
            for(auto&y:x){
                fre[y-'a']++;
            }
            store.push_back(fre);
        }
        
        vector<int>ans;  
        for(auto&x:Query){
            int c = 0,g = 0;
            for(auto&y:store){
              int f = 0;
               for(auto&z:x){
                   if(y[z-'a'] == 0){
                       f=1;
                       break;
                   }
               }
               if(f == 0){
                   g = c+1;
                   break;
               }
               c++;
            }
            ans.push_back(g-1);
        }
        
        return ans;
    }
};


// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int N, Q;
        cin >> N >> Q;

        vector<string> S(N), Query(Q);

        for (int i = 0; i < N; i++) cin >> S[i];
        for (int i = 0; i < Q; i++) cin >> Query[i];

        Solution sol;

        vector<int> ans = sol.solve(N, S, Q, Query);
        for (auto &it : ans) cout << it << " ";
        cout << "\n";
    }

    return 0;
}
  // } Driver Code Ends
