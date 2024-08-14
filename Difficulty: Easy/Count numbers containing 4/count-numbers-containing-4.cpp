//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool isfourexist(int num){
        while(num>0){
            int ld=num%10;
            if(ld==4){
                return true;
            }
            num=num/10;
        }
        return false;
    }
    int countNumberswith4(int n) {
        // code here
        long long cnt=0;
        for(long long int i=1; i<=n; i++){
            if(isfourexist(i)){ // time complexity is n2;
                cnt++;
            }
        }
        return cnt;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        Solution obj;
        int res = obj.countNumberswith4(n);

        cout << res << endl;
    }
}

// } Driver Code Ends