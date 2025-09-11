template <typename T>
LinkedList<T>::LinkedList()
: head(nullptr) {
    this->length = 0;
}

template <typename T>
LinkedList<T>::~LinkedList() {
    clear();
}

template <typename T>
void LinkedList<T>::append(const T& elem) {
    Node* newNode = new Node(elem);

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* curr = head;
        while (curr->next != nullptr)
            curr = curr->next;
        curr->next = newNode;
    }

    this->length++;
}

template <typename T>
void LinkedList<T>::clear() {
    Node* curr = head;
    while (curr != nullptr) {
        Node* temp = curr;
        curr = curr->next;
        delete temp;
    }
    head = nullptr;
    this->length = 0;
}

template <typename T>
T LinkedList<T>::getElement(int position) const {
    if (position < 0 || position >= this->length)
        throw string("Index out of range in getElement()");

    Node* curr = head;
    for (int i = 0; i < position; i++)
        curr = curr->next;

    return curr->value;
}

template <typename T>
int LinkedList<T>::getLength() const {
    return this->length;
}

template <typename T>
bool LinkedList<T>::isEmpty() const {
    return this->length == 0;
}

template <typename T>
void LinkedList<T>::insert(int position, const T& elem) {
    if (position < 0 || position > this->length)
        throw string("Index out of range in insert()");

    Node* newNode = new Node(elem);

    if (position == 0) {
        newNode->next = head;
        head = newNode;
    } else {
        Node* curr = head;
        for (int i = 0; i < position - 1; i++)
            curr = curr->next;
        newNode->next = curr->next;
        curr->next = newNode;
    }

    this->length++;
}

template <typename T>
void LinkedList<T>::remove(int position) {
    if (position < 0 || position >= this->length)
        throw string("Index out of range in remove()");

    Node* toDelete;
    if (position == 0) {
        toDelete = head;
        head = head->next;
    } else {
        Node* curr = head;
        for (int i = 0; i < position - 1; i++)
            curr = curr->next;
        toDelete = curr->next;
        curr->next = toDelete->next;
    }

    delete toDelete;
    this->length--;
}

template <typename T>
void LinkedList<T>::replace(int position, const T& elem) {
    if (position < 0 || position >= this->length)
        throw string("Index out of range in replace()");

    Node* curr = head;
    for (int i = 0; i < position; i++)
        curr = curr->next;

    curr->value = elem;
}
