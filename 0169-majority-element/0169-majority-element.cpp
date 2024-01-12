
class Solution {
public:
    int countmostfreq(vector<int>&v) {
  sort(v.begin(),v.end());
  int n = v.size();
  if (n == 0) {
    return -1;
  }

  if (n == 1) {
    return v[0];
  }

  int cnt = 1;
  int candidate = v[0];
  int prevCnt = 0;
  int mostfreq = candidate;

  for (int i = 1; i < n; i++) {
    if (v[i] == candidate) {
      cnt++;
    } else {
      if (prevCnt < cnt) {
        prevCnt = cnt;
        mostfreq = candidate;
      }
      cnt = 1;
      candidate = v[i];
    }
  }

  // Handle the last element/group
  if (prevCnt < cnt) {
    mostfreq = candidate;
  }
  return mostfreq;
}


    int majorityElement(vector<int>& nums) {
      return countmostfreq(nums);
    }
};