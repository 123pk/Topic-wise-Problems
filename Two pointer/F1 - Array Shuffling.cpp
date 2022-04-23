/*
Platform :- Codeforces
Contest :- Codeforces Global Round 20
Approach :- Sort values by frequency and make array of indexes, where we first take the most frequent value and all add all its indexes in inital array and similary for all
            other values. Similarly we will make array of values also , now we will shift the value array by maximum no frequency of element in array to left and initalise
            the indexes with new values after shifting.
            
            Approach is to get a array with least no indexes which have same values as inital array.
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        
        int A[n];
        int mx = 0;
        vector<int>fre(n+1);
        vector<int>idx[n+1];
        for(int i=0;i<n;++i){
            cin>>A[i];
            idx[A[i]].push_back(i);
            fre[A[i]]++;
            mx = max(mx,fre[A[i]]);
        }
        
        //sort by frequecny and get the elements indexes also and store in array according to values
        vector<pair<int,int>>temp;
        for(int i=1;i<=n;++i){
            if(fre[i]){
                temp.push_back({fre[i],i});
            }
        }
        
        sort(temp.begin(),temp.end());
        reverse(temp.begin(),temp.end());
        
        
        vector<int>val,z;
        for(int i=0;i<temp.size();++i){
            for(int j=0;j<temp[i].first;++j){
                val.push_back(temp[i].second);
                z.push_back(idx[temp[i].second][j]);
            }
        }
        //now choose the index and start by initialising the values after shifting it by mx
        for(int i=0;i<(n-mx);++i){
            A[z[i]] = val[i+mx];
        }
        int j = 0;
        for(int i=(n-mx);i<n;++i){
            A[z[i]] = val[j];
            j++;
        }
        
        for(auto&x:A)cout<<x<<" ";
        cout<<"\n";
    }
}
