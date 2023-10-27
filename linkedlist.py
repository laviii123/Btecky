# Indexing starts from 0.
def insertAtIndex(self, data, index):
        new_node = Node(data)
        current_node = self.head
        position = 0
        if position == index:
            self.insertAtBegin(data)
        else:
            while(current_node != None and position+1 != index):
                position = position+1
                current_node = current_node.next
 
            if current_node != None:
 
                new_node.next = current_node.next
                current_node.next = new_node
            else:
                print("Index not present")
