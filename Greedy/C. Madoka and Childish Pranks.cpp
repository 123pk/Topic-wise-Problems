/*
Platform :- Codeforces
Contest :- Codeforces Round 777 Div 2
Approach :- It is always optimal to come from n,m to (1,1) and we have '1' in our matrix we choose a rectange of (i,j-1) to (i,j) , for all j>1,
            --> if we have (1,1) of our matrix as  '1' then we dont have any possible answer
            --> if we have no cells with '1' then we have '0' operations to perform
            --> we will perform 'e' operations where 'e' is no of '1' in our matrix , for a values which is '1' at j = 0, in this case we choose (i-1,j) to (i,j) rectangle
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n,m;
        cin>>n>>m;
        
        
        char ch[n][m];
        int e = 0;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                cin>>ch[i][j];
                if(ch[i][j] == '1'){
                    e++;
                }
            }
        }
        
        if(e == 0){
            cout<<0<<"\n";
        }
        else{
            if(ch[0][0] == '1'){
                cout<<"-1\n";
            }
            else{
                 
                cout<<(e)<<"\n";
               
                for(int i = n-1;i>=0;--i){
                    for(int j = m-1;j>=0;--j){
                        if(ch[i][j] == '0')continue;
                        if(j==0){
                            cout<<(i)<<" "<<(j+1)<<" "<<(i+1)<<" "<<(j+1)<<"\n";
                        }else{
                            cout<<(i+1)<<" "<<(j)<<" "<<(i+1)<<" "<<(j+1)<<"\n";
                        }
                    }
                }
            }
        }
    }
}
