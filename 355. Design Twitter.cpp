class Twitter {
private:
    int timestamp = 0;
    unordered_map<int, vector<pair<int,int>>> tweets;
    unordered_map<int, unordered_set<int>> following;
    struct HeapNode {
        int time;
        int tweetId;
        int userId;
        int index;

        bool operator<(const HeapNode& other) const {
            return time < other.time;
        }
    };
public:
    Twitter() {}
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timestamp++, tweetId});
    }
    vector<int> getNewsFeed(int userId) {
        priority_queue<HeapNode> heap;
        unordered_set<int> relevant = following[userId];
        relevant.insert(userId);
        for (int uid : relevant) {
            auto it = tweets.find(uid);
            if (it != tweets.end() && !it->second.empty()) {
                int lastIdx = it->second.size() - 1;
                auto [time, tweetId] = it->second[lastIdx];
                heap.push({time, tweetId, uid, lastIdx});
            }
        }
        vector<int> result;
        while (!heap.empty() && result.size() < 10) {
            HeapNode top = heap.top();
            heap.pop();
            result.push_back(top.tweetId);
            int nextIdx = top.index - 1;
            if (nextIdx >= 0) {
                auto [time, tweetId] = tweets[top.userId][nextIdx];
                heap.push({time, tweetId, top.userId, nextIdx});
            }
        }
        return result;
    }
    void follow(int followerId, int followeeId) {
        if (followerId == followeeId) return;
        following[followerId].insert(followeeId);
    }
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};
