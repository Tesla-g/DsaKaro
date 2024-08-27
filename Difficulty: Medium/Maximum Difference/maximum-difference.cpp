//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    /*You are required to complete this method */
  vector<int> nextSmaller(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n);
    stack<int> st;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && nums[st.top()] > nums[i]) {
            ans[st.top()] = nums[i];
            st.pop();
        }
        st.push(i);
    }

    // Any remaining elements in the stack have no next smaller element
    while (!st.empty()) {
        ans[st.top()] = 0; // or -1 based on requirement
        st.pop();
    }

    return ans;
}

int findMaxDiff(vector<int>& arr) {
    // Find the next smaller elements in the array
    vector<int> nxtsmaller = nextSmaller(arr);

    // Reverse the array to find the previous smaller elements
    reverse(arr.begin(), arr.end());
    vector<int> prevsmaller = nextSmaller(arr);

    // Reverse back to match the original order
    reverse(prevsmaller.begin(), prevsmaller.end());

    // Calculate the maximum difference
    int n = nxtsmaller.size();
    int maxDiff = INT_MIN;
    for (int i = 0; i < n; i++) {
        maxDiff = max(maxDiff, abs(nxtsmaller[i] - prevsmaller[i]));
    }

    return maxDiff;
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

        Solution ob;
        cout << ob.findMaxDiff(arr) << endl;
    }
    return 0;
}

// } Driver Code Ends