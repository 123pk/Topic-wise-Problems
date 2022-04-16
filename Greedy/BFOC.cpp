/*
Platform :- Codchef
Contest :- Codechef Lunctime April 2022
Approach :- We will start distributing candies from the last frined (nth one) , if for ith friend the no of buckets is > candies available then we will ignore all the
            friends from (i) to (candies+i) ans they will not be able to get even 1 candi, so we will perform the same operation till the time no of candies are >=(k)
            and we have not reached the starting child.
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        long long n;
        long long candies,box;
        cin>>n>>candies>>box;
        
        long long rem = candies;
        long long start = n+box-1;
        start = min(start,candies);
        while(rem>=box && start>=box){
            if(rem>=start){rem = rem%start;
                start--;
            }
            else {
                start = min(start,rem);
            }
        }
        cout<<rem<<"\n";
    }
}
