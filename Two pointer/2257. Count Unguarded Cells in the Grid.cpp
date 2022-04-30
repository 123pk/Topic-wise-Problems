/*
Platform :- Leetcode
Contest :- Leetcode Bi Weekly contest 77 
Approach :- We will perform four traversal operations and that will cover all the cells which can be gurarded and all the remainig cells cannot be guarded and apart from
            walls the count of remaining ones is our answer.
            
            Basic idea is to do traversal and if we find any guard node then we mark flag , if we found a cell that is not guarded and our flag is marked then it means 
            we can guard this cell , if we found wall then we unmark the flag until we found any other guard .
            
            Four traversals are ( Left --> Right ) ,(Right --> left) , ( Top --> Bottom) and (Bottom to Top) 
*/
class Solution {
public:
    int countUnguarded(int n, int m, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        int ans = 0;
        vector<vector<int>>vis(n,vector<int>(m));
      //  vector<vector<int>>grid(n,vector<int>(m));
        for(auto&x:guards){
            vis[x[0]][x[1]] = 1;
        }
        
        for(auto&x:walls){
            vis[x[0]][x[1]] = 2;
        }
        
        //left to right
        for(int i=0;i<n;++i){
            int f = 0;
            for(int j=0;j<m;++j){
                if(vis[i][j] == 2){
                    f=0;
                }
                else {
                    if(vis[i][j] == 1)f=1;
                    else{
                        if(f)vis[i][j] = 3;
                    }
                    
                }
            }
        }
        
        //now move rigt to left
        for(int i=0;i<n;++i){
            int f = 0;
            for(int j=m-1;j>=0;--j){
                if(vis[i][j] == 2){
                    f=0;
                }
                else {
                    if(vis[i][j] == 1)f=1;
                    else{
                        if(f)vis[i][j] = 3;
                    }
                    
                }
            }
        }
        
        //lets go top down
        for(int j=0;j<m;++j){
            int f = 0;
            for(int i=0;i<n;++i){
                if(vis[i][j] == 2){
                    f=0;
                }
                else {
                    if(vis[i][j] == 1)f=1;
                    else{
                        if(f)vis[i][j] = 3;
                    }
                    
                }
            }
        }
        //bottom  up
        for(int j=0;j<m;++j){
            int f = 0;
            for(int i=n-1;i>=0;--i){
                if(vis[i][j] == 2){
                    f=0;
                }
                else {
                    if(vis[i][j] == 1)f=1;
                    else{
                        if(f)vis[i][j] = 3;
                    }
                    
                }
            }
        }
        
        //count the cells that are not guarded 
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(vis[i][j] == 0){
                    ans++;
                    
                }//cout<<vis[i][j]<<" ";
            }
            //cout<<"\n";
        }
        
        return ans;
    }
};
