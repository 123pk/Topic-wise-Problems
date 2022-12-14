/*
Contest :- Codechef Starters 69
Appproach:- 
*/
#include <bits/stdc++.h>
using namespace std;

#define int long long


int check(int n,long long val,vector<long long>&A){
	    
	    vector<vector<int>>pref,suff;
	    vector<int>fre(32);
	    
	    long long cur = 0;
	    set<long long>got;
	    map<long long,int>idx;
	    
	    
	    for(int i=0;i<n;++i){
	        cur |= A[i];
	        if(got.size()){
	            if(got.find(cur) == got.end()){
	                got.insert(cur);
	                idx[cur] = i+1ll;
	            }
	        }
	        else{
	            got.insert(cur);
	            idx[cur] = i+1ll;
	        }
	        
	        
	        string temp = bitset<32>(A[i]).to_string();
	        reverse(temp.begin(),temp.end());
	        
	        for(int j=0;j<32;++j){
	            if(temp[j] == '1')fre[j]++;
	        }
	        pref.push_back(fre);
	    }
	    
	    
	    vector<int>fre2(32);
	    int ans = -1;
	    
	    
	    long long beh = 0;
	    for(int i=n-1;i>=0;--i){
	        beh |= A[i];
	        if(beh == val){
	            if(i){
	                if((idx[val]-1ll)<i){
	                    ans = max(ans,i);
	                    ans = max(ans,(n-idx[val]));
	                     
	                }
	            }
	        }
	        
	        string temp = bitset<32>(A[i]).to_string();
	        reverse(temp.begin(),temp.end());
	        
	        for(int j=0;j<32;++j){
	            if(temp[j] == '1')fre2[j]++;
	        }
	        suff.push_back(fre2);
	    }
	    
	    string have = bitset<32>(val).to_string();
	    reverse(have.begin(),have.end());
	    
	    vector<int>req(32);
	    for(int i=0;i<32;++i)req[i] += (have[i]-'0');
	    //cout<<ans<<" \n";
	     
	    
	    cur = 0;
	    for(int i=n-1;i>0;--i){
	        cur |= A[i];
	        
	        //which bits are not set
	        string temp = bitset<32>(cur).to_string();
	        reverse(temp.begin(),temp.end());
	        
	        long long find = 0;
	        for(long long j=0;j<32;++j){
	            if((temp[j] == '0') &&  (req[j]>0)){
	                find += (1ll<<j);
	            }
	        }
	        
	        auto it = got.lower_bound(find);
	        if(it == got.end())continue;
	        
	        if(find == 0){
	            if((idx[val]-1)<i){
	                ans = max(ans,i);
	                ans = max(ans,n-idx[val]);
	            }
	            continue;
	        }
	        long long cur_val = *it;
	        int j = idx[cur_val]-1ll;
	        long long ba = cur_val & find;
	        
	        if((ba) == find){
	             
	            if(j<i){
	                int g = 0;
	                 
	                vector<int>zz = pref[i-1];
	                long long sum = 0;
	                for(int k=0;k<32;++k){
	                    zz[k] -= pref[j][k];
	                    if(zz[k]){
	                        sum += (1ll<<k);
	                    }
	                }
	                
	                if(sum == val){
	                    int score = (i-(j+1ll));
	                    if(score)ans = max(ans,score);
	                }
	            }
	        }
	    }
	    
	    
	    return ans;
}

 


int32_t main() {
	// your code goes here
	int t;
	cin>>t;
	
	while(t--){
	    int n;
	    cin>>n;
	    
	    vector<long long> A(n);
	    long long val = 0;
	    for(int i=0;i<n;++i){
	        cin>>A[i];
	        val |= A[i];
	    }
	    if(n == 1){
	        cout<<"-1\n";
	        continue;
	    }
	    
	    int ans = -1;
	    ans = check(n,val,A);
	    reverse(A.begin(),A.end());
	    ans = max(check(n,val,A),ans);
	     
	    
	    cout<<ans<<"\n";
	}
	return 0;
}
