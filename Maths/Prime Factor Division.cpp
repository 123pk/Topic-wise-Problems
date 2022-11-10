/*
Platform :- Codechef
Contest :- Codechef Starters 64B
Approach :- 
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	
	while(t--){
	    long long a,b;
	    cin>>a>>b;
	    
	    
	     long long val = __gcd(a,b);
	     int f = 0;
	     b/=val;
	     while(1){
	         
	         long long v2 = b;
	         long long v3 = __gcd(val,v2);
	         
	         if(v3 == 1 && v2!=1){
	             f=1;
	             break;
	         }
	         else if(v2 == 1 && v3 == 1)break;
	         
	         while(v2%v3 == 0){
	             v2/=v3;
	         }
	        // cout<<v2<<" "<<v3<<"\n";
	         b = v2;
	     }
	     
	    if(f)cout<<"NO\n";
	    else cout<<"YES\n";
	}
	return 0;
}
