class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int len=0;
        int sum=0;
        int zero=0;
        int l=0,r=0;
        while(r<nums.size()){
            if(nums[r]==0){
                zero++;
            }
            if(zero<=k){
                len=(r-l+1);
                sum=max(sum,len);
            }else{
                if(nums[l]==0){
                    zero--;
                    l++;
                }else{
                    l++;
                }
            }
            r++;
        }
        return sum;
    }
};