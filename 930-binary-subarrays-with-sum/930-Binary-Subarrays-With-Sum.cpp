class Solution {
public:

    int setGoal(vector<int>& nums, int goal){
        int l=0,r=0,count=0,ans=0;
        if(goal<0){
            return 0;
        }
        while(r<nums.size()){
            count+=nums[r];
            while(count>goal){
                count-=nums[l];
                l++;
            }
            ans+=(r-l+1);
            r++;
        }
        return ans;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return setGoal(nums,goal)-setGoal(nums,goal-1);
    }
};