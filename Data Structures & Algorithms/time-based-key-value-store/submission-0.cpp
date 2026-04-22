class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> store;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        store[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {

        if(store.find(key) == store.end()) return "";
        
        string res = "";
        auto &values = store[key];

        // binary search
        int l = 0, r = values.size()-1;
        while(l <= r) {
            int mid = l + (r - l)/2;
            if(values[mid].first <= timestamp) { // got the value
                res = values[mid].second;
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }

        return res;
    }
};
