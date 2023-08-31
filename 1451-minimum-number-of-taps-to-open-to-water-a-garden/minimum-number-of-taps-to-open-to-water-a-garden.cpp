class Solution {
public:
    map<pair<int,int>,int> mp;
    int N;
    int solve(int i, int maxEnd, vector<pair<int,int>>& range) {
        if(i >= range.size())
            return maxEnd >= N ? 0 : 1e9;

        if(range[i].first > maxEnd)
            return 1e9;

        if(mp.find({i,maxEnd}) != mp.end())
            return mp[{i,maxEnd}];

        int not_open_tap = solve(i+1, maxEnd , range);
        
        int open_tap     = 1 + solve(i+1, max(maxEnd, range[i].second), range);

        return mp[{i, maxEnd}] = min(open_tap, not_open_tap); 
    }
    
    int minTaps(int n, vector<int>& ranges) {
        N = n;
        
        vector<pair<int,int>> range;

        for(int i = 0; i < ranges.size(); i++) {
            
            int start = max(0, i - ranges[i]);
            int end   = min(n, i + ranges[i]);
            
            range.push_back({start, end});
            
        }
        
        sort(range.begin(), range.end());
        
        int ans = solve(0, 0, range);
        
        return ans == 1e9 ? -1 : ans;
    }
};
