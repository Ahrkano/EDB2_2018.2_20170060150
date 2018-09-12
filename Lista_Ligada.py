
# coding: utf-8

class Node(object):

    def __init__(self, data=None, next_node=None):
        self.data = data
        self.next = next_node

    def get_data(self):
        return self.data

    def get_next(self):
        return self.next_node

    def set_next(self, new_next):
        self.next_node = new_next


class LinkedList(object):
    def __init__(self, head=None):
        self.head = head
        self.size = 0
        
    def size(self):
        return self.size
    
    def print_elemets(self):
        current = self.head
        while current != None:
            print(current.get_data())
            current = current.get_next()
            
    def copy_list(self, other):
        current = other.head
        while current != None:
            self.insert(current.get_data())
            current = current.get_next()
    
    def insert(self, data):
        new_node = Node(data)
        new_node.set_next(self.head)
        self.head = new_node
        self.size += 1
    
    def search(self, data):
        current = self.head
        found = False
        
        while current and found is False:
            if current.get_data() == data:
                found = True
            else:
                current = current.get_next()
        if current is None:
            raise ValueError("Data not in list")
        return current
    
    def delete(self, data):
        current = self.head
        previous = None
        found = False
    
        while current and found is False:
            if current.get_data() == data:
                found = True
            else:
                previous = current
                current = current.get_next()
        if current is None:
            raise ValueError("Data not in list")
        if previous is None:
            self.head = current.get_next()
        else:
            previous.set_next(current.get_next())
            self.size -= 1
            
            
#====================================FUNCAO SWAP====================================# 
    def swap(self, node1, node2):
        # mesmo nó
        if node1 == node2: 
            return 
  
        # busca antecessor do nó 1 
        ant_node1 = None
        pos_node1 = self.head 
        while pos_node1 != None and pos_node1.data != node1.get_data(): 
            ant_node1 = pos_node1 
            pos_node1 = pos_node1.get_next()
  
        # busca antecessor do nó 2 
        ant_node2 = None
        pos_node2 = self.head 
        while pos_node2 != None and pos_node2.data != node2.get_data(): 
            ant_node2 = pos_node2 
            pos_node2 = pos_node2.get_next()
  
        # nós não encontrados
        if pos_node1 == None or pos_node2 == None: 
            return 
        
        # Se o nó 1 não é a cabeça da lista
        if ant_node1 != None: 
            ant_node1.set_next(pos_node2)  
        else: # nó 2 se torna cabeça
            self.head = pos_node2 
  
        # Se o nó 2 não é a cabeça da lista
        if ant_node2 != None: 
            ant_node2.set_next(pos_node1) 
        else: # nó 1 se torna cabeça 
            self.head = pos_node1 
  
        # Swap next pointers 
        aux = pos_node1.get_next()
        pos_node1.set_next(pos_node2.get_next()) 
        pos_node2.set_next(aux) 


#====================================FUNCAO MERGE====================================# 
def merge_lists(L1, L2):
    L3 = LinkedList()
    if L1 is None:
        L3.copy_list(L2)
        return L3
    if L2 is None:
        L3.copy_list(L1)
        return L3
    
    head1 = L1.head
    head2 = L2.head
            
    count = 0
    while (count < (L1.size+L2.size)):
        if (head1 != None and head2 != None):
            if (head1.get_data() < head2.get_data()):
                L3.insert(head1.get_data())
                head1 = head1.get_next()
            else:
                L3.insert(head2.get_data())
                head2 = head2.get_next()
        else:
            if (head1 == None and head2 != None):
                L3.insert(head2.get_data())
                head2 = head2.get_next()
            else:
                L3.insert(head1.get_data())
                head1 = head1.get_next()
        count+=1

    return L3


# In[59]:


Teste = LinkedList()
Teste2 = LinkedList()
Res = LinkedList()
Res2 = LinkedList()


# In[60]:


Teste.insert(10)
Teste.insert(20)
Teste.insert(30)
Teste.insert(40)
Teste.insert(50)
Teste.insert(60)
Teste.insert(70)

Teste2.insert(15)
Teste2.insert(25)
Teste2.insert(35)
Teste2.insert(45)


# In[61]:


Teste.print_elemets()


# In[62]:


Teste2.print_elemets()


# In[63]:


Teste.swap(Teste.search(10), Teste.search(70))


# In[64]:


Teste.print_elemets()


# In[65]:


Res = merge_lists(Teste2, Teste)


# In[66]:


Res.print_elemets()


# In[67]:


Res.size

