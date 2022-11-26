/*
Platform :- Codeforces
Contest :- Codeforces Global Round 24
Approach :- We will find the GCD of array and if it is '1' then we can have all values from 1 to A[n-1],
            else we can have total number of value = (A[n-1]/gcd)
Time Complexity :- O(n)
*/
#include<bits/stdc++.h>
using namespace std;

pair<int,int> find(int d,vector<int>&A){
    pair<int,int> len = {0,0};
    int score = -2;
    int c = 0;
    int lim = 1e5;
    lim++;
    vector<int>fre(lim);
    int start = 0;
    for(int i=0;i<A.size();++i){
        //cout<<"* ";
        if(fre[A[i]] == 0){
            if(c == d){
                //we need to move our start
                while(start<=i){
                    fre[A[start]]--;
                    if(fre[A[start]] == 0)break;
                    start++;
                }
                fre[A[i]]++;
            }
            else{
                fre[A[i]]++;
                c++;
            }
        }
        else{
            fre[A[i]]++;
        }
        
        if(c == d){
            int cur = (i-start)-d;
            if(score<(cur)){
                score = cur;
                len = {start,i};
            }
        }
    }
    
    
    return len;
}

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        
        long long val = 1e18;
        vector<long long>A(n);
        for(int i=0;i<n;++i){
            cin>>A[i];
            if(i){
                val = __gcd(val,A[i]);
            }
            else val = A[0];
        }
        
         
        int f = 0;
        for(int i=0;i<n;++i){
            if(A[i]%val){
                f=1;
                break;
            }
        }
        long long ans = 0;
        if(f){
            ans = A[n-1];
        }
        else ans = A[n-1]/val;
        
        cout<<ans<<"\n";
    }
}
