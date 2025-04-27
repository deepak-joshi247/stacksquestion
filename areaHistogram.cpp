//dont know how the fuck it is working though logic is right but still
class Solution {
vector<int> nextSmallerele(vector<int> arr, int n)
{
   stack<int> stack1;
   stack1.push(-1);
   vector<int> ans(n);

   for(int i=n-1;i>=0;i--){
       while(stack1.top() != -1 && arr[i]<=arr[stack1.top()]){ //since we want index in ans vector 
           stack1.pop();
       }
       ans[i] = stack1.top();
       stack1.push(i);
   }
   return ans;
}

vector<int> presmallerele(vector<int> arr, int n)
{
   stack<int> stack1;
   stack1.push(-1);
   vector<int > ans(n);

   for(int i=0; i<n; i++){
       while(stack1.top() != -1 && arr[i]<=arr[stack1.top()]){
           stack1.pop();
       }
       ans[i] = stack1.top();
       stack1.push(i);
   }
   return ans;
}   
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> next(n);
        next = nextSmallerele(heights, n);
        vector<int> pre(n);
        pre = presmallerele(heights,n);
        int area = INT_MIN;
        for(int i=0; i<n; i++){
            int l = heights[i];
            if(next[i]== -1){
                next[i] = n;
            }
            int width = next[i] - pre[i] - 1;
            int newarea = l*width;
            area = max(area,newarea);
        }
        return area;
    }
};
