class Solution:
    def findMid(self, head):
        if head == None:
            return -1
        
        i = 1
        len_lst = self.len_llist(head)
        mid_len = len_lst / 2 + 1 if len_lst % 2 == 0 else len_lst // 2 + 1

        while i <= mid_len:
            mid = head.data
            head = head.next
            i += 1

        return mid

    def len_llist(self,head):
        out = 1

        while head.next:
            head = head.next
            out += 1

        return out