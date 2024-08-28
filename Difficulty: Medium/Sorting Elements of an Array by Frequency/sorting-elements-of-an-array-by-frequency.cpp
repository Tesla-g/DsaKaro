//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Complete this function
 
std::vector<int> sortByFreq(std::vector<int>& arr) {
    std::map<int, int> freqMap;
    
    // Count the frequency of each element
    for (const auto& ele : arr) {
        freqMap[ele]++;
    }
    
    // Create a vector of pairs (frequency, element)
    std::vector<std::pair<int, int>> freqVec;
    for (const auto& ele : freqMap) {
        freqVec.push_back({ele.second, ele.first});
    }
    
    // Sort by frequency (descending) and then by element value (ascending)
    std::sort(freqVec.begin(), freqVec.end(), [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
        return (a.first == b.first) ? a.second < b.second : a.first > b.first;
    });
    
    // Generate the sorted result based on frequency
    std::vector<int> result;
    for (const auto& p : freqVec) {
        result.insert(result.end(), p.first, p.second);
    }
    
    return result;
}
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution obj;
        vector<int> v;
        v = obj.sortByFreq(arr);
        for (int i : v)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends