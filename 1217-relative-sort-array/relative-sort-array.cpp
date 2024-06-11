class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,int>mp;
        for(auto &ele : arr1){
            mp[ele]++;
        }
        vector<int>ans;
        for(auto &ele : arr2){
           while(mp[ele]>0){
               ans.push_back(ele);
               mp[ele]--;
           }
            
            if(mp[ele]<0){
                mp.erase(ele);
            }
        }
       for(auto &it : mp){
           while(it.second>0){
               ans.push_back(it.first);
               it.second--;
           }
           if(it.second<0){
               mp.erase(it.first);
           }
           
       }
        return ans;
    }
};