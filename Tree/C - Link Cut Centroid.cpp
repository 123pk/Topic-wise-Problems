/*
Platform :- Codeforces
Contest :- Codeforces Round 670 # Div 2
Approach :- First find the no of centroid , if there is just one centroid then we remove and add same edge .
            --> For finding centroid we store the size of subtree for each node and for node 'i' , we find the max of all subtree size of child nodes and (n-(sum_of_all)+1)
                 this will give me upper subtree (nodes above current node) size
                 
            --> We cannot have more than two centroid . In this case we remove leaf  node of one centroid and add it to other centroid.
*/
#include<bits/stdc++.h>
using namespace std;

int find(int node,vector<vector<int>>&tree,vector<vector<int>>&details,vector<int>&vis){
    
    vis[node]++;
    int val = 0;
    int mx = 0;
   // if(node == 1)cout<<vis[0]<<"\n";
    for(auto&x:tree[node]){
        if(vis[x])continue;
        int temp = find(x,tree,details,vis);
        val += (temp);
        mx = max(mx,temp);
        
        
    }
    int n = vis.size();
   // cout<<node+1<<" "<<val<<"\n";
   int z = n - (val+1);
   
    details[node] = {max(mx,z),val,z};
    return val+1;
}

  

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        
        vector<vector<int>>tree(n);
        for(int i=1;i<n;++i){
            int u,v;
            cin>>u>>v;
            u--;
            v--;
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
        
        //score , subtree size,parent size
        vector<vector<int>>details(n,vector<int>(3));
        vector<int>vis(n);
        int val = find(0,tree,details,vis);
        
        
        //now we can find the 
        int c = 0;
        int mn = INT_MAX;
        for(int i=0;i<n;++i){
            mn = min(mn,details[i][0]);
        }
        int d = 0,one = 0;
        vector<int>centroid;
        for(auto&x:details){
            if(x[0] == mn){
                c++;
                centroid.push_back(d);
            }
            d++;
        }
        
        if(c == 1){
            cout<<1<<" "<<tree[0][0]+1<<"\n";
            cout<<1<<" "<<tree[0][0]+1<<"\n";
        }
        else{
            //now let us traverse in one node and find any leaf node
            queue<pair<int,int>>bfs;
            vector<int>vis2(n);
            bfs.push({centroid[0],centroid[0]});
            vis2[centroid[0]]++;
            
            int start = 0,second = 0,f = 0;
            while(!bfs.empty()){
                int c = bfs.size();
                for(int i=0;i<c;++i){
                    pair<int,int>temp = bfs.front();
                    int node = temp.first;
                    int parent = temp.second;
                    bfs.pop();
                    
                    int count = 0;
                    for(auto&x:tree[node]){
                        if(vis2[x] )continue;
                        vis2[x]++;
                        if(x == centroid[1]){
                            continue;
                        }
                        
                        count++;
                        bfs.push({x,node});
                    }
                    //cout<<count<<" for "<<node+1<<"\n";
                    if(count == 0){
                        start = node;
                        second = parent;
                        f = 1;
                        break;
                    }
                }
                if(f)break;
            }
            
            cout<<start+1<<" "<<second+1<<"\n";
            cout<<(start+1)<<" "<<(centroid[1]+1)<<"\n";
        }
         
    }
}
