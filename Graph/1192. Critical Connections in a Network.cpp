/*
Platform :- Leetcode
Approach :- Find the count of articulation point in graph and that is our required value. 
             DFS + visited array time
*/
class Solution {
public:
    #define vc vector
    vc<vc<int>>g,ans;
    vc<int>disc,low,par;

    int time=0;
    void dfs(int u) //u is the  parent 
    {
       
      
        disc[u]=low[u]=time++; 
       
        int l=g[u].size();
        for(int i=0;i<l;i++)
        {
            
            int v=g[u][i];
            if((disc[v]==-1)) //if not visited then just start a new dfs from the adjacent node and hope it will discover a back-edge.
            {
                                            //v-> adjacent node
                                           //u->parent node
                
                
                par[v]=u;                //making u the parent
                dfs(v);                 //low values updated 
               //you can also update low value of parent here..
                
                if(low[v]>disc[u])ans.push_back({u,v}); //condition of back edge NOT found
                low[u]=min(low[u],low[v]);              //updating low value of parent
            }
            else if(v!=par[u])                                                                           
                low[u]=min(low[u],low[v]);
              
        }
        
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& con) {
        g=vc<vc<int>>(n);
        par=vc<int>(n,-1);
        low=vc<int>(n,-1);
        
        disc=low;
        for(auto &e:con)
            g[e[0]].push_back(e[1]),g[e[1]].push_back(e[0]);
        for(int v=0;v<n;v++)
            if(disc[v]==-1)dfs(v);
        return ans;
        
        
    }
};
