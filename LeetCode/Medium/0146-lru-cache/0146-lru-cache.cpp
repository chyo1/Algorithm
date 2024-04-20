class LRUCache {
public:
    int cnt = 0, size;
    queue<pair<int, int>> q;
    unordered_map<int, int> um, usedTime;

    LRUCache(int capacity) {
        new unordered_map<int, int>(capacity);
        size = capacity;
    }
    
    int get(int key) {
        if (um.find(key) == um.end())
            return -1;
        q.push({cnt + 1, key});
        usedTime[key] = ++cnt;
        return um[key];
    }
    
    void put(int key, int value) {
        if (um.find(key) == um.end() && um.size() == size) {
            while (q.front().first != usedTime[q.front().second])
                q.pop();
            um.erase(q.front().second);
            q.pop();
        }
        um[key] = value;

        q.push({cnt + 1, key});
        usedTime[key] = ++cnt;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */