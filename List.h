class Node
{
  public:
  void* obj;
  Node* next = NULL;
  Node(void* object, Node* next);
  Node();
};

class List
{
  public:
  Node* head = NULL;
  void pushFront(void* obj);
  void* popFront();
  void append(void* obj);
  //void remove((void*) obj);
  void* operator[](int j);
  int len();
  void remove(void* object);
};  


Node::Node(void* object, Node* NEXT)
{
  this -> obj = object;
  this -> next = NEXT;
}

Node::Node()
{
}
 
void List::pushFront(void* add)
{
  Node* newObj = new Node;
  *newObj = Node(add, this -> head);
  head = newObj;
}

void* List::popFront()
{
  if (head == NULL)
    return (void*) NULL;
  Node* pointer = head;
  head = head -> next;
  return pointer -> obj;
}

void List::append(void* object)
{
  Node* newNode = new Node;
  Node* current = head;
  
  if (!current)
  {
    head = newNode;
    newNode -> obj = object;
    return;
  }

  while (current -> next != NULL)
    current = current -> next;
 
  current -> next = newNode;
  newNode -> obj = object;
}

void* List::operator[](int i)
{
  Node* current = head;
  int j = 0;
  while (i != j)
  {
    if (!current)
      return head -> obj;
    current = current -> next;
    j++;
  }
  return current -> obj;
}

int List::len()
{
  int i = 0;
  Node* current = head;
  if (!current)
      return i;
  while (current -> next != NULL)
  {
    current = current -> next;
    i++;
  }
  i++;
  return i;
}

/*int List::getPos(void* obj)
{
  int i = 1;
  Node* current = head;
  while (current -> next != obj)
  {
    current = current -> next;
    i++;
  }
  i++;
  return i;
} */ 

void List::remove(void* object)
{
  Node* current = head;
  if (head -> obj == object)
  {
    this -> popFront();
    return;
  } 

  

  while ((current -> next != NULL) and (current -> next -> obj != object))
  {
    current = current -> next;
  }
  
  
  if (current -> next != NULL)
  {
    current -> next = current -> next -> next;
    
  }
   
  //else return; 
}










 
