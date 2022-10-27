/*
Platform :- Codechef
Contest :- Codechef starters 62
Approach :- Since the biggest odd factor of N is 10^5 , we can exploit this ,
           first of all you need to know X^2 * (A^2 + B^2) =  (XA^2 + XB^2) ,
           -- A number can be expressed as sum of square of two odd numbers if all the factors of form 4*k+3 occur even numbe rof time
           
           so A number N can be written as Y*Z where Y is product of combination of elements occuring even number of times . X*X*Y*Y... as this can be written into (X*Y)^2
           So at the end there will be the element Z which contins odd occurence of element with just one occurence we need to check if this number is perfect square or not
           if this number of perfect sqare then yes we can find a pair A,B and multiply them with the X*Y
Time Comlexity :- O(sqrt(2*10^5)
*/
#include<bits/stdc++.h>
using namespace std;
 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        
        long long n;
        cin>>n;
        
        long long val = 1;
        long long lim = 1e5;
         
        
        int d = 0;
        long long z = n;
        while(z%2ll == 0){
            z/=2;
            d++;
        }
        val = z;
        if(d%2)val*=2ll;
        long long mul = d/2;
        mul = (1ll<<mul);
        int f = 0;
        long long left=0,right = 0;
        for(long long i=0;i*i<=(val);++i){
            long long ex = i;
            ex*=ex;
            
            long long rem = (val - ex);
            long long sq = sqrtl(rem);
            long long sz = sq*sq;
            
            if(sz == rem){
                f=1;
                left = i;
                right = sq;
                break;
            }
        }
        
        left*=mul;
        right*=mul;
        
        if(f == 0)cout<<"-1\n";
        else cout<<left<<" "<<right<<"\n";
    }
	return 0;
}
