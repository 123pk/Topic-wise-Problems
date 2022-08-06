/*
Platform :- Codeforces
Contest :- Codeforces Round 812 Div 2
Approach :- First create an array of size n with all values 0, Start from the very end (n-1) and run till 0 now we check what is the nearest squre to this number to 
            its right (>=(n-i)) , let that value be 'y' which is definitely smaller than (n-i) , now from that index to (n-i) store the diff (x-j) where 'x'  is the square 
            and ( y <= 'j' <= (n-i)) .
            
            Similarly we find the new square value when (i<y) and update the 'y' .
Time Complexity :- O(n)
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        //for(int n=1;n<=1000;++n){
        cin>>n;
        
        vector<int>A(n);
        int mx = (n-1)*2;
        set<int>used;
        
        int f = 0;
        int cur = 0,low = 0;
        for(int i=n-1;i>=0;--i){
            if(A[i])continue;
            
           
                int near_sq = i;
                int val = sqrt(i);
                int sq = val*val;
            
                if(sq == i){
                    for(int j=1;j<i;++j){
                        A[j] = sq - j;
                        A[sq-j] = j;
                    }
                    i = 0;
                    A[i] = 0;
                    A[0] = sq;
                 }
                 else{
                     val++;
                     sq = val*val;
                   if((sq-i)<0 || (sq-i)>(n-1)){
                    f=1;break;
                }
                A[i] = sq - i;
                A[sq-i] = i;
                for(int j=sq-i;j<i;++j){
                    A[j] = sq - j;
                    A[sq-j] = j;
                }
                i = sq-i;
             }
             
            
            
        }
         
        map<int,int>count;
        for(int i=0;i<n;++i){
            int val = A[i]+i;
            count[A[i]]++;
            if(count[A[i]]>1){
            //cout<<i+1<<" "<<A[i]<<" "<<"\n";
                f=1;
                break;
            }
            
            int sq = sqrt(val);
            int xx = sq;
            sq*=sq;
            if(sq != val){
                f=1;
                break;
            }
        }
         
        if(f)cout<<n<<" "<<"-1\n";
        else{
            for(auto&x:A)cout<<x<<" ";
            cout<<"\n";
        }
    }
}
