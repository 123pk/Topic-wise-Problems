/*
Platform :- Codechef
Contest :- Codeforces Starters 26 
Approach :- First sort the characters of both the Alice and Bob string and now greedily choose on their turn and add desired character to the solution at desired position
          * Alice want the resultant string to be Lexiographically smaller so he will choose the smallest characters to be positoned in the smallest index possible
          * Bob want the resultant string to  be Lexiographically larger so he will choose the bigger character to be positioned in the largest index possible
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        
        string alice,bob;
        cin>>alice>>bob;
        
        string ans =alice;
        ans+=bob;
        
        sort(alice.begin(),alice.end());
        sort(bob.begin(),bob.end());
        reverse(bob.begin(),bob.end());
        
        
        int alice_start = 0,alice_end = n-1,bob_start = 0,bob_end = n-1;
        int l = 0,r = (2*n)-1;
        int c = 0;
        
        while((alice_start<=alice_end)||(bob_start<=bob_end)){
          
            //Bob turn
            if(c%2){
                //BOB will try to increase the lexiographical order
                //if Bob_start < Alice_start
                if(bob[bob_start]<=alice[alice_start]){
                    ans[r] = bob[bob_end];
                    bob_end--;
                    r--;
                }
                else{
                    ans[l] = bob[bob_start];
                    bob_start++;
                    l++;
                }
                
                
            }else{
                //Alice turn
                //Alice will try to add small value at the smallest index possible 
                //if the smallest value of alice is >the bob max valued character 
                if(alice[alice_start]>=bob[bob_start]){
                    ans[r] = alice[alice_end];
                    alice_end--;
                    r--;
                }else{
                    ans[l] = alice[alice_start];
                    alice_start++;
                    l++;
                }
                
            }
            
            c++;
        }
        cout<<ans<<"\n";
        
    }
}
