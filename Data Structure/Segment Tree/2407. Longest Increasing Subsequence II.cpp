/*
Platform :- Leetcode
Contest :- Weekly contest 310
Approach :- We will maintain one dp[i] for all values in range [1, 10^5+1] ,  for dp[i] = max value in range(dp[i-k] ,dp[i-1]) + 1 
            to find max value in range we will use segment tree
Time Complexity :- O(n*logn)
*/
// A utility function to get the
// middle index of given range.
int getMid(int s, int e)
{
    return s + (e - s) / 2;
}
 
/*  A recursive function to get the sum of
    values in given range of the array.
    The following are parameters for this
    function.
 
    st       -> Pointer to segment tree
    node     -> Index of current node in
                the segment tree .
    ss & se  -> Starting and ending indexes
                of the segment represented
                by current node, i.e., st[node]
    l & r    -> Starting and ending indexes
                of range query */
int MaxUtil(int* st, int ss, int se, int l,
            int r, int node)
{
    // If segment of this node is completely
    // part of given range, then return
    // the max of segment
    if (l <= ss && r >= se)
        return st[node];
 
    // If segment of this node does not
    // belong to given range
    if (se < l || ss > r)
        return -1;
 
    // If segment of this node is partially
    // the part of given range
    int mid = getMid(ss, se);
     
    return max(MaxUtil(st, ss, mid, l, r,
                       2 * node + 1),
               MaxUtil(st, mid + 1, se, l,
                       r, 2 * node + 2));
}
 
/* A recursive function to update the nodes
   which have the given index in their range.
   The following are parameters st, ss and
   se are same as defined
   above index -> index of the element
   to be updated.*/
void updateValue(int arr[], int* st, int ss, int se,
                 int index, int value, int node)
{
    if (index < ss || index > se)
    {
        cout << "Invalid Input" << endl;
        return;
    }
     
    if (ss == se)
    {  
        // update value in array and in segment tree
        arr[index] = value;
        st[node] = value;
    }
    else {
            int mid = getMid(ss, se);
             
            if (index >= ss && index <= mid)
                updateValue(arr, st,
                            ss, mid, index,
                            value, 2 * node + 1);
            else
                updateValue(arr,
                            st, mid + 1, se,
                            index,
                            value, 2 * node + 2);
             
            st[node] = max(st[2 * node + 1],
                       st[2 * node + 2]);
    }
    return;
}
 
// Return max of elements in range from
// index l (query start) to r (query end).
int getMax(int* st, int n, int l, int r)
{
    // Check for erroneous input values
    if (l < 0 || r > n - 1 || l > r)
    {
        printf("Invalid Input");
        return -1;
    }
 
    return MaxUtil(st, 0, n - 1, l, r, 0);
}
 
// A recursive function that constructs Segment
// Tree for array[ss..se]. si is index of
// current node in segment tree st
int constructSTUtil(int arr[], int ss, int se,
                    int* st, int si)
{
    // If there is one element in array, store
    // it in current node of
    // segment tree and return
    if (ss == se)
    {
        st[si] = arr[ss];
        return arr[ss];
    }
 
    // If there are more than one elements, then
    // recur for left and right subtrees and
    // store the max of values in this node
    int mid = getMid(ss, se);
     
    st[si] = max(constructSTUtil(arr, ss, mid, st,
                                 si * 2 + 1),
                 constructSTUtil(arr, mid + 1, se,
                                 st, si * 2 + 2));
     
    return st[si];
}
 
/* Function to construct segment tree
   from given array.
   This function allocates memory for
   segment tree.*/
int* constructST(int arr[], int n)
{
    // Height of segment tree
    int x = (int)(ceil(log2(n)));
 
    // Maximum size of segment tree
    int max_size = 2 * (int)pow(2, x) - 1;
 
    // Allocate memory
    int* st = new int[max_size];
 
    // Fill the allocated memory st
    constructSTUtil(arr, 0, n - 1, st, 0);
 
    // Return the constructed segment tree
    return st;
}


class Solution {
public:
    int lengthOfLIS(vector<int>& nums, int k) {
        
        int n = 100001;
        int arr[n];
        for(int i=0;i<n;++i)arr[i] = 0;
        
        // Build segment tree from given array
        int* st = constructST(arr, n);
        int ans = 0;
        
        for(int i=0;i<nums.size();++i){
            int l = max(0,nums[i]-k);
            int r = nums[i]-1;
           
            //find max value in range using Segment tree in [l,r]
            int val = getMax(st, n, l, r);
            ans = max(ans,val+1);
            
            //update segment tree change nums[i] with val+1
            updateValue(arr, st, 0, n - 1, nums[i], val+1, 0);
        }
        return ans;
    }
    
};
