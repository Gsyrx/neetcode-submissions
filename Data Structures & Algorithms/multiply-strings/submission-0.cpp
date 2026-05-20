class Solution {
public:
    string multiply(string num1, string num2) {
        // Handle edge case where either number is 0
        if (num1 == "0" || num2 == "0") return "0";
        
        int m = num1.size();
        int n = num2.size();
        
        // Initialize an array to store the result of the multiplication
        vector<int> result(m + n, 0);
        
        // Reverse both numbers to make multiplication easier
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                // Multiply digits and add to the corresponding position in the result
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int sum = mul + result[i + j + 1];
                
                // Update the result array, handling the carry
                result[i + j + 1] = sum % 10;
                result[i + j] += sum / 10;
            }
        }
        
        // Convert result array to string
        string res = "";
        for (int num : result) {
            if (!(res.empty() && num == 0)) { // Skip leading zeros
                res += to_string(num);
            }
        }
        
        return res;
    }
};
