class Solution {
public: 
        bool minbouqets(const vector<int>& bloomDay,int days, int m, int k){
           int bouqets = 0;
           int flowers = 0;
             for (int bloom:bloomDay){
                if (bloom <= days) {
                flowers++;
                if(flowers == k){
                    bouqets++;
                    flowers = 0;
                }}
                else{
                    flowers = 0;
                }
                if (bouqets >= m) return true;
             }
             return bouqets >= m;
        }


    int minDays(vector<int>& bloomDay, int m, int k) {
    int low = *min_element(bloomDay.begin(), bloomDay.end());
    int high = *max_element(bloomDay.begin(), bloomDay.end());
    int ans = -1;
        while(low<=high){
           int mid = low + (high - low) / 2;
            if(minbouqets(bloomDay,mid,m,k) ){
                ans = mid;
                high = mid-1;
            }
            else{
               low = mid+1;
            }
        }
        return ans;
    }
};
