class Solution {
public:
    bool isAnagram(string s, string t) {
        
    // if (s.length() != t.length()) {
    //     return false; // If lengths differ, they cannot be anagrams
    // }

    // unordered_map<char, int> count;

    // // Count frequencies of characters in `s`
    // for (char c : s) {
    //     count[c]++;
    // }

    // // Subtract frequencies using characters in `t`
    // for (char c : t) {
    //     if (count.find(c) == count.end() || count[c] == 0) {
    //         return false; // If `t` has extra or unmatched characters
    //     }
    //     count[c]--;
    // }

    // return true; // All character frequencies matched

    int count[256] = {0};
      if(s.size()!=t.size()){
        return false;
      }
      
      for(int i=0;i<s.size();i++){
        count[s[i]]++;
        count[t[i]]--;
      }
      
      for(int i=0;i<256;i++){
        if(count[i]!=0){
          return false;
        }
      }
      
      return true;
    }
};
