#include <bits/stdc++.h>
using namespace std;

class StringStack{
    public:
    string str;
    StringStack* next;

    StringStack()
    {
        StringStack* topS=NULL;
    }

    bool isEmptyS(StringStack* topS)
{
    if(topS==NULL)return true;
    else return false;
}
bool isFullS()
{
    StringStack* new_StringStack=new StringStack;
    if(new_StringStack==NULL)return 1;
    else return 0;
}

void pushS(StringStack* *topS,string x)
{
    if(isFullS())cout<<"StringStack Overflow\n"<<endl;
    else
    {
        StringStack* new_StringStack=new StringStack;
        new_StringStack->str=x;
        new_StringStack->next=*topS;
        *topS=new_StringStack; 

    }
}

void popS(StringStack* *topS)
{
    if(isEmptyS(*topS)){
    cout<<"StringStack UnderFlow\n";
    return;    
    }
    else 
    *topS=(*topS)->next;
     
}
string peekS(StringStack *topS)
{
        string x;
        if(topS==NULL)
        {x='0';}
        else
        {x=topS->str;}
        return x;
}


};   
