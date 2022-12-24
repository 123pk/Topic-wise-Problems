/*
Platform :- Leetcode
Contest :- Leetcode Bi Weekly contest 94
Approach :- If you will observe we need to find product of no of distinct permutation of each string .
            We need to take care of modulo;
            We will use Little fermant theorem to find no of distict permutation
More help :- https://stackoverflow.com/questions/32713762/distinct-permutations-of-a-string-modulo-a-prime
Time Complexity :- O(n*m*log(m!%mod))
*/

#define ll long long 
long long mod =1e9+7;

 
 
// Returns count of distinct permutations
// of str.
int calc(string str,vector<long long>&factorial)
{
    int length = str.length();
 
    int freq[26];
    memset(freq, 0, sizeof(freq));
 
    // finding frequency of all the lower case
    // alphabet and storing them in array of
    // integer
    for (int i = 0; i < length; i++)
        if (str[i] >= 'a')
            freq[str[i] - 'a']++;
 
    // finding factorial of number of appearances
    // and multiplying them since they are
    // repeating alphabets
    long long fact = 1;
    for (int i = 0; i < 26; i++){
        fact = fact * factorial[freq[i]];
        fact %= mod;
    }
        
 
    // finding factorial of size of string and
    // dividing it by factorial found after
    // multiplying
    long long val = factorial[length];
    //if(fact == 0)return 1;
    return val / fact;
}

 
  
 ll power(ll x, ll y, ll p)
{
    ll res = 1; // Initialize result
 
    // Update x if it is more than or
    // equal to p
    x = x % p;
 
    while (y > 0) {
       
        // If y is odd, multiply x
        // with the result
        if (y & 1)
            res = (res * x) % p;
 
        // y must be even now
        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}

class Solution {
public:
    vector<string> get(string s){
        string temp = "";
        vector<string>P;
        for(auto&x:s){
            if(x == ' '){
                P.push_back(temp);
                temp = "";
            }
            else temp += x;
        }
        return P;
    }
    int countAnagrams(string s) {
        long long ans = 1;
        
        long long val =1;
        int n = s.size();
        
        vector<long long>fact(n+1);
        fact[0] = 1;
        for(int i=1;i<=n;++i){
            long long z = i;
            val*=z;
            val%=mod;
            fact[i] = val;
        }
        
        s+=' ';
        vector<string>P = get(s);
        
        for(auto&x:P){
            //get the fre of character
            vector<int>fre(26);
            for(auto&y:x){
                fre[y-'a']++;
            }
           int sz = x.size(); 
            long long div = 1;
            long long mul = fact[sz];
            
            for(int i=0;i<26;++i){
                if(fre[i]>1){
                    long long cur = fact[fre[i]];
                    cur = power(cur,mod-2,mod);
                    mul*=cur;
                    mul%=mod;
                    
                }
            } 
           
            ans*=mul;
            ans%=mod;
        }
        
        return ans;
    }
};
