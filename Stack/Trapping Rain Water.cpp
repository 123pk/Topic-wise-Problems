/*
Platform :- Geeksforgeeks
Approach :- We can trap water in non-decresasing subsequence from (0th index to 'last_max_elemet') and non_increasing sequence from (n-1 to max_element)we also maintain
           vis array to store the index which are already being used.
           We will use stack to find non- increasing and non_decreasing subsequence.
Time Complexity :- O(N)
*/
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        // code here
        long long tot = 0;
      //  long long pref[n];
      vector<int>vis(n);
        stack<pair<long long,int>>P;
        for(int i=0;i<n;++i){
            if(i == 0)P.push({arr[i],i});
            else{
                if(P.top().first<=arr[i]){
                    P.push({arr[i],i});
                }
            }
        }
        
        pair<long long,int>temp1,temp2;
        tot = 0;
        int c = 0;
        while(!P.empty()){
            if(c == 0){
                c++;
                temp1 = P.top();
                P.pop();
            }
            else{
                temp2 = P.top();
                P.pop();
                long long val = temp2.first;
                vis[temp2.second]++;
                vis[temp1.second]++;
                for(int i=temp2.second+1;i<temp1.second;++i){
                    tot += (val - arr[i]);
                    vis[i]++;
                }
               temp1 = temp2;
            }
        }
        
        //now same but from right to left
        for(int i=n-1;i>=0;--i){
            if(i == n-1)P.push({arr[i],i});
            else{
                if(P.top().first<arr[i]){
                    P.push({arr[i],i});
                }
            }
        }
        
         c = 0;
        while(!P.empty()){
            if(c == 0){
                c++;
                temp1 = P.top();
                P.pop();
            }
            else{
                temp2 = P.top();
                P.pop();
                long long val = temp2.first;
                for(int i=temp1.second+1;i<temp2.second;++i){
                    if(vis[i])break;
                    tot += (val - arr[i]);
                }
               temp1 = temp2;
            }
        }
        
        
        return tot;
    }
};
