
class Solution {
public:



int min_unfairness = INT_MAX;

void cookie(vector<int>& a, const vector<int>& c) {
    if (c.size() == 0) {
        int val = *max_element(a.begin(), a.end());
        if (val < min_unfairness) {
            min_unfairness = val;
        }
        return;
    }

    for (int i = 0; i < a.size(); i++) {
        if (a[i] + c[0] < min_unfairness) { // Pruning: Only explore if it can lead to a smaller unfairness
            vector<int> ip = a;
            vector<int> c_copy = c;

            ip[i] += c_copy[0];
            c_copy.erase(c_copy.begin());

            cookie(ip, c_copy);
        }
    }
}

    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> a(k, 0);
        cookie(a, cookies);
        return min_unfairness;
    }
};


