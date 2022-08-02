/*
Platform :- Codeforces
Contest :- Codeforces Round 811 Div 3
Appraoch :- We will use binary lifting and binary search.
*/
#include<bits/stdc++.h>
using namespace std;

// Binary Lifting tutorial https://youtu.be/oib-XsjFa-M

    vector<vector<int>> up; // int up[N][20];
    vector<int> depth;
    int LOG;

    void create(int n, vector<int>& parent) {
        LOG = 0;
        while((1 << LOG) <= n) {
            LOG++;
        }
        up = vector<vector<int>>(n, vector<int>(LOG));
         
        // up[v][j] is 2^j -th ancestor of node v
        parent[0] = 0;
        for(int v = 0; v < n; v++) {
            up[v][0] = parent[v];
             
            for(int j = 1; j < LOG; j++) {
                up[v][j] = up[ up[v][j-1] ][j-1];
            }
        }
    }
    int getparent(int node, int k) {
        if(depth[node] < k) {
            return -1;
        }
        for(int j = LOG - 1; j >= 0; j--) {
            if(k >= (1 << j)) {
                node = up[node][j];
                k -= 1 << j;
            }
        }
        return node;
    }
    
    
    void find(int nd,vector<vector<int>>&tree,vector<long long>&A,map<pair<int,int>,long long>&w){
        queue<pair<int,pair<int,long long>>>bfs;
        bfs.push({0,{0,0ll}});
        A[0] = 0;
         int n = A.size();
         depth = vector<int>(n);
         
        while(!bfs.empty()){
            int c = bfs.size();
            for(int i=0;i<c;++i){
                pair<int,pair<int,long long>>temp = bfs.front();
                bfs.pop();
                int node = temp.first;
                int deep = temp.second.first;
                long long cost = temp.second.second;
                depth[node] = deep;
                
             //   cout<<node+1<<" ";
                for(auto&x:tree[node]){
                  //  cout<<x+1<<" ";
                    A[x] = cost + w[{min(x,node),max(x,node)}];
                    bfs.push({x,{deep+1,A[x]}});
                    
                }
               // cout<<endl;
            }
           // cout<<endl;
           // cout<<endl;
        }
         
    }

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        
        vector<int>parent(n);
        vector<vector<int>>tree(n);
        map<pair<int,int>,long long>A,B;
        for(int i=1;i<n;++i){
            int p;
            long long x,y;
            cin>>p>>x>>y;
            p--;
            parent[i] = p;
            tree[p].push_back(i);
            A[{min(p,i),max(p,i)}] = x;
            B[{min(p,i),max(p,i)}] = y;
        }
        
        create(n,parent);
        
        //I want each node to store the value
        vector<long long>svalue(n);
        find(0,tree,svalue,B);
        
        
        /*
        Let us check the depth of each node
       
        for(auto&x:depth)cout<<x<<" ";
        cout<<"\n"; */
        
        vector<int>score(n);
        //now let us move and compute two thing level and the wieght
        // node --  depth, score A
        queue<pair<int,pair<int,long long>>>bfs;
        bfs.push({0,{0,0ll}});
        
        while(!bfs.empty()){
            int c = bfs.size();
            for(int i=0;i<c;++i){
                pair<int,pair<int,long long>>temp = bfs.front();
                bfs.pop();
                int node = temp.first;
                int depth = temp.second.first;
                long long cost = temp.second.second;
                
                //I do binary search and store the score
             //   cout<<node+1<<" "<<cost<<" "<<svalue[node]<<" "<<depth<<endl;
                int s = 0,e = depth,m = (s+e)/2;
                if(cost >= svalue[node]){
                    
                    score[node] = depth;
                }
                
                while(s<=e){
                    //find the score of parent there
                 
                   //cout<<(node+1)<<" "<<m<<" "<<depth-m<<" ";
                    int p = getparent(node,depth-m);
                   // cout<<p<<endl;
                    
                    long long sum = svalue[p];
                    if(sum<=cost){
                        //move down
                        score[node] = max(score[node],m);
                        s = m+1;
                        m = (e+s)/2;
                    }
                    else{
                        e = m-1;
                        m = (s+e)/2;
                    }
                }
             //   cout<<"\n";
                
                for(auto&x:tree[node]){
                    long long val = A[{min(x,node),max(x,node)}]+cost;
                    bfs.push({x,{depth+1,val}});
                }
            }
        }
        
        for(int i=1;i<n;++i)cout<<score[i]<<" ";
        cout<<"\n";
    }
}
