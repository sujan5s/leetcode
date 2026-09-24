class Solution {
public:
    string minWindow(string s, string t) {
        int minlen=INT_MAX,count=0,sind=-1;
        unordered_map<char,int> mp;
        for(int i=0;i<t.size();i++){
            mp[t[i]]++;
        }
        int l=0,r=0;
        while(r<s.size()){
            if(mp[s[r]]>0){
                
                count ++;
            }
            mp[s[r]]--;
            while(count==t.size()){
                if(r-l+1<minlen){
                    minlen = r-l+1;
                    sind=l;
                }
                mp[s[l]]++;
                if(mp[s[l]]>0){
                    count--;
                }
                l++;
            }
            r++;
        }
        return sind==-1 ? "": s.substr(sind,minlen);
    }
};