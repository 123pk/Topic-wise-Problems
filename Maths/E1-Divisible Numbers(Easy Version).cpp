#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
         long long a,b,c,d;
         cin>>a>>b>>c>>d;
        
        long long x,y ;
        int f = 0;
        long long val = a*b;
         for(long long i=a+1;i<=c;++i){
             
             //if this is one of the required va;ue
             
             long long z = __gcd(val,i);
             z = val/z;
             long long zz = (d/z);
             zz*=z;
             if(zz>b){
                 x = i;
                 y = zz;
                 f = 1;
                 break;
             }
         }
         
         if(f == 0)cout<<"-1 -1\n";
         else cout<<x<<" "<<y<<"\n";
    }
}
