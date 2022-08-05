/*
Platform :- Codeforces
Contest :- Codeforces Educatinal Round 133
Approach :- We have two options only either to go right or down . We will follow this pattern DRURDRUR...
            and at each point we have option to go straing to the end and then go up and get back stragint and we do the same we precompute the cost of 
            path1 , going from 0,0 --> 0,1-->...0,n-1 then to 1,n-1 --> 1,n-2 -- ... 1,0 , this is our path 1 we find the time to reach the node and waiting time 
            to reach till that node .
            
            Similarly path2 is reverse of this and we do the same .
            While folowing the starting pattern of (DRURDR..) at any point of time we will find the cost to reach using the path1 or 2 and the min cost out of all such option
            is our solutin.
*/
#include<bits/stdc++.h>
using namespace std;

void find(vector<vector<long long>>&A,vector<vector<pair<long long,long long>>>&P,int n,int f){
    if(f == 0){
        //start = 12
        P[0][0] = {0,0};
        long long cost = 0,wt =0;
        for(int i=1;i<n;++i){
            if(cost<A[0][i]){
                wt += (A[0][i]-cost);
                cost = A[0][i]+1;
            }
            else cost++;
            P[0][i].first = cost;
            P[0][i].second = wt;
        }
        
        for(int i=n-1;i>=0;--i){
            if(cost<A[1][i]){
                wt += (A[1][i]-cost);
                cost = A[1][i]+1;
            }
            else cost++;
            P[1][i].first = cost;
            P[1][i].second = wt;
        }
        
    }
    else{
        //start = 21
        P[0][0] = {0,0};
        long long cost = 0,wt =0;
        for(int i=0;i<n;++i){
            if(cost<A[1][i]){
                wt += (A[1][i]-cost);
                cost = A[1][i]+1;
            }
            else cost++;
            P[1][i].first = cost;
            P[1][i].second = wt;
        }
        
        for(int i=n-1;i>0;--i){
            if(cost<A[0][i]){
                wt += (A[0][i]-cost);
                cost = A[0][i]+1;
            }
            else cost++;
            P[0][i].first = cost;
            P[0][i].second = wt;
        }
    }
}

int main(){
    int test;
    cin>>test;
    
    while(test--){
        int n;
        cin>>n;
        
        vector<vector<long long>>A(2,vector<long long>(n));
        for(int i=0;i<2;++i){
            for(int j=0;j<n;++j){
                cin>>A[i][j];
            }
        }
        
        //now what we will find the movement cost
        vector<vector<pair<long long,long long>>>P1(2,vector<pair<long long,long long>>(n));
        vector<vector<pair<long long,long long>>>P2 = P1;
        
        find(A,P1,n,0);
        find(A,P2,n,1);
        
       /*for(int i=0;i<2;++i){
            for(int j=0;j<n;++j){
                cout<<P1[i][j].first<<","<<P1[i][j].second<<" -- ";
            }
            cout<<"\n";
        }
        cout<<"\n";
        for(int i=0;i<2;++i){
            for(int j=0;j<n;++j){
                cout<<P2[i][j].first<<","<<P2[i][j].second<<" -- ";
            }
            cout<<"\n";
        }
        cout<<"\n";
        */
        
        //now we move zig zag
        long long ans = min(P1[1][0].first,P2[0][1].first);
        //cout<<ans<<" ";
        long long cost = 0,wt = 0;
        int i=1,j=0;
        while(i<2 && j<n){
           // cout<<(i+1)<<" "<<(j+1)<<"\n";
            if(i%2){
                if(j%2){
                    //then I can move up only
                    if(cost<A[i][j]){
                        cost = A[i][j]+1;
                    }
                    else cost++;
                    
                    //this is wher I am moving up
                    i--;
                }
                else{
                    //we can use pref2 or P2
                    if(cost<A[i][j]){
                        cost = A[i][j]+1;
                    }
                    else cost++;
                    
                    if((j+1)<n){
                        long long ex = cost - (P2[i][j].first);
                        pair<long long,long long>temp = P2[i-1][j+1];
                        
                        long long tcost = temp.first;
                        long long twt = temp.second-P2[i][j].second;
                       //  cout<<cost<<" "<<ex<<" "<<tcost<<" "<<twt<<" down \n";
                        if(ex>twt){
                            ans = min(ans,tcost + (ex-twt));
                        }
                        else{
                            ans = min(ans,tcost);
                        }
                    
                    }
                    j++;
                }
            }
            else{
                if(j%2 == 0){
                    //move down
                    if(cost<A[i][j]){
                        cost = A[i][j]+1;
                    }
                    else cost++;
                    i++;
                }
                else{
                    //now use P1
                    if(cost<A[i][j]){
                        cost = A[i][j]+1;
                    }
                    else cost++;
                    
                    
                    if((j+1)<n){
                        long long ex = cost - (P1[i][j].first);
                        pair<long long,long long>temp = P1[i+1][j+1];
                        
                        long long tcost = temp.first;
                        long long twt = temp.second - P1[i][j].second;
                        //cout<<cost<<" "<<ex<<" "<<tcost<<" "<<twt<<" up \n";
                        if(ex>twt){
                            ans = min(ans,tcost + (ex-twt));
                        }
                        else{
                            ans = min(ans,tcost);
                        }
                    }
                    
                    //we move ritht
                    j++;
                }
            }
            //cout<<ans<<" "<<(i+1)<<" "<<j+1<<"\n";
        }
        
        
        cout<<ans<<"\n";
        
    }
}
