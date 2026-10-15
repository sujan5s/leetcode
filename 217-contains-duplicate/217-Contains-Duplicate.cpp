class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int ,int>mp;
        if(nums.size()<=1){
            return false;
        }
        for(int i=0;i<nums.size();i++){
           
            if(mp.count(nums[i])>0){
                return true;
            }
             mp[nums[i]]++;
        }
        return false;
    }
};