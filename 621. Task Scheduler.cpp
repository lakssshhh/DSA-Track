class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> pq;
        vector<int> mp(26, 0);
        for (char task : tasks) {
            mp[task - 'A']++;
        }
        for (int i = 0; i < 26; i++) {
            if (mp[i] > 0) {
                pq.push(mp[i]);
            }
        }
        int time = 0;
        while (!pq.empty()) {
            vector<int> remain;
            int cycle = n + 1;
            while (cycle > 0 && !pq.empty()) {
                int freq = pq.top();
                pq.pop();
                freq--;
                if (freq > 0) {
                    remain.push_back(freq);
                }
                time++;
                cycle--;
            }
            for (int freq : remain) {
                pq.push(freq);
            }
            if (pq.empty()) {
                break;
            }

            time += cycle;
        }
        return time;
    }
};
