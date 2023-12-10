class Solution {
public:
vector<vector<int>> transpose(vector<vector<int>>& a) {
  int m=a.size();
  int n=a[0].size();
  vector<vector<int>>v(n,vector<int>(m,0));
  for(int j=0;j<n;j++){
    for(int i=0;i<m;i++){
      v[j][i]=a[i][j];
    }
  }
  return v;
        
}
};