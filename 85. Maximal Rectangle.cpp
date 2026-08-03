class Solution {
public:
vector<int> prevSmaller(vector<int>& arr) {
    stack<int> st;
    vector<int> ans(arr.size(), -1);
    for (int i = 0; i < arr.size(); i++) {
        while (!st.empty() && arr[st.top()] > arr[i])
            st.pop();
        if (!st.empty())
            ans[i] = st.top();
        st.push(i);
    }
    return ans;
}
vector<int> nextSmaller(vector<int>& arr) {
    stack<int> st;
    vector<int> ans(arr.size(), arr.size());
    for (int i = arr.size() - 1; i >= 0; i--) {
        while (!st.empty() && arr[st.top()] >= arr[i])
            st.pop();
        if (!st.empty())
            ans[i] = st.top();
        st.push(i);
    }
    return ans;
}
int largestRectangleArea(vector<int>& heights) {
    vector<int> prev = prevSmaller(heights);
    vector<int> next = nextSmaller(heights);

    int ans = INT_MIN;
    for (int i = 0; i < heights.size(); i++) {
        ans = max(ans, (next[i] - prev[i] - 1) * heights[i]);
    }
    return ans;
}
int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
        return 0;
    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<int> heights(cols, 0);
    int maxArea = 0;
for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
        heights[j] = (matrix[i][j] == '1') ? heights[j] + 1 : 0;
    }
    maxArea = max(maxArea, largestRectangleArea(heights));
}
return maxArea;
    }
};
