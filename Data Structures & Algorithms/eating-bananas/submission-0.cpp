class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // Set the bounds for binary search
        int left = 1, right = *max_element(piles.begin(), piles.end());
        
        // Binary search for the minimum speed
        while (left < right) {
            int mid = left + (right - left) / 2;
            int hours = 0;
            
            // Calculate the total hours Koko would take at speed `mid`
            for (int pile : piles) {
                hours += (pile + mid - 1) / mid;  // Equivalent to ceil(pile / mid)
            }
            
            // If the total hours exceed `h`, we need to increase the speed
            if (hours > h) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        
        return left;
    }
};
