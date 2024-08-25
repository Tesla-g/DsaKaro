class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
       int cnt=0;
        for(auto & v : grid){
        for(auto & ele : v){
            if(ele<0){
                cnt++;
            }
         }
       } 
        return cnt; 
    }
};