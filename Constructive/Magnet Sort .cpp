/*
Platform :- Codechef
Contest :- Codechef Lunchtime February 2022
Approach :- If you will carefully analyse the problem , you will find that value of answer one of {0,1,2} for possible cases else -1.
           ---> if array is sorted then answer is '0'
           --> when we have only one type of character in string either 'N' or 'S' then we have no solution if array is not sorted so '-1'
           --> we need atmax '2' moves to sort the array
               we find the first and last index of unsorted elment , if they are between a subarray with different polarities in end then aswer is '1'
               else '2'
*/
#include<bits/stdc++.h>
using namespace std;

bool comp(pair<long long,int>&P,pair<long long,int>&Q){
    if(P.first==Q.first){
        return P.second<Q.second;
    }
    return P.first<Q.first;
    
}

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        
        vector<long long>A(n),Q(n);
        for(int i=0;i<n;++i){
            cin>>A[i];
            Q[i] = A[i];
        }
        
        string s;
        cin>>s;
        
     
        
        sort(Q.begin(),Q.end());
        int f = 0;
        for(int i=1;i<n;++i){
            if(A[i] <A[i-1]){
                f=1;break;
            }
        }
        
        if(f==0){
            cout<<"0\n";
            continue;
        }
        int c = count(s.begin(),s.end(),'N');
        if(c == n || c==0){
            cout<<"-1\n";
            continue;
        }
        
        
        
        //now we will find the first and last index of mismatch
        int dif_start = -1,dif_end = -1;
        int start_N = -1 ,end_N = -1, start_S = -1 , end_S = -1;
        
        for(int i=0;i<n;++i){
            if(s[i]=='N'){
                if(start_N == -1)start_N = i;
                end_N = i;
            }
            else{
                if(start_S == -1)start_S = i;
                end_S = i;
            }
            
            if(A[i] != Q[i]){
                if(dif_start == -1)dif_start = i;
                dif_end = i;
            }
        }
        //cout<<dif_start+1<<" "<<dif_end+1<<"\n";
        
        //so we have first and last of index of mismatched index
        //first and last index of both 'N' and 'S'
        
        if(s[dif_start] == 'N'){
            //I want to know the last index of 'S'
            if(dif_end <= end_S){
                // we will choose subarray from dif_start to end_S and sort them
                cout<<1<<"\n";
            }
            else{
                //Now we will check in reverse
                if(s[dif_end] == 'N'){
                    if(start_S <= dif_start){
                        cout<<1<<"\n";
                    }
                    else{
                        cout<<2<<"\n";
                    }
                }
                else{
                    if(start_N <= dif_start){
                        cout<<1<<"\n";
                    }
                    else{
                        cout<<2<<"\n";
                    }
                }
            }
        }
        else{//cout<<"*";
            if(dif_end <= end_N){
                // we will choose subarray from dif_start to end_S and sort them
                cout<<1<<"\n";
            }
            else{
                //Now we will check in reverse
                if(s[dif_end] == 'S'){
                    
                    if(start_N <= dif_start){
                        cout<<1<<"\n";
                    }
                    else{
                        cout<<2<<"\n";
                    }
                }
                else{
                    if(start_S <= dif_start){
                        cout<<1<<"\n";
                    }
                    else{
                        cout<<2<<"\n";
                    }
                }
            }
        }
         
    }
}
