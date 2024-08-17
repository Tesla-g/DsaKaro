class Solution {
public:
    vector<vector<int>>memo;
    int helper(int r,int c, vector<vector<int>>&matrix){
        if(r>=matrix.size() or c<0 or c>=matrix.size()){
            return INT_MAX;
        }
        if(memo[r][c]!=INT_MAX){
            return memo[r][c];
        }
         // Base case: last row
        if (r == matrix.size() - 1) {
            return matrix[r][c];
        }
            int cost= matrix[r][c];
            int op=min({helper(r+1,c+1,matrix), helper(r+1, c-1, matrix), helper(r+1, c, matrix)});
            if(op!=INT_MAX){
                cost+=op;
            };
          return memo[r][c]=cost;
        
        
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans=INT_MAX;
        int n=matrix.size();
        memo=vector<vector<int>>(n, vector<int>(n, INT_MAX));
        
        for(int i=0;i<matrix[0].size(); i++){
            ans=min(ans, helper(0, i, matrix));
        }
        return ans;

    }
};