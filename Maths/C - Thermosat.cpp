/*
Platform :- Codeforces
Contest :- Codeforces Round 834
Approach:- We don't have any solution when max distance of a and b from fathest end is <= x
           1. if a and b are same then there is no need of any operatino 
           2. if abs(a-b)>=x then 1 operation is rquired
           3. Get to one of the end end try to get to b if it is possible then 2 operation
           4. else 3 opearation
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    int sum = 0;
    /*set<int>can_have;
    int lim = 3000;
    for(int i=1;i<=lim;++i){
        sum += i;
        can_have.insert(sum);
    }
    */
    
    while(t--){
         long long l,r,x;
         cin>>l>>r>>x;
         long long a,b;
         cin>>a>>b;
         
         if(a == b){
             cout<<0<<"\n";
             continue;
         }
         //so approach is to make a to one of the end that is fathest from b and get to there
         long long dist1 = abs(l-b);
         long long dist2 =abs(r-b);
         
         long long dist3 = abs(l-a);
         long long dist4 = abs(r-a);
         
         long long mx1 = max(dist1,dist2);
         long long mx2 = max(dist3,dist4);
         
         if(mx1>=x && mx2>=x){
            //the max operation is 3
            long long dif = abs(a-b);
            if(dif>=x)cout<<1<<"\n";
            else{
                //they are far from one of the end
                //let us choose l
                if(dist1>=x && dist3>=x)cout<<2<<"\n";
                else if(dist2>=x && dist4>=x)cout<<2<<"\n";
                else cout<<3<<"\n";
            }
         }
         else cout<<"-1\n";
    }
}
