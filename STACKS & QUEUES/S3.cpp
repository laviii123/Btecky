#include<bits/stdc++.h>
using namespace std;
/***********************CHECK FOR VALID PARENTHESIS*****************************************/
//SOLUTION 1:
bool isValidParenthesis(string s)
{
       stack<char>st;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('||s[i]=='{'||s[i]=='['||st.size()==0){
                st.push(s[i]);
            }
            else if((s[i]==')'&&st.top()=='(')||(s[i]=='}'&&st.top()=='{')||(s[i]==']'&&st.top()=='[')){
                st.pop();
            }
            else{
                 st.push(s[i]);
            }
        }
        if(st.size()==0){
            return true;
        }
        else{
            return false;
        }
}
//SOLUTION 2:
bool isValid(string s) {
        stack<char>st; 
        for(auto it: s) {
            if(it=='(' || it=='{' || it == '[') st.push(it); 
            else {
                if(st.size() == 0) return false; 
                char ch = st.top(); 
                st.pop(); 
                if((it == ')' and ch == '(') or  (it == ']' and ch == '[') or (it == '}' and ch == '{')) continue;
                else return false;
            }
        }
        return st.empty(); 
}