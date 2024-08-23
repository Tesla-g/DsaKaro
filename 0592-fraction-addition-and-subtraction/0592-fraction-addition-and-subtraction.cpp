#include <numeric>  // For std::gcd

class Solution {
public:
    string fractionAddition(string exp) {
        int numerator = 0;   // Final numerator
        int denominator = 1; // Final denominator
        
        int i = 0;
        int n = exp.size();
        
        while (i < n) {
            int sign = 1; // Default to positive
            
            // Check for sign
            if (exp[i] == '+' || exp[i] == '-') {
                if (exp[i] == '-') {
                    sign = -1;
                }
                i++;
            }
            
            // Parse the numerator
            int num = 0;
            while (i < n && isdigit(exp[i])) {
                num = num * 10 + (exp[i] - '0');
                i++;
            }
            num *= sign; // Apply sign to the numerator
            
            // Skip the '/' character
            if (i < n && exp[i] == '/') {
                i++;
            }
            
            // Parse the denominator
            int den = 0;
            while (i < n && isdigit(exp[i])) {
                den = den * 10 + (exp[i] - '0');
                i++;
            }
            
            // Add the current fraction to the accumulated fraction
            numerator = numerator * den + num * denominator;
            denominator *= den;
            
            // Simplify the fraction
            int gcd = std::gcd(abs(numerator), denominator);
            numerator /= gcd;
            denominator /= gcd;
        }
        
        return to_string(numerator) + "/" + to_string(denominator);
    }
};
