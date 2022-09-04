/*
Platform :- Leetcode
Contest :- Leetcode Weekly contest 309
Approach :- We will use one frequency array of size 32 , where we will store frequencey of each bit , we have '&' value zero if each bit do not occur more than once 
            if it happens then we move our left/start pointer which will intitally start from '0' , start will reprensent the starting point of our subarray we keep track
            of size of subarray too .
Time Complexity :- O(n)
*/
class Solution {
public:
    
    string find(int val){
        string temp = bitset<32>(val).to_string();
        reverse(temp.begin(),temp.end());
        return temp;
    }
    
    int longestNiceSubarray(vector<int>& nums) {
        int ans = 1;
        int n = nums.size();
        vector<int>fre(32);
        int c = 0;
        int last = 0;
        
        string cur = "";
        for(int i=0;i<n;++i){
            string temp = bitset<32>(nums[i]).to_string();
            reverse(temp.begin(),temp.end());
            int f = 0;
            for(int j=0;j<32;++j){
                if(temp[j] == '1' && fre[j]){
                    f=1;
                    break;
                }
            }
            
            if(f){
                ans = max(ans,i-last);
                
                //now I start moving my last pinter
                while(last<i){
                    cur = "";
                    cur = find(nums[last]);
                    for(int j=0;j<32;++j){
                        if(cur[j] == '1')fre[j]--;
                    }
                    
                    //now check fi the 
                    f = 0;
                    for(int j=0;j<32;++j){
                        if(temp[j] == '1' &&  fre[j]){
                            f=1;
                            break;
                        }
                    }
                    last++;
                    if(f)continue;
                    else break;
                }
                
                for(int j=0;j<32;++j){
                    if(temp[j] == '1'){
                        fre[j] = 1;
                    }
                }
                ans = max(ans,(i+1)-last);
            }
            else{
                for(int j=0;j<32;++j){
                    if(temp[j] == '1'){
                        fre[j] = 1;
                    }
                }
                    ans = max(ans,((i+1)-last));
                
            }
        }
        
        return ans;
    }
};
