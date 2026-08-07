class LRUCache {
private:
    int capacity;
    unordered_map<int, list<pair<int, int>>::iterator> addr;
    list<pair<int, int>> lru;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        if (addr.find(key) == addr.end())
            return -1; 

        auto keyPos = addr[key];
        lru.splice(lru.begin(), lru, keyPos);
        return lru.front().second;
    }

    void put(int key, int value) {
        if (addr.find(key) != addr.end()) {
            auto keyPos = addr[key];
            lru.splice(lru.begin(), lru, keyPos);
            lru.front().second = value;
            return;
        }
        if (addr.size() == capacity) {
            int backKey = lru.back().first;
            lru.pop_back();
            addr.erase(backKey);
        }
        lru.push_front({key, value});
        addr[key] = lru.begin();
    }
};
