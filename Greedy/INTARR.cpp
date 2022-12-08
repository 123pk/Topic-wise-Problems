/*
Platform :- Codechef
Contest :- Codechef Starters 68B
Approach :- If you will observe you will find that if frequency of any element > (n+1)/2 ,then we cannot have the desired array.
            We first find the max frequency and check if answer exist or not.
            
            We first sort the array ,then we divide the array into 'small'(first (n+1)/2 value) and 'big' remainging values of second half,
            So there are two option 
            1. We have an array of A[0]>A[1]<A[2]>A[3].., even index values are greater than odd indexed values
            2. We have even indexed values smaller than odd index values , 
            We greedily check both the options and if any of one is satisified we print it else we print -1.

Time Complexity :- O(n log n) --sorting
*/
#include<bits/stdc++.h>
using namespace std;

bool check(vector<long long>&temp){
    int n = temp.size();
    for(int i=2;i<n;++i){
        //increasing
        if(temp[i-2]<=temp[i-1] && temp[i-1]<=temp[i])return false;
        
        //decreasing
        if(temp[i-2]>=temp[i-1] && temp[i-1]>=temp[i])return false;
    }
    return true;
}


int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        
        long long A[n];
        map<long long,int>count;
        int lim = (n+1)/2;
        
        for(int i=0;i<n;++i){
            cin>>A[i];
            count[A[i]]++;
            if(count[A[i]]>lim && lim != -1){
                lim = -1;
            }
        }
        
        if(lim == -1){
            cout<<lim<<"\n";
            continue;
        }
        
        sort(A,A+n);
        
        //modify
        vector<long long>small,big;
        int idx = (n+1)/2;
        for(int i=0;i<idx;++i){
            small.push_back(A[i]);
            if((i+idx)<n)big.push_back(A[i+idx]);
        }
        
        //start with small
        vector<long long>temp1;
        int j = 0;
        for(int i=0;i<small.size();++i){
            temp1.push_back(small[i]);
            if(j<big.size()){
                temp1.push_back(big[j]);
                j++;
            }
        }
        
        while(j<big.size()){
            temp1.push_back(big[j]);
            j++;
        }
        
        
        if(check(temp1)){
            for(auto&x:temp1)cout<<x<<" ";
            cout<<"\n";
            continue;
        }
        
        //start with big
        j = 0;
        temp1.clear();
        for(int i=0;i<big.size();++i){
            temp1.push_back(big[i]);
            if(j<small.size()){
                temp1.push_back(small[j]);
                j++;
            }
        }
        while(j<small.size()){
            temp1.push_back(small[j]);
            j++;
        }
        
        if(check(temp1)){
            for(auto&x:temp1)cout<<x<<" ";
            cout<<"\n";
        }
        else cout<<"-1\n";
    }
}
