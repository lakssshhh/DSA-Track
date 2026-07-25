class MinStack {
private:
    stack<long long> st;
    int mini;
public:
    MinStack() {
        mini = -1;
    }
    
    
    void push(int val) {
           if (st.empty()) {
            st.push(0);
            mini = val;
        } else {
            st.push((long long)val - mini);
            mini = min(val, mini);
        }
    }
    
    void pop() {
       if (st.top() < 0)
            mini = mini - st.top();
        st.pop(); 
    }
    
    int top() {
         int ans = -1;
        if (st.top() < 0)
            ans = mini;
        else
            ans = mini + st.top();
        return ans;
    }
    
    int getMin() {
         return mini;
    }
};
