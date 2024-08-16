class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int minVal = arrays[0][0];      // Minimum value encountered so far
        int maxVal = arrays[0].back();  // Maximum value encountered so far
        int maxDistance = 0;

        for (int i = 1; i < arrays.size(); ++i) {
            // Calculate potential max distances using current array's first and last elements
            maxDistance = max(maxDistance, abs(arrays[i].back() - minVal));
            maxDistance = max(maxDistance, abs(maxVal - arrays[i][0]));

            // Update minVal and maxVal for future comparisons
            minVal = min(minVal, arrays[i][0]);
            maxVal = max(maxVal, arrays[i].back());
        }

        return maxDistance;
    }
};
