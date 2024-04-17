class RandomizedSet {

public:
    vector <int> v;
    // srand(time(NULL));
    RandomizedSet() {
    }
    
    bool insert(int val) {
        if (find(v.begin(), v.end(), val) != v.end())
            return false;
        v.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        auto iter = find(v.begin(), v.end(), val);
        if (iter ==  v.end())
            return false;
        v.erase(iter);
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