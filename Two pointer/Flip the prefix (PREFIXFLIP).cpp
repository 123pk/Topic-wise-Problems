/*
Platform :- Codechef
Contest :- Codechef Starters 71
Approach :- I reduced the array or compressed to alteranting string of 01010.. or 101010.. form , where I stored two thigns (current_character,count_of_consecutive_this_char)
           Now I tried sliding window and two pointer where I find the window with sum of charcters >= k and cost to be minimum.
           
Time Complexity ;- O(n)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	
	while(t--){
	    int n;
	    int k;
	    cin>>n>>k;
	    
	    string s;
	    cin>>s;
	    
	    //let us compress
	    int one = 0,zero = 0;
	    char ch = s[0];
	    vector<pair<char,int>>temp;
	    
	    for(int i=0;i<n;++i){
	        if(s[i] == '1'){
	            one++;
	        }
	        else zero++;
	        
	        if(s[i] != ch){
	             
	            if(s[i] == '0')temp.push_back({ch,one});
	            else temp.push_back({ch,zero});
	            
	            if(s[i] == '1'){
	                ch = '1';
	                zero = 0;
	                
	            }
	            else{
	                ch = '0';
	                one = 0;
	            } 
	        }
	        if(i == n-1){
	            if(s[i] == '0')temp.push_back({ch,zero});
	            else temp.push_back({ch,one});
	        }
	    }
	    
	    int ans = INT_MAX;
	    int sum = 0,start = 0,cost = 0;
	    for(int i=0;i<temp.size();++i){
	        char cur_ch = temp[i].first;
	        int len = temp[i].second;
	        //cout<<cur_ch<<" "<<len<<"\n";
	        if(len>=k){
	                if(cur_ch == '1'){
	                    ans = 0;
	                    break;
	                }
	                else {
	                    ans = min(ans,1);
	                    
	                }
	        }
	        
	        sum += len;
	        if(i == 0){
	             if(cur_ch == '0')cost++;
	             ch = cur_ch;
	        }
	        else{
	            
	            if(cur_ch == '0') cost += 2;
	            
	            while(start<i){
	                if((sum-temp[start].second)>=k){
	                    sum -= temp[start].second;
	                    cost--;
	                    start++;
	                }
	                else break;
	            }
	            //cout<<cur_ch<<" "<<len<<" "<<i+1<<" "<<cost<<"\n";
	           if(sum>=k) ans = min(ans,cost);
	        }
	    }
	    cout<<ans<<"\n";
	}
	return 0;
}
