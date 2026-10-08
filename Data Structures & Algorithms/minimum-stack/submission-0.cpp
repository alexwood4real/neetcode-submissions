class MinStack {
private:
    /* (value, current min) */
    vector<pair<int, int>> stk;

public:
    MinStack() {
        /* constructor */
    }
    
    void push(int value) {
        /* set the min value*/
        int curr_min = stk.empty() ? value : min( value, stk.back().second );
        
        /* push to the stack */
        stk.emplace_back( value, curr_min );
    }
    
    void pop() {
        /* removes last element if stack is empty */
        if( !stk.empty() )
            {
            stk.pop_back();
            }
    }
    
    int top() {
        /* returns value of current top */
        return stk.back().first;
    }
    
    int getMin() {
        /* returns minimum of current top */
        return stk.back().second;
    }
};