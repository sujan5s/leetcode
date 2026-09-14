class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0,r=0,maxlen=0,maxf=0;
        unordered_map<int,int> mp;
        while(r<s.size()){
            mp[s[r]-'A']++;
            maxf = max(maxf,mp[s[r]-'A']);
            while((r-l+1)-maxf>k){
                mp[s[l]-'A']--;
                l++;
            }
    
                maxlen = max(maxlen,(r-l+1));
                r++;
        }
        return maxlen;
    }
};