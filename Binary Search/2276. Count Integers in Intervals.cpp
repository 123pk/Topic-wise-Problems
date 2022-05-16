/*
Platform :- Leetcode
Contest :- Leetcode Weekly contest 293
Approach :- Basic approach is to store the first value of range in set so we can do (insert and delet operation in Log(n)) , We will store the end part of range of each 
            value of set using map . 
            
            There are many cases to take care of 
            1. If our set is empty we push directly into the set 
            2. else we will check if we start value of range in set or not , if yes then we will update the end value accordingly and if we have certain overlapping ranges
               we will remove them if they come inside the range .
            3. If this value is not present in set then also ther are two sceneraio 
                 i. either it is withing some range or 
                 ii. not in range of any 
                 we take care of these cases accordingly.
*/

class CountIntervals {
public:
    long long tot = 0;
    set<long long>start;
    map<long long,long long>end;
    CountIntervals() {
        tot = 0;
    }
    vector<long long>temp;
    void add(int x, int y) {
        long long left = x,right = y;
        
        if(start.size() == 0){
            start.insert(left);
            tot+=(right-left)+1;
            end[left] = right;
        }
        else{
            auto it = start.lower_bound(left);
            long long val = *it;
            if(start.find(left) == start.end()){
                //1. not present means either in disjoint place
                //2. at the beginning 
                //3. at the end
                
                
                if(it == start.end()){
                    //this set is at end
                    it--;
                    val = *it;
                   // cout<<val<<" "<<end[val]<<" "<<left<<" \n";
                    if(end[val]<left){
                        //this means we have to add this disjoint edge
                        start.insert(left);
                        end[left] = right;
                        tot+=(right-left)+1;
                    }
                    else if(end[val]>=right){
                       // cout<<" * ";
                    }
                    else{
                        tot+=(right-end[val]);
                        //if(end[val]>left)tot++;
                        end[val] = right;
                    }
                }
                else{
                    //between the range
                    auto it2 = start.lower_bound(left);
                    int f = 0,g = 0;
                    if(it == start.begin()){
                        
                    }
                    else{
                        
                        it2--;
                        val = *it2;
                        if(end[val]>=left){
                            if(end[val]>=right){
                                g=1;
                            }
                            else f=1;
                        }
                    }
                    
                    if(g == 0){
                        it = start.lower_bound(left);
                        long long prev = 0,last = 0;
                        if(f){
                            prev+=(end[val]-left);
                            if(end[val]>=left)prev+=1;
                            last = end[val];
                        }
                        temp.clear();
                        for(;it!=start.end();++it){
                            val = *it;
                            if(end[val]<=right){
                                temp.push_back(val);
                                prev+=(end[val]-val)+1;
                            }
                            else if(val<=right){
                                last = end[val];
                                temp.push_back(val);
                                prev+=(right-val)+1;
                            }
                            else break;
                        }
                        
                        if(f){
                            //we will update
                            long long cur = (right-left)+1;
                            tot+=(cur-prev);
                            end[*it2] = max(last,right);
                        }
                        else{
                            long long cur = (right-left)+1;
                            start.insert(left);
                            tot+=(cur-prev);
                            end[left] = max(last,right);
                        }
                        
                        for(auto&x:temp)start.erase(x);
                    }
                    
                    
                    //at the beginning
                }
                
                //4. between a range
            }
            else{
                //present means
                //1. completely overlapping under other rnage
                //2. range to right 
                //3. range to right and overlapping
                if(end[val]>=right){
                    //current range is already inside other range
                    //do nothing
                }
                else{
                    long long prev = 0,last = 0;
                    temp.clear();
                    for(;it!=start.end();it++){
                        val = *it;
                        if(end[val]<=right){
                            temp.push_back(val);
                            prev+=(end[val]-val)+1;
                        }
                        else if(val<=right){
                            //this means current range falls in between some other range
                            last = end[val];
                            prev+=(right-val)+1;
                            temp.push_back(val);
                        }
                        else break;
                    }
                    
                    long long cur = (right-left)+1;
                    tot+=(cur-prev);
                    for(auto&x:temp)start.erase(val);
                    start.insert(left);
                    end[left] = max(last,right);
                }
            }
        }
       // cout<<tot<<" "<<left<<" "<<right<<"\n";
    }
    
    int count() {
      //  for(auto&x:start)cout<<x<<" "<<end[x]<<"\n";
        return tot;
    }
};

/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals* obj = new CountIntervals();
 * obj->add(left,right);
 * int param_2 = obj->count();
 */
