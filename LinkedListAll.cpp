/*

Linked List DS Preparation

Maintainer: Arpit Sardana

*/

using namespace std;
#include <bits/stdc++.h>
#define ll long long 

struct Node{
    ll data;
    Node* next;
};

Node* head;

void printLL(){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }cout<<endl<<endl;
}

void insertValueAtBeg(ll data){
    Node* temp = new Node();
    temp->data = data;
    temp->next = head;
    head = temp;
}

void insertValueAtNthPos(ll data, ll n){
    if(n==1){
        insertValueAtBeg(data);
        return;
    }
    Node* insertNode = new Node();
    insertNode->data = data;
    Node* temp = head;
    for(int i=0;i<n-2;i++){
        temp = temp->next;
    }
    insertNode->next = temp->next;
    temp->next = insertNode;
}

void deleteNodeAtNthPos(ll pos){
    Node* temp = head;
    if(pos==1){
        head=head->next;
        delete(temp);
        return;
    }
    for(ll i=0;i<pos-2;i++){
        temp=temp->next;
    }
    Node* del = temp->next;
    temp->next = temp->next->next;
    delete(del);
}

void reverseLinkedListIteratively(){
    Node* prev = NULL;
    Node* current = head;
    Node* nextNode = head;
    
    while(current!=NULL){
        nextNode=current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }
    head = prev;
}

void printLLRecursivelyOrder(Node* temp){
    if(temp==NULL)
        return;
    cout<<temp->data<<" ";
    printLLRecursivelyOrder(temp->next);
}

void printLLRecursivelyNotOrder(Node* temp){
    if(temp==NULL)
        return;
    printLLRecursivelyNotOrder(temp->next);
    cout<<temp->data<<" ";
}

void reverseLinkedListRecursively(Node* temp){
    if(temp->next==NULL){
        head = temp;
        return;
    }
    reverseLinkedListRecursively(temp->next);
    temp->next->next = temp;
    temp->next = NULL;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    head = NULL;
    cout<<"Enter number of nodes to be inserted at Beginning"<<endl<<endl;
    ll n;
    cin>>n;
    for(ll i=0;i<n;i++){
        ll num;
        cin>>num;
        insertValueAtBeg(num);
        printLL();
    }
    
    insertValueAtNthPos(5,2);
    insertValueAtNthPos(6,1);
    insertValueAtNthPos(7,6);
    
    printLL();
    
    deleteNodeAtNthPos(3);
    deleteNodeAtNthPos(6);
    deleteNodeAtNthPos(1);
    
    printLL();
    
    reverseLinkedListIteratively();
    
    printLL();
    
    printLLRecursivelyOrder(head);
    cout<<endl<<endl;
    printLLRecursivelyNotOrder(head);
    cout<<endl<<endl;
    
    reverseLinkedListRecursively(head);
    
    printLL();
    
	return 0;
}	
