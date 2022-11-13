/*
Platform :- Leetcode
Approach :- We will maintain two heaps , the main idea is to store the first half in max heap and second halp of sorted array in min_heap ,  so the top value of both would 
            represent the middle values of sorted array.
            - We need to carefully insert the values . We don't want the top value of first half be "greater" than "top" value of min_heap which store the second half.
            So we greediy insert the values and at any point the difference in size should not be more than '1'
 Time Complexity :- O(n*logn)
*/
 
class MedianFinder {
public:
    //we need two heaps one for left half
    //one for right half
    priority_queue<int>small;
    priority_queue<int,vector<int>,greater<int>>big;
    int c = 0,d = 0;
    MedianFinder() {
        
    }
     
    void addNum(int num) {
        //this is the tricky part
        if(c == d){
            if(d && abs(big.top())<num){
               small.push(abs(big.top()));
               big.pop();
               big.push(num);
            }
            else small.push(num);
             c++;
        }
        else if(c>d){
            if(num<small.top()){
                big.push(small.top());
                small.pop();
                small.push(num);
                
            }
            else big.push(num);
            d++;
        }
        
    }
    
    double findMedian() {
        double ans = small.top();
        if((c+d)%2 == 0){
            ans += big.top();
            ans/=2.0;
        }
        return ans;

    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
