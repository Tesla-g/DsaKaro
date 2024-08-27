//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    /*You are required to complete this method */
    int findMaxDiff(vector<int> &arr) {
        // Your code here
        // nearest left smaller and nearst right smaller 
        int ans =INT_MIN;
        for(int i = 0; i<arr.size(); i++){
            // fnd the left smaller than this 
            // find the right smaller than this 
            int currentelement= arr[i];
            int j = i-1;
            int leftsmaller=0;
            while(j>=0 ){
                if(currentelement>arr[j]){
                    leftsmaller=arr[j];
                    break;
                }
                j--;
            }
            
            int k = i+1; 
            int rightsmaller=0;
            while(k<arr.size()){
                if(arr[i]>arr[k]){
                    rightsmaller=arr[k];
                    break;
                }
                k++;
            }
            ans=max(ans, std::abs(leftsmaller-rightsmaller));
            
        }
        return ans; 
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