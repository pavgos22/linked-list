#include <iostream>

#define MAX_SIZE 5
#define ITERATOR 10

using namespace std;

struct Commands {
    const char aLeft[3] = { ".A" };
    const char aRight[3] = { "A." };
    const char beg[4] = { "BEG" };
    const char end[4] = { "END" };
    const char all[4] = { "ALL" };
    const char print[2] = { "P" };
    const char remove[2] = { "R" };
    const char initIterator[2] = { "i" };
    const char asc[2] = { "+" };
    const char desc[2] = { "-" };
};

struct Node {
    unsigned long long int data;
    Node* next;
    Node* prev;
};


Node* CreateNode(unsigned long long int x) {
    Node* newNode = new Node;
    newNode->data = x;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

int LastIndex(char* str) {
    int last_id = 0;
    while (str[last_id++] != '\0');
    return --last_id;
}

bool StrCompare(char str[MAX_SIZE], const char command[]) {
    int lastIndex = LastIndex(str);

    if (command[lastIndex] != '\0')
        return false;

    for (int i = 0; i < lastIndex; i++) {
        if (str[i] != command[i])
            return false;
    }

    return true;
}

void PushFront(Node*& head, Node*& tail, Node* node, unsigned long long int x) {
    Node* newNode = CreateNode(x);
    if (head == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }

    Node* prevNode = node->prev;

    newNode->prev = prevNode;
    newNode->next = node;
    node->prev = newNode;

    if (prevNode == NULL)
        head = newNode;
    else
        prevNode->next = newNode;
}

void PushBack(Node*& head, Node*& tail, Node* node, unsigned long long int x) {
    Node* newNode = CreateNode(x);
    if (head == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }

    Node* nextNode = node->next;

    newNode->next = nextNode;
    newNode->prev = node;
    node->next = newNode;

    if (nextNode == NULL)
        tail = newNode;
    else
        nextNode->prev = newNode;
}

void DeleteNode(Node* iterators[], Node* nodeToDelete) {
    for (int i = 0; i < ITERATOR; i++) {
        if (iterators[i] == nodeToDelete) {
            if (iterators[i]->next != NULL)
                iterators[i] = iterators[i]->next;
            else
                iterators[i] = iterators[i]->prev;
        }
    }

    delete nodeToDelete;
}

void Delete(Node*& head, Node*& tail, Node* nodeToDelete, Node* iterators[]) {
    if (nodeToDelete == NULL)
        return;

    Node* prevNode = nodeToDelete->prev;
    Node* nextNode = nodeToDelete->next;

    if (prevNode == NULL)
        head = head->next;
    else
        prevNode->next = nextNode;

    if (nextNode == NULL)
        tail = tail->prev;
    else
        nextNode->prev = prevNode;

    DeleteNode(iterators, nodeToDelete);
}

void Print(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void PrintIndex(Node* node) {
    if (node != NULL)
        cout << node->data << endl;
}

void InsertI() {
    char z;
    cin >> z;
    if (z == 'I') {
        int I;
        cin >> I;
    }
}


void InsertCommand(Commands& Command, Node*& head, Node*& tail, Node* iterator[]) {
    char command[MAX_SIZE], second[MAX_SIZE];
    unsigned long long int n;
    int x;

    while (cin >> command) {
        if (StrCompare(command, Command.aLeft)) {
            cin >> second;
            if (StrCompare(second, Command.beg)) {
                cin >> n;
                PushFront(head, tail, head, n);
            }
            else if (StrCompare(second, Command.end)) {
                cin >> n;
                PushFront(head, tail, tail, n);
            }
            else {
                int iterNumber = second[0] - '0';
                cin >> n;
                PushFront(head, tail, iterator[iterNumber], n);
            }
        }

        else if (StrCompare(command, Command.aRight)) {
            cin >> second;
            cin >> n;
            if (StrCompare(second, Command.end)) {
                PushBack(head, tail, tail, n);
            }
            else if (StrCompare(second, Command.beg)) {
                PushBack(head, tail, head, n);
            }
            else {
                int iterNumber = second[0] - '0';
                PushBack(head, tail, iterator[iterNumber], n);
            }
        }

        else if (StrCompare(command, Command.initIterator)) {
            cin >> x;
            cin >> second;
            if (StrCompare(second, Command.beg))
                iterator[x] = head;
            else if (StrCompare(second, Command.end)) {
                iterator[x] = tail;
            }
            else
                iterator[x] = iterator[second[0] - '0'];
        }

        else if (StrCompare(command, Command.asc)) {
            cin >> x;
            if (iterator[x] != NULL && iterator[x]->next != NULL)
                iterator[x] = iterator[x]->next;
        }

        else if (StrCompare(command, Command.desc)) {
            cin >> x;
            if (iterator[x] != NULL && iterator[x]->prev != NULL)
                iterator[x] = iterator[x]->prev;
        }

        else if (StrCompare(command, Command.print)) {
            cin >> second;
            if (StrCompare(second, Command.all)) {
                Print(head);
            }
            else
                PrintIndex(iterator[second[0] - '0']);
        }

        else if (StrCompare(command, Command.remove)) {
            cin >> second;
            if (StrCompare(second, Command.end)) {
                Delete(head, tail, tail, iterator);
            }
            else if (StrCompare(second, Command.beg)) {
                Delete(head, tail, head, iterator);
            }
            else {
                int iterNumber = second[0] - '0';
                Delete(head, tail, iterator[iterNumber], iterator);
            }
        }
    }
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;
    Commands Command;
    Node* iterator[ITERATOR];

    InsertI();
    InsertCommand(Command, head, tail, iterator);

    while (head != NULL)
        Delete(head, tail, head, iterator);

    return 0;
}