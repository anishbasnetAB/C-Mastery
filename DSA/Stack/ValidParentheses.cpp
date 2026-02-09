class Solution {
public:
    bool isValid(string s) {
        stack<char> stk; //stack of char

        for( char c:s)
        {
            if(c=='{') stk.push('}');
            else if(c=='[') stk.push(']');
            else if( c=='(') stk.push(')');

            else
            {
                if(stk.empty() || stk.top()!=c) return false;
                stk.pop();
            }
        }
        return stk.empty();
    }
};

//Leetcode 20