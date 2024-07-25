class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        priority_queue<int, vector<int>,greater<int>>pq;
        for(auto & ele : nums){
            pq.push(ele);
        }
        vector<int>ans;
        while(!pq.empty()){
            int top=pq.top();
            pq.pop();
            ans.push_back(top);
        }
        return ans;
    }
};