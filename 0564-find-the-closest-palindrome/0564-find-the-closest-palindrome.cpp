class Solution {
public:
    #define LL long long

    LL convertpalindrome(LL m) {
        string s = to_string(m);
        LL n = s.size();
        LL l = 0, r = n - 1;
        while (l <= r) {
            s[r--] = s[l++];
        }
        return stoll(s);
    }

    LL prevpalindrome(LL num) {
        LL l = 1, r = num - 1;
        LL ans = -1;
        while (l <= r) {
            LL m = l + (r - l) / 2;
            LL palin = convertpalindrome(m);
            if (palin < num) {
                ans = palin;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return ans;
    }

    LL nextpalindrome(LL num) {
        LL l = num + 1, r = 1e18;
        LL ans = 0;
        while (l <= r) {
            LL m = l + (r - l) / 2;
            LL palin = convertpalindrome(m);
            if (palin > num) {
                ans = palin;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return ans;
    }

    string nearestPalindromic(string n) {
        LL num = stoll(n);
        if(num==1){
            return to_string(0);
        }
        LL nxt = nextpalindrome(num);
        LL prv = prevpalindrome(num);

        if (abs(nxt - num) >= abs(prv - num)) {
            return to_string(prv);
        }
        return to_string(nxt);
    }
};
