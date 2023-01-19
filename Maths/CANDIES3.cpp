/*
Platform :- Codechef
Contest :- Codechef Starters 74
Approach :- For each value 'i' from 1 to m , we will find sum of (A[j]/i) for all A[j] in array.
            This will be O(2*m) because no of factors -
	    1 have m
	    2 have m/2
	    3 have m/3
	    4 have m/5
	    5 have m/6 
	    .
	    .
	    m have 1 
	    
	    so the sum is m+ (m/2) + (m/3) + (m/4) + .. +1 ~ = 2*m
	    We need to maintain one array of size 'm' to store the frequencies ,now we will do suffix sum where 'suff[i]' = no of values >=i in array are present
	    We will now for each value of i' from 1 to m traverse from the largest multiple of 'i' <= m ,and come all the way to '1' 
	    We will know no of value in range ( 'count' = suff[j] - suff[j+i] ) , we will have (j/i)*count values in that range which will we get reward from
Time Complexity :- O(2*m) ~ O(m) 
*/
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
