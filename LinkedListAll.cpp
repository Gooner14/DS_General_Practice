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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    head = NULL;
    for(ll i=0;i<5;i++){
        ll num;
        cin>>num;
        insertValueAtBeg(num);
        printLL();
    }
    
    printLL();
    
	return 0;
}	
