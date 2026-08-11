class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int , int> mp;
            for(int j=nums2.size()-1;j>=0;j--){
                while(!st.empty() && st.top()<=nums2[j]){
                    st.pop();
                }
                if(st.empty()){
                    mp[nums2[j]]=-1;
                } else {
                    mp[nums2[j]]=st.top();
                }
                st.push(nums2[j]);
            }
            vector<int> ans;
            for(int x:nums1){
                ans.push_back(mp[x]);
            }
        return ans;
    }
};