#include<bits/stdc++.h>
using namespace std;

bool check(string s,string p){
    sort(s.begin(),s.end());
    sort(p.begin(),p.end());
    
    for(int i=0;i<s.size();++i){
        if(s[i] != p[i])return false;
    }
    return true;
}

int main(){
    int t;
    cin>>t;
    
    while(t--){
         int n,k;
         cin>>n>>k;
         
        string s,p;
        cin>>s>>p;
        
        if(!check(s,p)){
            cout<<"NO\n";
            continue;
        }
        
        int f = 0;
        vector<int>vis(k);
        for(int i=0;i<min(k,n);++i){
            if((i+k)<n){
                continue;
            }
            if(s[i] != p[i]){
                f=1;
                break;
            }
            
        }
        
        if(f)cout<<"NO\n";
        else cout<<"YES\n";
         
    }
}
