/*
Platform :- Codeforces
Contest :- Codeforces Global Round 21
Approach :- If you will analyse you will find you need atmax 2 opearation in worst case ,now you will count no of subarrays which are between zeros or zeros and bounday
            and min (value,2) is our answer.
Time Complexity = O(N)
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
        int d = 0,f = 0;
        long long ans = 0;
        for(int i=0;i<n;++i){
            cin>>A[i];
            if(A[i]){
                if(f == 0){
                    d++;
                    f=1;
                }
            }
            else{
                f = 0;
            }
            //ans = max(ans,(A[i] | x));
        }
        d = min(d,2);
        cout<<d<<"\n";
    }
}
