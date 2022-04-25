/*
Platform :- Leetcode
Approach :- We will use queue data structure to implement the desired iterator
            --> Queue front() to peek
            --> for returning next value we will first get the element and earase it from queue and return the delted element
            --> if queue is not empty we will return true else false in ( is Next())
*/
class PeekingIterator : public Iterator {
public:
    queue<int>P;
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    for(auto&x:nums)P.push(x);
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        return P.front();
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
        int val = P.front();
        P.pop();
	    return val;
	}
	
	bool hasNext() const {
	    return !P.empty();
	}
};
