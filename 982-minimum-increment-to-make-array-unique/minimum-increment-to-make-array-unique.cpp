class Solution {
public:
    int minIncrementForUnique(vector<int>& A, int res = 0) {
  sort(begin(A), end(A));
  for (auto i = 1; i < A.size(); ++i) {
    res += max(0, A[i - 1] - A[i] + 1);
    A[i] += max(0, A[i - 1] - A[i] + 1);
  }
  return res;
 }
};