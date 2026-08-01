class Solution {
public:
    string removeKdigits(string num, int k) {
    stack<char> st;
    for (char c : num) {
        while (!st.empty() && k > 0 && st.top() > c) {
            st.pop();
            k--;
        }
        st.push(c);
    }
    while (!st.empty() && k > 0) {
        st.pop();
        k--;
    }
    string ans;
    while (!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }
    
    while (!ans.empty() && ans.back() == '0') {
        ans.pop_back();
    } 
    reverse(ans.begin(), ans.end());
    return ans.empty() ? "0" : ans;
    }
};
