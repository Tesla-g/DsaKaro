class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
      sort(target.begin(), target.end());
        sort(arr.begin(), arr.end());
        return arr==target;
        // all the element is present of arr  is present in target but you shoula also check for each 
    }
};