/*
Platform :- Leetcode
Contest :- Weekly contest 316
Approach :- Get all the odd and even values of nums array, now sort the target array and for each odd value or even value , get the abs(x-value[j])/2 where j is the last odd or 
            even element accordingly .
            At the end we have to half of those operations as we are covering two operatino in 1 move.
Time Complexity :- O(n logn)
*/
class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        long long ans = 0;
        
        //get the frequency aray
        vector<int>odd,eve;
        map<int,int>fre;
        for(auto&x:target)fre[x]++;
        
        for(auto&x:nums){
             
                if(x%2)odd.push_back(x);
                else eve.push_back(x);
           
        }
        
        
        vector<int>rem;
        for(auto&x:target){
             
                rem.push_back(x);
             
        }
        sort(odd.begin(),odd.end());
        sort(eve.begin(),eve.end());
        sort(rem.begin(),rem.end(),greater<int>());
         
        
        int i = 0,j = 0;
        int c = 0,d = 0;
         
        
        for(auto&x:rem){
            if(x%2){
              //  cout<<odd.size()<<" odd "<<endl;
                ans += abs(x-odd[odd.size()-1])/2;
                odd.pop_back();
            }
            else{
               // cout<<eve.size()<<" eve"<<endl;
             //   cout<<x<<" "<<eve[eve.size()-1]<<" \n";
                ans += abs(x-eve[eve.size()-1])/2;
                eve.pop_back();
            }
               
        }
       
        ans>>=1;
        return ans;
    }
};
