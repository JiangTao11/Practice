# TEST
class Node():


    def __init__(self,element=None, next=None, pre=None):
        self.pre = pre
        self.element = element
        self.next = next

class LinkedList():


    def __init__(self, head=None, tail=None,count=0):
        self.head = Node()
        self.tail = Node()
        self.count = count
    def insert_after(self, item, node):
        temp_node = self.head
        insert_item = Node(item)
        if temp_node.next is None and node.element is None:
            self.head.next = insert_item
            self.tail = insert_item
            self.count = self.count+1
            return

        while temp_node.next is not None:
            if temp_node.next.element is  node.element:
                if temp_node.next is self.tail:
                    self.tail.next = insert_item
                    insert_item.pre = self.tail
                    self.tail = insert_item
                    self.count = self.count+ 1
                else:
                    node.next = insert_item.next
                    node.next.pre = insert_item
                    insert_item.pre = node
                    node.next = insert_item
                    self.count = self.count + 1
                return
            else:
                temp_node = temp_node.next
        print("node is not found --> insert_after")

    def __repr__(self):
        return repr(self.element)

    def insert_before(self,item, node):
        temp_node =  self.head
        insert_item =Node(item)
        if temp_node.next is None and node.element is None:
            self.head.next = insert_item
            self.tail = insert_item
            self.count = self.count+1
            return
        while temp_node.next is not None:
            if temp_node.next.element is node.element:
                if temp_node.next is self.head.next:
                    self.head.next.pre = insert_item
                    insert_item.next = self.head.next
                    self.head.next = insert_item
                    self.count = self.count+1
                else:
                    temp_node.next.pre = insert_item
                    insert_item.next = temp_node.next
                    insert_item.pre = temp_node
                    insert_item.next = temp_node.next
                    return
            else:
                temp_node = temp_node.next
        print('node is not found--> insert_before')

    def delete_item(self,item):
        temp_node = self.head
        delete_item = Node(item)
        if temp_node.next is None:
            return
        while temp_node.next is not None:
            if temp_node.next.element is item :
                if temp_node.next is self.head.next:
                    self.head.next = self.head.next.next
                    self.head.next.next.pre = self.head
                    self.count = self.count-1
                    return
                elif temp_node.next is self.tail:
                    self.tail = self.tail.pre
                    self.count = self.count - 1
                    return
                else:
                    temp = temp_node.next
                    temp.pre.next = temp.next
                    temp.next.pre = temp.pre
                    self.count = self.count -1
                    return

            temp_node = temp_node.next
        print('item is not found-->delete_item')
    def length(self):
        return self.count

    def first_node(self):
        return self.head.next.element

    def last_node(self):
        return self.tail.element

    def reverse(self):
        front = self.head.next
        rear = self.tail
        if front is None:
            return
        if (self.length()%2) ==1:
            while front is not rear:
                temp = front.element
                front.element = rear.element
                rear.element = temp
                front = front.next
                rear = rear.pre
        else:
            while front.next is not rear:
                temp = front.element
                front.element = rear.element
                rear.element = temp
                front = front.next
                rear = rear.pre
            temp = front.element
            front.element = rear.element
            rear.element = temp
    def find(self,item):
        temp_node = self.head
        if temp_node.next is None:
            return None
        while  temp_node.next is not None:
            if temp_node.next.element == item:
                return True
            else:
                temp_node = temp_node.next

        return False


def testLinkedListNode():
    testNode=Node(1)
    assert testNode.element == 1

def testLinkedListInsert_after():
    testLinkedList=LinkedList()
    testLinkedList.insert_after(1,Node())
    testLinkedList.insert_after(2,Node(1))
    testLinkedList.insert_after(3,Node(2))
    assert testLinkedList.head.next.element == 1
    assert testLinkedList.tail.element ==3
    assert testLinkedList.head.next.next.element == 2

def testLinkedListInsert_before():
    testLinkedList = LinkedList()
    testLinkedList.insert_before(3,Node())
    testLinkedList.insert_before(4,Node(3))
    testLinkedList.insert_before(5,Node(4))
    assert testLinkedList.head.next.element == 5
    assert testLinkedList.tail.element ==3

def testLinkedListDelete_item():
    testLinkedList = LinkedList()
    testLinkedList.insert_before(3,Node())
    testLinkedList.insert_before(4,Node(3))
    testLinkedList.insert_before(5,Node(4))
    testLinkedList.delete_item(5)
    assert testLinkedList.tail.element == 3
    testLinkedList.delete_item(3)
    assert testLinkedList.head.next.element == 4

def testLinkedListReverse_firstNode_lastNode_length_findItem():
    testLinkedList = LinkedList()
    testLinkedList.insert_before(3,Node())
    testLinkedList.insert_before(4,Node(3))
    testLinkedList.insert_before(5,Node(4))
    testLinkedList.reverse()
    assert testLinkedList.head.next.element == 3
    assert testLinkedList.tail.element == 5
    assert testLinkedList.first_node() == 3
    assert testLinkedList.last_node() == 5
    assert testLinkedList.length()  == 3

if __name__=='__main__':
    testLinkedListNode()
    testLinkedListInsert_after()
    testLinkedListInsert_before()
    testLinkedListDelete_item()
    testLinkedListReverse_firstNode_lastNode_length_findItem( )