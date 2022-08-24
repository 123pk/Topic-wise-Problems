/*
Platform :- CSES
Approach :- Sort the first Array in increasing order and then do binary search on B and find the samllest element in range (A[i]-k,A[i]+k)
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    long long k;
    cin>>n>>m>>k;
    
    long long A[n];
    set<long long>P;
    for(int i=0;i<n;++i){
        cin>>A[i];
       
    }
    
    long long B[m];
    map<long long,int>count;
    for(int i=0;i<m;++i){
        cin>>B[i];
        P.insert(B[i]);
        count[B[i]]++;
    }
    
    //now what to do
    int ans = 0;
    
    sort(A,A+n);
    for(int i=0;i<n;++i){
        //check if there is some value which satisfy the condition
        if(P.size() == 0)break;
        auto it = P.lower_bound(A[i]);
        if(it == P.end()){
            it--;
            long long val = *it;
            long long dif = abs(A[i] - val);
            
            if(dif<=k){
                ans++;
                count[val]--;
                if(count[val] == 0)P.erase(val);
            }
        }
        else{
            long long val = *it;
            long long dif = abs(A[i]-val);
             
            if(it == P.begin()){
                if(dif<=k){
                    count[val]--;
                    ans++;
                    if(count[val] == 0)P.erase(val);
                }
            }
            else{
                //it--;
                long long val2 = A[i]-k;
                it = P.lower_bound(val2);
                val2 = *it;
                long long dif2 = abs(A[i] - val2);
                
                if(dif2<=k){
                    ans++;
                    count[val2]--;
                    if(count[val2] == 0)P.erase(val2);
                }
                else{
                    if(dif<=k){
                        ans++;
                        count[val]--;
                        if(count[val] == 0)P.erase(val);
                    }
                }
            }
        }
        
  //      cout<<ans<<" ";
        
    }
    
    cout<<ans<<"\n";
}
