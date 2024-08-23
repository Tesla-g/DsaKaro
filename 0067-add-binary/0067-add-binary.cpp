class Solution {
public:
    string addBinary(string a, string b) {
        stack<int> s1, s2;

        // Push digits into the stacks
        for (char ele : a) {
            s1.push(ele - '0');
        }
        for (char ele : b) {
            s2.push(ele - '0');
        }

        int carry = 0;
        stack<int> ans;

        // Process both stacks
        while (!s1.empty() || !s2.empty() || carry) {
            int sum = carry;
            if (!s1.empty()) {
                sum += s1.top();
                s1.pop();
            }
            if (!s2.empty()) {
                sum += s2.top();
                s2.pop();
            }

            ans.push(sum % 2);  // Push the binary digit
            carry = sum / 2;     // Update carry
        }

        // Convert stack to string
        string result = "";
        while (!ans.empty()) {
            result += to_string(ans.top());
            ans.pop();
        }

        return result;
    }
};
