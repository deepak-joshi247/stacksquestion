 void I_summonrecursion(stack<int>& myStack, int x){
    //base case
    if(myStack.empty()){
        myStack.push(x);
        return;
    }
    int temp = myStack.top(); //The memory location for temp is unique for each call of the function
    myStack.pop();
    //recursion
    I_summonrecursion(myStack,x);
    myStack.push(temp); //after putting x last we put thing back again
    return;
    
}
stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    I_summonrecursion(myStack,x);
    return myStack;
}
