class Solution {
public:
    string longestPalindrome(string s) {
        int sz = s.size();
        vector<vector<bool>> dp(sz+1,vector<bool>(sz+1,0));
        int st=-1,en=-1;
        for(int gap=0;gap<sz;gap++){
            for(int l=0,r=gap;r<sz;l++,r++){
                if(l==r){
                    dp[l][r]=true;
                }else if(gap==1){
                    dp[l][r]=(s[l]==s[r]);
                }else{
                    dp[l][r]=(s[l]==s[r] and dp[l+1][r-1]);
                }
                
                if(dp[l][r]){
                    st=l,en=r;
                }
            }
        }
        string ans = s.substr(st,en-st+1);
        return ans;
        
    }
};