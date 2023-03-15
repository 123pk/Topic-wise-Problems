
#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	
	while(t--){
	    int n;
	    cin>>n;
	    
	    int A[n];
	    int one = 0;
	    for(int i=0;i<n;++i){
	        cin>>A[i];
	        one += A[i];
	    }
	    
	    int zero = n - one;
	    
	    if(n%2 || one == 0 )cout<<"-1\n";
	    else if(one == n && n == 2)cout<<"-1\n";
	    else if(zero == one)cout<<0<<"\n";
	    else{
	        if(zero > one){
	             
	            cout<<((zero-one)/2)<<"\n";
	        }
	        else {
	            int dif = (one - zero);
	            int rem = (dif%4);
	            int move = 0;
	            if(rem == 2)move += 2;
	             move += dif/4;
	             
	            
	            cout<<move<<"\n";
	            
	        }
	    }
	}
	return 0;
}
