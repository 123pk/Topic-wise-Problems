/*
Platform :- Codechef
Contest :- Codechef Starters 74
Approach :- We will use stack and find all the unique difference from left to right of array and right to left of array seperately,
           then union of both is our required no of unique vlues
           We maintain stack of decreasing sequence ,if some bigger value increase we remove all the smaller value that this from the stack ,we do store the differnce
           of value we get from it and the removed element.

Time Complexity :- O(n log n) - set operation
*/

#include <bits/stdc++.h>
using namespace std;

void find(vector<long long>&A,set<long long>&unq){
    stack<long long>P;
    for(int i=0;i<A.size();++i){
        if(P.empty()){
            P.push(A[i]);
        }
        else{
            if(P.top()<A[i]){
                while(P.top()<=A[i]){
                    long long val = P.top();
                    P.pop();
                    val = A[i]-val;
                    unq.insert(val);
                    if(P.empty())break;
                }
                P.push(A[i]);
            }
            else{
                long long val = P.top();
                val -= A[i];
                P.push(A[i]);
                unq.insert(val);
            }
        }
    }
}

int main() {
	// your code goes here
	int t;
	cin>>t;
	
	while(t--){
	    int n;
	    cin>>n;
	    
	    vector<long long>A(n);
	    for(int i=0;i<n;++i){
	        cin>>A[i];
	    }
	    
	    set<long long>unq;
	    find(A,unq);
	    reverse(A.begin(),A.end());
	    find(A,unq);
	    
	    cout<<unq.size()<<"\n";
	}
	return 0;
}
