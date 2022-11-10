    # input tree

    #       1
    #     /   \
    #    2     5
    #   / \     \
    #  3   4     6

class Node:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None

class Solution:
    def flatten(self, root):
        preorder_data = []
        self.preorder_fill_values(root, preorder_data)

        root.left = root.right = None
    
        for data in preorder_data[1:]:
            root.right = Node(data)
            root = root.right

    def preorder_fill_values(self, start, traversal):
        traversal.append(start.data)

        if start.left:
            self.preorder_fill_values(start.left, traversal)
        if start.right:
            self.preorder_fill_values(start.right, traversal)

        return traversal