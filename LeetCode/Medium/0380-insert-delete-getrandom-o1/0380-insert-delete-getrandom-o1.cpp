class RandomizedSet {

private:
    vector<int> v;
    unordered_map<int, int> m;
    
public:
    RandomizedSet() {
    }
    
    bool insert(int val) {
        
        if (v.size() && m.find(val) != m.end())
            return false;
        
        v.push_back(val);
        m[val] = v.size() - 1;
        
        return true;
    }
    
    bool remove(int val) {
        if (v.empty())
            return false;

        auto iter = m.find(val);
        if (iter == m.end())
            return false;    
        
        v[iter->second] = v.back();
        m[v.back()] = iter->second;
        v.pop_back();
        m.erase(val);
        
        return true;
    }
    
    int getRandom() {
        int randomNum = rand() % v.size();
        return v[randomNum];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */  