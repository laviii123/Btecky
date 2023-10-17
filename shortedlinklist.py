class node:
    def __init__(self,n):
        self.n = n
        self.next_node = None


class SortedLikedList:
    def __init__(self):
        self.Head = None
        self.Tail = None
    
    def insertSorted(self,node):
        if self.Head==None and self.Tail==None:
            self.Head = node
            self.Tail = node

        elif self.Head == self.Tail:
            if node.n>self.Head.n:
                self.Head.next_node = node
                self.Tail = node
            else:
                node.next_node = self.Head
                self.Head  = node
        
        else:
            if node.n<self.Head.n:
                node.next_node = self.Head
                self.Head  = node
            else:
                current_node  = self.Head
                while current_node!=self.Tail:
                    if node.n>=current_node.n and node.n <= current_node.next_node.n:
                        node.next_node = current_node.next_node
                        current_node.next_node = node
                        return
                    current_node = current_node.next_node
                self.Tail.next_node  = node
                self.Tail = node
                return

    def display(self):
        current_node  = self.Head
        while current_node.next_node != None:
            print(current_node.n, end=" ")
            current_node = current_node.next_node
        print(current_node.n, end=" ")
        
        
sll = SortedLikedList()

sll.insertSorted(node(12))
sll.insertSorted(node(5))
sll.insertSorted(node(8))
sll.insertSorted(node(24))
sll.insertSorted(node(2))
sll.insertSorted(node(20))
print(sll)
sll.display() 
