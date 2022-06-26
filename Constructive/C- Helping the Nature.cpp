/*
Platform :- Codeforces
Contest :- Codeforces Round 802 Div 2
Approach :- Main motive is to make all elements till n-1 equal and last element may or maynot be equal , we can always do operatiions accordinbly , if last value>cur_value
            then we decrease the last value with cost of (last_value - cur_value) , else we change cur_value to last_value and all the values to right are also change 
            (cur_value - last_value),we maintain a varible which store how much we need to change current value from previous operations 
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
        
        long long cost = 0,left = 0,right = 0;
        long long last = 0;
        //we store the last value in last variable
        //algorithm is to traverse through the array and check if current value is greater than 
        //the last value then change the element to last element in CURR_VAL - last ,  and add that to right 
        //as all the values to right will be decreased by that change value
        
        for(int i=0;i<n;++i){
            if(i == 0){
                last = A[i];
                
            }
            else{
                A[i] += right;
                if(A[i] == last)continue;
                if(A[i]<last){
                    //change last to A[i]
                    cost += (last - A[i]);
                    last = A[i];
                }
                else{
                    //change current value to last
                    right -= (A[i] - last);
                    cost += (A[i] - last);
                    A[i] = last;
                }
            }
        }
        
        cost+=abs(A[n-1]);
        if(last!=A[n-1])cost+=abs(last + abs(A[n-1]));
        
        cout<<cost<<"\n";
    }
}
