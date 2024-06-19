class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        
      vector<pair<int,int>>v;
     for(int i=0;i<difficulty.size();i++){
        v.push_back({difficulty[i],profit[i]});
      }
        int total=0;
        for(int i=0;i<worker.size();i++){
            int workerLimit=worker[i];
            int limit=-1;
            for(int j=0;j<v.size();j++){
                if(v[j].first<=workerLimit){
                    limit=max(limit,v[j].second);
                }
            }
            if(limit!=-1){
                total+=limit;
            }
        }
        return total;
    }
};