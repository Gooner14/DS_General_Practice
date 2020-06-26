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
    
	return 0;
}	
