class MyQueue {
    stack<int> inputStack;
    stack<int> outputStack;
    void transfer(){
        if(outputStack.empty()){
            while(!inputStack.empty()){
                outputStack.push(inputStack.top());
                inputStack.pop();
            }
        }
    }
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        inputStack.push(x);
    }
    
    int pop() {
        transfer();
        int res=outputStack.top();
        outputStack.pop();
        return res;
    }
    
    int peek() {
        transfer();
        return outputStack.top();
    }
    
    bool empty() {
        return outputStack.empty() && inputStack.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */