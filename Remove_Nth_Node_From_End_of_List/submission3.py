# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def removeNthFromEnd(self, head, n):

        previous = None
        current = head
        forward = None
        temp = current

        while n!=0:
            temp = temp.next
            n -= 1
        
        while temp is not None:
            forward = current.next
            temp = temp.next
            previous = current
            current = forward
            if forward is not None:
                forward = forward.next

        if previous is None:
            forward = current.next
            current.next = None
            del current
            return forward
        else:
            previous.next = forward
            current.next = None
            del current
            return head