/*
Platform :- Leetcode
Contest :- Leetcode Weekly contest 88
Approach :- You need to simplify the equation 
                        nums1[i] - nums1[j] <= nums2[i] - nums2[j] + diff 
                   ---> nums2[j] - nums1[j] <=  nums2[i] - nums1[i] + diff , 
                   ---> now for each 'i' we want to find the number of values (nums2[j] - nums1[j]) for each 'j' greater than 'i' are smaller than nums2[i] - nums1[i] + diff 
            So problem is reduced to find number of value smaller than or equal this to right .
*/
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>


// Structure which will store both
// array elements and queries.
struct node {
    int pos;
    int l;
    int r;
    int val;
};
 
// Boolean comparator that will be used
// for sorting the structural array.
bool comp(node a, node b)
{
    // If 2 values are equal the query will
    // occur first then array element
    if (a.val == b.val)
        return a.l > b.l;
 
    // Otherwise sorted in descending order.
    return a.val > b.val;
}
 
// Updates the node of BIT array by adding
// 1 to it and its ancestors.
void update(int* BIT, int n, int idx)
{
    while (idx <= n) {
        BIT[idx]++;
        idx += idx & (-idx);
    }
}
// Returns the count of numbers of elements
// present from starting till idx.
int query(int* BIT, int idx)
{
    int ans = 0;
    while (idx) {
        ans += BIT[idx];
 
        idx -= idx & (-idx);
    }
    return ans;
}
 
// Function to solve the queries offline
long long solveQuery(int arr[], int n, int QueryL[],
                int QueryR[], int QueryK[], int q)
{
    // create node to store the elements
    // and the queries
    node a[n + q + 1];
    // 1-based indexing.
 
    // traverse for all array numbers
    for (int i = 1; i <= n; ++i) {
        a[i].val = arr[i - 1];
        a[i].pos = 0;
        a[i].l = 0;
        a[i].r = i;
    }
 
    // iterate for all queries
    for (int i = n + 1; i <= n + q; ++i) {
        a[i].pos = i - n;
        a[i].val = QueryK[i - n - 1];
        a[i].l = QueryL[i - n - 1];
        a[i].r = QueryR[i - n - 1];
    }
 
    // In-built sort function used to
    // sort node array using comp function.
    sort(a + 1, a + n + q + 1, comp);
 
    // Binary Indexed tree with
    // initially 0 at all places.
    int BIT[n + 1];
 
    // initially 0
    memset(BIT, 0, sizeof(BIT));
 
    // For storing answers for each query( 1-based indexing ).
    int ans[q + 1];
 
    // traverse for numbers and query
    for (int i = 1; i <= n + q; ++i) {
        if (a[i].pos != 0) {
 
            // call function to returns answer for each query
            int cnt = query(BIT, a[i].r) - query(BIT, a[i].l - 1);
 
            // This will ensure that answer of each query
            // are stored in order it was initially asked.
            ans[a[i].pos] = cnt;
        }
        else {
            // a[i].r contains the position of the
            // element in the original array.
            update(BIT, n, a[i].r);
        }
    }
    
    long long val = 0;
    // Output the answer array
    for (int i = 1; i <= q; ++i) {
        long long z = ans[i];
        long long tot = (QueryR[i-1]-QueryL[i-1]+1)-z;
        val += tot;
    }
    return val;
}

class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        long long ans =0 ;
        ordered_set P;
        int n = nums1.size();
        int temp2[n];
        int Q1[n-1],Q2[n-1],Q3[n-1];
       vector<int>temp1;
        for(int i=0;i<n;++i){
            //temp1.push_back((nums2[i]-nums1[i]+diff));
            temp2[i] = ((nums2[i]-nums1[i]));
        }
        
        int q = sizeof(Q1) / sizeof(Q1[0]);
        
        for(int i=n-2;i>=0;--i){
            int val = nums2[i]-nums1[i] + diff;
            Q3[i] = val;
            Q1[i] = i+2;
            Q2[i] = n;
        }
        //for(auto&x:temp2)cout<<x<<" ";
        //cout<<"\n";
        
         
        return solveQuery(temp2, n, Q1, Q2, Q3, q);
         
        return ans;
    }
};
