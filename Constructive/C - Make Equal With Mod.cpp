/*
Platform :- Codeforces
Contest :- Codeforces CodeTon Round 1(Div 1+Div 2)
Approach :- So this problem is all about analysing it , 
            1.if we have the minimum element of array >1 then we can always have a solution , we will choose elements in decreasing
            order starting from the maximum value and all the way to minimum value and perform the operation.
            
            2. If we have all same element then also we have a valid solution
            3. If we have both 1 and 0 then we have no solution
            4. if we have min value as 0 and 1 is not present then we have solution ,it is same as case 1
            5. if we have min vaue as 1 then if we have two adjacent values in sorted array having absolute different == 1 , then also we don't have any solution
            
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
        map<long long,int>P;
        long long mn = 1e10;
        int c = 0;
        int o = 0,z = 0;
        for(int i=0;i<n;++i){
            cin>>A[i];
            if(A[i] == A[0])c++;
            mn = min(mn,A[i]);
            if(A[i] == 0)z++;
            if(A[i] == 1)o++;
           // P[A[i]]++;
        }
        int f = 0;
        if(z&&o){
            cout<<"NO\n";
            continue;
        }
     //   cout<<c<<" "<<mn<<"\n";
        if(c == n || mn>1 ){
            f=1;
        }else{
            if(mn == 1){
               
        
            sort(A,A+n);
            int g = 0;
            
            long long last = 1;
            for(int i=0;i<n;++i){
                if(A[i]==last)continue;
                else{
                   // cout<<A[i]<<" "<<last<<" \n";
                    if((A[i]-last) <= 1){
                        g=1;break;
                    }
                    last = A[i];
                }
            }
            if(g==0){
                f=1;
            }
            
            }
            else f=1;
        }
        
        if(f)cout<<"YES\n";
        else cout<<"NO\n";
    }
}
