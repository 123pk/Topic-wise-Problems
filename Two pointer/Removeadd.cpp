/*
Platform :- Codechef
Contest :- Codechef starters 41
Approach :- We will find the longest subarray with distinct elements , now the count of elemnet to left be 'x' and elements to the right 'y' , so we will remove min(x,y)
            elements and the we will add that element to the side with max(x,y) and then we will remove the (x+y)values and append distinct values,
            Take care of longest prefix and suffix and find the min cost out of them also . The min of all three is our answer.
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
        map<long long,int>count,count1,count2;
        for(int i=0;i<n;++i){
            cin>>A[i];
        }
        
        //we store the last index of current value
        int ans = 0;
        int start = 1,end = 0,val = 0,x = 0,y= 0;
        for(int i=0;i<n;++i){
            end = i+1;
            if(count[A[i]] == 0){
                
                if(val<((end-start)+1)){
                    val = (end-start)+1;
                    x = start;
                    y = end;
                }
                count[A[i]] = i+1;
            }
            else{
                //we move the start pointer to the previous value and update it
                start = max(start,count[A[i]]+1);
                
                if(val<((end-start)+1)){
                    val = (end-start)+1;
                    x = start;
                    y = end;
                }
                count[A[i]] = i+1;
            }
           // cout<<start<<" "<<end<<"\n";
        }
        
        
        //min no of values to remove from start to end
        int lef = x - 1;
        int right = n - y;
       // cout<<lef<<" "<<right<<" ";
        ans = min(lef,right) + (lef+right);
        
        
        //some left prefix 
        start = 1,end = 0,x= 0,y = 0,val = 0;
        for(int i=0;i<n;++i){
            end = i+1;
            if(count1[A[i]] == 0){
                count1[A[i]]++;
            }
            else{
                break;
            }
        }
        ans = min(ans,(n-end)+1);
     //   cout<<end<<" ";
        
        //some right suffix
        reverse(A,A+n);
        start = 1,end = 0,x= 0,y = 0,val = 0;
        for(int i=0;i<n;++i){
            end = i+1;
            if(count2[A[i]] == 0){
                count2[A[i]]++;
            }
            else{
                break;
            }
        }
      //  cout<<end<<" ";
        ans = min(ans,(n-end)+1);
        
        cout<<ans<<"\n";
        
    }
}
