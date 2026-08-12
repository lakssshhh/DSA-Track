class Solution {
public:
    int characterReplacement(string s, int k) {
    unordered_set<char> ltrs;
    for(auto it : s)
        ltrs.insert(it);
    int ans = 0;
    for(auto ltr : ltrs) {
        int start = 0, ltrCnt = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == ltr)
                ltrCnt++;
            while((i - start + 1) - ltrCnt > k) {
                if(s[start] == ltr)
                    ltrCnt--;
                start++;
            }
            if((i - start + 1) - ltrCnt <= k)
                ans = max(ans, i - start + 1);
        }
    }
    return ans;
    } 
};
