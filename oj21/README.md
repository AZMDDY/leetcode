# LeetCode —— 21. 合并两个有序链表

## 题目

![](https://azmddy.github.io/img/20210324074009.png)

## 思路

使用迭代的方法，依次比较两个链表中的元素，将较小的添加到结果中。

## 实现

### C++

```cpp
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        ListNode* ans = new ListNode(0);
        ListNode* tmp = ans;
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                tmp->next = l1;
                l1 = l1->next;
            } else {
                tmp->next = l2;
                l2 = l2->next;
            }
            tmp = tmp->next;
        }
        if (l1 != nullptr) {
            tmp->next = l1;
        }
        if (l2 != nullptr) {
            tmp->next = l2;
        }
        tmp = ans->next;
        delete ans;
        return tmp;
    }
};
```

### Go

```go
func mergeTwoLists(l1 *ListNode, l2 *ListNode) *ListNode {
	prehead := &ListNode{}
	tmp := prehead
	for l1 != nil && l2 != nil {
		if l1.Val < l2.Val {
			tmp.Next = l1
			l1 = l1.Next
		} else {
			tmp.Next = l2
			l2 = l2.Next
		}
		tmp = tmp.Next
	}
	if l1 != nil {
		tmp.Next = l1
	}
	if l2 != nil {
		tmp.Next = l2
	}
	return prehead.Next
}
```

### Python

```python
class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        prehead = ListNode()
        tmp = prehead
        while l1 != None and l2 != None:
            if l1.val < l2.val:
                tmp.next = l1
                l1 = l1.next
            else:
                tmp.next = l2
                l2 = l2.next
            tmp = tmp.next
        if l1 != None:
            tmp.next = l1
        if l2 != None:
            tmp.next = l2
        return prehead.next

```
