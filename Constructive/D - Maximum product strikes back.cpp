/*
Platform :- Codeforces
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        
        int A[n];
        int c = 0;
        vector<map<int,int>>fre;
        map<int,int>P;
        int odd_count[n]={0};
        vector<int>zeros;
        zeros.push_back(-1);
        
        for(int i=0;i<n;++i){
            cin>>A[i];
            if(abs(A[i])>1){
                P[A[i]]++;
            }
            if(A[i] == 0)zeros.push_back(i);
            
            fre.push_back(P);
            if(A[i]<0)c++;
            odd_count[i] = c;
        }
        zeros.push_back(n);
        
        /*
        Approach is to traverse betweenn zeros and find the best I can get 
        If we have odd no of -ve values between two zeros then we first choose 1 to x-1 
        where x is index of last -ve value , or y+1 to z where y- index of first -ve value
        */
        
        int ans = 0,start = 0,end = 0;
        for(int i = 1;i<zeros.size(); ++i){
            //if we have odd count of -ve values 
            //else we select every onve
            int nod = 0;
            if(i == 1){
                nod = odd_count[zeros[i]];
            }
            else{
                nod = odd_count[zeros[i]] - odd_count[zeros[i-1]];
            }
            
            //nod is no of odd values
            if(nod%2){
                //here we left our the first valeu or the last value
                
            }
            else{
                if(i == 1){
                    if(ans<fre[zeros[i]]){
                        ans = fre[zeros[i]][2] + fre[zeros[i]][-2];
                        start = 0;
                        end = (n-zeros[i]);
                    }
                }
                else{
                    int val = fre[zeros[i]][2]+fre[zeros[i]][-2] - (fre[zeros[i-1]][2]+fre[zeros[i-1]][-2]);
                    if(ans<val){
                        ans = val;
                        start = zeros[i-1]+1;
                        end = (n-zeros[i]);
                    }
                }
            }
        }
        
        cout<<start<<" "<<endl;
    }
}
