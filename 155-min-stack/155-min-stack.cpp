class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> main, aux;
    MinStack() {
     
    }
    
    void push(int val) {
      if(main.empty()){
          main.push(val);
          aux.push(val);
      } 
    else if(val > aux.top()){
        main.push(val);  
          
      }else if(val <= aux.top()){
        main.push(val);
        aux.push(val);
    }
    }
    
    void pop() {
        if(main.empty()) return;
        if(main.top() == aux.top()){
            main.pop(); aux.pop();
        } 
        else main.pop();
    }
    
    int top() {
        return main.top();
    }
    
    int getMin() {
        return aux.top();
        
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */