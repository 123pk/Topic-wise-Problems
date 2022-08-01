/*
Platform :- Codeforces
Contest :- Codeforces Round 811 Div 3
Approach :- You need to carefully observe few things , for all values except (5 and 0) , we can always hit the repeating values at the one's position .
            if we perform the repetitve operation given in problem we will get following sequence for remainder value (1 to 9) excluding (5 and 0)
            1 --> 2 --> 4 --> 8 --> 6 --> 2 --> 4 -->8  ..so 
            2 --> 4 ---> 8 -->6 --->2 ...
            yeah so repetaing value is (2 - 4 - 8 - 6 ) the sum of them is 20.
            So basic idea is to cahnge the values of array such that we get the remainder with 10 one of the above vlaue . Now we can only convert one to another if 
            the differnece between them is multiple of 20 else we cannot .If for any of the remainder value (2,4,6,8} we get the condition satisfied we can make them eual
            
            For 5 --> 0
            for 0.
            So we will do check them separately 
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        
        long long A[n];
        for(int i=0;i<n;++i){
            cin>>A[i];
        }
        sort(A,A+n);
        
        if((A[0] == A[n-1]) || (n ==1))cout<<"Yes\n";
        else{
            int d = 0;
            for(auto&x:A){
                if(x%10 == 0){
                    d++;
                }
                if(x%10 == 5){
                    d++;
                }
            }
            if(d>0 && d<n){
                cout<<"No\n";
                continue;
            }
            
            if(d == n){
                //we will convert each value to 10
                for(auto&x:A){
                    if(x%10 == 5)x+=5;
                }
                
                sort(A,A+n);
                if(A[0] == A[n-1]){
                    cout<<"Yes\n";
                }
                else cout<<"No\n";
                continue;
            }
            
            int f = 0;
            vector<long long>temp;
            for(int k=2;k<=8;k+=2){
                //we will convert each elemetn to have the last digit as 2
                temp.clear();
                for(auto&x:A)temp.push_back(x);
                
                for(int i=0;i<n;++i){
                     //we will conert last digit to 2
                    // the k
                    while(1){
                        long long rem = temp[i]%10ll;
                        if(rem == k)break;
                        temp[i]+=rem;
                    }
                }
                int h = 0;
                
                for(int i=1;i<n;++i){
                    long long dif = abs(temp[i]-temp[i-1]);
                    if(dif%20){
                        h = 1;
                        break;
                    }
                }
                if(h == 0){
                    f=1;
                    break;
                }
            }
            
            if(f)cout<<"Yes\n";
            else cout<<"No\n";
        }
        
    }
}
