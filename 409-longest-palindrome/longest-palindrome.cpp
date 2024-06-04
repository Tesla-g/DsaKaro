class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> mp;
        for (auto &ch : s) {
            mp[ch]++;
        }
        
        int length = 0;
        bool hasOdd = false;
        
        for (auto &ele : mp) {
            if (ele.second % 2 == 0) {
                length += ele.second;  // Even counts can all be used
            } else {
                length += ele.second - 1;  // Use the even part of odd counts
                hasOdd = true;  // Remember there is an odd count
            }
        }
        
        if (hasOdd) {
            length += 1;  // Add one odd character in the center
        }
        
        return length;
    }
};
