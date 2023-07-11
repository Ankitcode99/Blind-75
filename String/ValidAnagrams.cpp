class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s==t) return true;
        if(s.size()!=t.size()) return false;
        int sz = s.size();
        int charMap[26]={0};
        for(int idx=0;idx<sz;idx++){
            charMap[s[idx]-'a']++;
            charMap[t[idx]-'a']--;
        }
        for(int idx=0;idx<26;idx++) {
            if(charMap[idx]!=0)
                return false;
        }
        return true;
    }
};