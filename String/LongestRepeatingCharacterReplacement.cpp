class Solution {
public:
    int characterReplacement(string s, int k) {
        int size = s.size(); int ret = 0;
        vector<int> count(26, 0);
        int start = 0; int end = 0; int localMaxFreq = 0; 
        for(; end<size; end++){
            count[s[end]-'A'] += 1;
            localMaxFreq = max(localMaxFreq, count[s[end]-'A']);
            if((end-start+1)-localMaxFreq > k) {
                ret = max(ret, (end-start));
                count[s[start]-'A'] -= 1;
                start += 1;
                localMaxFreq = *(max_element(count.begin(), count.end()));
            }
        }
        return max(ret, end-start);
    }
};