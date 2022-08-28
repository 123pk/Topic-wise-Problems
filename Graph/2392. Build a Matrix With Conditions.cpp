/*
Platform :- Leetcode
Contest :- Leetcode Weekly contest 308
Approach :- So you need to understand it is a graph problem more formally Disjoint Set Union (DSU) or connected componenets .
            i. Condition for 'NOT' having any solutin is when we have a 'Cycle' in any of the connected component.
            ii. Now we know we have solution but how to initialise the cells , it is better to create two graphs based on conditions one for row and for column
            iii. Now we use topological sort to give the cell to the number from 1 to k , 
            iv. We fill the values which have both row and column value already from topological sorting
            v. Now for remaining values with either row or column value , we can give cells to any one of them first so how to do that , suppose we know the row 
               then we will run a loop for column from 0 to k-1 and will find the first unfilled cell and give it to this number . We do same until finshed

Time complexity :- O(N^2) , in worst case when we just have row or column value only
*/
class Solution {
public:
    //we need a degree array and sort them based on smalles degree first
    void fill(vector<vector<int>>&dsur,vector<int>&cur_row,int k,vector<int>&degree){
        
        queue<int>bfs;
        for(int i=0;i<k;++i){
            if(dsur[i].size() == 0)continue;
            
            if(degree[i]  == 0)bfs.push(i);
        }
        int r = 0;
        while(!bfs.empty()){
            int node = bfs.front();
            bfs.pop();
            cur_row[node] = r;
            r++;
            //now move too all the cells and decrement the 
            //degree 
            for(auto&x:dsur[node]){
                degree[x]--;
                if(degree[x] == 0)bfs.push(x);
            }
        }
    }
    
    void cycle(int node,vector<vector<int>>&graph,vector<int>&vis,int& f){
        if(f)return;
        vis[node]++;
        for(auto&x:graph[node]){
            if(vis[x] == 1){
                f=1;
                return;
            }
            if(vis[x] == 0)cycle(x,graph,vis,f);
        }
        vis[node] = 2;
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rrow, vector<vector<int>>& ccol) {
        
        //we create a graph and if there is any circle in DSU then we return empty matrix
        vector<vector<int>>dsur(k),dsuc(k);
        vector<int>d1(k),d2(k);
        
        vector<vector<int>>ans;
        vector<int>vis(k);
        for(auto&x:rrow){
            dsur[x[0]-1].push_back(x[1]-1);
            d1[x[1]-1]++;
        }
        
        for(int i=0;i<k;++i){
            if(vis[i] == 0){
                int f = 0;
                cycle(i,dsur,vis,f);
                if(f)return ans;
            }
        }
        
        vis.clear();
        vis.resize(k);
        
        for(auto&x:ccol){
            dsuc[x[0]-1].push_back(x[1]-1);
            d2[x[1]-1]++;
        }
        
        for(int i=0;i<k;++i){
            if(vis[i] == 0){
                int f = 0;
                cycle(i,dsuc,vis,f);
                if(f)return ans;
            }
        }
        
        
        //now we dont have any cycle so we use toplogical sort to order the elements
        vector<int>row(k),col(k);
        fill(dsur,row,k,d1);
        fill(dsuc,col,k,d2);
        
        vector<vector<int>>fin(k,vector<int>(k));
        for(int i=0;i<k;++i){
            //we fill the cells with exact i,j values 
            if(row[i]>=0 && col[i]>=0){
               // cout<<row[i]<<" "<<col[i]<<" for "<<i+1<<" \n";
                fin[row[i]][col[i]] = i+1;
            }
        }
        
        //now we fill it row firsst
        for(int i=0;i<k;++i){
            if(row[i]>=0 && col[i] == -1){
                //so I can choose any not choosen oclum and fill it
                int g = 0;
                for(int j=0;j<k;++j){
                    if(fin[row[i]][j])continue;
                    fin[row[i]][j] = i+1;
                    g = 1;
                    break;
                }
                if(g == 0)return ans;
            }
        }
        
        //now fill the coulms
        for(int i=0;i<k;++i){
            if(row[i] == -1 && col[i]>=0){
                int g = 0;
                for(int j=0;j<k;++j){
                    if(fin[j][col[i]])continue;
                    g = 1;
                    fin[j][col[i]] = i+1;
                    break;
                }
                if(g == 0)return ans;
            }
        }
        
        return fin;
        
    }
};
