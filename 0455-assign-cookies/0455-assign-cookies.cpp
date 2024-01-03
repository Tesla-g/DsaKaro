class Solution {
public:

int f(vector<int>&g,vector<int>&s){
  int cnt=0;
  sort(g.begin(),g.end());
  sort(s.begin(),s.end());
  int n=g.size(); int m=s.size();
  int i=0; int j=0;
  while(i<n && j<m){
    if(g[i]<=s[j]){
      cnt++;

      i++;
      // if the greed factor is lesser than the cookie siz

    }
    // if the gredd factor is greatr thatn th ecookie siz
    // all the othr value will also be greater o
    // then i will check for the othr cookie sizeooo
    // if the cookie is not prestn then just break that thing

    j++;
  }
  return cnt;

}
    int findContentChildren(vector<int>& g, vector<int>& s) {
        return f(g,s);
    }
};