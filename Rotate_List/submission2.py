# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def length(self, head):
        
        lengthOfList = 0
        while head is not None:
            lengthOfList += 1
            head = head.next
        
        return lengthOfList

    def rotateRight(self, head, k):

        n = self.length(head)
        if n!=0:
            k = k % n

        if n==0 or k==0:
            return head

        previous = None
        current = head

        for i in range(n-k):
            previous = current
            current = current.next
        
        previous.next = None
        newHead = current

        while current is not None and current.next is not None:
            current = current.next
        
        
        current.next = head
        return newHead