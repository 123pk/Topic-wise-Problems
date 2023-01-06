/*
Platform :- Leetcode
Approach :- If you will carfully observe you will find that there is formation of strongly connected component between cells with stones ,we need to count no of nodes 
            in stricly connected compment for each cell ,let 'x' be the count ,then we can remove x-1 of them .
            So sum of all such 'x-1' for each connected component is our solution.
            We will use two map which will store the cell for each row , and column .We will start with bfs and visited array so that we don't visit same cell again.
            and keep on counting.
 Time Complexiy :- O(m*n*log(m*n))
*/
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        //dsu
        map<int,vector<int>>row,col;
        set<pair<int,int>>used;
        int i = 0,ans= 0;
        for(auto&x:stones){
            row[x[0]].push_back(i);
            col[x[1]].push_back(i);
            i++;
        }
        
        for(auto&x:stones){
            if(used.size()){
                if(used.find({x[0],x[1]}) != used.end())continue;
            }
            used.insert({x[0],x[1]});
            int count = 1;
            queue<pair<int,int>>bfs;
            bfs.push({x[0],x[1]});
            
            while(!bfs.empty()){
                pair<int,int>temp = bfs.front();
                bfs.pop();
                int r = temp.first;
                int c = temp.second;
                
                for(auto&x:row[r]){
                    if(used.find({stones[x][0],stones[x][1]}) != used.end())continue;
                    count++;
                    used.insert({stones[x][0],stones[x][1]});
                    bfs.push({stones[x][0],stones[x][1]});
                }
                
                for(auto&x:col[c]){
                    if(used.find({stones[x][0],stones[x][1]}) != used.end())continue;
                    count++;
                    used.insert({stones[x][0],stones[x][1]});
                    bfs.push({stones[x][0],stones[x][1]});
                }
            }
            
            
            ans += count-1;
        }
        return ans;
    }
};
