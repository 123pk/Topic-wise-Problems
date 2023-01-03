/*
Platform :- Codeforces
Contest :- Hello 2023
Approach :- The approach is to store the indexes of each value of B in a vector and map with the value,now we start will bigger size razor,
            we can always cut a hair fro (l,r) to 'x' if the max value in range (l,r) inclusive is <= x
            now we start from last index value and then move to smaller and all the way to the first index ,
            we delete the value from index array and change the size in A to x if the max value in range is <='x'
            We use Segment tree to find the max in range and update the index remaining for each value.
            At the end we check if both array are equivalent.
            
            -- We cannot have solution in case where A[i]<B[i],we can't grow hair natural thing :)

Time Complexity :- O(n log n)
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void buildTree(int *tree,int *a,int index,int s,int e)
{
	//base case
	if(s>e)
		return;
	//reached leaf node
	if(s==e)
	{
		tree[index]=a[s];
		return ;
	}
	//now build the segment tree in bottom up manner
	int m = (s+e)/2;
	buildTree(tree,a,2*index,s,m);
	buildTree(tree,a,2*index+1,m+1,e);
	tree[index]= max(tree[2*index],tree[2*index+1]);
	return;
}

//function to query the segment tree for RMQ
int query(int *tree,int index,int s,int e,int qs,int qe)
{
	//base case: if query range is outside the node range
	if(qs>e || s>qe)
		return INT_MIN;
	//complete overlap
	if(s>=qs && e<=qe)
		return tree[index];
	//now partial overlap case is executed
	int m = (s+e)/2;
	int left_ans = query(tree,2*index,s,m,qs,qe);
	int right_ans = query(tree,2*index+1,m+1,e,qs,qe);
	return max(left_ans,right_ans);
}

//function to update a value at position to "pos"
void updateNode(int *tree,int index,int s,int e,int pos,int val)
{
	if(pos<s || pos>e)
		return ;
	if(s==e)
	{
		tree[index] = val;
		return ;
	}
	int m = (s+e)/2;
	updateNode(tree,2*index,s,m,pos,val);
	updateNode(tree,2*index+1,m+1,e,pos,val);
	tree[index] = max(tree[2*index],tree[2*index+1]);
	return;
}

//function to update the values in a range
void updateRange(int *tree,int index,int s,int e,int rs,int re,int inc)
{
	//query range outside the node range
	if(s>re || e<rs)
		return;
	if(s==e)
	{
		tree[index] += inc;
		return ;
	}
	int m = (s+e)/2;
	updateRange(tree,2*index,s,m,rs,re,inc);
	updateRange(tree,2*index+1,m+1,e,rs,re,inc);
	tree[index] = max(tree[2*index],tree[2*index+1]);
	return;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin>>t;
    
    while(t--){
      int n;
      cin>>n;
    //size of input array
    
     long long A[n];
     map<long long,vector<long long>>P;
     
     for(int i=0;i<n;++i){
         cin>>A[i];
         
     }
     
     int f = 0;
     long long B[n];
     for(int i=0;i<n;++i){
         cin>>B[i];
         P[B[i]].push_back(i);
         if(B[i]>A[i]){
             f=1;
         }
     }
     
     int m;
     cin>>m;
     
     long long C[m];
     for(int i=0;i<m;++i)cin>>C[i];
     
     if(f){
         cout<<"NO\n";
         continue;
     }
     
    
    int *tree = new int[4*n+1];                                    //array to store the segment tree
    int index = 1;													//index of 1st node
    int s =0,e=n-1;
    buildTree(tree,B,index,s,e);									//now tree has been built
    
    sort(C,C+m);
    reverse(C,C+m);
    
    vector<long long>temp;
    for(int i=0;i<m;++i){
        //I will find the index where I can cut them to size of C[i]
        temp = P[C[i]];
        
        int sz = temp.size();
        if(sz){
             int last = temp[sz-1];
            while(temp.size()){
                int cur = temp[temp.size()-1];
                int mx = query(tree,index,s,e,cur,last);
               // cout<<mx<<" "<<C[i]<<" "<<sz<<"\n";
                if(mx<=C[i]){
                    A[cur] = C[i];
                    temp.pop_back();
                }
                else break;
            }
            P[C[i]] = temp;
        }
        
        temp.clear();
    }
    
    for(int i=0;i<n;++i){
        if(A[i]!=B[i]){
            f=1;
            break;
        }
    } 
    if(f)cout<<"NO\n";
    else cout<<"YES\n";
    
    
    
    }
    return 0;
}
