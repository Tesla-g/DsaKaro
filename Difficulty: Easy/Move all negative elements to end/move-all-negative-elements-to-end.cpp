//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void segregateElements(vector<int>& arr) {
        
     
        vector<int>negatives;
        vector<int>postives;
        vector<int>final;
        for(auto &ele : arr){
            if(ele>=0) postives.push_back(ele);
            else{
                negatives.push_back(ele);
            }
        }
        for(auto & ele : postives){
            final.push_back(ele);
        }for(auto & ele : negatives){
            final.push_back(ele);
        }
        arr=final;
        
        
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);

    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        ob.segregateElements(nums);

        for (int x : nums)
            cout << x << " ";
        cout << endl;
    }
}
// } Driver Code Ends