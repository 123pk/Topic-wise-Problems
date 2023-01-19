
#include <bits/stdc++.h>
using namespace std;

 

int main() {
	// your code goes here
	int t;
	cin>>t;
	
	while(t--){
	    int n,m;
	    cin>>n>>m;
	    
	    vector<long long>fre(m+1);
	    int A[n];
	    for(int i=0;i<n;++i){
	        cin>>A[i];
	        fre[A[i]]++;
	    }
	    
	    
	    int B[m];
	    for(int i=0;i<m;++i){
	        cin>>B[i];
	    }
	    
	    //let us set it down
	    long long tot = 0;
	    for(int i=m;i>=1;--i){
	        fre[i] += tot;
	        tot = fre[i];
	    }
	    
	   // for(int i=1;i<=m;++i)cout<<fre[i]<<" - "<<i<<"\n";
	  //  cout<<"\n";
	    
	    //now the magic
	    long long ans = 0;
	    
	    for(int i=0;i<m;++i){
	        long long start = i+1;
	        int last = m-(m%start);
	        long long cur_value = 0;
	        long long bv = fre[last];
	        
	        for(int j=last;j>=1;j-=start){
	           if(j == last){
	               bv = fre[j];
	               long long mul = j/start;
	               mul*=bv;
	               cur_value += mul;
	           }   
	           else{
	               long long count = fre[j];
	               long long z = bv;
	               bv = count;
	               count -= z;
	               
	               long long mul = j/start;
	               mul*=count;
	               cur_value += mul;
	           }
	         //  if(last == 6 && i == 0)cout<<j<<" "<<cur_value<<" "<<bv<<"\n";
	        }
	       // cout<<i+1<<" "<<cur_value<<"\n";
	        long long z = B[i];
	        cur_value*=z;
	        ans = max(ans,cur_value);
	    }
	    
	    cout<<ans<<"\n";
	}
	return 0;
}
