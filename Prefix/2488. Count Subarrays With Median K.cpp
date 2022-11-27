/*
Platform :- Leetcode
Contest :- Leetcode Weekly contest 321
Approach :- It is one of those repeated subarray problems which we have standard approach to solve them .
            -- We get all the value < k and replace with -1
            -- we get all the values >= k and replace with 1
            Now problem is narrowed down to find number of subarray with sum 1.
            Which we solve using map and prefix sum .
Time Comlexity :- O(n log n)
*/
class Solution {
public:
    int countSubarrays(vector<int>& a, int k) {
        using ll = long long;
        ll p = 0;
        
        ll n = a.size();
        
        for (ll i = 0; i < n; i++) if (a[i] == k) p = i;
        
        map<ll, ll> v;
        ll c = 0;
        for (ll i = p; i >= 0; i--) {
            if (a[i] < k) --c;
            else if (a[i] > k) ++c;
            
            ++v[c];
        }
        
        ll ans = 0;
        
        c = 0;
        for (ll i = p; i < n; i++) {
            if (a[i] < k) --c;
            else if (a[i] > k) ++c;
            
            ans += v[-c];
            ans += v[-c + 1];
            // cout << ans << '\n';
        }
        return ans;
    }
};
