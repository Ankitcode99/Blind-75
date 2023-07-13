class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        for(char ch:s){
            if(ch=='(' or ch=='{' or ch=='['){
                stack.push(ch);
            }else{
                switch(ch){
                    case ')': 
                        if(stack.size() && stack.top()=='('){
                            stack.pop();
                        }else{
                            return false;
                        }
                        break;
                    case '}':
                        if(stack.size() && stack.top()=='{'){
                            stack.pop();
                        }else{
                            return false;
                        }
                        break;
                    case ']':
                        if(stack.size() && stack.top()=='['){
                            stack.pop();
                        }else{
                            return false;
                        }
                        break;
                    default: return false;
                }
            }
        }
        return stack.size()==0;
    }
};