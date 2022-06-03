/*
Platform :- Leetcode
Approach :- We will maintain two heaps , one max heap which will store (k+1)/2 smallest values where 'k' is size of array at that moment,
            similarly we will maintain a min heap which will store (k)/2 largest values.
            Now for answering queries, if we have odd no of elements then we will return the max value of the smaller values,
            if its even then we will return the middle value of 'top' element of both heaeps
*/
class MedianFinder {
public:
    
    priority_queue<int>small;
    priority_queue<int,vector<int>,greater<int>>large;
    
    int n ;
    MedianFinder() {
        n = 0;
    }
    
    void addNum(int num) {
        n++;
         
        int left = (n+1)/2;
        int right = n/2;
        
        //we do some stuff 
        if(small.size() == left){
            //we have to insert in right
            //we will compare 
            
            if(num<small.top()){
                large.push(small.top());
                small.pop();
                small.push(num);
            }
            else large.push(num);
        }
        else{
            //we have to insert to left 
            if(large.size() == 0){
                small.push(num);
            }
            else{
                if(num>large.top()){
                    small.push(large.top());
                    large.pop();
                    large.push(num);
                }
                else small.push(num);
            }
        }
        
    }
    
    double findMedian() {
         
        if(n%2)return small.top();
        else {
            double first  = small.top();
            double second = large.top();
            first+=second;
            first/=2.0;
            return first;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
