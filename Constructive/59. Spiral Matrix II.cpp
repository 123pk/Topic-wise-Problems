/*
Platform :- Leetcode
Approach :- We will use a pointer which will help us in changing direction , few things to take care of the values of matrix cannot be more than (n*n) where n = no of rows
            second thing while changing direction we will take care of boundaries like (i<n && j<n) for 0 based indexing.
            
            starting by moving ( Right  - > Down  -> Left -> UP -> Right and so on)
*/
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
       vector<vector<int>>graph(n,vector<int>(n));
        int c = 3;
        int f = 0;
        int i = 0,j = 0,val = 1;
        while(val<=(n*n)  && (i<n && j<n)){
           // int f = 0;
            if(c%4 == 3){
               graph[i][j] = val;
                val++;
               if((j+1)<n && graph[i][j+1] == 0){
                   j++;
                  // val++;
               }   
               else {
                   c++;
                   i++;
               }
            }   
            else if(c%4 == 0){
               graph[i][j] = val;
                val++;
               if((i+1)<n && graph[i+1][j] == 0){
                   i++;
                   //val++;
               }   
               else{
                   c++;
                   j--;
               }
            }
            else if(c%4 == 1){
                graph[i][j] = val;
                val++;
               if((j-1)>=0 && graph[i][j-1] == 0){
                   j--;
                   
               }   
               else{
                  c++; 
                  i--;
               } 
            }
            else{
                graph[i][j] = val;
                val++;
               if((i-1)>=0 && graph[i-1][j] == 0){
                   i--;
                 //  val++;
               }   
               else {
                   c++;
                   j++;
               }
            }
           // cout<<i<<" "<<j<<" "<<val<<endl;        
        }
        
        return graph;
    }
};
