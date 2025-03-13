#include <bits/stdc++.h> 
//wont pass on codingninja platform even though i think code is right
bool findRedundantBrackets(string &s)
{
    if(s.size()==0){
        return false;
    }
    if(s.size()==1){
        return true;
    }
    bool ans = false;
    stack<char> stackofs;
    for(int i=0;i<s.size();i++){
        if(s[i]=='('){
            stackofs.push(s[i]);
        }
        if(s[i] == '+' || s[i] == '-' || s[i] == '*' ||s[i]  == '/'){
            stackofs.push(s[i]);
        }
        if(s[i]==')'){
            char top = stackofs.top();
           if(top != '+' && top != '-' && top != '*' && top != '/'){
               stackofs.pop();
               ans = true;
           }
           else{
               ans = false;
               stackofs.pop();
           }
        }
    }
    return ans;
}
