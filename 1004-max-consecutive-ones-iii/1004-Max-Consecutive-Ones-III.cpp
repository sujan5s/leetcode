class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int len=0;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            int zero=0;
            int j=i;
            while(j!=nums.size()){
                if(nums[j]==0){
                    zero++;
                }
                if(zero<=k){
                    len=(j-i+1);
                    sum=max(sum,len);
                }else{
                    break;
                }
                j++;
            }
            if(j==nums.size()){
                break;
            }
        }
        return sum;
    }
};