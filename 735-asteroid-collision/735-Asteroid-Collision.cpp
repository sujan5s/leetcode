class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int i=0;
        
        stack<int> st;
        while(i<asteroids.size()){
            bool alive = true;
            if(st.empty()){
                st.push(asteroids[i]);
                i++;
            } else if(st.top()>0 && asteroids[i]>0){
                st.push(asteroids[i]);
                i++;
            } else {
                while(!st.empty() && st.top()>0 && asteroids[i]<0){
                    if(abs(st.top()) > abs(asteroids[i])){
                        i++;
                        alive=false;
                        break;
                    } else if (abs(st.top()) < abs(asteroids[i])){
                            st.pop();
                    } else {
                        st.pop();
                        i++;
                        alive = false;
                        break;
                    }
                }
                if(alive == true){
                    st.push(asteroids[i]);
                    i++;
                }
            }
        }
        vector<int> ans;

while(!st.empty()){
    ans.push_back(st.top());
    st.pop();
}

reverse(ans.begin(), ans.end());

return ans;
    }
};