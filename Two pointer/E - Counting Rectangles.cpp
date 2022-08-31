/*
Platform :- Codeforces
Contest :- Codeforces Round 817 Div 4
Approach :- We maintain prefix sum for each row where A[i][j] gives me the area of square in in range i<= height and j<=width , 
            now for each query we travese through columnn or row depending upon the prefix sum we have maintained we find the value in range specified 
            for columns from b1+1 to b2-1
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    
    //string s = "Timur";
    //sort(s.begin(),s.end());
    //int len  = s.size();
    
    while(t--){
        int n,q;
        cin>>n>>q;
        
        int A[1000][1000] = {0};
        
        for(int i=0;i<n;++i){
            int x,y;
            cin>>x>>y;
            x--;
            y--;
            A[x][y]++;
        }
        
        for(int i=0;i<1000;++i){
            int tot = 0;
            for(int j=0;j<1000;++j){
                int val = (i+1ll)*(j+1ll);
                tot += (val*A[i][j]);
                A[i][j] = tot;
            }
        }
        
        for(int i=0;i<q;++i){
            int h1,w1,h2,w2;
            cin>>h1>>w1>>h2>>w2;
            h1--;w1--;h2--;w2--;
            
            long long tot = 0;
            for(int j=h1+1;j<h2;++j){
               // cout<<j<<" "<<w2<<" "<<w1<<"\n";
                tot += (A[j][w2-1]);
                 
                tot-=A[j][w1];
            }
            cout<<tot<<"\n";
        }
        
    }
}
