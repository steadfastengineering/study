# Accepted solution
# Submitted
def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        out = ListNode(0,None)
        root = out
        carry = 0
        while l1 != None and l2 != None:
            # Walk the nodes up to end of one of the lists, or both and sum
            sum = l1.val + l2.val + carry
            carry = 0 if sum < 10 else 1
            sum = sum if sum < 10 else sum-10

            out.val = sum

            # Walk the result and addends up
            if l1.next != None or l2.next != None:
                out.next = ListNode(0,None)
                out = out.next

            l1 = l1.next
            l2 = l2.next

        while l1 == None and l2 != None:
            # There are remaining nodes in l2
            sum = l2.val + 0 + carry
            carry = 0 if sum < 10 else 1
            sum = sum if sum < 10 else sum-10

            out.val = sum

            # Walk the result and addends up
            if l2.next != None:
                out.next = ListNode(0,None)
                out = out.next

            l2 = l2.next

        while l1 != None and l2 == None:
            # There are remaining nodes in l1
            sum = l1.val + 0 + carry
            carry = 0 if sum < 10 else 1
            sum = sum if sum < 10 else sum-10

            out.val = sum

            # Walk the result and addends up
            if l1.next != None:
                out.next = ListNode(0,None)
                out = out.next

            l1 = l1.next


        if carry > 0:
            out.next = ListNode(0,None)
            out = out.next
            out.val = carry
        else:
            out = None

        return root
