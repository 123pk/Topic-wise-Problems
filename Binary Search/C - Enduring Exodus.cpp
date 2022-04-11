/*
Platform :- Codeforces
Approach :- We will do binary serach on minimum distance 'x' from John tohis fatherst cow , we would also precompute no of zeros till 'ith' index , 
            now while doing binary search we will travers through array and check for no of zeros in range of '[ max(0,i-mid)] to [min(i+mid,n-1) ] '
            if it contains values > k then we choose min of all available values.
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    //cin>>t;
    t = 1;
    while(t--){
        int n,k;
        cin>>n>>k;
        
        string s;
        cin>>s;
        
         
        vector<int>pref(n);
        int c = 0;
        for(int i = 0;i<n;++i){
            if(s[i] == '0'){
              //  zeros.push_back(i);
                c++;
            }
            pref[i] = c;
        }
        
        
        int ans = 0;
     
        
        ans = 2*n;
        int strt = 0,ed = n+1,mid = (strt+ed)>>1;
        while(strt<=ed){
            int f = 0;
            //for choosen mid if the no of zeros to left and right are greater than k+1
            for(int i = 0;i<n;++i){
                if(s[i] == '1')continue;
                //find that much to the left and to the right
                //cout<<i<<" "<<mid<<endl;
                int val = 0;
                if((i+mid)<n)val+=pref[i+mid];
                else val = pref[n-1];
                
                if((i-(mid+1))>=0)val-=pref[i-(mid+1)];
                if(val>k){
                    f=1;break;
                }
            }
          //  cout<<mid<<" "<<f<<"\n";
            //cout<<endl;
            if(f){
                ans = min(ans,mid);
                ed = mid-1;
                mid = (strt+ed)>>1;
            }
            else{
                strt = mid+1;
                mid = (strt+ed)>>1;
            }
        }
        cout<<ans;
    }
}
