class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n=piles.size();
      sort(piles.begin(),piles.end());
      int res=0;
      for(int i=n/3;i<n;i+=2){
        res+=piles[i];
      }
      return res;
    }
};