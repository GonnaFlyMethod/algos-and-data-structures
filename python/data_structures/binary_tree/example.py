
class BTNode:
    def __init__(self, val: int):
        self.val = val
        self.left = None
        self.right = None

    def insert(self, val: int):
        if self.val > val:
            if self.left is None:
                self.left = BTNode(val)
            else:
                self.left.insert(val)
        elif self.val < val:
            if self.right is None:
                self.right = BTNode(val)
            else:
                self.right.insert(val)

    def sum(self):
        if self.left and self.right:
            return self.val + self.left.sum() + self.right.sum()
        if self.left is None and self.right:
            return self.val + self.right.sum()
        if self.left and self.right is None:
            return self.val + self.left.sum()
        if self.left is None and self.right is None:
            return self.val

    def print_tree(self):
        if self.left:
            self.left.print_tree()
        print(self.val)
        if self.right:
            self.right.print_tree()

    def contains(self, val: int):
        if self.val == val:
            print(f"The value {self.val} was found in the tree")
        if self.left:
            self.left.contains(val)
        if self.right:
            self.right.contains(val)

    def invert(self):
        raise NotImplementedError

bt = BTNode(12)
bt.insert(6)
bt.insert(14)
bt.insert(3)

print("Sum of nodes:", bt.sum())
print("Printing tree...")
bt.print_tree()

bt.contains(12)
