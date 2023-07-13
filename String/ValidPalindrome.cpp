class Solution {
public:
    bool isPalindrome(string s) {
        string temp="";
        for(char x:s)
        {
            if(x>='a' and x<='z')
                temp+=x;
            else if(x>='A' and x<='Z')
                temp+=(char)((int)x + 32);
            else if(x>='0' and x<='9')
                temp+=x;
        }
        
        int j=temp.size()-1,i=0;
        while(i<j)
        {
            if(temp[i]==temp[j])
                i++,j--;
            else
                return false;
        }
        return true;
    }
};