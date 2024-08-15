//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    #define ll long long 
    public:
    //Function to count the number of ways in which frog can reach the top.
  
    long long countWays(int n)
    { const ll mod=1000000007;
       vector<long long>vec(n+1,0);
       vec[0]=1;
       vec[1]=1;
       vec[2]=2;
       for(size_t i =3; i<vec.size(); ++i){
           vec[i]=(vec[i-1]%mod+vec[i-2]%mod+vec[i-3]%mod)%mod;
       }
        return vec[n];
        
    }
};


//{ Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}

// } Driver Code Ends