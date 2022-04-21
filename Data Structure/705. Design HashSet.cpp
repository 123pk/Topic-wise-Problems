
class MyHashSet {
public:
    /** Initialize your data structure here. */
   set<int>P;
    MyHashSet() {
      
    }
    
    void add(int key) {
        if(P.find(key)==P.end())
        {
            P.insert(key);
        }
        
    }
    
    void remove(int key) {
        if(P.find(key)!=P.end())
        {  auto it=P.find(key);
         P.erase(it);  
        }
        
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
       if(P.find(key)==P.end())
        {
            return false;
        }
        return true;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
