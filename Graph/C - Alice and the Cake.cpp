/*
Platform :- Codeforces 
Contest :- Codeforces Round 778(Div1 + Div 2)A
Approach :- We will start in reverse, from initial value we will try to get the array , so the starting value is going be sum of array elements , we will also maintain
            one frequency array which will help us in determining that we should divide further the value of not , we will do bfs,starting with the sum  if the frequency
            of current element of queue is '0' then we don't have that element in our array and we need to divide it , we will do the operation (n-1) time, if at the end
            we have some element whose frequency is not '0' then we cannot obtain that array and answer is "NO" else "YES".
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
        long long tot = 0;
        map<long long,int>fre;
        for(int i=0;i<n;++i){
            cin>>A[i];
            tot+=A[i];
            fre[A[i]]++;
            //A[i] = -A[i];
        }
        //we will do in reverse from max to here
        int f = 0;
        int lim = n;
        queue<long long>P;
        P.push(tot);
        while(lim){
            long long temp = P.front();
            P.pop();
            if(fre[temp]){
                fre[temp]--;
            }
            else{
                //this is unwanted and we want to split this
                P.push(temp/2);
                P.push((temp+1)/2);
                lim--;
            }
        }
        
        for(auto&x:fre){
            if(x.second>0){
                f=1;break;
            }
        }
        
        if(f)cout<<"NO\n";
        else cout<<"YES\n";
    }
}
