#include <bits/stdc++.h> 
class TwoStack {
        int *arr;
        int size;
        int top1 ;
        int top2;

public:

    // Initialize TwoStack.
    TwoStack(int s) {
        
        size = s;
        arr = new int[size];
        top1 = -1; //to remeber the top data of stack1
         top2 = size;; //to remeber the top data of stack2
        // i am making top1 move from left to right and opp for top2 for space perfect use.
    }
    
    // Push in stack 1.
    void push1(int num) {
        if(top2 - top1 > 1){ 
            top1++;
            arr[top1] = num; 
        }
    }

    // Push in stack 2.
    void push2(int num) {
         if(top2 - top1 > 1){ 
            top2--;
            arr[top2] = num; 
        }
    }

    // Pop from stack 1 and return popped element.
    int pop1() {
        if(top1>=0){
            int ans = arr[top1];
            top1--;
            return ans;
        }
        else{
            return -1;
        }
    }

    // Pop from stack 2 and return popped element.
    int pop2() {
         if(top2<size){
            int ans = arr[top2];
            top2++;
            return ans;
        }
        else{
            return -1;
        }
    }
};
