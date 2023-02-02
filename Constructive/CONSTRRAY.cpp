
/*
Platform :- Codechef
Contest :- Codechef Starters 76 B
Approach :- we start from very big value and greedily add them so that they satisfy the condition,
            for even and odd indexes as given,
Time Complexity :- O(n)
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        
        if(n%2)cout<<"-1\n";
        else{
            vector<long long>A(n);
            long long start = 1e8;
            long long left = 0,right = 0;
            for(int i=0;i<(n/2);++i){
                if(i%2 == 0){
                    //left sum > right sum
                    left += start;
                    A[i] = start;
                    long long rem = (left-right)-1;
                    A[n-1-i] = rem;;
                    right += rem;
                }
                else{
                    //we need to make right sum > left sum
                    right += start;
                    A[n-1-i] = start;
                    long long rem = (right - left)-1;
                    A[i] = rem;
                    left += rem;
                    
                }
            }
            
            for(auto&x:A)cout<<x<<" ";
            cout<<"\n";
        }
    }
}
