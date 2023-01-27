/*
Platform :- Codechef
Contest  :- Codechef Starters 75
Approach :- You need to observe the values  of f(x) and g(x) for [1<= x <=32 ] , you will find that the max value is for 'x' which is 'power_of_2' .
            After that we the value decreases .
            till it reach the next power_of_2.
            So approach is to find the biggest power of '2' in range 'a' to 'b' if there is no such value then we find the score for 
            first 100 values from 'a' to min(b,a+100) 
            and the biggest will be our answr.
            Else the power of 2 will give use the max value.
Time Complexity :- O(log(b))
*/
#include<bits/stdc++.h>
using namespace std;

long long f1(long long x){
    if(x == 1)return 1;
    else{
        if(x%2)return 2ll*f1(x/2);
        else return 2ll*f1(x/2)+1;
    }
}

long long f2(long long x){
    if(x == 1)return 0;
    else{
        if(x%2)return f2(x/2);
        else return f2(x/2)+1;
    }
}

int main(){
    int t;
    cin>>t;
    
    while(t--){
        long long a,b;
        cin>>a>>b;
        
        //smallest value
        long long ans = 0;
        long long dif = (b-a);
        for(long long i = 0;i<=min(100ll,dif);++i){
            ans = max(ans,f1(a+i)+f2(a+i));
        }
        
        //find the biggest multiple of f2
        long long score = 1;
        int f = 0;
        while(score<b){
            score*=2ll;
        }
        if(score>b)score/=2ll;
        
        if(a<=score && score<=b){
            long long tot1 = 0,tot2 = 0;
           // cout<<score<<"\n";
            long long d = 0;
            while(score >1){
                score/=2;
                d++;
            }
            
            tot2 = (1ll<<d);
            tot2*=2ll;
            tot2--;
          //  cout<<d<<" "<<tot2<<"\n";
            tot1 = (d+tot2);
            ans = max(ans,tot1);
        }
        cout<<ans<<"\n";
    }
}
