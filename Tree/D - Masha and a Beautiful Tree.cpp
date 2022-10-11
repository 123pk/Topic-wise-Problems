/*
Platform :- Codeforces
Contest :- Codeforces Round 826 Div 3
Appraoch :- We will make complete tree from the give data, where parents store  ( min_value_in_subtree , max_value_in_subtree , no_of_nodes_in_subtree },
            --- when is the given tree cannot be sorted , it is a permutaion so if there is any missing  value in subtree then it cannot be sorted
            --- missing value is when ( max - min)+1 > no_of_nodes in subtree.
            --- We keep on check this also ,if the min is from right subtree of current node then we need to flip it and it will cost us '1' point
Time Comlexity :- O(n*log(n))
*/
#include<bits/stdc++.h>
using namespace std;

void fill(vector<vector<int>>&tree,int& invalid,int& count,int idx){
    
    for(int i=idx;i>=0;--i){
        
        //get the two childs
        //check for validity
        int lchild = (2*i)+1;
        int rchild = (2*i) + 2;
        
        //check two things if value in range is 
        vector<int>l = tree[lchild];
        vector<int>r = tree[rchild];
      //  cout<<l[0]<<" "<<l[1]<<" "<<r[0]<<" "<<r[1]<<"\n";
        
        int mn = min(l[0],r[0]);
        int mx = max(l[1],r[1]);
        int no = l[2] + r[2];
        
        int have = (mx - mn) + 1;
        if(have>no){
            invalid = 1;
            break;
        }
        
        //check if we need to swap it ?
        if(mn == r[0])count++;
        tree[i] = {mn,mx,have};
        l.clear();
        r.clear();
    }
    
}

int main(){
     ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        
        int ans = 0;
        int f = 0;
        int sz = (2*n)-1;
        vector<vector<int>>tree(sz,{-1,-1,0});
        
        vector<int>A(n);
        for(int i=0;i<n;++i)cin>>A[i];
        int j = n-1;
        for(int i=sz-1;j>=0;--i){
            tree[i] = {A[j],A[j],1};
            j--;
        }
        
        int rstart = sz-n-1;
        //void fill tree and find answer
        fill(tree,f,ans,rstart);
        
        if(f)cout<<"-1\n";
        else cout<<ans<<"\n";
    }
}
