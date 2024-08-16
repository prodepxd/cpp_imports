#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *next;

        Node (int data){
            this->data = data;
            this->next = nullptr;
        }
};

class LinkedList{
    private:
        Node *head;

        int countNodes(Node* node){
            if (node == nullptr){
                return 0;
            }
            
            return 1 + countNodes(node->next);
        }

    public:
        LinkedList(){
            this->head = nullptr;
        }

        void printList(){
            cout << endl;

            if (head == nullptr){
                cout << "list empty!";
                return;
            }

            Node *temp = head;
            while(temp != nullptr){
                cout << temp->data << " -> ";
                temp = temp->next;
            }
            cout << "nullptr";
        }

        void insertFirst(int data){
            Node *newNode = new Node(data);
            newNode->next = head;
            head = newNode;
        }

        void insertLast(int data){
            Node *newNode = new Node(data);

            if (head == nullptr){
                head = newNode;
                return;
            }
            
            Node *temp = head;
            while (temp->next != nullptr){
                temp = temp->next;
            }
            temp->next = newNode;
        }

        void insertPosition(int pos, int data){
            if (pos < 1){
                cout << endl <<"invalid position";
                return;
            }
            if (pos == 1){
                insertFirst(data);
                return;
            }

            Node *newNode = new Node(data);
            Node *temp = head;
            
            for (int i = 2; i < pos && temp; i++){
                temp = temp->next;
            }

            if (!temp){
                cout << endl << "invalid position";
                delete newNode;
                return;
            }

            newNode->next = temp->next;
            temp->next = newNode;
        }

        void deleteFirst(){
            if (head == nullptr){
                return;
            }

            Node *temp = head;
            head = head->next;
            delete temp;
        }

        void deleteLast(){
            if (head == nullptr){
                return;
            }

            if (head->next == nullptr){
                delete head;
                head = nullptr;
                return;
            }

            Node *temp = head;;
            while (temp->next->next != nullptr){
                temp = temp->next;
            }
            delete temp->next;
            temp->next = nullptr;
        }

        void deletePosition(int pos){
            if (pos < 1){
                cout << endl <<"invalid position";
                return;
            }
            if (pos == 1){
                deleteFirst();
                return;
            }

            Node *temp = head;
            for (int i = 0; i < pos-2 && temp; i++){
                temp = temp->next;
            }

            if (!temp || !temp->next){
                cout << endl << "invalid position";
                return;
            }

           Node *del = temp->next;
           temp->next = temp->next->next;
           delete del;
        }

        int countList(){
            return countNodes(head);
        }
    
        void reverseList(){
            Node* prev = nullptr;
            Node* curr = head;
            Node* next = nullptr;
            while (curr != nullptr) {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            head = prev;
        }

        int valueAt(int pos){
            Node *temp = head;
            if (pos < 1 || pos > countNodes(head)){
                cout << endl << "invalid position";
                return -1;
            }

            for(int i = 1; i < pos && temp; i++){
                temp = temp->next;
            }
            return temp->data;
        }

        int valueNEnd(int n){
            Node *temp = head;
            Node *ref = head;

            if (n < 1){
                cout << endl << "invalid position";
                return -1;
            }

            for (int i=1; i<n; i++){
                ref = ref->next;
            }

            if (ref == NULL){
                cout << endl << "invalid position";
                return -1;
            }

            while (ref->next != nullptr){
                ref = ref->next;
                temp = temp->next;
            }

            return temp->data;
        }
};