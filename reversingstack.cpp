 void insertatbottom(stack<int>& myStack, int x){
    //base case
    if(myStack.empty()){
        myStack.push(x);
        return;
    }
    int temp = myStack.top(); //The memory location for temp is unique for each call of the function
    myStack.pop();
    //recursion
    insertatbottom(myStack,x);
    myStack.push(temp); //after putting x last we put thing back again
    return;
    
}
 void reversingstack(stack<int>& myStack){
    //base case
    if(myStack.empty()){
        return;
    }

    int x = myStack.top(); 
    myStack.pop();
    //recursion
    reversingstack(myStack);
    insertatbottom(myStack,x);
    return;
    
}
void reverseStack(stack<int> &stack) {
    reversingstack(stack);
    
}
