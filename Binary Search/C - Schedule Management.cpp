/*
Platform :- Codeforces
Contest :- Codeforces Educational Round 131
Approach :- We will do binary search on it , since max no of days can be 2*m , so for 'i' no of days we can find total no of tasks that can be completed by labours 
            if tot_task_completed >= m , then we can do all the task in 'i' days , so using binary search we can do find the value.
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        long long n,m;
        cin>>n>>m;

        long long A[m];
        
        //count of worker
        vector<long long>count(n+1);
        //for(int i=1;i<=n;++i)count[i] = 0;
        
        for(int i=0;i<m;++i){
            cin>>A[i];
            count[A[i]]++;
        }
        
        long long ans = m*2ll;
        //let us do binary search
        long long start = 1,end = m*2ll,mid=(start+end)>>1ll;
        while(start<=end){
            long long tot = 0;
           // cout<<mid<<"\n";
            //can we get the desired result in mid day or not
            for(int i=1;i<=n;++i){
                long long val = 0;
                if(mid > count[i]){
                    val += count[i];
                    long long extra = (mid - count[i]);
                    val += (extra>>1ll);
                }
                else{
                    val += mid;
                }
                //cout<<val<<" "<<i<<"\n";
                tot+=val;
            }
            
         //   cout<<"\n";
            if(tot>=m){
                ans = min(ans,mid);
                end = mid-1ll;
                mid= (start+end)>>1ll;
            }
            else {
                start = mid+1ll;
                mid = (start+end)>>1ll;
            }
        }
        
        cout<<ans<<"\n";
    }
}
