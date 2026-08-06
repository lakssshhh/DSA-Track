class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        // code here
        int top=0;
        int down = mat.size()-1;
        
        while(top < down){
            if(mat[top][down] == 1){
                top++;
            }
            else if(mat[down][top] == 1){
                down--;
            }else{
                top++;
                down--;
            }
        }
        
        if(top > down) return -1;
        
        for(int i=0; i<mat.size(); i++){
            if(i==top) continue;
            if(mat[top][i] != 0 || mat[i][top] != 1){
                return -1;
            }
        }
        return top;
    }
};
