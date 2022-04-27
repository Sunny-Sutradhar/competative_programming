#include<bits/stdc++.h>
using namespace std;
typedef struct dinamic_list node;
struct dinamic_list
{
	int data;
	node *next;

};

void inserLeft(node **head,node **tail,int item){
      node *temp,*newNode;
      temp = *head;

      newNode = new node();
      newNode->data = item;

      if(temp==NULL){
          *head = newNode;
          *tail = newNode;
      	  newNode->next = *head;
      	  //newNode->prev = *head;

      }
      else{
         newNode->next = temp;
        // temp->prev = newNode;
         //newNode->prev = *tail;
         node *tempTail;
         tempTail = *tail;
         tempTail->next = newNode;
         *head = newNode;
      }
}

int main(){
	node *head=NULL;
	node *tail;

	inserLeft(&head,&tail,6);
	inserLeft(&head,&tail,16);
	inserLeft(&head,&tail,65);
	inserLeft(&head,&tail,45);
	inserLeft(&head,&tail,10);
	for(int i=0;i<5;i++)
	{
		cout<<head->data<<" ";
		head = head->next;
	}

}