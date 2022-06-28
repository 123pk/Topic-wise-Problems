/*
Platform :- Codeforces 
Contest :- Codeforces Round 803
*/
#include<bits/stdc++.h>
using namespace std;


int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        
        long long A[n];
         int c = 0,d = 0;
         map<long long, int>P;
        for(int i=0;i<n;++i){
            cin>>A[i];
            P[A[i]]++;
            if(A[i]>0)c++;
            if(A[i]<0)d++;
        }
        
        sort(A,A+n);
        
        if(n <= 100){
            int f = 0;
            for(int i=0;i<n;++i){
                for(int j=i+1;j<n;++j){
                    for(int k=j+1;k<n;++k){
                        long long val = A[i]+A[j]+A[k];
                        if(P[val] == 0){
                            f=1;break;
                        }
                    }
                    if(f)break;
                }
                if(f)break;
            }
            
            if(f)cout<<"NO\n";
            else cout<<"YES\n";
            continue;
        }
        
        if(c>1 ||  d>1)cout<<"NO\n";
        else{
            if((c+d) == n)cout<<"NO\n";
            else if(c && d){
                if(A[0]+A[n-1])cout<<"NO\n";
                else cout<<"YES\n";
            }
            else cout<<"YES\n";
        }
        
        
    }
    
}
