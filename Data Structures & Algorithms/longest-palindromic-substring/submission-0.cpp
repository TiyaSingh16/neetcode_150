class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if (n < 2) return s;

        int start = 0, maxLen = 0;

        for (int i = 0; i < n; i++) {
            // Case 1: Odd length (center is s[i])
            expand(s, i, i, start, maxLen);
            
            // Case 2: Even length (center is between s[i] and s[i+1])
            expand(s, i, i + 1, start, maxLen);
        }

        return s.substr(start, maxLen);
    }

private:
    void expand(string& s, int l, int r, int& start, int& maxLen) {
        // Expand outward as long as characters match and we are in bounds
        while (l >= 0 && r < s.length() && s[l] == s[r]) {
            int currentLen = r - l + 1;
            if (currentLen > maxLen) {
                start = l;
                maxLen = currentLen;
            }
            l--;
            r++;
        }
    }
};