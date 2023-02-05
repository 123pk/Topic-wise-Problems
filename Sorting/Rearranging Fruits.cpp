/*
Platform :- Leetcode
Contest :- Leetcode Weekly contest 331
Approach :- https://leetcode.com/problems/rearranging-fruits/solutions/3144111/explained-with-image-c-sorting-map/
Time Complexity :- O(n log n)
*/
class Solution {
public:
    
    void find(vector<long long>&ex1,vector<long long>&ex2,long long& ans,long long mn){
        int m = ex1.size();
        long long cost = 0;

        //mn_cost is the cost we need to pay if we want to swap elements from min value
        long long mn_cost = 2ll*mn;

        for(int i=0;i<m;++i){
            //cur_cost is cost of swapping ex1[i] and ex2[i] , ith extra element of both bucket
            long long cur_cost = min(ex1[i],ex2[i]);
            
            //if swapping with minimum value is efficient we swap with min value individually
            if(mn_cost < cur_cost){
                cost += mn_cost;
            }//else we swap them
            else cost += cur_cost;
        }

        ans = min(ans,cost);
    }
    
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        long long ans = 0;
        
        vector<long long>ex1,ex2;
        map<long long ,long long>fre,fre1,fre2;

        //we find the frequency of element in both basket
        for(auto&x:basket1){
            fre1[x]++;
            fre[x]++;
        }
        long long mn = 1e18;
        for(auto&x:basket2){
            fre2[x]++;
            fre[x]++;
        }
        
         //fre1 -- store the frequency of element in bucket1
         //fre2 -- store the frequency of elemtn in bucket2
        for(auto&x:fre){
            mn = min(x.first,mn);

            //if any element is odd number of times we cannot divide into two groups
            //so it is impossible
            if(x.second%2)return -1ll;
            
            int sz = x.second/2;
            //we need sz no of elements in our bucket 
            //if we have more we need to swap them

            //adding extra elements of bucket 1 in ex1
            for(int i=0;i<(fre1[x.first]-sz);++i){
                ex1.push_back(x.first);
            }
            //adding extra elements of bucket 2 in ex2
            for(int i=0;i<(fre2[x.first]-sz);++i){
                ex2.push_back(x.first);
            }
        }
         
        //we want to map smallest of extra element of first bucket
        //with maximum of extra element of second element and so on.
        reverse(ex2.begin(),ex2.end());
        
        ans = 1e18;
        find(ex1,ex2,ans,mn);
         
        return ans;
    }
};
