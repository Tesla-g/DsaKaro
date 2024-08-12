//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

//Position this line where user code will be pasted.
class Solution {
  public:
    int SumofMiddleElements(vector<int> &arr1, vector<int> &arr2) {
        // code here
        vector<int>nums;
        for(auto & ele : arr1){
            nums.push_back(ele);
        }
        for(auto & ele : arr2){
            nums.push_back(ele);
        }
        sort(nums.begin(), nums.end());
        // 
        int n =nums.size();
        // if 
        if(n%2==0){
            // even leght array so middle willbe the 
            int mid=n/2;
            
            int sum=nums[mid]+nums[mid-1];
            return sum;
        }else{
            int mid=n/2;
            int sum=nums[mid];
            return sum;
        }
    }
};

//{ Driver Code Starts.
//Back-end complete function template in C++

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr, brr;
        string input1;
        getline(cin, input1);
        stringstream ss1(input1);
        int number1;
        while (ss1 >> number1) {
            arr.push_back(number1);
        }
        string input2;
        getline(cin, input2);
        stringstream ss2(input2);
        int number2;
        while (ss2 >> number2) {
            brr.push_back(number2);
        }
        Solution ob;
        int res = ob.SumofMiddleElements(arr, brr);
        cout << res << endl;
    }
}
// } Driver Code Ends