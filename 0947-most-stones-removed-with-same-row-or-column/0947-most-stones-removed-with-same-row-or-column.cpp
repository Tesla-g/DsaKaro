class Solution {
public:

    void dfs(vector<vector<int>>&stones, int index, vector<bool>&visited){
        visited[index]=true;
        
        for(int i = 0; i<stones.size(); i++){
            // iterate over the all the x , y 
            int currx=stones[index][0];
            int curry=stones[index][1];
            if(visited[i]==false and (currx==stones[i][0] or curry==stones[i][1])){
                // if this is the case 
                dfs(stones, i, visited);
            }
            
        }

        
    }
    
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<bool> visited(n, false);
        int group=0;
        for(int i =0; i< n; i++){
            if(visited[i]==true)
                continue;
            dfs(stones, i, visited); // this will count the crop 
            group++;// count all the groups 
            
        }
       return n-group;
    }
};