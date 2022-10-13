/*
Platform :- Codeforces
Contest :- Codeforces Contest 827 Div 4
Appraoch :- We get increasing value if we set a bit that is not set , so there can be atmax 30 bits inside current constraints . So we will can have atamax 30 values 
            which will be acutally setting a bit , we will run loop 32 times on array and each time we will find the one elements that will change the OR the most.
            We will mark them , we will choose from unmarked values and at the end the we take all the unmarked ones.
            
 Time Complexity :- O(n)
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        int A[n];
        for(int i=0;i<n;++i)cin>>A[i];
        vector<int>vis(n);
        vector<int>ans;
        
        //we have just 32 bits and we can set them
        int val = 0;
        for(int i=0;i<32;++i){
            int score = val;
            int idx = -1;
            for(int j=0;j<n;++j){
                if(vis[j])continue;
                int cur = val | A[j];
                
                if(cur>score){
                    score = cur;
                    idx = j;
                }
            }
            
            if(idx == -1)break;
            vis[idx]++;
            ans.push_back(A[idx]);
            val = score;
        }
        
        
        for(int i=0;i<n;++i){
            if(vis[i])continue;
            ans.push_back(A[i]);
        }
        
        for(auto&x:ans)cout<<x<<" ";
        cout<<"\n";
    }
}
