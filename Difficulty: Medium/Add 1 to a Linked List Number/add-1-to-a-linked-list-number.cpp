//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data%10; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    Node *reverse(Node *head){
        if(head==NULL || head->next==NULL){
            return head;
        }
        Node *newhead=reverse(head->next);
        Node *front=head->next;
        front->next=head;
        head->next=NULL;
        return newhead;
    }
    Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding one
        Node *newhead=reverse(head);
        Node *temp=newhead;
        bool carry=false;
        if(temp->data==9){
            temp->data=0;
            carry=true;
            //temp=temp->next;
        }
        else {
            temp->data += 1;
            carry = false;
        }
        temp = temp->next;
        while(temp!=NULL){
            if(carry){
                if(temp->data==9){
                    carry=true;
                    temp->data=0;
                }
                else{
                    carry=false;
                    temp->data+=1;
                }
                
            }
            temp=temp->next;
        }
        Node *newhead2=reverse(newhead);
        if(carry){
             Node *dummy = new Node(1);
            dummy->next = newhead2;
            newhead2 = dummy;
        }
        return newhead2;
        
        
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends