#include<iostream>
#include<vector>
#define null NULL

using namespace std;

struct list{
       int data;
       list *next;
       };

void print(list *head);
void split(list *,list **,list **);  
void mergesort(list **head);
void merge(list **head,list *a,list *b) ;

 
int main(){
  
  int n;
    cin>>(n);// no of elements
       if(n<1)return 0;
             int data;
             cin>>data;
             list *head = new list;
             head->data=data;
             head->next=NULL;
             list* p1=head;
             for(int i=1;i<n;i++){cin>>data;
             list* p=new list;
             p->data=data;p->next=NULL;p1->next=p;p1=p1->next;}
             mergesort(&head);
           cout<<endl;  
           print(head);  
           cout<<endl;  
           
    system("pause");
    return 0;
    }
 
 void split(list *head,list **a,list **b){
      list *slow=head,*fast=(head)->next;
      while(fast!=null){
                        fast=fast->next;
                        if(fast!=null){
                          fast=fast->next;
                          slow=slow->next;
                        }
      
      }*b=slow->next;slow->next=null;*a=head;
}    

void mergesort(list **head){
     list *a,*b;
     split(*head,&a,&b);
     if(a!=null&&a->next!=null){
                                mergesort(&a);
                                }
     if(b!=null&&b->next!=null){
                                mergesort(&b);
                                }
      merge(head,a,b);            
     }

void merge(list **head,list *a,list *b){
     
     if(a==null)*head=b;
     else if(b==null)*head=a;
     else{
          list *neww;
          if(a->data>b->data){*head=b;b=b->next;}
          neww=*head;
          while(a!=null||b!=null){
                                  if(a==null||(b!=null && a->data>b->data)){neww->next=b;b=b->next;neww=neww->next;}
                                  else{ neww->next=a;a=a->next;neww=neww->next;  }
                                  }neww->next=null;
          
          
          }
     }
      
  void print(list *head){
     
    while(head!=null){
     cout<<head->data;head=head->next;}
     
     }
