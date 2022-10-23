'''
Platform :- Leetcode
Contest :- Leetcode Weekly contest 316
Approach :- So I did binary search and for each of the value I find the cost , then another cost to one of neighbours of current mid value (mid+1) or (mid-1) I choose the 
            side where cost was decreasing 
Time Complexity :- O(n log n)
'''

    
class Solution:
    
            
    def minCost(self, nums: List[int], cost: List[int]) -> int:
        
        start = int(1)
        end = int(10**9)
        mid = (start+end)//2
        ans = 10**20
        while(start<=end):
            sc1 = 0
            for x in range(len(nums)):
                z = abs(mid-nums[x])
                z = z*cost[x]
                sc1 = sc1 + z
                
            sc2 = 0
            val = mid+1
            for x in range(len(nums)):
                z = abs(val-nums[x])
                z = z*cost[x]
                sc2 = sc2 + z
            
            if(sc1<sc2):
                if(ans>sc1):
                    ans = sc1
                end = mid-1
                mid = (start+end)//2
            else:
                if(ans>sc2):
                    ans = sc2
                start = mid+1
                mid = (start+end)//2
        
        
        return ans
        
        
