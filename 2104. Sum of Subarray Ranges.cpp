class Solution {
public:
      vector<int> prevSmaller(vector<int>& arr){
    stack<int> st;
    vector<int> ans(arr.size(), -1);
    for(int i = 0; i < arr.size(); i++){
        while(!st.empty() && arr[st.top()] > arr[i])
            st.pop();
        if(!st.empty())
            ans[i] = st.top();
        st.push(i);
    }
    return ans;
}

vector<int> nextSmaller(vector<int>& arr){
    stack<int> st;
    vector<int> ans(arr.size(), arr.size());
    for(int i = arr.size()-1; i >= 0; i--){
        while(!st.empty() && arr[st.top()] >= arr[i])
            st.pop();
        if(!st.empty())
            ans[i] = st.top();
        st.push(i);
    }
    return ans;
}

vector<int> prevGreater(vector<int>& arr){
    stack<int> st;
    vector<int> ans(arr.size(), -1);
    for(int i = 0; i < arr.size(); i++){
        while(!st.empty() && arr[st.top()] < arr[i])
            st.pop();
        if(!st.empty())
            ans[i] = st.top();
        st.push(i);
    }
    return ans;
}

vector<int> nextGreater(vector<int>& arr){
    stack<int> st;
    vector<int> ans(arr.size(), arr.size());
    for(int i = arr.size()-1; i >= 0; i--){
        while(!st.empty() && arr[st.top()] <= arr[i])
            st.pop();
        if(!st.empty())
            ans[i] = st.top();
        st.push(i);
    }
    return ans;
}

long long subArrayRanges(vector<int>& arr) {
    vector<int> prevS = prevSmaller(arr);
    vector<int> nextS = nextSmaller(arr);
    vector<int> prevG = prevGreater(arr);
    vector<int> nextG = nextGreater(arr);
    long long ans = 0;

    for(int i = 0; i < arr.size(); i++){
        long long minleftElements = i - prevS[i];
        long long minrightElements = nextS[i] - i;
        long long maxleftElements = i - prevG[i];
        long long maxrightElements = nextG[i] - i;
        ans += (maxleftElements * maxrightElements * arr[i]) - (minleftElements * minrightElements * arr[i]);
    }
    return ans;
}  
    
};
