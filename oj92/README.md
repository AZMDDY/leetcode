# LeetCode —— 92. 反转链表 II

## 题目

![](https://azmddy.github.io/img/20210318075204.png)

## 思路

一次遍历，将需要反转范围内的元素一次插入反转部分的起始位置。

## 实现

### C++

```cpp
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right)
    {
        ListNode* p = new ListNode(-1, head);
        ListNode* pre = p;
        for (int i = 0; i < left - 1; i++) {
            pre = pre->next;
        }
        ListNode* cur = pre->next;
        ListNode* next;
        for (int i = 0; i < right - left; i++) {
            next = cur->next;
            cur->next = next->next;
            next->next = pre->next;
            pre->next = next;
        }
        ListNode* ans = p->next;
        delete p;
        return ans;
    }
};
```

### Go

```go
func reverseBetween(head *ListNode, left int, right int) *ListNode {
	p := new(ListNode)
	p.Next = head
	pre := p
	for i := 0; i < left -1; i++ {
		pre = pre.Next
	}
	cur := pre.Next
	for i := 0; i < (right - left); i++ {
		next := cur.Next
		cur.Next = next.Next
		next.Next = pre.Next
		pre.Next = next
	}
	return p.Next
}
```

### Python

```python
class Solution:
    def reverseBetween(self, head: ListNode, left: int, right: int) -> ListNode:
        p = ListNode(-1)
        p.next = head
        pre = p
        for _ in range(left - 1):
            pre = pre.next

        cur = pre.next
        for _ in range(right - left):
            next = cur.next
            cur.next = next.next
            next.next = pre.next
            pre.next = next
        return p.next
```
