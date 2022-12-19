#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        //the main motive is get the max
        int n;
        cin>>n;
        
        long long A[n];
        vector<int>fre(32);
        long long val = 0,ad = 0;
        for(int i=0;i<n;++i){
            cin>>A[i];
            val |= A[i];
            if(i == 0)ad = A[i];
            else ad&=A[i];
        }
        
        val -= ad;
        cout<<val<<"\n";
    }
}
