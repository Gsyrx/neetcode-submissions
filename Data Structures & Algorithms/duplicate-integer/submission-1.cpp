class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        // unordered_set<int> seen;
        // for(int num: nums){
        //     if(seen.count(num)){
        //         return true;
        //     }

        //     seen.insert(num);
        // }

        // return false;

        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        
        for(auto x = mp.begin(); x!=mp.end();x++){
            if(x->second>1){
            return true;
            }
        }
        
        return false;
    }
};
