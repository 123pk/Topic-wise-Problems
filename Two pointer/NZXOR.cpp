
/*
Platform :- Codechef
Contest :- Codechef Starters 55
Approach :- We traverse through the array and computer the xor of all elements till ith index , we also maintain a set which stores the 'xor_values' already occured
            whenever we get xor_value  = 0 or a xor_values which is repating ( this means we have a subarray which has xor  = 0) so we increment out count as we need to
            change this value , and make xor_value = 0 and do the traversal again , we also make the set empty .
Time Complexity :- O(n)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	
	while(t--){
	    int n;
	    cin>>n;
	    
	    long long A[n];
	    set<long long>have;
	    long long cur = 0;
	    int ans = 0;
	    for(int i=0;i<n;++i){
	        cin>>A[i];
	        cur = cur ^ A[i];
	        if(cur == 0){
	            have.clear();
	            ans++;
	        }
	        else{
	            if(have.size()){
	                if(have.find(cur) != have.end()){
	                    have.clear();
	                    cur = 0;
	                    ans++;
	                }
	                else have.insert(cur);
	            }
	            else{
	                have.insert(cur);
	            }
	        }
	    }
	    
	    //now in rverse order
	    reverse(A,A+n);
	    int fin = ans;
	    cur = 0;
	    ans = 0;
	    have.clear();
	    for(int i=0;i<n;++i){
	        //cin>>A[i];
	        cur = cur ^ A[i];
	        if(cur == 0){
	            have.clear();
	            ans++;
	        }
	        else{
	            if(have.size()){
	                if(have.find(cur) != have.end()){
	                    have.clear();
	                    cur = 0;
	                    ans++;
	                }
	                else have.insert(cur);
	            }
	            else{
	                have.insert(cur);
	            }
	        }
	    }
	    fin = min(fin,ans);
	    ans = fin;
	    cout<<ans<<"\n";
	}
	return 0;
}
