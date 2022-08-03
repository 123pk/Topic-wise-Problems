/*
Platform :- Codeforces
Contest :- Codeforces Round 803 Div 2
Approach :- We will definitely use binary search as ( n < 10000) and no of queries is atmax (15) , now we want to know how to check if an range [l,r] contain 
            the fixed point or not , so the range will contain fixed point if count = number of values in range are (l<=x <=r) if this count is odd.
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        
        int start = 1,end = n,mid = (start+end)/2;
        
        int lim = 15;
        int ans = 0,count = 0;
        int x;
        
        while(lim--){
            
           cout<<"? "<<start<<" "<<mid<<"\n";
           cout.flush();
           count = 0;
           for(int i=start;i<=mid;++i){
               cin>>x;
               if(start<=x && x<=mid)count++;
           }
           
           if(count == 1 && (start == mid))break;
           
           if(count%2){
               //then there is some fixed point else no fixed point
               end = mid;
               mid = (start+end)/2;
           }
           else{
               start = mid+1;
               mid = (start+end)/2;
           }
           //cout<<start<<" "<<mid<<" "<<end<<"\n";
        }
        ans = mid;
        cout<<"! "<<ans<<endl;
        cout.flush();
    }
    exit(0);
}
