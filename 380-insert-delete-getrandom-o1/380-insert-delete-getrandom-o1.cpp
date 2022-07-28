class RandomizedSet {
public:
    unordered_map<int, int> s;
    vector<int> v;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(s.find(val) == s.end()) { 
            v.emplace_back(val); 
            s[val] = v.size() - 1; 
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if(s.find(val) != s.end()){ 
            int lst = v.back();
            s[lst] = s[val];
            v[s[val]] = lst;
            
            
            s.erase(val);
            v.pop_back();
            return true; 
        }
        return false;
    }
    
    int getRandom() {
        return v[rand() % v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */