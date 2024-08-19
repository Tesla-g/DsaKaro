#include <unordered_map>
#include <string>
#include <climits>

class Solution {
public:
    unordered_map<string,int>memo;
    int helper(int n, string current, string copied_prev) {
        if (current.size() > n) {
            return INT_MAX; 
        }
         
        if (current.size() == n) {
            return 0;
        }

    string key=current+"_"+copied_prev;
  if(memo.count(key)){
    return memo[key];
  }
        int paste = INT_MAX;
        if (!copied_prev.empty()) {
            int res2 = helper(n, current + copied_prev, copied_prev);
            if (res2 != INT_MAX) {
                paste = min(paste, 1 + res2);
            }
        }

        int copy = INT_MAX;
        if (current.size() != copied_prev.size()) {
            int res3 = helper(n, current, current);
            if (res3 != INT_MAX) {
                copy = min(copy, 1 + res3);
            }
        }

        // Store the result in the memoization table
        memo[key] = min(paste, copy);
        return memo[key];
    }

    int minSteps(int n) {
        memo.clear();  // Clear the memoization table before starting
        return helper(n, "A", "");
    }
};

