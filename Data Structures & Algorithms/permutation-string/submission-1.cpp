class Solution {
public:
    bool isfreqsame(int freq1[], int freq2[]) {
        for(int i = 0; i < 26; i++){
            if (freq1[i] != freq2[i]){
                return false;
            }
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        int n1 = s1.length();
        int n2 = s2.length();
        
        if (n1 > n2) {
            return false;
        }

        int freqs1[26] = {0};
        for (char c : s1) {
            freqs1[c - 'a']++;
        }
        
        int winfreq[26] = {0};
        
        // Initialize the first window
        for (int i = 0; i < n1; i++) {
            winfreq[s2[i] - 'a']++;
        }
        
        if (isfreqsame(winfreq, freqs1)) {
            return true;
        }

        // Slide the window
        for (int r = n1; r < n2; r++) {
            // Add the new character on the right
            winfreq[s2[r] - 'a']++;
            
            // Remove the character leaving on the left (at index r - n1)
            winfreq[s2[r - n1] - 'a']--; 

            if (isfreqsame(winfreq, freqs1)) {
                return true;
            }
        }

        return false;
    }
};