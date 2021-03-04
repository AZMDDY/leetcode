package oj232

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
