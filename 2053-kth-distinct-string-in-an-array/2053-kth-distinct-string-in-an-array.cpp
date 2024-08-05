#include <vector>
#include <string>
#include <unordered_map>

class Solution {
public:
    string kthDistinct(std::vector<std::string>& arr, int k) {
        std::unordered_map<std::string, int> countMap;

        // Count occurrences of each string
        for (const auto& ele : arr) {
            countMap[ele]++;
        }

        // Iterate through the array again to find the k-th distinct element
        for (const auto& ele : arr) {
            if (countMap[ele] == 1) {
                k--;
                if (k == 0) {
                    return ele;
                }
            }
        }

        return "";
    }
};
