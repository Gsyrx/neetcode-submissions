

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) {
            return false; // If total cards can't be divided evenly into groups
        }

        unordered_map<int, int> cardCount;
        
        // Count the frequency of each card
        for (int card : hand) {
            cardCount[card]++;
        }

        // Sort the hand to start forming groups from the smallest card
        sort(hand.begin(), hand.end());
        
        for (int card : hand) {
            if (cardCount[card] > 0) {
                // Try to form a group starting from this card
                for (int i = 0; i < groupSize; ++i) {
                    if (cardCount[card + i] <= 0) {
                        return false; // If any card in the sequence is not available
                    }
                    cardCount[card + i]--;
                }
            }
        }

        return true;
    }
};
