class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char ,int> mp;
        int count=0;
        int l=0,r=0;
        while(r<s.size()){
            mp[s[r]]++;
            while(mp.size()>=3){
                count+=(s.size()-r);
                mp[s[l]]--;
                if(mp[s[l]]==0){
                    mp.erase(s[l]);
                }
                l++;
            }
            r++;
        }
        /*
        for(int i=0;i<s.size();i++){
            for(int j=i;j<s.size();j++){
                mp[s[j]]++;
                if(mp.size()>=3){
                    count++;
                }
            }
            mp.clear();
        }
        */
        return count;
    }
};