#include <bits/stdc++.h> 
class NStack{
private:
    int index;
    int *arr;
    int *next;
    int *top;
    int freespot = 0;//updates which each function not resets
public:
    // Initialize your data structure.
    NStack(int N, int S)
    {
        int s = S;
        int n = N;
        arr = new int[S];
        next = new int[S];
        top = new int[N];
        //intializing next
        for (int i = 0; i < s; i++)
        {
            if(i==s-1){
                next[i]=-1;
            }
            next[i] = i+1;
        }
        //intializing top
        for (int i = 0; i < n; i++)
        {
            top[i] = -1;
        }        
    }

    
    bool push(int x, int m)
    {
        if(freespot == -1){
            return false;
        }
       //find index
       index = freespot;
       //update freespot;
       freespot = next[index];
       //inserting in array
       arr[index] = x;
       //updating next
       next[index] = top[m-1];
       //update top
       top[m-1] = index;
       return true;
    }

   //reverse of push()
    int pop(int m)
    {
        if(top[m-1] == -1){
            return -1;
        }
        index = top[m-1];
        top[m-1] = next[index];
        next[index] = freespot;
        freespot = index;
        return arr[index];
    }
};
