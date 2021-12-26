#include<bits/stdc++.h>
using namespace std;
typedef struct LinkedList node;


struct LinkedList
{
    int data;
    LinkedList *next;
    LinkedList *prev;
};
void printfBack(node *tail){
    node *temp;
    temp = tail;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->prev;
    }cout<<endl;
}
void printFont(node *head){
    node *temp;
    temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }cout<<endl;
}


//This fucntion use for insert last or insert end
void insertRght(node **head,node **tail,int item){
    cout<<"item"<<item<<endl;
    node *temp,*newNode;
    node *tempTail;
    tempTail = *tail;
    temp = *head;
    newNode = new node();
    newNode->data = item;
    newNode ->prev = NULL;

    if(*head==NULL){
         newNode ->next =NULL;
         *head = newNode;
         *tail = newNode;
    }
    else {
        newNode ->next = temp;
        temp->prev = newNode;
        newNode->prev = tempTail;
        tempTail->next = newNode;
        //*head = newNode;
    }
}

// this function 1st or at the beggining
void insertleft(node **head,node **tail,int item){
    cout<<"item"<<item<<endl;
    node *temp,*newNode;
    node *tempTail;
    tempTail = *tail;

    temp = *head;
    newNode = new node();
    newNode->data = item;
    newNode ->prev = NULL;

    if(*head==NULL){
         newNode ->next =NULL;
         *head = newNode;
         *tail = newNode;
    }
    else {
        newNode ->next = temp;
        temp->prev = newNode;
        tempTail->next = newNode;
        newNode->prev = tempTail;
        
        
        //tempTail->next = newNode;
        cout<<temp->prev->data<<endl;
        *head = newNode;
        
    }
}

void operation(int arr[],int p[],int n){
    node *head=NULL,*tail=NULL;
      int i = 0;
      int j = n-1;
      int maxVal = 0;
      for(;i<j;){
        if(arr[i]>arr[j]){
            cout<<arr[j]<<" "<<"j value "<<j<<endl;
            insertRght(&head,&tail,arr[j]);
            j--;
            maxVal = 0;
        }
        else{
           cout<<arr[i]<<" "<<"i value "<<i<<endl;
            insertleft(&head,&tail,arr[i]);
            i++;
            maxVal = 1;
        }
      }
      
      if(maxVal==1)insertRght(&head,&tail,arr[j]);
      else insertleft(&head,&tail,arr[i]);

      for(i=0;i<n;i++){
        p[i] = head->data;
        head = head->next;
      }
      delete(head);
      delete(tail);

}


int main(){

   int t;
   cin>>t;

   while(t--){
      int n;
      cin>>n;
      int arr[n];

      for(int i=0;i<n;i++){
        cin>>arr[i];
      }
      int p[n],a[n];


      operation(arr,p,n);
     // operation(p,a,n);
      // int ans = 1;
      // for(int i=0;i<n;i++){
      //   if(a[i]!=arr[i])ans = -1;
      // }

      // if(ans==-1)cout<<ans<<endl;
      // else{
        for(int i=0;i<n;i++){
            cout<<p[i]<<" ";
        }cout<<endl;
        // for(int i=0;i<n;i++){
        //     cout<<a[i]<<" ";
        // }cout<<endl;
      // }







   }

}
