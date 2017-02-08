# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        tmp1 = []
        tmp2 = []
        tmp1.append(str(l1.val))
        tmp2.append(str(l2.val))
        
        x1 = l1
        x2 = l2

        while x1.next != None:
            tmp1.append(str(x1.next.val))
            
            x1 = x1.next
            
        while x2.next != None:
            tmp2.append(str(x2.next.val))
            x2 = x2.next
        
        tmp1.reverse()
        tmp2.reverse()
        d =  list(str(int(''.join(tmp1)) + int(''.join(tmp2))))
        
        d.reverse()

        # print d
        
        n = ListNode(d[0])
        last = n
        
        for item in d:
            t = ListNode(item)
            last.next = t
            last = t
        return n.next
        