class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();

        // edge case
        if(n == 0) return 0;

        vector<int> dpA(n, 0);
        vector<int> dpB(n, 0);

        // Handling the first character for both the letter 'a' and 'b'
        dpA[0] = (s[0] == 'b') ? 1 : 0; // If first character is b then 1 deletion 
        dpB[0] = (s[0] == 'a') ? 1 : 0; // If first character is b then 1 deletion

        // fill the both DP arrays
        for(int i = 1; i < n; i++){
            if(s[i] == 'a'){
                dpA[i] = dpA[i-1];
                dpB[i] = min(dpA[i-1], dpB[i-1] + 1);
            }
            else{ // s[i] == 'b'
                dpA[i] = dpA[i-1] + 1;
                dpB[i] = min(dpB[i-1], dpA[i-1]);
            }
        }

        return min(dpA[n-1], dpB[n-1]);
    }
};