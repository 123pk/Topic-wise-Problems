/*
Platform :- Codeforces
Contest :- Educational Round 132
Approach :- We will try to find max value in range of (y1,y2) columns  using segment tree in log(n) per query . Then we will check few things the abs(x2-x1) and abs(y2-y1)
            both this should be divisible by 'k' else we cannot reach there , then we will check if we can go above the max value or not ,basically a distance 'x' which is
            multiple of 'k' distance from 'x1' and 'x'> max value .
*/
#include<bits/stdc++.h>
using namespace std;

//#define int long long

//filling my segment tree
void make_Seg_tree(vector<pair<int,pair<int,int>>>& A,int idx){
    
    for(int i=idx;i>=0;--i){
        A[i].first = max(A[(2*i)+1].first , A[(2*i)+2].first);
        A[i].second = {(min(A[(2*i)+2].second.first,A[(2*i)+1].second.first)),max(A[(2*i)+1].second.second,(A[(2*i)+2].second.second))};
    }
}

//answering queries of my segment tree
int query(vector< pair< int, pair<int,int>> >& A ,int lo_lim ,int up_lim,int idx){
   
    //in case range of node and target range are disjoint
    if( A[idx].second.first > up_lim || A[idx].second.second < lo_lim){
       // cout<< idx+1<<" && "<<A[idx].second.first<<" "<<up_lim<<" "<<A[idx].second.second<<" "<<lo_lim<<"\n" ;
        return 0;
    }
    
    // if completely overlap
    if(A[idx].second.first>= lo_lim && A[idx].second.second <= up_lim){
        return A[idx].first;
    }
    
    //else we have partial overlapping range
    int val = max(query(A,lo_lim,up_lim,2*idx+1) , query(A,lo_lim,up_lim,2*idx+2));
    return val;
}


//doing updates in  my segment tree
void update(vector<pair<int,pair<int,int>>>& A, int idx ,int val){
    A[idx].first = val;
    idx=(idx-1)/2;
    while(1){
     //   cout<<idx<<" "<<(idx*2+1)<<" "<<(idx*2)<<endl;
        A[idx].first = max(A[idx*2 + 1].first , A[idx*2+2].first);
        if(idx==0)break;
        idx=(idx-1)/2;
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    
    
    int d=0;
     string temp=bitset<32>(m).to_string();
     reverse(temp.begin(),temp.end());
     int c=0;
     
     for(int i=0;i<32;++i){
         if(temp[i]=='1'){
             c++;
             d=i;
         }
     }
   //  cout<<d<<" ---> ";
     if(c>1)d++;
     d=pow(2,d);
     int x=d-m;
     d<<=1;
     d-=1;
    // cout<<d<<" -- "<<m<<"-- "<<(d-x)<<"\n";
     //this is our seg tree  leaf nodes
     vector<pair<int,pair<int,int>>> seg_tree(d);
     for(int j=(d-x)-m;j<(d-x);++j){
          cin>>seg_tree[j].first;
     }
   
     for(int i=(d-x)-m;i<d;++i){
         seg_tree[i].second={i,i};
     }
     
     // making my segment tree
     make_Seg_tree(seg_tree,(d-x)-m-1);
     int start = (d-x)-m;
    
     
    int q;
    cin>>q;
    
    for(int i=0;i<q;++i){
        int x1,y1,x2,y2,k;
        cin>>x1>>y1>>x2>>y2>>k;
        
        if(y2<y1){
            swap(x2,x1);
            swap(y1,y2);
        }
        
        //so what options do we have 
        int difx = abs(x2 - x1);
        int dify = abs(y2 - y1);
        if(difx%k || dify%k)cout<<"NO\n";
        else {
            
            if(y1 == y2){
                cout<<"YES\n";
                continue;
            }
            
            int l = (y1-1)+start;
           int r = (y2-1)+start;
           
           int x = query(seg_tree,l,r,0);
          // cout<<l+1<<" "<<r+1<<" "<<x<<"\n";
           if(x1<= x){
               //this means I canot move straight
                int dif = (x-x1);
                int val = dif/k;
                val++;
                
                val*=k;
                val+=x1;
                
                
              //  cout<<val<<" ";
               if((val)>n)cout<<"NO\n";
               else cout<<"YES\n";
           }
           else cout<<"YES\n";
        }
    }
}
