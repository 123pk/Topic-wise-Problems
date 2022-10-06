#include <map>

class TimeMap {
    using timeKey = std::pair<std::string, int>;
    std::map<timeKey, std::string> data;
public:
    TimeMap() {
     //   
    }
    
    void set(string key, string value, int timestamp) {
       data.emplace(std::make_pair(key, timestamp), value); 
    }
    
    string get(string key, int timestamp) {
        auto it = data.upper_bound(std::make_pair(key, timestamp));
        if (it == data.begin())
            return "";
        --it;
        if (it->first.first != key)
            return "";
        return it->second;
    }
};
