//detailed version
class Solution {
public:
    string minWindow(string s, string t) {
	    vector<int> m(128, 0);
	    // Statistic for count of char in t
	    for (auto c : t) 
            m[c]++;
	    // counter represents the number of chars of t to be found in s.
	    int start = 0, end = 0, counter = t.size(), minStart = 0, minLen = INT_MAX;
	    int size = s.size(); 
	
	    while (end < size) {
		    if (m[s[end]] > 0)
			    counter--;
				m[s[end]]--;
		    end++;
		    while (counter == 0) {
			    if (end - start < minLen) {
				    minStart = start;
				    minLen = end - start;
			    }
			    m[s[start]]++;
			    if (m[s[start]] > 0)
				    counter++;
			    start++;
		    }
	    }
	    if (minLen != INT_MAX)
		    return s.substr(minStart, minLen);
	    return "";
    }
};