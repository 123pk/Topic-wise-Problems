/*
Platform :- Codeforces
Contest :- Codeforces Global Round 24
Approach :- So it is of no use if we use a distinct value in our subarray as it will not effect our answer, so we can add any number of distinct values 
             so [1,n] is one of the subarrays which give us the max score.
Time Complexity :-O(n) -- reading input
*/
#include<bits/stdc++.h>
using namespace std;
 

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        
        vector<int>A(n);
        for(int i=0;i<n;++i){
            cin>>A[i];
            
        }
        
        cout<<1<<" "<<n<<"\n";
    }
}
