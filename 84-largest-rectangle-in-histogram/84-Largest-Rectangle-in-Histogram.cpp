class Solution {
public:

    vector<int> findNSE(vector<int>& heights){
        stack<int> st;
        vector<int> ans(heights.size(),heights.size());
        for(int i=heights.size()-1;i>=0;i--){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(!st.empty()){
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }

    vector<int> findPSE(vector<int>& heights){
        stack<int> st;
        vector<int> ans(heights.size(),-1);
        for(int i=0;i<heights.size();i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(!st.empty()){
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {
        vector<int> nse = findNSE(heights);
        vector<int> pse = findPSE(heights);
        int maxi = 0;
        for(int i=0;i<heights.size();i++){
            maxi = max(maxi,heights[i]*(nse[i]-pse[i]-1));
        }
        return maxi;
    }
};