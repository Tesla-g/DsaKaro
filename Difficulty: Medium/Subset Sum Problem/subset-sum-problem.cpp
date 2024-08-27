//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
// For memset

int t[101][10001]; // Adjust the size based on the problem constraints

bool solve(int i, int currsum, int &target, std::vector<int>& arr) {
   
   if (currsum == target) {
        return true; 
    }
    if (currsum > target || i >= arr.size()) {
        return false; 
    }
    
    

    if (t[i][currsum] != -1) {
        return t[i][currsum];
    }

    // Option 1: Include the current element in the sum
    bool res= false;
    if(arr[i]<=target){
       res = solve(i + 1, currsum + arr[i], target, arr);  

    }
    // Option 2: Exclude the current element from the sum
    bool res2 = solve(i + 1, currsum, target, arr);

    // Store the result in the memoization table
    return t[i][currsum] = (res || res2); 
}

bool isSubsetSum(std::vector<int>& arr, int target) {
    memset(t, -1, sizeof(t)); // Initialize memoization table with -1
    return solve(0, 0, target, arr);
}

};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends