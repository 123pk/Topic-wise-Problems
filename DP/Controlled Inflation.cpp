/*
Platform :- Coding Competition with google
Contest :- Google Codejam 2022 Round 1B
Approach :- We will try to bruteforce all the permutations possibls for array of each people and then using dp we will try to find optimal soluton ,
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    for(int xxx = 1;xxx<=t;++xxx){
        cout<<"Case #"<<xxx<<": ";
        int n,p;
        cin>>n>>p;
        
        vector<long long>temp;
        vector<vector<long long>>A(n,vector<long long>(p));
        for(int i=0;i<n;++i){
            for(int j=0;j<p;++j){
                cin>>A[i][j];
            }
        }
        
        int x = 1;
        
        vector<long long>z;
        for(int i=0;i<p;++i)z.push_back(i);
        
        for(int i=1;i<=p;++i){
            x*=i;
        }
        p = x;
        
        //so what options do we have 
        //in pair first store the cost till this index and second store the last value where we ended
        vector<vector<vector<long long>>>dp(n,vector<vector<long long>>(6));
        long long cost = 0,last = 0;
        //we initialise the starting state of the dp
        for(int i = 0;i<n;++i){
            
            temp.clear();
            temp = z;
             
            sort(temp.begin(),temp.end());
            int j = 0;
            do{
                cost =  0;
                last = 0;
               for(int k = 1;k<temp.size();++k){
                   int idx = temp[k];
                   int lid = temp[k-1];
                   cost+=abs(A[i][idx]-A[i][lid]);
                   last = A[i][idx];
               }
            
               if(i == 0)cost+=A[i][temp[0]];
               
               dp[i][j] = {cost,A[i][temp[0]],last};
               j++;    
            }
            while(next_permutation(temp.begin(),temp.end()));
        }
        
        vector<vector<long long>>fin(n,vector<long long>(p,1e18));
        for(int j=0;j<p;++j){
            fin[0][j] = dp[0][j][0];
        }
        //now we have initialised with all the values now we will run a loop from i = 1 to n
        //and we will use the stored data to find the min cost till that ith index choosing the jth permutation of ith array
        for(int i =1;i<n;++i){
            
            
            for(int j=0;j<p;++j){
                long long tot = 0;
                
                for(int k = 0;k<p;++k){
                //    cout<<i<<" "<<j<<" "<<k<<endl;
                     
                    tot = fin[i-1][k] + dp[i][j][0] + abs(dp[i-1][k][2]-dp[i][j][1]);
                    fin[i][j] = min(fin[i][j],tot); 
                }
            }
        }
        
        long long ans = 1e18;
        for(int j =0;j<p;++j){
            ans = min(ans,fin[n-1][j]);
        }
        
        
        
        cout<<ans<<"\n";
    }
}
