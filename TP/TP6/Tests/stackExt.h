# include <iostream>
# include <stack>

using namespace std;

template <class T>
class StackExt {
public:
	StackExt() {};
	bool empty() const; 
	T &top();
	void pop();
	void push(const T & val);
	T &findMin();

private:
    std::stack<T> stack;
    std::stack<T> minStack;
};

// a alterar
template <class T> 
bool StackExt<T>::empty() const
{
    return stack.empty();
}

//a alterar
template <class T> 
T& StackExt<T>::top()
{
    return stack.top();
}

//a alterar
template <class T> 
void StackExt<T>::pop()
{
    if( !minStack.empty() && minStack.top() == stack.top()) minStack.pop();
    if( !stack.empty() ) stack.pop();
}

//a alterar
template <class T> 
void StackExt<T>::push(const T & val)
{
    if( minStack.empty() || val < minStack.top()) minStack.push(val);
    stack.push(val);
}

//a alterar
template <class T> 
T& StackExt<T>::findMin()
{
    return minStack.top();
}

