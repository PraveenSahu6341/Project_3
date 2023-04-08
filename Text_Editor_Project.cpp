#include <bits/stdc++.h>
#include <fstream>
#include "IntStack.cpp"
#include "StringStack.cpp"

using namespace std;


class Node{
    public:
    string data;
    Node* next;
};

void insert_data(Node** head,string str,int* t_nodes,int line,int menu)
{
    // INSERTING NEW DATA IF NOT EXIST..
    Node* curr=*head;
    Node* prev=*head;
    
    if(*head==NULL)
    {  
        Node* head_node=new Node;
        head_node->data=str;
        head_node->next=*head;
        *head=head_node;
        (*t_nodes)++;
        return ;   
    }
    else if(menu==10)
    {
         if(*head==NULL or line==0){
        Node* head_node=new Node;
        head_node->data=str;
        head_node->next=*head;
        *head=head_node;
        (*t_nodes)++;
        return ;  
        }
        
        else{
    while(curr && line>0 )
    { 
        prev=curr;
        curr=curr->next;
        --line;
    }
    Node * new_node=new Node;
        prev->next=new_node;
        new_node->data=str;
        new_node->next=curr;
        ++(*t_nodes);
       
    }    
    }
    else{
    while(curr)
    {   
        prev=curr;
        curr=curr->next;
    }
    Node * new_node=new Node;
        prev->next=new_node;
        new_node->data=str;
        new_node->next=curr;
        ++(*t_nodes);
    }
   
}


void update(Node* head,int line,string str,int* t_nodes)
{
    // UPDATING THE EXISITING DATA
    Node* curr=head;
    int i=0;
    while(i!=(line) && curr!=NULL)
    {curr=curr->next;i++;}
    curr->data=str;
    }

int append(Node* head,int line,string str,int menu,int length)
{
    // APPENDING NEW DATA TO THE EXISTING DATA
  
    Node* curr=head;
    int i=0;
    while(i!=(line) && curr!=NULL)
    {curr=curr->next;i++;}
    if(menu==4 or menu==11){
    int length=curr->data.length();
    if(curr->data=="")curr->data=curr->data+str;
    else
    curr->data=curr->data+" "+str;
    return length;
    }

    else if(menu==10){
       
       int size=str.length();
        curr->data.replace(length, size+1,"");

    }
}

void printNodes(Node* head,int* t_nodes)
{
    // cout<<head<<endl;
    cout<<"_____________________________________________________________________________________________\n";
    if(head!=NULL){
    Node* curr=head;
   
while(curr!=NULL)
{   
    cout<<curr->data<<endl;
    curr=curr->next;
}
    }{for(int i=1;i<=15-*t_nodes;i++)cout<<endl;}
    cout<<"_____________________________________________________________________________________________\n\n\n\n";

}

void delete_single(Node** head,int line,int *dS,int* t_nodes,StringStack **topS,StringStack contentU,string* s_str)
{
    // DELETING THE CONTENTS OF THE GIVEN line.
    Node* curr=*head;
    int i=0;
    if(line>=*t_nodes or line<0)
    {cout<<"Invalid Node!!!!\nTHIS LINE IS NOT PRESENT!!"<<endl;
    *dS=0;
    }
    
    else if((line)==0)
    {
        Node* temp=*head;
         contentU.pushS(&(*topS),curr->data);
          *s_str=contentU.peekS(*topS);
        *head=(*head)->next;
        delete temp;
        (*t_nodes)--;
    }
    else{

    while(i!=(line-1) && curr!=NULL)
    {curr=curr->next;i++;}
    Node* temp=curr->next; 
    contentU.pushS(&(*topS),curr->next->data);
    *s_str=contentU.peekS(*topS);
    curr->next=curr->next->next; 
    delete temp;  
    --(*t_nodes);

    }
    
}
void delete_last(Node** head,int* t_nodes,StringStack **topS,StringStack contentU,string *str,int *InsertCount,int *check,int menu)
{
     Node* curr=*head;
     
     if(*t_nodes==0)
     {
        cout<<"\nNo data to be deleted!!!\n"<<endl;
        *check=0;
        return ;
     }
     else if(*t_nodes==1)
     {
        Node* temp=*head;
        if(menu==6 or menu==11){
        contentU.pushS(&(*topS),(*head)->data);
        *str=contentU.peekS(*topS);}
        *head=(*head)->next;
        delete temp;
         --(*t_nodes);
     }
    else
    {
        
        while(curr->next->next!=NULL)
            curr=curr->next;
        if(menu==6 or menu==11){
        contentU.pushS(&(*topS),curr->next->data);
        *str=contentU.peekS(*topS);}
        Node* temp=curr->next;
        curr->next=curr->next->next;
        delete temp;
         --(*t_nodes);
    }
    (*InsertCount)--;
    
}


int search(string *Str,Node *head,string data,int menu)
{
    Node * curr=head;
    int i=0;
    size_t found; 
    int count=0;

    while(curr != NULL){
        i++;
        string str,str2;
        str=curr->data;
        str2=data;
        int len=data.length();
       
        for(int k=0;k<str.length();k++)
        str[k]=toupper(str[k]);
      
        for(int k=0;k<str2.length();k++)
		str2[k]=toupper(str2[k]);
        found = str.find(str2);
        int c=0;
        while (found != string::npos){
            
            if(c==0 && menu==7)
            {cout<<"\nFound at line "<<i<<" at character "<<found+1;c++;}
            else if(menu==3)
            curr->data.replace(found,len,*Str);
            else if(menu==10)
            curr->data.replace(found,len,*Str);
            else if(menu==11)
            curr->data.replace(found,len,*Str);
            else cout<<","<<found+1;
            count++;
            found = curr->data.find(data,found+1);
        }
        curr = curr->next;
        
    }cout<<"\n\n";if(count==0)cout<<"Not Found.\n"<<endl;
    return count;
}


int main(){
cout<<"\n\t\t\t\t\tTEXT EDITOR\n\t\t\t\t\t-----------\n";

int totalFiles,line,length,InsertCount=0, lines=0,t_nodes=0, check=1,dS=1,i,val,d=0,U_R=0;
StringStack contentU,contentR,* topS=NULL,*topSR=NULL;;
string Str,subStr,str,s_str,file;
Node* head=NULL,*tail=NULL;
Stack Undo,Redo, *top=NULL,*topR=NULL;


do
{
    cout<<"\n1) Open File 2) Insert 3) Update 4) Append 5) Display 6) Delete 7) Search 8) Save 9) Save As 10) Undo 11) Redo 12) Quit"<<endl;
    cout<<"\nCHOICE (1-12): ";
    cin>>i;
int menu=i;

if(menu==1)
{ string st;
     totalFiles=0;
    cout<<"Enter the file path: ";
    cin>>file;
   
    if(file[0]=='"') file.replace(0, 1,"");
    if(file[file.length()-1]=='"') file.replace(file.length()-1, 1,"");

    ifstream in(file);
    if(in){
    while(in.eof()==0)
    {
    getline(in,st);
     InsertCount++;
     totalFiles++;    
     if(st!="")
     {insert_data(&head,st,&t_nodes,line,menu);
    contentU.pushS(&topS,st);}
    else{
    insert_data(&head,"",&t_nodes,line,menu);
    contentU.pushS(&topS,"");
    }
    }
    Undo.push(&top,totalFiles);
    Undo.push(&top,menu);
    printNodes(head,&t_nodes);}
    else{cout<<"\nFile doesn't exist"<<endl;file="";continue;}
     
}
else if(menu==2)
{
    int line;
    cout<<"Enter Substring: ";
    cin.ignore();
    getline(cin,subStr);
    insert_data(&head,subStr,&t_nodes,line,menu);  
    InsertCount++;  
    contentU.pushS(&topS,subStr);
    Undo.push(&top,menu);
    printNodes(head,&t_nodes);   
}


else if(menu==3)
{
    int count;
    // string Str; 
    // cout<<"\n\nEnter the line number : ";
    // int line;
    // cin>>line;
    cout<<"\nEnter Substring: ";
    cin.ignore();
    getline(cin,subStr);
    contentU.pushS(&topS,subStr);
    cout<<"Enter the new string : ";
    getline(cin,Str);  
    contentU.pushS(&topS,Str);
    count=search(&Str,head,subStr,menu);
    Undo.push(&top,menu);
    if(count==0)
    {
        contentU.popS(&topS);
        contentU.popS(&topS);
        Undo.pop(&top);
    }else
    printNodes(head,&t_nodes);

}

else if(menu==4)
{
    int line;
    
    cout<<"\n\nEnter the line number : ";
    cin>>line;  
    if(line>t_nodes or line<=0)
    { cout<<"\nAppending to Invalid Node...\n"<<endl;}
    else{
    cout<<"Enter Substring: ";
    cin.ignore();
    getline(cin,subStr);
    contentU.pushS(&topS,subStr);
    int length=append(head,line-1,subStr,menu,length);
    Undo.push(&top,line);
    Undo.push(&top,length);
    Undo.push(&top,menu);
    printNodes(head,&t_nodes);}
}
else if(menu==5)printNodes(head,&t_nodes);
else if(menu==6)
{
cout<<"\n1. Delete Last Node\n2. Delete Single Line\n3. Delete All\n\n";
cin>>val;

if(val==1)
{
   
    Undo.push(&top,val);
    Undo.push(&top,menu);
    delete_last(&head,&t_nodes,&topS,contentU,&str,&InsertCount,&check,menu);
        if(check==0){
        Undo.pop(&top);
        Undo.pop(&top);
        check=1;
        }else printNodes(head,&t_nodes);

}
else if(val==2)
{  
     int line;
    cout<<"\n\nEnter the line number : ";
    cin>>line;
    Undo.push(&top,line-1);Undo.push(&top,val);Undo.push(&top,menu);
    delete_single(&head,line-1,&dS,&t_nodes,&topS,contentU,&s_str);
    if(dS==0)
    {
        Undo.pop(&top);Undo.pop(&top);Undo.pop(&top);dS=1;
    }
    else{
    InsertCount--;
     printNodes(head,&t_nodes);}
}

else if(val==3)

{
    d=0;
    while(t_nodes!=0){d++;
    delete_last(&head,&t_nodes,&topS,contentU,&str,&InsertCount,&check,menu);}
    Undo.push(&top,d);
    Undo.push(&top,3);
    Undo.push(&top,menu);
    if(d==0)
    {cout<<"\nNO DATA TO BE DELETED\n"; Undo.pop(&top);Undo.pop(&top);Undo.pop(&top); }
    else { cout<<"\nALL CONTENTS DELETED!!\n";
    
    printNodes(head,&t_nodes);}
}

}
else if(menu==7)
{   string data;
    cout<<"Enter data to be searched: ";
    cin.ignore();
    getline(cin,data);
     search(&data,head,data,menu);
    }

else if(menu==8 or menu==9)
{
    string Savefile;
    if(menu==9 or (menu==8 and (file==""))){
    cout<<"Enter file path & name(with extension): ";
    cin >> Savefile;int count=0;
    for(int element=0;element<Savefile.size();element++){
    if (Savefile == " " or Savefile == "."  or Savefile[element] == '\\' or Savefile[element] == '/' or Savefile[element] == '*' or Savefile[element] == ':' or Savefile[element] == '?' or Savefile[element] == '<' or Savefile[element] == '>' or Savefile[element] == '|' ){cout<<"\nGive correct file name.\n";count=1;break;}}
    if(count==0){cout<<"\nFile Saved.\n";
     if(Savefile[0]=='"') Savefile.replace(0, 1,"");
    if(Savefile[Savefile.length()-1]=='"') Savefile.replace(Savefile.length()-1, 1,"");}}
    else {Savefile=file;cout<<"\nFile Saved.\n";}
    ofstream out(Savefile);
    Node* curr=head;
while(curr!=NULL)
{
    out<<curr->data<<endl;
    curr=curr->next;
}

}
else if(menu==10)
{
    if(head!=NULL && Undo.peek(top)!=6){
      if(Undo.peek(top)==1)
    {
    
        int totalFiles=Undo.peek(top);
        // Redo.push(&topR,);
        Undo.pop(&top);
        for(int i=1;i<=Undo.peek(top);i++)
        {
        delete_last(&head,&t_nodes,&topS,contentU,&str,&InsertCount,&check,menu);
        contentR.pushS(&topSR,contentU.peekS(topS));
        contentU.popS(&topS);
        }
        Redo.push(&topR,Undo.peek(top));
        Redo.push(&topR,totalFiles);
        Undo.pop(&top);
        printNodes(head,&t_nodes);   
    }
    
    
    else if(Undo.peek(top)==2)
    {
        
        delete_last(&head,&t_nodes,&topS,contentU,&str,&InsertCount,&check,menu);
        contentR.pushS(&topSR,contentU.peekS(topS));
        contentU.popS(&topS);
        Redo.push(&topR,Undo.peek(top));
        Undo.pop(&top);
        printNodes(head,&t_nodes);
   
    }
    else if(Undo.peek(top)==3)
    {
        subStr=contentU.peekS(topS);

        contentU.popS(&topS);
        Str=contentU.peekS(topS);
        contentR.pushS(&topSR,Str);
        contentU.popS(&topS);
        contentR.pushS(&topSR,subStr);
      
        search(&Str,head,subStr,10);
        Redo.push(&topR,Undo.peek(top));
        Undo.pop(&top);
        printNodes(head,&t_nodes);
    }
    else if(Undo.peek(top)==4)
    {
        Undo.pop(&top);

        string subStr=contentU.peekS(topS);
        contentR.pushS(&topSR,contentU.peekS(topS));
        contentU.popS(&topS);
        int length=Undo.peek(top);
        Undo.pop(&top);
        int line=Undo.peek(top);
        Undo.pop(&top);
        Redo.push(&topR,line);
        Redo.push(&topR,length);
        Redo.push(&topR,4);
        length=append(head,line-1,subStr,10,length);
        printNodes(head,&t_nodes);
    }    }
    
    else if(Undo.peek(top)==6)
    {
        Undo.pop(&top);
        if(Undo.peek(top)==1)
        {
            int line=0;
            Node* temp=head;
            while(temp){line++;temp=temp->next;}
            if(check!=0){
            str=contentU.peekS(topS);
            contentU.popS(&topS);}
            insert_data(&head,str,&t_nodes,line,menu);
            InsertCount++;
            Redo.push(&topR,Undo.peek(top));
            Undo.pop(&top);  
            Redo.push(&topR,6);
            printNodes(head,&t_nodes); 

        }
        else if(Undo.peek(top)==2)
        {
            Undo.pop(&top);   
            s_str=contentU.peekS(topS);
            contentU.popS(&topS);
            int line=Undo.peek(top);
            insert_data(&head,s_str,&t_nodes,line,menu);
            Redo.push(&topR,Undo.peek(top));
            Undo.pop(&top);  
            Redo.push(&topR,2);
            Redo.push(&topR,6);
            InsertCount++;
            printNodes(head,&t_nodes);

        }
        else if(Undo.peek(top)==3)
        {
            Undo.pop(&top); 
            d=Undo.peek(top);
            cout<<"D: "<<d<<endl;
            Undo.pop(&top);
            while(d!=0){
            s_str=contentU.peekS(topS);
            contentU.popS(&topS);
             insert_data(&head,s_str,&t_nodes,line,menu); d--;
             InsertCount++;
             }     
             
             Redo.push(&topR,d);
             Redo.push(&topR,3);
             Redo.push(&topR,6);
            printNodes(head,&t_nodes);       
        }}
    else cout<<"\nCan't Undo!!!!"<<endl;
    U_R=0;
    
}

else if(menu==11 )
{

 if(U_R==0){
    if(topR!=NULL){
  
        if(Redo.peek(topR)==1)
  {  
        Redo.pop(&topR);
        Undo.push(&top,Redo.peek(topR));
    for(int i=1;i<=Redo.peek(topR);i++){
 
       insert_data(&head,contentR.peekS(topSR),&t_nodes,line,menu);++InsertCount;
        contentU.pushS(&topS,contentR.peekS(topSR));
        contentR.popS(&topSR);}
        Redo.pop(&topR);
        Undo.push(&top,1);
        printNodes(head,&t_nodes); 
  }
  else if(Redo.peek(topR)==2)
  {
    insert_data(&head,contentR.peekS(topSR),&t_nodes,line,menu);
        ++InsertCount;
        contentU.pushS(&topS,contentR.peekS(topSR));
        contentR.popS(&topSR);
        Undo.push(&top,Redo.peek(topR));
        Redo.pop(&topR);
          printNodes(head,&t_nodes); 
  }

  else if(Redo.peek(topR)==3)
    {
        Str=contentR.peekS(topSR);
        contentR.popS(&topSR);
        subStr=contentR.peekS(topSR);
        contentR.popS(&topSR);

        contentU.pushS(&topS,subStr);
        contentU.pushS(&topS,Str);
         search(&Str,head,subStr,11);
        Undo.push(&top,Redo.peek(topR));
        Redo.pop(&topR);
        printNodes(head,&t_nodes);
    }
 else if(Redo.peek(topR)==4)
    {
        Redo.pop(&topR);

        string subStr=contentR.peekS(topSR);
        contentU.pushS(&topS,contentR.peekS(topSR));
        contentR.popS(&topSR);
        int length=Redo.peek(topR);
        Redo.pop(&topR);
        int line=Redo.peek(topR);
        Redo.pop(&topR);
        Undo.push(&top,line);
        Undo.push(&top,length);
        Undo.push(&top,4);
        length=append(head,line-1,subStr,11,length);
        printNodes(head,&t_nodes);
    }

     else if(Redo.peek(topR)==6)
    {
           
        Redo.pop(&topR);
        if(Redo.peek(topR)==1)
        {
            Undo.push(&top,val);
            Redo.pop(&topR);
            Undo.push(&top,6);
            delete_last(&head,&t_nodes,&topS,contentU,&str,&InsertCount,&check,menu);
            if(check==0){
            Redo.pop(&topR);
            Redo.pop(&topR);
            check=1;}

            else printNodes(head,&t_nodes);
        }
        else if(Redo.peek(topR)==2){   
            Redo.pop(&topR);
            Undo.push(&top,Redo.peek(topR));
            delete_single(&head,Redo.peek(topR),&dS,&t_nodes,&topS,contentU,&s_str);
            Redo.pop(&topR);
            Undo.push(&top,2);
            Undo.push(&top,6);
            
            InsertCount--;
            printNodes(head,&t_nodes); 
        }
        else if(Redo.peek(topR)==3)
        {
            d=0;
            while(t_nodes!=0){d++;
            delete_last(&head,&t_nodes,&topS,contentU,&str,&InsertCount,&check,menu);}
            Undo.push(&top,d);
             Redo.pop(&topR);
            Undo.push(&top,3);
             Redo.pop(&topR);
            Undo.push(&top,6);
       
        cout<<"\nALL CONTENTS DELETED!!\n";
            
            printNodes(head,&t_nodes);}  
        }
    }
 else cout<<"\nCan't Redo!!!!"<<endl;
 }
  else cout<<"\nCan't Redo!!!!"<<endl;    
}

else if(menu==12)break;
else if(i>12 or i<0 ){cout<<"Enter Valid Input\n\n";}

if(menu==10)U_R=0;
else if(menu!=11 && menu!=5 && (menu>0 and menu<=6))
{
    U_R=1;
    topSR=NULL;
    topR=NULL;
}

}while(true);
return 0;
}

