class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int r = 0;
    for (int l = 0; l < s.size() && r < g.size(); l++) {
        if (s[l] >= g[r])
            r++;
    }
    return r;
}
};
