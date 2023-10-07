class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None

    def append(self, data):
        new_node = Node(data)
        if not self.head:
            self.head = new_node
            return
        current = self.head
        while current.next:
            current = current.next
        current.next = new_node

    def display(self):
        current = self.head
        while current:
            print(current.data, end=" -> ")
            current = current.next
        print("None")

    def delete(self, value):
        if not self.head:
            return  # List is empty

        if self.head.data == value:
            self.head = self.head.next
            return

        current = self.head
        while current.next:
            if current.next.data == value:
                current.next = current.next.next
                return
            current = current.next

        print(f"Value {value} not found in the linked list.")

# Creating a linked list and adding elements
my_linked_list = LinkedList()
my_linked_list.append(1)
my_linked_list.append(2)
my_linked_list.append(3)

# Displaying the original linked list
print("Original Linked List:")
my_linked_list.display()

# Deleting a node with value 2
my_linked_list.delete(2)

# Displaying the modified linked list
print("Modified Linked List:")
my_linked_list.display()
