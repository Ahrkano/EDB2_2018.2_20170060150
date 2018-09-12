
# coding: utf-8

class HashTable(object):
    tableSize    = 0
    elements     = 0
    hashTable    = []
     
    def __init__(self, t_size):
        self.tableSize = t_size
        self.hashTable = [[] for i in range(t_size)]
        
    def number_of_elements(self):
        return elements
        
    def hash_function(self, x): 
        return hash(x) % self.tableSize
    
    def insert(self,input,value): 
        self.hashTable[self.hash_function(input)].append((input,value))
        self.elements+=1
        
    def remove(self,input,value):
        wanted = self.hashTable[self.hash_function(input)]
        for i in wanted:
            if i[1] == value :
                wanted.remove(i)
        
    def search(self, input, value):
        wanted = self.hashTable[self.hash_function(input)]
        for i in wanted:
            if i[1] == value :
                return i
    
    def show(self):
        count = 0
        while count < self.tableSize:
            print(self.hashTable[count])
            count+=1


# In[36]:


Teste = HashTable(5)


# In[37]:


Teste.insert(41,'apple')
Teste.insert(93,'banana')
Teste.insert(13,'tangerine')


# In[38]:


Teste.show()


# In[39]:


Teste.search(13, 'tangerine')


# In[40]:


Teste.remove(93, 'banana')


# In[41]:


Teste.show()

