class Stack {
public:
    queue<int> input, tmp;
    // Push element x onto stack.
    void push(int x) {
        input.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        while(input.size()>1){
            tmp.push(input.front());
            input.pop();
        }
        input.pop();
        while(!tmp.empty()){
            input.push(tmp.front());
            tmp.pop();
        }
    }

    // Get the top element.
    int top() {
        return input.back();
    }

    // Return whether the stack is empty.
    bool empty() {
        return input.empty();
    }
};
