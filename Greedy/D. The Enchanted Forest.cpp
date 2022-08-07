/*
Platform :- Codeforces
Contest :- Codeforces Round 796 Div 2
Approach :- We have two cases 
           i. k < n , here we will find the subarray of length with max sum and we will start from starting index of this subarray and find the final value
           ii. k >=n , here we can visit all elements of array and we will do the same , It take us (n) days in start to get all the way to last element from start and after that we
               will get all the way to end element in (n-1) days . So we will find the extra addition cost for 'x' days which is (x*(x-1))/2 , similary if there are some 
               remaining days it is better to get them the max values in those days
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n,k;
        cin>>n>>k;
        
        long long A[n];
        for(int i=0;i<n;++i)cin>>A[i];
        
        if(k>=n){
            //we can start from 0;
            long long tot = 0;
            for(int i=0;i<n;++i)tot+=A[i];
            //tot+=extra;
            long long sum = n;
            sum*=(sum-1ll);
            sum>>=1ll;
            
            tot += sum;
          //  cout<<sum<<" ";
            k -=(n);
            
            if(n == 1){
                tot +=k;
                cout<<tot<<"\n";
                continue;
            }
            //cout<<tot<<" "<<k<<"\n";
            
            sum = n-1;
            sum*=(sum-1ll);
            sum>>=1ll;
            
            long long add = n-1;
            long long d = k/add;
            long long rem = k%add;
            
            long long range = n;
            range*=(range+1ll);
            range>>=1ll;
            range-=1;
            
            d*=(range+sum);
            
            long long rem_range = n;
            rem_range*=(n+1ll);
            rem_range>>=1ll;
            
            long long remove_range = (n-rem);
            remove_range*=((n-rem)+1ll);
            remove_range>>=1ll;
            
            
            rem_range-=remove_range;
            
            rem*=(rem-1ll);
            rem>>=1;
            
           // cout<<rem<<" "<<rem_range<<"\n";
            rem+=rem_range;
            
            tot +=d;
            tot+=rem;
            
            cout<<tot<<"\n";
            continue;
        }
        
        long long sum = 0,mx = 0;
        int start = 0;
        //store the value of subarray 
        
        for(int i=0;i<k;++i){
            sum += A[i];
        }
        
        
        long long extra = k-1;
        extra*=(extra+1ll);
        extra>>=1ll;
        mx = max(mx,extra+sum);
        
        for(int j=k;j<n;++j){
            sum-=A[j-k];
            sum+=A[j];
            mx = max(mx,extra+sum);
        }
        
        cout<<mx<<"\n";
        
    }
}
