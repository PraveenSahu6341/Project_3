#include <bits/stdc++.h>
using namespace std;

class Stack{
    public:
    int data;
    Stack* next;
    
    bool isEmpty(Stack* topU)
    {
        if(topU==NULL)return true;
        else return false;
    }

    
    bool isFull()
    {
        Stack* new_Stack=new Stack;
        if(new_Stack==NULL)return 1;
        else return 0;
    } 

    void push(Stack* *topU,int x)
    {
        if(isFull())cout<<"Stack Overflow\n"<<endl;
        else
        {
            Stack* new_Stack=new Stack;
            new_Stack->data=x;
            new_Stack->next=*topU;
            *topU=new_Stack; 
        }
    }

    void pop(Stack* *topU)
    {
        if(isEmpty(*topU)){
        cout<<"Stack UnderFlow\n";
        
        }
        else 
        *topU=(*topU)->next;      
    }

    int peek(Stack *topU)
    {
            int x;
            if(topU==NULL)
            {x=0;}
            else
            {x=topU->data;
            }
            return x;
    }

  
};