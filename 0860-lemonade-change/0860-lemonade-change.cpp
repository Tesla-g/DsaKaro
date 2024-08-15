class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fivedollar = 0;
        int tendollar = 0;

        for (auto &ele : bills) {
            if (ele == 5) {
                fivedollar++;
            } else if (ele == 10) {
                if (fivedollar == 0) {
                    return false;
                }
                tendollar++;
                fivedollar--;
            } else if (ele == 20) {
                if (tendollar > 0 && fivedollar > 0) {
                    // Give one $10 and one $5 as change
                    tendollar--;
                    fivedollar--;
                } else if (fivedollar >= 3) {
                    // Give three $5 bills as change
                    fivedollar -= 3;
                } else {
                    return false;
                }
            }
        }
        
        return true;
    }
};
