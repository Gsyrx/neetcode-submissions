class Solution {
public:
    // Encode a list of strings into a single string
    string encode(vector<string>& strs) {
        string encoded = "";
        for (const string& str : strs) {
            encoded += to_string(str.size()) + '#' + str; 
            // Format: "length#string"
        }
        return encoded;
    }

    // Decode a single string back to a list of strings
    vector<string> decode(string s) {
        vector<string> decoded;
        int i = 0;

        while (i < s.size()) {
            int j = i;
            // Find the position of the delimiter '#'
            while (s[j] != '#') {
                j++;
            }

            // Extract the length of the next string
            int length = stoi(s.substr(i, j - i)); 

            // Extract the actual string
            string str = s.substr(j + 1, length); 

            decoded.push_back(str);

            // Move to the start of the next encoded part
            i = j + 1 + length;
        }

        return decoded;
    }
};
