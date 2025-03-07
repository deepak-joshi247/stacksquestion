#include<iostream>
#include<stack>
using namespace std;
class Node{
    public:
        int data;
        Node* next;
        Node (int data){
            this->data = data;
            this -> next = NULL;
        }
};
Node Insertathead(Node* &head,int data){ //this funtion cant be placed inside main function
    Node* temp = new Node(data);
    temp->next = head;
    head = temp;
}
int main()
{
Node* head = new Node(12);

Insertathead(head,45);
Insertathead(head,458);
Insertathead(head,4);
Node* justptr = head;
while(justptr!=NULL)
{
    cout<<justptr->data<<endl;
    justptr = justptr ->next;
}
return 0;
}
