#include <iostream>
using namespace std;

struct Node{
    int value;
    Node* next;
};

Node* push_front(Node*, int);
Node* remove_head(Node*);
void print_list(Node*);
int count_nodes(Node*);
bool contains(Node* , int);


int main(){

    Node* currentnode = nullptr;
    for(int i = 0 ; i < 5 ; i++){
        currentnode = push_front(currentnode, 50 - i * 10);
    }
    print_list(currentnode);

    cout << "The number of list is : " << count_nodes(currentnode)<< endl;

    for(int i = 0 ; i<2 ; i++){
        currentnode = remove_head(currentnode);
        print_list(currentnode);
    }
    count_nodes(currentnode);
    
    cout << "Does it contain 50? " ;
    if(contains(currentnode, 50))
        cout << "true" << endl;
    else
        cout << "false"; 
    cout << "Does it contain 44? ";
    if(contains(currentnode, 44))
        cout << "true" << endl;
    else
        cout << "false"; 
}

Node* push_front(Node* head, int value) {
    Node* node = new Node;
    node->value = value;
    node->next  = head;
    return node;
}

void print_list(Node* head) {
    for (Node* cur = head; cur != nullptr; cur = cur->next) {
        cout << cur->value << " ";
    }
    cout << endl;
}

int count_nodes(Node* head){
    int count = 0;
    for(Node* cur = head; cur != nullptr; cur = cur->next){
        count++;
    }
    return count;
}

Node* remove_head(Node* head) {
    if (head == nullptr) {
        return nullptr;
    }
    Node* oldHead = head;
    head = head->next;
    delete oldHead;
    return head;
}

bool contains(Node* head , int target){
    for(Node* cur = head ; cur != nullptr ; cur = cur -> next){
        if(cur -> value == target){
            return true;
        }
    }
    return false;
}
