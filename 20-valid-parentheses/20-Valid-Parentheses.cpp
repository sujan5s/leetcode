class Solution {
public:
    bool isValid(string s) {
        stack<string> st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push("(");
            }
            if(s[i]=='['){
                st.push("[");
            }
            if(s[i]=='{'){
                st.push("{");
            }
            if(s[i]==')' && st.top()=="("){
                st.pop();
            }
            if(s[i]==']' && st.top()=="["){
                st.pop();
            }
            if(s[i]=='}' && st.top()=="{"){
                st.pop();
            }
            
        }
        if(st.empty()){
            return true;
        }
        return false;
    }
};