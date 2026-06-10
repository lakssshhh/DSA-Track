class Solution {
public:
    int max_finder(vector<int>& row) {
    int maxi = INT_MIN;
    int ans = -1;
    for (int i = 0; i < row.size(); i++) {
        if (row[i] > maxi) {
            maxi = row[i];
            ans = i;
        }
    }
    return ans;
}

vector<int> findPeakGrid(vector<vector<int>>& mat) {
    int n = mat.size();
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        int col = max_finder(mat[mid]);
        if ((mid == 0 || mat[mid][col] > mat[mid - 1][col]) && 
            (mid == n - 1 || mat[mid][col] > mat[mid + 1][col]))
            return {mid, col};
        else {
            if (mid != 0 && mat[mid][col] < mat[mid - 1][col])
                high = mid - 1;
            else
                low = mid + 1;
        }
    }
    return {-1, -1};
}
};
