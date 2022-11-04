#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        long long A[n];
        long long mn = 1e18;
        for(int i=0;i<n;++i){
            cin>>A[i];
            mn = min(mn,A[i]);
        }
        //remvoe the samller -1 from everywhere
        for(int i=0;i<n;++i){
            A[i]-=(mn-1);
        }
        priority_queue<long long>P;
        long long unused;
        for(int i=1;i<n;++i)P.push(-A[i]);
        unused = A[0]-1;
        
        int f = 0;
        
        
        while(!P.empty()){
            //we will start with bob turn
            long long temp = P.top();
            P.pop();
            temp = abs(temp);
            
            if(temp == 0){
                break;
            }
            else{
                //this is O(1), we will fall into TLE / infinte
                P.push(-unused);
                unused = temp-1;
            }
            
            f++;
        }
        if(f%2)cout<<"Bob\n";
        else cout<<"Alice\n";
        
    }
}
