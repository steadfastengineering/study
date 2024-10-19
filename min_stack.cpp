#include <iostream>
#include <climits>

using namespace std;

class Node
{
    public:
        int val = 0;
        Node* below = nullptr;
};

class MinStack 
{

private:
    int minimum = INT_MAX;
    
    Node* stack_top = nullptr;
    Node* stack_mins = nullptr;

public:
    MinStack(){ }
    
    void push(int val) 
    {
        // if stack is null, create element and save value, else add element on top of stack.
        if(stack_top == nullptr)
        { 
            stack_top = new Node();
            stack_top->val = val;
        }
        else
        {
            Node* new_top = new Node();
            new_top->val = val;
            new_top->below = stack_top;
            stack_top = new_top;
        }
        
        // if mins was null (empty stack) the val is the minimum, else add new minimum and save it on top of stack
        if(stack_mins == nullptr)
        {
            stack_mins = new Node();
            stack_mins->val = val;
            minimum = val;
        }
        else
        {
            if(val <= minimum)
            {
                // if the value inserted was less than the last min, keep it in the minimums stack
                Node* new_min_top = new Node();
                new_min_top->val = val;
                new_min_top->below = stack_mins;
                stack_mins = new_min_top;
                minimum = val;
            }
        }
    }
    
    void pop() 
    {
        if(stack_top == nullptr) return;

        int popped_val = stack_top->val;

        // remove top value
        Node* old_top = stack_top;
        stack_top = stack_top->below;
        delete old_top; 

        // update minimum
        if(popped_val == minimum)
        {
            Node* old_min_top = stack_mins;
            stack_mins = stack_mins->below;
            delete old_min_top;

            if(stack_mins == nullptr)
            {
                minimum = INT_MAX;
            }
            else
            {
                minimum = stack_mins->val;
            }
        }
    }
    
    int top() 
    {
        if(stack_top != nullptr) return stack_top->val; 

        return INT_MAX;
    }
    
    int getMin() 
    {
        return minimum;
    }
};


// Methods pop, top and getMin operations will always be called on non-empty stacks.

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 =    stack_top();
 * int param_4 = obj->getMin();
*/

void print_min_stack(MinStack* s)
{
    while(s->top() != INT_MAX)
    { 
        cout << "min:" << s->getMin() << " top:" << s->top() << " ";
        s->pop();
        cout << endl;
    }
}

int main()
{
    MinStack* ms = new MinStack();
    ms->push(6);
    ms->push(3);
    ms->push(5);
    ms->push(1);
    ms->push(33);
    ms->push(1);
    ms->push(0);

 
    print_min_stack(ms);

    return 0;
}