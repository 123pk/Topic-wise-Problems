/*
Platform :- Coding Competition with google
Contest :- Google Kickstart Round C
Approach :- So for test case one , we will try out all the possible options we have and look for palindromic substring after each operation .
            Let 'd' be count of points we have and 'x' be total substrings then we will need to find (d/x)%mod .
            --> You need to know modular arithmetic for this 
                 (a/b) % mod = a* ( b^(mod-2)) % mod)  , where mod is prime

Time Complexity :- O(n!)
*/
#include<bits/stdc++.h>
using namespace std;

bool ispali(string& s){
    int n = s.size();
    for(int i=0;i<(n/2);++i){
        if(s[i]!=s[n-1-i])return false;
    }
    return true;
}
int power(int x, int y, int p)
{
    int res = 1; // Initialize result
 
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

int main(){
    int t;
    cin>>t;
    
    for(int z = 1;z<=t;++z){
        cout<<"Case #"<<z<<": ";
        int n;
        cin>>n;
        
        string s;
        cin>>s;
        
        string temp = "",x = "";
        queue<pair<string,int>>bfs;
        //vector<string>z;
        bfs.push({s,0});
        int val = 0;
        long long ans = 0;
        int d = 0;
        while(!bfs.empty()){
            int c = bfs.size();
            for(int i=0;i<c;++i){
                pair<string,int>f = bfs.front();
                temp = f.first;
                val = f.second;
                bfs.pop();
                //z.clear();
             //   cout<<temp<<" ";
                //choose every index and what will happen if we remove it 
                for(int j = 0;j<temp.size();++j){
                    x = "";
                    for(int k = 0;k<temp.size();++k){
                        if(j == k)continue;
                        x = x+temp[k];
                    }
                    if(ispali(x))bfs.push({x,val+1});
                    else bfs.push({x,val});
                }
                if(temp.size() == 0){
                    ans+=val;
                    d++;
                    
                }
            }
          //  cout<<"\n";
        }
        //cout<<ans<<" ";
        int mod = 1e9+7;
        long long value = ans%mod;
        long long temp1 = power(d,mod-2,mod);
       // cout<<temp1<<" ";
        value*=temp1;
        value%=mod;
        cout<<value<<"\n";
    }
}
