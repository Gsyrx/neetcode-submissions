class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        // To track if we can select each value of the target from any triplet
        bool canFormTarget[3] = {false, false, false}; 
        
        // Iterate through each triplet
        for (auto& triplet : triplets) {
            // Check if the current triplet can contribute to the target
            // It can only contribute if each value in the triplet is <= the corresponding value in the target
            if (triplet[0] <= target[0] && triplet[1] <= target[1] && triplet[2] <= target[2]) {
                // Mark the positions in the target that can be fulfilled
                if (triplet[0] == target[0]) canFormTarget[0] = true;
                if (triplet[1] == target[1]) canFormTarget[1] = true;
                if (triplet[2] == target[2]) canFormTarget[2] = true;
            }
        }
        
        // If all positions in the target are fulfilled, return true
        return canFormTarget[0] && canFormTarget[1] && canFormTarget[2];
    }
};
