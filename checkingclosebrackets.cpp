void checkinstack(stack<char> &storebrackets,string s, int i){
    if(s[i]=='}'&&storebrackets.top()=='{'){
        storebrackets.pop();
        return;
    }
    if(s[i]==')'&&storebrackets.top()=='('){
        storebrackets.pop();
        return;
    }
    if(s[i]==']'&&storebrackets.top()=='['){
        storebrackets.pop();
        return;
    }
    else{
        return;
    }

}
bool isValidParenthesis(string s)
{
    stack<char> storebrackets;
    for(int i=0;i<s.size();i++){
        if(s[i]=='}'||s[i]==')'||s[i]==']'){
            if(storebrackets.empty()){ //if stack is already empty that means it started with close bracket
                return false;
            }
            checkinstack(storebrackets,s,i);
            
        }
        else{
            storebrackets.push(s[i]);
            
        }
    }
    if(storebrackets.empty()){
        return true;
    }
    else {
        return false;
    }
}
