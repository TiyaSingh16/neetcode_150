class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;
        unordered_map<int,int> hash;
        for(int i:hand){
            hash[i]++;
        }
        sort(hand.begin(), hand.end());

        for (int card : hand) {
            if (hash[card] > 0) { // Only start a group if this card hasn't been used
                for (int i = 0; i < groupSize; i++) {
                    if (hash[card + i] <= 0) return false;
                    hash[card + i]--;
                }
            }
        }
        return true;
    }
};
