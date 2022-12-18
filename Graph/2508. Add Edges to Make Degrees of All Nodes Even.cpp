/*
Platform :- Leetcode
Contest :- Leetcode Weekly contest 324
Approach :- We will first compress the values to be in range from [0,n-1],
            now we will find degree of nodes ,let c = count of nodes with odd degree
            if 'c' > 4 we cannot do it as two edges can cover atmax '4' nodex.
            if 'c' =  1 or c = '3' then also we cannot cover them in two edges.
            if (c==4) then we can cover if their is two pair of nodes out of all combination such that we can add them 
            if(c == 2) we have two option either to add a directly if possible or 
            node1 -->x  and  node2 --> x ,where x is some even degree node and it is allowed to have those edges
Time Compelxity :- O(n+e)
*/
class Solution {
public:
    bool isPossible(int n, vector<vector<int>>& edges) {
        
        int val = 1;
        map<int,int>compress;
        set<int>avail;
        for(auto&x:edges){
            int a = x[0];
            int b = x[1];
            
            if(avail.size()){
                
                if(avail.find(a) == avail.end()){
                    compress[a] = val;
                    val++;
                    avail.insert(a);
                }
                
                if(avail.find(b) == avail.end()){
                    avail.insert(b);
                    compress[b] = val;
                    val++;
                }
                continue;
            }
            
            avail.insert(x[0]);
            compress[a] = val;
            val++;
            avail.insert(x[1]);
            compress[b] = val;
            val++;
        }
        
        
        vector<vector<int>>graph;
        vector<int>degree(n);
        set<pair<int,int>>P;
        
        for(auto&x:edges){
            int y = compress[x[0]]-1;
            int z = compress[x[1]]-1;
            
            degree[y]++;
            degree[z]++;
            int a = min(y,z);
            int b = max(y,z);
           //cout<<y<<" "<<z<<"\n";
            P.insert({a,b});
        }
        
        vector<int>extra;
        for(int i=0;i<n;++i){
            if(degree[i]%2){
                extra.push_back(i);
                if(extra.size()>4)return false;
            }
        }
        int add = 0;
        if(extra.size()%2)return false;
        
        if(extra.size() == 2){
            //we need to know all this 
            //node that are free;
            
            int a1 = min(extra[0],extra[1]);
            int b1 = max(extra[1],extra[0]);
            if(P.find({a1,b1}) == P.end())return true;
            
             
                for(int i=0;i<n;++i){
                    if(extra[0] == i || extra[1] == i)continue;
                    
                    int a = min(extra[0],i);
                    int b = max(extra[0],i);
                    
                    int c = min(extra[1],i);
                   int d = max(extra[1],i);
                    
                    if(P.find({a,b}) == P.end()){
                        if(P.find({c,d}) == P.end()){
                            return true;
                        }
                    }
                }
            return false;
            
        }
         
       do{
           int can = 0;
            for(int i=1;i<extra.size();i+=2){
                int a = min(extra[i],extra[i-1]);
                int b = max(extra[i],extra[i-1]);
                
                if(P.find({a,b}) ==P.end()){
                    //cout<<a<<" "<<b<<"\n";
                    can++;
                }
            }
            //cout<<can<<"\n";
            add = max(add,can);
        }while(next_permutation(extra.begin(),extra.end()));
        
      //  cout<<add<<"\n";
        int req = extra.size()-(add*2);
        
        if(req == 0)return true;
        return false;
    }
};
