class Solution {
  public:
    int celebrity(vector<vector<int> >& mat) {
        int n = mat.size();
        int candidate;
        //using stack
        stack<int> s;
        for(int i=0;i<n;i++){
            s.push(i);
        }
        // elimination process
        while(s.size()>1){
            int A = s.top();
            s.pop();
            int B = s.top();
            s.pop();
            if(mat[A][B]==1){
                //A isn't a celeb
                s.push(B);
            }
            else{
                s.push(A);
            }
        }
        if(s.empty()){
            return -1;
        }
        candidate = s.top();
        //final check
        for(int i=0;i<n;i++){
            if(candidate == i){
                continue;
            }
            if(mat[i][candidate]==0 || mat[candidate][i]==1){
                return -1;
            }
        }
        return candidate;
    }
};
