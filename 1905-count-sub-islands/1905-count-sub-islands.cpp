class Solution {
public:
    typedef pair<int,int> P;
    bool bfs(int i , int j , vector<vector<int>>&grid1, vector<vector<int>>&grid2){
        vector<vector<int>>dir={{-1,0},{0,1},{1,0},{0,-1}};
        queue<P>que;
        que.push({i,j});
        // mark them as visted
        grid2[i][j]=-1;
        
        bool result=true;
        while(!que.empty()){
            auto top=que.front();
            que.pop();
            // expolore all it's child
            if(grid1[top.first][top.second]!=1){
                result=false;
            }
            
            // if the grid is not does not conat the one 
            // but explore all of it's child
            
            
            for(auto &ele: dir){
                int newx=top.first+ele[0];
                int newy=top.second+ele[1];
                // explore all of it's natural 
                // mark this as visite
                if(newx>=0 and newy>=0 and newy<grid2[0].size() and newx<grid2.size() and grid2[newx][newy]==1){
                    grid2[newx][newy]=-1;
                    que.push({newx,newy}); 
                }
                
            }

        }
        return result;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int count=0;
        int m = grid2.size(); int n = grid2[0].size();
        for(int i = 0; i<m ; ++i){
            
            for(int j= 0; j< n; ++j){
                if(grid2[i][j]==1 and bfs(i,j,grid1, grid2)){
                    count++;
                }
            }
            
        }
        
        
        return count; 

 
    }
};