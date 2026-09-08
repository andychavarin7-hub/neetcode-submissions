class MinStack {
public:
    std::stack<int> intStack{};
    std::stack<int> minValStack{};
    MinStack() {
        
    }
    
    void push(int val) {
        intStack.push(val);
        if(minValStack.empty()){
            minValStack.push(val);
        } else if(val <= minValStack.top()){
            minValStack.push(val);
        }
    }
    
    void pop() {
        int val=intStack.top();
        if(!intStack.empty()){
            intStack.pop();
        }
        if(!minValStack.empty() && val <= minValStack.top()){
            minValStack.pop();
        }
    }
    
    int top() {
        return intStack.top();
    }
    
    int getMin() {
        return minValStack.top();
    }
};
