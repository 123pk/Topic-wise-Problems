/*
Platform :- Leetcode
Contest :- Leetcode Weekly contest 304
Approach :- We will traverse from 0 to n-1, if the nodes are already visited we don't visit then again , else we do dfs and store two vlues the length till 'x'th node
          (path len till there) and the starting node or root of current connected component or DSU , if we visit one node whose root node is (i+1) then it means we have
          a cycle and it is of length (curent_len - len_till_that_node)+1. 
          --> If we visite a node whose root is not (i+1) then it means we have already considered that path and will not traverse it again so we stop our bfs there and 
              break out .
Time complexity :- O(n)
Space complexity :- O(n)
*/
class Solution {
public:
    
    
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<vector<int>>graph(n);
        
        
        for(int i=0;i<n;++i){
            if(edges[i] == -1)continue;
            graph[i].push_back(edges[i]);
        }
        
        int ans = -1;
        vector<int>again(n);
        vector<int>len(n);
        for(int i=0;i<n;++i){
            if(again[i])continue;
            
            queue<pair<int,int>>bfs;
            bfs.push({i,1});
            len[i] = 1;
            again[i] = i+1;
            int f = 0,val = -1;
            
            while(!bfs.empty()){
                int c = bfs.size();
                for(int j=0;j<c;++j){
                    pair<int,int>temp = bfs.front();
                    bfs.pop();
                    int node = temp.first;
                    int dist = temp.second;
                    //cout<<node<<" -- "<<dist<<"\n";
                    for(auto&x:graph[node]){
                        //cout<<x<<" "<<again[x]<<" "<<(i+1)<<" \n";
                        if(again[x]){
                            if(again[x]!=(i+1)){
                               f=1;break;
                            }
                            val = max(val,dist - (len[x]-1));
                            continue;
                        }
                        again[x] = i+1;
                        len[x] = dist+1;
                        bfs.push({x,dist+1});
                    }
                //    cout<<"\n";
                    if(f)break;
                }
                if(f)break;
            }
            //cout<<"\n";
         //   cout<<(i+1)<<" "<<val<<"\n";
            
            
            if(f == 0)ans = max(ans,val);
        }
        
        
        return ans;
    }
};
