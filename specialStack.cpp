//didnt do anything extra from myself so still about only 50% knowledge of this (yes i cheated)
class SpecialStack {
    private:
    stack<int> s;
    int mini = INT_MAX;\

    public:       
    void push(int data) {
        if(s.empty()){
            mini = data;
            s.push(data);
        }
        else{
            if(data<mini){
                s.push(2*data - mini);
                mini = data;
            }
            else{
                s.push(data);
            }
        }
    }

    void pop() {
        if(s.empty()){
            return ;
        }
        int curr = s.top();
        s.pop();
        if(curr<mini){
            int val = 2*mini - curr;
            mini = val;   
        }
    }

    int top() {
        if(s.empty()){
            return -1;
        }
        int curr = s.top();
        if(curr<mini){
            return mini;
        }
        else{
            return curr;
        }
    }

    int getMin() {
        if(s.empty()){
            return -1;
        }
        return mini;
    }  
};
