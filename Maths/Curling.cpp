/*
Platform :- Coding Competitions with google
Approach :- You need to now how to check if a two cirlces overlap,touch or are dijoint .
            C1*C2 <= abs(R1-R2) --- this means we have two cirlces which have contact to each other 
            else others are disjoint.
            We checkf or all the red and yellow points and store the points touching in increasing order . We increase the count until we found any of different 
            color.
Time Complxity :- O((n+m)*log(m+n)
*/
#include<bits/stdc++.h>
using namespace std;

vector<double> find(int x1, int y1, int x2, int y2, int r1, int r2)
{
    double d = sqrt((x1 - x2) * (x1 - x2)
                         + (y1 - y2) * (y1 - y2));
 
    if (d <= r1 - r2) {
        return {1,d};
    }
    else if (d <= r2 - r1) {
        return {1,d};
    }
    else if (d < r1 + r2) {
        return {1,d};
    }
    else if (d == r1 + r2) {
        return {1,d};
    }
    else {
        return {0,d};
    }
}


int main(){
    int t;
    cin>>t;
    
    for(int z=1;z<=t;++z){
        cout<<"Case #"<<z<<": ";
        
        int Rb,Rh;
        cin>>Rb>>Rh;
        //distance from the point of center
        
        
        int n;
        cin>>n;
        
        vector<pair<double,double>>P;
        for(int i=0;i<n;++i){
            int x,y;
            cin>>x>>y;
            
            vector<double>temp = find(0,0,x,y,Rh,Rb);
            if(temp[0]){
                P.push_back({temp[1],1});
            }
        }
        
        int m;
        cin>>m;
        
        for(int i=0;i<m;++i){
            int x,y;
            cin>>x>>y;
            
            vector<double>temp = find(0,0,x,y,Rh,Rb);
            if(temp[0]){
                P.push_back({temp[1],2});
            }
        }
        
        sort(P.begin(),P.end());
        int f = 0;
        int red = 0,yellow = 0;
        int last = 0;
        for(auto&x:P){
            if(last == 0){
                if(x.second == 2)yellow++;
                else red++;
                last = x.second;
            }
            else{
                if(last != x.second){
                    break;
                }
                else{
                    if(x.second == 2)yellow++;
                    else red++;
                }
            }
        }
        
        cout<<red<<" "<<yellow<<"\n";
        
    }
}
