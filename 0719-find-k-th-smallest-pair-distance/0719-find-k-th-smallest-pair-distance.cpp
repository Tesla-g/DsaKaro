class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>vec;
        for(size_t i=0; i<n; ++i){
            for(size_t j=i+1; j<n; ++j){
                int dist=abs(nums[i]-nums[j]);
                vec.push_back(dist);
            }
           
        
    }
         nth_element(begin(vec), begin(vec)+k-1, end(vec));
            return vec[k-1];
    }
};