class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        
        p1 = l1
        p2 = l2
        
        carry = (p1.val + p2.val)//10
        result = ListNode((p1.val + p2.val)%10)
        p3 = result
        while p1.next and p2.next:
            p3.next = ListNode(0)
            p3 = p3.next
            p1 = p1.next
            p2= p2.next
            
            temp = p1.val + p2.val + carry
            p3.val = temp%10
            carry = temp//10
            
            
        while p1.next:
            p3.next = ListNode(0)
            p1 = p1.next
            p3 = p3.next
            p3.val = (p1.val + carry)%10
            carry = (p1.val + carry)//10
            
        
        while p2.next:
            p3.next = ListNode(0)
            p2 = p2.next
            p3 = p3.next
            p3.val = (p2.val + carry)%10
            carry = (p2.val + carry)//10
        if carry > 0:
            p3.next = ListNode(carry)
        else:
            p3.next = None
        
        return result
