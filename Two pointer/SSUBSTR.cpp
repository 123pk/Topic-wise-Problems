/*
Platform :- Codechef
Contest :- Codechef Starters 62
Approach :- We first change out binary string into 10101... or 010101.. or basically compress out string , where bunch of same segment are compressed to 1 ,ex (001110 --> 010)
            No we want to make this string sort in ascending order which will be possible if we have '0's in front and '1's in last . So we will try each combination
            likke if we are at '1' we want all the values beyond this point to be '1' and all values to left of this to be '0' we will found the cost .
            The min of all is our answer.
Time Complexity :- O(n)
*/
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	
	while(t--){
	    int n;
	    cin>>n;
	    
	    string s;
	    cin>>s;
	    
	    //let us compress this
	    string temp = "";
	    char ch;
	    for(int i=0;i<n;++i){
	        if(i == 0){
	            if(s[i] == '0'){
	                ch = '0';
	            }
	            else ch = '1';
	            temp += ch;
	        }
	        else{
	            if(s[i] != ch){
	                ch = s[i];
	                temp += ch;
	            }
	        }
	    }
	    
	    
	    //now make the count
	    int c = count(temp.begin(),temp.end(),'0');
	    int curz = 0,curo = 0;
	    int ans = INT_MAX;
	    for(int i=0;i<temp.size();++i){
	        //we need to get this
	        if(temp[i] == '1'){
	            //all values beyond from this point are '1'
	            int cur = curo + c - curz;
	            ans = min(ans,cur);
	            //all ones to left
	            curo++;
	        }
	        else{
	            
	            //if this is zero then all points beyond this are '0'
	            int cur = curo + (c - (curz+1));
	            ans = min(ans,cur);
	            curz++;
	        }
	        
	    }
	    cout<<ans<<"\n";
	}
	return 0;
}
