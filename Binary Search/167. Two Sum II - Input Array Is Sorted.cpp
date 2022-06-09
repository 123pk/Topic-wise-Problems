
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int>ans;
        
         
        //now constant space solution 
        //we will use bitwise or operation 
        //since both values need to be smaller than target 
        //so will choose that element only which will get us the value
        int f = 0;
        for(int i=0;i<numbers.size();++i){
             if((target-numbers[i])<numbers[i])break;
            
             //binary searchthis value
            int start = i+1,end = numbers.size()-1,mid = (start+end)/2,val = target-numbers[i];
             while(start<=end){
                 if(numbers[mid] == val){
                     f=1; ans = {i+1,mid+1};break;
                    
                 }
                 else{
                     if(numbers[mid]>val){
                         end = mid-1;
                         mid = (start+end)/2;
                     }
                     else {
                         start = mid+1;
                         mid = (start+end)/2;
                     }
                 }
             }
            
            if(f)break;
        }
        
        return ans;
    }
};
