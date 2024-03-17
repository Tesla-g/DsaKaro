class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int si=newInterval[0];
        int ei=newInterval[1];
        int value=INT_MAX;
        int value2=INT_MIN;
        vector<vector<int>>ans;
       for (int i = 0; i < intervals.size(); i++) {
            int start = intervals[i][0];
            int end = intervals[i][1];
//             the start value should be less than the end value and the end value should be greater than or equal to the start the value 
            if (start <= ei && end >= si) { // Check for overlap
                si = min(si, start);
                ei = max(ei, end);
            } else {
                ans.push_back(intervals[i]);
            }
        }
        ans.push_back({si, ei});
        sort(ans.begin(), ans.end()); // Ensure intervals are sorted
        return ans;
  }
};