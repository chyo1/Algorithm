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
        
        // map에 없는 값이라면 -1 반환
        if (um.find(key) == um.end())
            return -1;
        
        // 큐에 현재 순서 삽입, usedTime에 마지막 사용시간 갱신
        q.push({cnt + 1, key});
        usedTime[key] = ++cnt;
        return um[key];
    }
    
    void put(int key, int value) {
        
        // um에 그 값이 없으면 LRU를 생각하지 않아도 됨
        if (um.find(key) == um.end() && um.size() == size) {
            
            // 큐에 저장된 시간 == 마지막 사용 시간인 값을 찾음
            while (q.front().first != usedTime[q.front().second])
                q.pop();
            um.erase(q.front().second);
            q.pop();
        }
        um[key] = value;

        // 큐에 현재 순서 삽입, usedTime에 마지막 사용시간 갱신
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