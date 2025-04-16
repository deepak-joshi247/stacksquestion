//this question is to check right side first smallest element not smallest at right side
#include<stack>
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
   stack<int> stack1;
   stack1.push(-1);
   vector<int > ans(n);

   for(int i=n-1;i>=0;i--){
       while(arr[i]<=stack1.top()){
           stack1.pop();
       }
       ans[i] = stack1.top();
       stack1.push(arr[i]);
   }
   return ans;
}
