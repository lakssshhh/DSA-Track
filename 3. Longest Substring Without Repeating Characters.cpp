class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    int ans = 0;
    unordered_map<char, int> mp;
    int start = 0;
    
    for (int i = 0; i < s.size(); i++) {
        mp[s[i]]++;
        
        while (mp.size() < i - start + 1) {
            mp[s[start]]--;
            if (mp[s[start]] == 0)
                mp.erase(s[start]);
            start++;
        }
        
        if (mp.size() == i - start + 1)
            ans = max(ans, i - start + 1);
    }
    
    return ans;
 
    }
};
