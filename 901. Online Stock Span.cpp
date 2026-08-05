class StockSpanner {
public:
    stack<pair<int, int>> st;
    int cnt;
    StockSpanner() {
        cnt = 0;
    }
    int next(int price) {
        while (!st.empty() && st.top().first <= price)
            st.pop();
        int ans = 1;       
        if (!st.empty())
            ans = cnt - st.top().second;
        else
            ans = cnt + 1;
        st.push({price, cnt});
        cnt++;
        return ans;
    }
};
