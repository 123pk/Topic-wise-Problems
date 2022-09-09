/*
Platform :- Leetcode
Approach :- First we sort the array by first value , then for each value we try to find the max value (second one)that we can get from all the values greatear than it .
            We first find max of all second value for particular x,like for (5,2) , (5,4) , (5,8) , (5,9) ... we want to store (5,9) for value of 5 , 9 is the max value we 
            can have . Similary for all other value .
            Now we want to find max of all second values for all first values greater than current first value 
            (5,9) (6,7)(9,8)  --- we will store (5,8) (6,8) (9,0) as that is the maximum second value that we can have from all value greater than first value.
*/
 bool comp(vector<int>&P,vector<int>&Q){
        if(P[0] == Q[0]){
            return P[1]<Q[1];
        }
        return P[0]<Q[0];
    }

class Solution {
public:
    
   
    
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
         
        
        sort(properties.begin(),properties.end(),comp);
        
        int ans = 0;
        int n = properties.size();
        int mx1 = 0,mx2 = 0,mx = 0;
        
        map<int,int>value;
        for(int i= n-1;i>=0;--i){
            if(i != n-1){
                if(properties[i][0] == properties[i+1][0]){
                    mx = max(mx,properties[i][1]);
                    if(i == 0)value[properties[i][0]]=mx;
                }
                else{
                    value[properties[i+1][0]]=mx;
                    mx = properties[i][1];
                    
                    if(i == 0)value[properties[i][0]]=mx;;
                }
            }
            else{
                mx = properties[i][1];
            }
            
        }
        
        mx = 0;
        for(auto x = value.rbegin();x!=value.rend();x++){
            pair<int,int>temp = *x;
            
            value[temp.first] = mx;
            mx = max(mx,temp.second);
        }
        
        /*for(auto&x:value){
            cout<<x.first<<" "<<x.second<<"\n";
        }
        cout<<"\n";
       */ mx1 = properties[n-1][0];
        mx2 = 0;
        
         
        for(auto&x:properties){
            if(x[0]<mx1 && x[1]<value[x[0]])ans++;
        }
        return ans;
    }
};
