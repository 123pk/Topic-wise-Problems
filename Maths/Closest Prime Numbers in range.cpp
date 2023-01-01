/*
Platform :- Leetcode
Contest :- Leetcode Weekly contest 326
Approach :- We will find the prime factors till 'right' using seive,now we will traverse through the array storing the prime and find the prime with smallest difference 
           between them and add to the answer.
Time Comlexity :- O(n)
Space Complexity :- O(n)
*/
vector<int> find(int n,int left)
{
    // Create a boolean array "prime[0..n]" and initialize
    // all entries it as true. A value in prime[i] will
    // finally be false if i is Not a prime, else true.
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));
 
    for (int p = 2; p * p <= n; p++) {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true) {
            // Update all multiples of p greater than or
            // equal to the square of it numbers which are
            // multiple of p and are less than p^2 are
            // already been marked.
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    
    vector<int>ans = {-1,-1};
    // Print all prime numbers
    int last = -1;
    int cur_dif = -1;
    for (int p = max(2,left); p <= n; p++)
        if (prime[p]){
            if(last == -1){
                last = p;
            }
            else{
               // cout<<p<<" "<<last<<" \n";
                int score = p-last;
                if(cur_dif == -1){
                    cur_dif = score;
                    ans = {last,p};
                }
                else{
                    if(cur_dif>score){
                        cur_dif = score;
                        ans = {last,p};
                    }
                }
            }
            last = p;
        }
    return ans;
}

class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        return find(right,left);
    }
};
