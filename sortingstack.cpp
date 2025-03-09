 //dont know how it runned but it gets TLE logic was correct but didnt understood 
 //why we place recursion at step 25
 
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

void sortingstack(stack<int> &stack){
	//base case 
	if(stack.empty()||stack.size()==1){
		return;
	}
	int max = stack.top();
	stack.pop();
	sortingstack(stack);
	if( stack.empty() || max< stack.top()){
		insertatbottom(stack,max);
		max = stack.top();
		sortingstack(stack);
		stack.pop();
		stack.push(max);
	}
	else{
		stack.push(max);	
	}
	return;
}

void sortStack(stack<int> &stack)
{
	if(stack.size()==0||stack.size()==1){
		return;
	}
	sortingstack(stack);
}
