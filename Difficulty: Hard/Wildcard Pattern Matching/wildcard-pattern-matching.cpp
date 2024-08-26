//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    /*You are required to complete this method*/
    int wildCard(string pattern, string str) {
    int m = pattern.size(); 
    int n = str.size();
    vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));  // DP table with dimensions (m+1)x(n+1)
                            // y axis      x axis
    dp[m][n] = true;  // Base case: empty pattern matches empty string

    // Fill the DP table bottom-up
    for(int row = m; row >= 0; row--) { // iterating over the y axis 
        for(int col = n; col >= 0; col--) {// iteratiing ove teh x axis
            if(row == m && col == n) {
                continue;  // Skip the already initialized last cell
            } else if(row == m) {
                // Last row: pattern is empty
                dp[row][col] = false;
            } else if(col == n) {
                // Last column: only '*' can match the remaining pattern
                dp[row][col] = (pattern[row] == '*') ? dp[row+1][col] : false;
            } else {
                // Main cases
                if(pattern[row] == '?') {
                    // '?' matches a single character
                    dp[row][col] = dp[row+1][col+1];
                } else if(pattern[row] == '*') {
                    // '*' matches zero or more characters
                    dp[row][col] = dp[row+1][col] || dp[row][col+1];
                } else if(pattern[row] == str[col]) {
                    // Exact match required
                    dp[row][col] = dp[row+1][col+1];
                } else {
                    dp[row][col] = false;
                }
            }
        }
    }

    return dp[0][0];  // Return whether the whole pattern matches the whole string
}
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, text;
        cin >> pat;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> text;
        Solution obj;
        cout << obj.wildCard(pat, text) << endl;
    }
}

// } Driver Code Ends