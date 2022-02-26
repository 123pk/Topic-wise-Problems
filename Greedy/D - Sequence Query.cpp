/*
Platform :- Atcoder
Contest :- Atcoder Beginner Contest 241
Approach :- We want to do query optimally , that is to store the elements in sorted order and do query on them efficiently , I am using set to store the elements and jump to 
            nearest value of 'x' using lowerbound and we will also maintain frequency array , I will now move to left and right accordinly of query and if the frequecy of elements
            are >= y then that is required value else print -1;
*/
#include<bits/stdc++.h>
using namespace std;


// the basic operation that is required in this is to optimally find the kth value smaller than
//the required 'x' or the value greater than it 
// SO I am thinking of using a set 

int main(){
    int query;
    cin>>query;
    
    int type;
    long long x;
    int y;
    set<long long>val;
    map<long long,int>count;
    int req = 0;
    
    for(int i=0;i<query;++i){
        int type;
        cin>>type;
        
        if(type == 1){
            cin>>x;
            val.insert(x);
            count[x]++;
        }
        else if(type == 2){
            cin>>x>>y;
            
            if(val.size()==0){
                cout<<"-1\n";
                continue;
            }
            
            auto it = val.lower_bound(x);
            if(it == val.end()){
                it--;
            }
             
            if(*it>x){
                it--;
                 
            }
             
            req = 0;
            for(; ;--it){
                //check if the value we have satisfy the condition or not
                 if(*it<=x)req+=count[*it];
                if(req>=y)break;
                if(it==val.begin()){
                    break;
                }
            }
            
            if(req>=y)cout<<*it<<"\n";
            else cout<<"-1\n";
        }
        else{
            cin>>x>>y;
            
            if(val.size()==0){
                cout<<"-1\n";
                continue;
            }
            auto it = val.lower_bound(x);
            if(it == val.end()){
                cout<<"-1\n";
            }
            else{
                req = 0;
                for(;it!=val.end();++it){
                    req+=count[*it];
                    if(req>=y){
                        break;
                    }
                }
                
                if(req>=y)cout<<*it<<"\n";
                else cout<<"-1\n";
            }
        }
    }
    
}
