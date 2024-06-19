class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        
       vector<pair<int, int>> jobs;
        int n = difficulty.size();
        
        // Combine difficulty and profit into a single vector of pairs
        for (int i = 0; i < n; ++i) {
            jobs.push_back({difficulty[i], profit[i]});
        }
        
        // Sort jobs by difficulty
        sort(jobs.begin(), jobs.end());
        
        // Preprocess to find the maximum profit up to each difficulty
        for (int i = 1; i < n; ++i) {
            jobs[i].second = max(jobs[i].second, jobs[i - 1].second);
        }
        
        // Sort workers by their ability
        sort(worker.begin(), worker.end());
        
        int totalProfit = 0;
        for (int ability : worker) {
            int l = 0, r = n - 1;
            int bestProfit = 0;
            
            // Binary search to find the maximum profit the worker can get
            while (l <= r) {
                int mid = (l + r) / 2;
                if (jobs[mid].first <= ability) {
                    bestProfit = jobs[mid].second;
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
            
            totalProfit += bestProfit;
        }
        
        return totalProfit;
    }
};