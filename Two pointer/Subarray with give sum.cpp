/*
Platform :- Geeksforgeeks
Approach :- We maintain two pointer pointing to stat and end of required range , we traverse through the array and update tot = tot + arr[i]
            we move our start pointer till tot>s , at the end we check if we have required sum or not , if yes then we have range from [start,end]
            
Time Complexity :- O(n)
*/
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int arr[], int n, long long s)
    {
        // Your code here
        int start = 0,end = -1;
        long long tot = 0;
        for(int i=0;i<n;++i){
            tot += arr[i];
            while(tot>s){
                tot -= arr[start];
                start++;
            }
            
            if(tot == s){
                end = i;
                break;
            }
        }
        if(end == -1 || start>end)return {-1};
        return {start+1,end+1};
    }
};
