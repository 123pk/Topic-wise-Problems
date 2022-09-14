/*
Platform :- Leetcode
Approach :- We find the starting index and ending index where our array is unsorted , 
            * if the subarry from start to end is sorted , in that case we will consider situation when we will remove prefix and suffix of that
            * For each element in [0,start-1] we will find a value which is smallest index where ( arr[i]>= arr[current_index] ) value in [end,n-1] , 
                as they will form sorte array as value in [end,n-1] are already sorted .
           * Similarly for all element in [end,n-1] we will find one value which will be <= current value in range [ 0 ,star-1].
           We will use binary search to find the indexes as they are already sorted.
           
 Time Comlexity - O(n log n) -- binary search
*/

int find(int start,int end,vector<int>&arr,int idx){
    int mid = (start+end)/2;
    int ans = -1;
    
    while(start<=end){
        if(idx>end){
            if(arr[mid]<=arr[idx]){
                ans = mid;
                start = mid+1;
                mid = (start+end)/2;
            }
            else{
                end = mid-1;
                mid = (start+end)/2;
            }
        }
        else{
            if(arr[mid]>=arr[idx]){
                ans = mid;
                end = mid-1;
                mid = (start+end)/2;
            }
            else {
                start = mid+1;
                mid = (start+end)/2;
            }
        }
    }
    
    return ans;
}

class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int ans = 0;
        
        //first find the first index where array become unsorted
        int start = -1;
        for(int i=1;i<arr.size();++i){
            if(arr[i]<arr[i-1]){
                start = i;
                break;
            }
        }
        
        if(start == -1)return ans;
        
        int end = -1;
        int n = arr.size();
         for(int i=n-2;i>=0;--i){
            if(arr[i]>arr[i+1]){
                end = i+1;
                break;
            }
            
        }
        
         
        //if we remove the middle part 
        //check if middle part is sorte
        int f = 0;
       for(int i=start+1;i<=end;++i){
            if(arr[i]<arr[i-1]){
                f=1;
                break;
            }
        }
        
        ans = INT_MAX;
        //this means middle part is sorted
        if(f == 0){
            ans = (start+(arr.size()-(end+1)));
        }
        
         
        //we know that 0 to start-1 is sorted 
        //and end,n-1 is sorted so for each value in 0,start we will find one value which is 
        //greater than choosen value in 0 to start-1 and vice versa for end,n-1 because that part
        //will fort sorted arry
        for(int i=0;i<start;i++){
            int idx = find(end,arr.size()-1,arr,i);
            if(idx == -1)idx = arr.size();
            int cost = (idx - i)-1;
            ans = min(ans,cost);
        }
        //cout<<ans<<" \n";
        //similarly for second half now
        for(int i=end;i<arr.size();++i){
            int idx = find(0,start-1,arr,i);
            //cout<<idx<<' ';
            if(idx == -1)idx = -1;
            int cost = (i-idx)-1;
            ans = min(ans,cost);
        }
        
        return ans;
    }
};
