# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def swapNodes(self, head):

        if (head is None or head.next is None):
            return head

        nextNode = head.next
        head.next = self.swapNodes(nextNode.next)
        nextNode.next = head
        return nextNode

    def swapPairs(self, head):
        return self.swapNodes(head)