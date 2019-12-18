template <typename objName>

class Node
{
  public:
  objName obj;
  Node* next = NULL;
  Node(objName object, Node* next);
  Node();
};

template <typename objName>

class List
{
  public:
  Node<objName>* head = NULL;

  void pushFront(objName obj);
  objName popFront();
  void append(objName obj);
  //void remove((void*) obj);
  objName& operator[](int j);
  int len();
  void remove(objName object);
  ~List();
  void operator+(List list);
};  

template <typename objName>
Node<objName>::Node(objName object, Node* NEXT)
{
  this -> obj = object;
  this -> next = NEXT;
}

template <typename objName>
Node<objName>::Node()
{
}

template <typename objName> 
void List<objName>::pushFront(objName add)
{
  head = new Node<objName>(add, this -> head);
}

template <typename objName>
objName List<objName>::popFront()
{
  if (head == NULL)
    return NULL;
  objName object = head -> obj;
  Node<objName>** node = &head;
  head = head -> next;
  delete *node;
  return object;
}

template <typename objName>
void List<objName>::append(objName object)
{
  Node<objName>* newNode = new Node<objName>;
  Node<objName>* current = head;
  
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

template <typename objName>
objName& List<objName>::operator[](int i)
{
  Node<objName>* current = head;
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

template <typename objName>
int List<objName>::len()
{
  int i = 0;
  Node<objName>* current = head;
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

template <typename objName>
void List<objName>::remove(objName object)
{
  Node<objName>* current = head;
  if (head -> obj == object)
  {
    this -> popFront();
    return;
  } 

  

  while ((current -> next != NULL) and (current -> next -> obj != object))
  {
    current = current -> next;
  }
  
  Node<objName>** node;
  if (current -> next != NULL)
  {
    node = &(current -> next);
    current -> next = current -> next -> next;   
  }
  
  delete *node; 
  //else return; 
}

template <typename objName>
List<objName>::~List()
{
  while (head != NULL)
    this -> popFront();
}

template <typename objName>
void List<objName>::operator+(List<objName> list)
{
  int i = this -> len();
  Node<objName>* current = this -> head;
  for(int j = 0; j < len - 1; j++)
    current = current -> next;
  
  if (!head)
    this -> head = list.head;
  current -> next = list.head;
}







 
