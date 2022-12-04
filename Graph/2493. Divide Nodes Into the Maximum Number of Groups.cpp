/*
Platform :- Leetcode
Contest :- Leetcode Weekly contest 322
Approach :- First if you will observer the problem you will find that if the graph has even length of cycle then we cannot have any valid distribution.
            Even length  = even no of edges  ,
            else we have multiple subgraph which are disjoint and we will try to find the max length we can get to by Brutefrocing for each of the node,
            and the max value out of all the nodes is added to our answer.
 Time Complexity :- O(n*(n+m))
*/
class Solution {
public:
    
    int find(int node,vector<vector<int>>&graph,int n){
        
        queue<pair<int,int>>bfs;
        vector<int>group(n);
            bfs.push({node,1});
            
            int f = 0,d = 1;
            group[node] = 1;
            
            while(!bfs.empty()){
                int c = bfs.size();
                for(int j=0;j<c;++j){
                    pair<int,int>temp = bfs.front();
                    bfs.pop();
                    int node = temp.first;
                    int cur_group = temp.second;
                    d = max(d,cur_group);
                   // cout<<node<<" "<<cur_group<<"\n";
                    for(auto&x:graph[node]){
                        if(group[x]){
                            if(abs(group[x] - cur_group)!=1){
                                f=1;
                                break;
                            }
                            continue;
                        }
                        else{
                            group[x] = cur_group+1;
                            bfs.push({x,group[x]});
                        }
                    }
                }
                if(f)break;
            }
            if(f){
                return -1;
            }
        return d;
    }
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<int>group(n);
        
        vector<vector<int>>graph(n);
        vector<int>degree(n);
        vector<pair<int,int>>P;
        for(auto&x:edges){
            graph[x[0]-1].push_back(x[1]-1);
            graph[x[1]-1].push_back(x[0]-1);
            degree[x[0]-1]++;
            degree[x[1]-1]++;
        }
        
        for(int i=0;i<n;++i){
            P.push_back({degree[i],i});
        }
        
        sort(P.begin(),P.end());
        
        int ans = 0,tot = 0;
        vector<int>vis(n);
        for(int i=0;i<n;++i){
            if(vis[i])continue;
            
            vector<int>temp;
            queue<int>bfs;
            bfs.push(i);
            vis[i]++;
            temp.push_back(i);
            
            while(!bfs.empty()){
                int node = bfs.front();
                bfs.pop();
                for(auto&x:graph[node]){
                    if(vis[x])continue;
                    vis[x]++;
                    temp.push_back(x);
                    bfs.push(x);
                }
            }
            
            int d = 1;
            for(auto&x:temp){
                int val = find(x,graph,n);
                if(val == -1)return -1;
                d = max(d,val);
            }
            
            ans += d;
        }
        return ans;
    }
};
