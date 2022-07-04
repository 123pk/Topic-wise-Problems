/*
Platform :- Codeforces
Contest :- Codeforces Round 804 Div 2
Approach :- Constructive algorithm (10) start with this horizontally and vertically change it alternatingy(01) .. so after (10 -- 01 .. 10 ..01) and so on 
           same vertically
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n,m;
        cin>>n>>m;
        
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(i%4 == 0 || i%4 == 3){
                    if(j%4 == 0 || j%4 == 3){
                        cout<<"1 ";
                    }
                    else{
                        cout<<"0 ";
                    }
                }
                else{
                    if(j%4 == 0 || j%4 == 3){
                        cout<<"0 ";
                    }else{
                        cout<<"1 ";
                    }
                }
            }
            cout<<"\n";
        }
        //cout<<"\n";
    }
}
