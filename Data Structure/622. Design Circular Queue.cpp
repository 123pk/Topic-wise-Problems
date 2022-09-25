/*
Platform :- Leetcode
Approach :- We will use vector and two pointer one will act as start and one as end .
            Condition for empty queue is when start == -1 or start>end
*/
class MyCircularQueue {
public:
    vector<int>cqueue;
    int start = -1,end = -1;
    int sz = 0;
    MyCircularQueue(int k) {
        cqueue.resize(k);
        sz = k;
    }
    
    bool enQueue(int value) {
        //we cannot insert any element if queue is full
        //if end+1%sz == start
       // cout<<start<<" "<<end<<"\n";
        if((start!=-1) && (end+1)%sz == (start%sz)){
           // cout<<" * ";
            return false;
        }
        else{
            //move the end and add the element
            end++;
            cqueue[end%sz] = value;
            if(end == 0)start = 0;
            return true;
        }
    }
    
    bool deQueue() {
        //cout<<" del \n";
        //if it is empty they return false
        if(start>end || start==-1)return false;
        else{
            if(start == end){
                start = -1;
                end = -1;
            }
            else start++;
            return true;
        }
    }
    
    int Front() {
        //cout<<" front \n";
        if(start>end ||  start == -1)return -1;
        return cqueue[start%sz];
    }
    
    int Rear() {
       // cout<<" at last \n";
        if(start>end || start == -1)return -1;
        return cqueue[end%sz];
    }
    
    bool isEmpty() {
        return (start>end || start == -1);
    }
    
    bool isFull() {
        //cout<<" full or not \n";
        if((end+1)%sz == start)return true;
        return false;
    }
};

