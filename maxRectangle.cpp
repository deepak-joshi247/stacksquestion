class Solution {
  private :
    vector<int> nextSmallerele(int* arr, int n)
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
    
    vector<int> presmallerele(int* arr, int n)
        {
           stack<int> stack1;
           stack1.push(-1);
           vector<int> ans(n);
        
           for(int i=0; i<n; i++){
               while(stack1.top() != -1 && arr[i]<=arr[stack1.top()]){
                   stack1.pop();
               }
               ans[i] = stack1.top();
               stack1.push(i);
           }
           return ans;
        } 
        
    int largestRectangleArea(int* heights,int n) {
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
    
  public:
    int maxArea(vector<vector<int>> &mat) {
        int n = mat.size();
        int m = mat[0].size();
        //area of 1st row
        //dont know why but .data() is imp
        int area = largestRectangleArea(mat[0].data(),m);
        //adding rest row
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j] != 0){
                    mat[i][j] = mat[i][j] + mat[i-1][j];
                }
            }
            area = max(area,largestRectangleArea(mat[i].data(),m));
        }
        return area;
    }
};
