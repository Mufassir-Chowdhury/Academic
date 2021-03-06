template <typename data_type>
SinglyLinkedList<data_type>::SinglyLinkedList()
    : head(nullptr), tail(nullptr), number_of_member(0) {}


// Methods


template <typename data_type>
void SinglyLinkedList<data_type>::push_back(data_type value){
    Node<data_type>* newNode = getNewNode(value);
    
    if(is_empty())
        setHead(newNode);
    else
        getTail()->setPtr(newNode);
    
    setTail(newNode);
    increaseMember();
}

template <typename data_type>
void SinglyLinkedList<data_type>::push_front(data_type value){
    Node<data_type>* newNode = getNewNode(value);

    if(is_empty()){
        setTail(newNode);
    }
    newNode->setPtr(getHead());
    setHead(newNode);

    increaseMember();
}

template <typename data_type>
data_type SinglyLinkedList<data_type>::pop_front(){
    if(is_empty()){
        std::cout << "List empty! Returning NULL." << std::endl;
        return static_cast<data_type>(NULL);
    }

    data_type value{getHead() -> getValue()};
    if(getHead() == getTail()){
        delete getHead();
        setHead(nullptr);
        setTail(nullptr);
    } else{
        Node<data_type>* nextToHead = getHead() ->getPtr();
        delete getHead();
        getHead() -> setPtr(nextToHead);
    }
    decreaseMember();
    return value;
}

template <typename data_type>
data_type SinglyLinkedList<data_type>::pop_back(){
    if(is_empty()){
        std::cout << "List empty! Returning NULL." << std::endl;
        return static_cast<data_type>(NULL);
    } else if(getHead() == getTail()){

    }
}

template <typename data_type>
data_type SinglyLinkedList<data_type>::back() const{
    if(is_empty()){
        std::cout << "List empty! Returning NULL." << std::endl;
        return static_cast<data_type>(NULL);
    } else
        return getTail() -> getValue();
}

template <typename data_type>
data_type SinglyLinkedList<data_type>::front() const{
    if(is_empty()){
        std::cout << "List empty! Returning NULL." << std::endl;
        return static_cast<data_type>(NULL);
    } else    
        return getHead() -> getValue();
}

// Utility Functions


template <typename data_type>
bool SinglyLinkedList<data_type>::is_empty() const {
    return not length();
}

template <typename data_type>
int SinglyLinkedList<data_type>::length() const {
    return number_of_member;
}

template <typename data_type>
void SinglyLinkedList<data_type>::print() const {
    if(is_empty())
        std::cout << "List Empty!";
    else{
        Node<data_type>* temporary = getHead();
        std::cout << "List: ";
        while(temporary){
            std::cout << temporary -> getValue() << " ";
            temporary = temporary -> getPtr();
        }
    }
    std::cout << std::endl;
}

// Helper Functions

template <typename data_type>
void SinglyLinkedList<data_type>::setHead(Node<data_type>* ptr){
    head = ptr;
}

template <typename data_type>
void SinglyLinkedList<data_type>::setTail(Node<data_type>* ptr){
    tail = ptr;
}

template <typename data_type>
Node<data_type>* SinglyLinkedList<data_type>::getHead() const{
    return head;
}

template <typename data_type>
Node<data_type>* SinglyLinkedList<data_type>::getTail() const{
    return tail;
}

template <typename data_type>
void SinglyLinkedList<data_type>::increaseMember(){
    number_of_member++;
}

template <typename data_type>
void SinglyLinkedList<data_type>::decreaseMember(){
    number_of_member--;
}

template <typename data_type>
Node<data_type>* SinglyLinkedList<data_type>::getNewNode(data_type value){
    return new Node<data_type>(value);
}