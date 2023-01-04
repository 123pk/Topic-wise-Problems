/*
Platform :- Geeksforgeeks
Contest :- Mega Job-A-thon 4 january
Approach :- First create on 2d dp where dp[i][j] -- store the no of points in rectangle from 1,1 to i,j
            we create 2d dp of size (max_x coordinate,max_y coordinate) in array.
Time Compelxity :- O(n^2)
Space Complexity :- O(mxx*mxy) - O(n^2)
*/
// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int maximumpoints(vector<vector<int> >& arr, int n, int x, int y) {
        // code here
        
        int mxx = 0,mxy = 0,mnx = 1000,mny = 1000;
        for(auto&x:arr){
            mxx = max(mxx,x[0]);
            //mnx = min(mnx,x[0]);
            mxy = max(mxy,x[1]);
           // mny = min(mny,x[1]);
        }
        vector<vector<int>>dp(mxx+1,vector<int>(mxy+1));
        for(auto&x:arr)dp[x[0]][x[1]]++;
        
        //we make the dp
        //wheere dp[i][j] = no of region from 1,1, to i,j recatnge
        for(int k=2;k<=mxx;++k){
          int     j = 1, i= k;
        while(i>=1 && j<=mxy){
            if(j == 1){
                dp[i][j] += dp[i-1][j];
            }
            else if(i == 1){
                dp[i][j] += dp[i][j-1];
            }
            else{
                dp[i][j] += (dp[i-1][j] + dp[i][j-1]-dp[i-1][j-1]);
            }
            i--;
            j++;
        }
        
        }
         
        
        for(int k=2;k<=mxy;++k){
            int i = mxx,j = k;
            while(j<=mxy && i>=1){
                if(j == 1){
                  dp[i][j] += dp[i-1][j];
                }
               else if(i == 1){
                  dp[i][j] += dp[i][j-1];
               }
               else{
                  dp[i][j] += (dp[i-1][j] + dp[i][j-1]-dp[i-1][j-1]);
              }
              i--;
              j++;
            }
        }
        
        int ans = 0;
        
        
        for(int i=1;i<=mxx;++i){
            for(int j=1;j<=mxy;++j){
                //get the top count 
                int up = i - (x+1);
                int left = j - (y+1);
                //get the left count
                //get the top left count
                int cur = dp[i][j];
                int rem = 0;
                if(up>=1){
                    rem += dp[up][j];
                }
                
                if(left>=1){
                    rem += dp[i][left];
                }
                
                if(up>=1 && left>=1){
                    cur += dp[up][left];
                }
                
                cur-=rem;
                ans = max(ans,cur);
                
            }
        }
        
        return ans;
    }
};


// { Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;

        vector<vector<int> > arr(n, vector<int> (2, 0));
        for (int i = 0; i < n; i++)
            cin >> arr[i][0] >> arr[i][1];

        int x, y;
        cin >> x >> y;

        Solution ob;
        cout << ob.maximumpoints(arr, n, x, y) << "\n";
    }
    return 0;
}
  // } Driver Code Ends
