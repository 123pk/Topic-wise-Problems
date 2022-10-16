/*
Platform :- Codeforces
Contest :- Codeforces Round 827 
Approach :- We will find 2^x that we have in our array from the elements by dividing them by '2' , then we will use one array to store the additional power that we can ad
            if we have 'x'>=n we don't need to do any operation , else we will sort the values arrray which store the power of '2' for each index in decresaing order
            and keep incrementing 'x' if 'x'<n after all the addition then it is not possible else we will maintain count which will be our answer.
            
Time Complexity :- Nlog(N)
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
        int c = n;
        for(int i=0;i<n;++i){
            cin>>A[i];
            while(A[i]%2ll == 0){
                A[i]>>=1ll;
                c--;
            }    
        }
     //  cout<<c<<" ";
        if(n%2)n--;
        int op = 0;
        vector<int>P;
        for(int i=n;i>=1;i-=2){
            int d = i;
            int count = 0;
            while(d%2 == 0){
                d/=2;
                count++;
            }
            P.push_back(count);
        }
        
        
        sort(P.begin(),P.end(),greater<int>());
        for(int i=0;i<P.size();++i){
            if(c<=0)break;
            c -= P[i];
            op++;
        }
        
        if(c<=0)cout<<op<<"\n";
        else cout<<"-1\n";
        
        
    }
}
