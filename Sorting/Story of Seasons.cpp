/*
Platform :- Coding Competitions with google
Contest :- Google Kickstart Round F
Approach :- We sort values by increasinng order of their "days_of_maturity" , now for each different day we add the crop "profit_value,no_of_seeds" in priority_queue
            and choose the 'x' out of them.
Time Complexity :- O(D*log(D)) - -- D is max allowed days
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    
    for(int z=1;z<=t;++z){
        cout<<"Case #"<<z<<": ";
        long long tot_days,lim;
        int n;
        cin>>tot_days>>n>>lim;
        
        //this stores the seed on each day with profit and amount of them
        map<long long,vector<pair<long long,long long>>>seed_day;
        set<long long>diff_days;
        vector<vector<long long>>P(n,vector<long long>(3));
        
        for(int i=0;i<n;++i){
            //long long quantity,mature_time,profit;
            cin>>P[i][0]>>P[i][1]>>P[i][2];
            diff_days.insert(P[i][1]);
            seed_day[P[i][1]].push_back({P[i][2],P[i][0]});
        }
        
        /*
        Approach is to start from seed with smallest no of days require and if there are multiple of them then choose the one with 
        maximum profit
        */
        
        pair<long long,long long>temp;
       // cout<<"\n";
        //profit and no of units of that seed
        priority_queue<pair<long long,long long>>order;
        long long ans = 0;
        auto it = diff_days.begin();
        long long start = *it;
        start--;
        while(1){
            start++;
            long long x = start;
            if((tot_days - x) <= 0)break;
            
         //   cout<<x<<" \n";
            if(diff_days.find(x) != diff_days.end()){
            //get all the values at that day
            for(auto&y:seed_day[x]){
                order.push(y);
            }
            
            }
            //now get the top x seeds with max profit
            long long seed = 0 , req , sum = 0;
            long long val,no;
            while(seed<lim && !order.empty()){
                temp = order.top();
                req = lim - seed;
                val = temp.first;
                no = temp.second;
                
                
                req = min(no,req);
                //cout<<req<<" with profit "<<val<<"\n";
                sum += val*req;
                seed += req;
                no -=req;
                order.pop();
                if(no)order.push({val,no});
            }
            
            ans += sum;
            
            if(order.empty()){
                //move 
                while(it!=diff_days.end()){
                    it++;
                    long long cur = *it;
                    if(cur>start)break;
                }
                
                if(it == diff_days.end())break;
                start = *it;
                start--;
            }
            //this is the smallest day
            
        }
        
        
        cout<<ans<<"\n";
    }
}
