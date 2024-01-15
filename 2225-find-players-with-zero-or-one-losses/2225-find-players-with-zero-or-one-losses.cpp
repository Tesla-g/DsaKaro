class Solution {
public:
  vector<vector<int>> solution(vector<vector<int>> & m){
  map<int,int>win;
  map<int,int>lost;
  for(auto &e:m ){
    win[e[0]]++;
    lost[e[1]]++;
  }
  
  vector<vector<int>>ans(2);
  for(auto& e: win){
    if(lost[e.first]==0){
      ans[0].push_back(e.first);
    }
  }
  for(auto &ele: lost){
    if(ele.second==1){
      ans[1].push_back(ele.first);
    }
  }

  return ans;
}

    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        return solution(matches);
    }
};