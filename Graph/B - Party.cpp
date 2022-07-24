/*

*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n,m;
        cin>>n>>m;
        
        vector<vector<int>>graph(n);
        vector<int>count(n);
        vector<long long>value(n);
        for(int i=0;i<n;++i)cin>>value[i];
        
        
        for(int i=0;i<m;++i){
            int x,y;
            cin>>x>>y;
            x--;
            y--;
            graph[x].push_back(y);
            graph[y].push_back(x);
            count[x]++;
            count[y]++;
        }
        
        if(m%2 == 0)cout<<"0\n";
        else{
            //we have to remove one of the odd value
            vector<int>odd,eve;
            long long ans = 1e18;
            
            for(int i=0;i<n;++i){
                if(count[i]%2){
                    ans = min(ans,value[i]);
                }
                else{
                    eve.push_back(i);
                }
            }
            
            //now for alle vel{
            for(int i=0;i<eve.size();++i){
                //find the sum
                long long val = value[eve[i]];
                for(auto&x:graph[eve[i]]){
                    if(count[x]%2 == 0){
                        ans = min(ans,val+value[x]);
                    }
                }
            }
            
            cout<<ans<<"\n";
        }
    }
}
