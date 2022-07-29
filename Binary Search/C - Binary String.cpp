/*
Platform :- Codeforces
Contest :- Codeforces Educational Round 128
Appraoch :- We do binary search on no of zeros we will eliminate , we will have a 'V' shape curve , vlaues will decrease then increase after reaching some point , so we will 
            find two value/score , one is for the middile element and one to its neighbour and based on score we will decide which way to move . As we want to reach the local
            minima.
            We will use prefix and suffix array which will store no of '1' we have to remove till that '0' value index.
            This will help us in finding the score in O(mid) time ,
            So what we will do is first mid,mid-1,mid-2......1.0 , value from start and 0,1,....mid values from end in this combination we  wull remove zeros .
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        string s;
        cin>>s;
        
        int n = s.length();
        
        int c = count(s.begin(),s.end(),'0');
        if(c == n || c == 0){
            cout<<0<<"\n";
            continue;
        }
        
        vector<int>pref,suff;
        int d = 0;
        for(int i=0;i<n;++i){
            if(s[i] == '0')pref.push_back(d);
            else d++;
        }
        
        reverse(s.begin(),s.end());
         d = 0;
        for(int i=0;i<n;++i){
            if(s[i] == '0')suff.push_back(d);
            else d++;
        }
        
        int ans = c;
        int start = 0,end = c,mid = (start+end)/2;
        
        
        while(start<=end){
            
            //now what is I will be removing c '0' values from 
            //the string and find the score the min score oout of all is our solution
            int score = INT_MAX;
            for(int i=0;i<=mid;++i){
                //this means i value from right and k-i from left
                int val = 0;
                if(i){
                    val+=pref[i-1];
                    if(i<mid)val+=suff[mid-(i+1)];
                }
                else val+=suff[mid-1];
                score = min(score,val);
            }
        //    cout<<score<< "-- ";
            score = max(score,c-mid);
            
            //now which way to move we will check to one of its neighbour and based on that we will
            //decide which way to move 
            int score2 = 0;
            int l = 0;
            if(mid == c){
                score2 = INT_MAX;
                for(int i=0;i<=(mid-1);++i){
                //this means i value from right and k-i from left
                int val = 0;
                if(i){
                    val+=pref[i-1];
                    if(i<(mid-1))val+=suff[(mid-1)-(i+1)];
                }
                else val+=suff[(mid-1)-1];
                
                score2 = min(score2,val);
               }
               score2 = max(score2,c-(mid-1));
               
               if(score2<score){
                   //move to left
                   l = 1;
               }
            }
            else {
                score2 = INT_MAX;
                for(int i=0;i<=(mid+1);++i){
                   //this means i value from right and k-i from left
                   int val = 0;
                if(i){
                    val+=pref[i-1];
                    if(i<=mid)val+=suff[(mid+1)-(i+1)];
                }
                else val+=suff[(mid+1)-1];
                
                   score2 = min(score2,val);
                }
                score2 = max(score2,c-(mid+1));
                if(score2<score){
                    //then move to right
                }
                else l = 1;
            }
            ans = min(ans,score);
        //    cout<<start<<" "<<end<<" "<<mid<<" --> "<<score<<endl;
            if(l){
                end = mid-1;
                mid = (start+end)/2;
            }
            else{
                start = mid+1;
                mid = (start+end)/2;
            }
            
        }
        
        cout<<ans<<"\n";
    }
}
