# LeetCode —— 232. 用栈实现队列

## 题目

![20210305074613](https://raw.githubusercontent.com/AZMDDY/imgs/master/img/20210305074613.png)

## 思路

使用两个栈来模拟队列，一个作为输入栈，一个作为输出栈，当输入栈为空时，将输入栈中的所有元素依次弹出并压入输出栈。

## 实现

### C++

```cpp
class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {}

    /** Push element x to the back of queue. */
    void push(int x) { inStk.push(x); }

    /** Removes the element from in front of queue and returns that element. */
    int pop()
    {
        if (outStk.empty()) {
            in2out();
        }
        int ans = outStk.top();
        outStk.pop();
        return ans;
    }

    /** Get the front element. */
    int peek()
    {
        if (outStk.empty()) {
            in2out();
        }
        return outStk.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() { return inStk.empty() && outStk.empty(); }

private:
    stack<int> inStk;
    stack<int> outStk;

    void in2out()
    {
        while (!inStk.empty()) {
            outStk.push(inStk.top());
            inStk.pop();
        }
    }
};
```

### Go

```go
type MyQueue struct {
	inStk, outStk []int
}

func (this *MyQueue) in2out() {
	for len(this.inStk) > 0 {
		this.outStk = append(this.outStk, this.inStk[len(this.inStk)-1])
		this.inStk = this.inStk[:len(this.inStk)-1]
	}
}

/** Initialize your data structure here. */
func Constructor() MyQueue {
	return MyQueue{}
}

/** Push element x to the back of queue. */
func (this *MyQueue) Push(x int) {
	this.inStk = append(this.inStk, x)
}

/** Removes the element from in front of queue and returns that element. */
func (this *MyQueue) Pop() int {
	if len(this.outStk) == 0 {
		this.in2out()
	}
	x := this.outStk[len(this.outStk)-1]
	this.outStk = this.outStk[:len(this.outStk)-1]
	return x
}

/** Get the front element. */
func (this *MyQueue) Peek() int {
	if len(this.outStk) == 0 {
		this.in2out()
	}
	return this.outStk[len(this.outStk)-1]
}

/** Returns whether the queue is empty. */
func (this *MyQueue) Empty() bool {
	return len(this.inStk) == 0 && len(this.outStk) == 0
}
```

### Python

```python
class MyQueue:
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.stack1 = []
        self.stack2 = []

    def push(self, x: int) -> None:
        """
        Push element x to the back of queue.
        """
        self.stack1.append(x)

    def pop(self) -> int:
        """
        Removes the element from in front of queue and returns that element.
        """
        while self.stack1:
            self.stack2.append(self.stack1.pop())
        res = self.stack2.pop()
        while self.stack2:
            self.stack1.append(self.stack2.pop())
        return res

    def peek(self) -> int:
        """
        Get the front element.
        """
        while self.stack1:
            self.stack2.append(self.stack1.pop())
        res = self.stack2[-1]
        while self.stack2:
            self.stack1.append(self.stack2.pop())
        return res

    def empty(self) -> bool:
        """
        Returns whether the queue is empty.
        """
        return not self.stack1

```
