/*Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
 

Example 1:

Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]

Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2*/


/*ALGO
Push(x) : Inserts x at the top of stack. 
 

If stack is empty, insert x into the stack and make minEle equal to x.
If stack is not empty, compare x with minEle. Two cases arise:
If x is greater than or equal to minEle, simply insert x.
If x is less than minEle, insert (2*x – minEle) into the stack and make minEle equal to x. For example, let previous minEle was 3. Now we want to insert 2. We update minEle as 2 and insert 2*2 – 3 = 1 into the stack.
Pop() : Removes an element from top of stack. 
 



Remove element from top. Let the removed element be y. Two cases arise:
If y is greater than or equal to minEle, the minimum element in the stack is still minEle.
If y is less than minEle, the minimum element now becomes (2*minEle – y), so update (minEle = 2*minEle – y). This is where we retrieve previous minimum from current minimum and its value in stack. For example, let the element to be removed be 1 and minEle be 2. We remove 1 and update minEle as 2*2 – 1 = 3.
Important Points: 
 

Stack doesn’t hold actual value of an element if it is minimum so far.
Actual minimum element is always stored in minEle*/



class MinStack {
    stack<long long> st; 
    long long mini; 
public:
    /** initialize your data structure here. */
    MinStack() {
        while(st.empty() == false) st.pop(); 
        mini = INT_MAX; 
    }
    
    void push(int value) {
        long long val = value; 
        if(st.empty()) {
            mini = val; 
            st.push(val); 
        }
        else {
            if(val < mini) {
                st.push(2 * val- mini);
                mini = val; 
            }
            else {
                st.push(val); 
            }
        }
    }
    
    void pop() {
        if(st.empty()) return; 
        long long el = st.top(); 
        st.pop(); 
        
        if(el < mini) {
            mini = 2 * mini - el; 
        }
    }
    
    int top() {
        if(st.empty()) return -1; 
        
        long long el = st.top(); 
        if(el < mini) return mini; 
        return el; 
    }
    
    int getMin() {
        return mini; 
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