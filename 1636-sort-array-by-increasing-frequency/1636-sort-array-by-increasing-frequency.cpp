#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    std::vector<int> frequencySort(std::vector<int>& A) {
        std::unordered_map<int, int> freqMap;
        
        // Step 1: Count frequencies of each element
        for (auto ele : A) {
            freqMap[ele]++;
        }
        
        // Step 2: Create a vector of pairs (frequency, element)
        std::vector<std::pair<int, int>> freqVec;
        for (const auto& ele : A) {
            freqVec.push_back({freqMap[ele], ele});
        }
        
        // Step 3: Sort the pairs based on frequency (ascending) and element value (descending)
        std::sort(freqVec.begin(), freqVec.end(), [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
            return a.first == b.first ? a.second > b.second : a.first < b.first;
        });
        
        // Step 4: Build the result array
        std::vector<int> result;
        for (const auto& p : freqVec) {
            result.push_back(p.second);
        }
        
        return result;
    }
};
