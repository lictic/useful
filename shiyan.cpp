#include "shiyan.h"

/*�����û�*/
void Getname(Linklist *p)
{
    Linklist t=*p;
    cout<<"����������(���ó���15���ַ�): ";
    cin>>t->name;
    string a=t->name;
    while(a.length()>15)
    {
        cout<<"���ֹ���,����������: ";
        cin>>t->name;
        a=t->name;
    }
}
void Getsex(Linklist *p)
{
    cout<<"�������Ա�: ";
    cin>>(*p)->sex;
     

}
void Getbirthday(Linklist *p)
{
    char a,b,c,d;
    int sum=0;
    cout<<"����������(YYYY-MM-DD): ";
    cin>>(*p)->birthday ;
    for(int i=0;i<=3;i++)
    {
        switch ((*p)->birthday[i])
        {
        case '1':sum=sum*10+1;
            break;
        case '2':sum=sum*10+2;
            break;
        case '3':sum=sum*10+3;
            break;
        case '4':sum=sum*10+4;
            break;
        case '5':sum=sum*10+5;
            break;
        case '6':sum=sum*10+6;
            break;
        case '7':sum=sum*10+7;
            break;
        case '8':sum=sum*10+8;
            break;
        case '9':sum=sum*10+9;
            break;
        case '0':sum=sum*10+0;
            break;
        default:
            break;
        }
    }
    (*p)->age=2023-sum;
}
void Getemail(Linklist *p)
{
    cout<<"����������: ";
    cin>>(*p)->emile;
}
void GetUID(Linklist *p,int a)
{
    (*p)->UID=a;
}
void Xitong::Setworker(Linklist *p)/*�����û���Ϣ*/
{
    Linklist cur,head=*p,tail,enter=NULL;
    int k = 0,i=1;
    char a;
    if(head!=NULL)
    {
        while(head->next!=NULL)
        {
            head=head->next;
            i++;
        }
        i=i+1;
    }
    cur=(Linklist)malloc(LEN);
    cur->next=NULL;
    if(enter==NULL)
    {
        enter=cur;
        tail=cur;
    }
    else
    {
        tail->next=cur;
        tail=cur;
    }
    Getname(&cur);
    cout<<endl;
    Getsex(&cur);
    cout<<endl;
    Getbirthday(&cur);
    cout<<endl;
    Getemail(&cur);
    cout<<endl;
    GetUID(&cur,i);
    cout<<endl;
    cur->coin=100;
    i++;
    cout<<"��ӳɹ���"<<endl;
    if(head==NULL)
    {
        (*p)=enter;
    }
    else
    {
        head->next=enter;
    }
}

/*�������*/
void Xitong::Output(Linklist *p)
{
    Linklist t=*p;
    while(t!=NULL)
    {
        cout<<"$�û���: "<<t->name<<endl;
        cout<<"�Ա�: "<<t->sex<<endl;
        cout<<"��������: "<<t->birthday<<endl;
        cout<<"����: "<<t->emile<<endl;
        cout<<"UID: "<<t->UID<<endl;
        cout<<"Ӳ��: "<<t->coin<<endl;
        cout<<"����: "<<t->age<<endl;
        cout<<endl;
        t=t->next;
    }
}
void Xitong::Output1(Linklist *p)/**/
{
    Linklist t=*p;
    cout<<"$�û���: "<<t->name<<endl;
    cout<<"�Ա�: "<<t->sex<<endl;
    cout<<"��������: "<<t->birthday<<endl;
    cout<<"����: "<<t->emile<<endl;
    cout<<"UID: "<<t->UID<<endl;
    cout<<"Ӳ��: "<<t->coin<<endl;
    cout<<"����: "<<t->age<<endl;      
}

/*Ѱ�������ַ����*/
Linklist Xitong::Search(Linklist *p,string a)
{
    Linklist t=*p;
    while(t->name!=a&&t!=NULL)
    {
        t=t->next;
    }
    return t;
}

/*ɾ������*/
void Xitong::Remove(Linklist *p)
{
    Linklist t=*p,q;
    Xitong w;
    string a;
    cout<<"������Ҫɾ�����û���: ";
    cin >>a;
    q=w.Search(&t,a);
    if(q==NULL)
    {
        cout<<"����Ĳ�����";
        return;
    }
    if(q==(*p))/*ɾ��ͷָ��*/
    {
        (*p)=t->next;
    }
    else
    {
        while(t->next!=q)
        {
            t=t->next;
        }
        t->next=(t->next)->next;
    }
    cout<<endl;
    cout<<"ɾ���ɹ���"<<endl;
}

/*�޸�Ӳ����*/
void Xitong::Fixcoin(Linklist *p)
{
    string a;
    int b;
    Xitong w;
    Linklist t=*p,q;
    cout<<"������Ҫ�޸ĵ��û�����Ӳ����: ";
    cin>>a>>b;
    q=w.Search(&t,a);
    q->coin=b;
    cout<<endl;
    cout<<"�޸ĳɹ���"<<endl;
    w.Output1(&q);
}

/*�������*/
void Exchange(Linklist *p,Linklist *q)
{
    Linklist t1=*p,t2=*q;
    char a[20],b[10],c[12],d[20];
    int num1,num2,num3;
    strcpy(a,t1->name);
    strcpy(b,t1->sex);
    strcpy(c,t1->birthday);
    strcpy(d,t1->emile);
    num1=t1->UID;
    num2=t1->coin;
    num3=t1->age;
    strcpy(t1->name,t2->name);
    strcpy(t1->sex,t2->sex);
    strcpy(t1->birthday,t2->birthday);
    strcpy(t1->emile,t2->emile);
    t1->UID=t2->UID;
    t1->coin=t2->coin;
    t1->age=t2->age;
    strcpy(t2->name,a);
    strcpy(t2->sex,b);
    strcpy(t2->birthday,c);
    strcpy(t2->emile,d);
    t2->UID=num1;
    t2->coin=num2;
    t2->age=num3;
}
/*������*/
void Xitong::Sort(Linklist *p)
{
    Linklist t=*p,q=*p;
    int i=0,a,b;
    while(q->next!=NULL)
    {
        q=q->next;
        i++;
    }
    for(a=0;a<i;a++)
    {
        t=*p;
        for(b=0;b<i;b++)
        {
            if(t->coin>=(t->next)->coin)
            {
                if(t->coin<(t->next)->coin)
                {
                    Exchange(&t,&(t->next));
                }
                else
                {
                    if(t->age<(t->next)->age)
                    {
                        Exchange(&t,&(t->next));
                    }
                }
            }
        }
    }
}

/*���ļ�*/
void Xitong::Readfile(Linklist *p)
{
    Linklist cur=NULL,tail=NULL;
    fstream fp;
    string a;
    Xitong w;
    char b[20],c[10],d[12],e[20];
    int num1,num2,num3;
    fp.open("C:\\shiyan\\wenjian.txt",ios::in);
    if(!fp.is_open())
    {
        cout<<"Can not open the file!!";
        return;
    }
    while(getline(fp,a))
    {
        istringstream record(a);
        cur=(Linklist)malloc(LEN);
        while(record >>b>>c>>d>>e>>num1>>num2>>num3)
        {
            strcpy(cur->name,b);
            strcpy(cur->sex,c);
            strcpy(cur->birthday,d);
            strcpy(cur->emile,e);
            cur->UID=num1;
            cur->coin=num2;
            cur->age=num3;
            cur->next=NULL;
            if(*p==NULL)
            {
                *p=cur;
                tail=cur;
            }
            else
            {
                tail->next=cur;
                tail=cur;
            }
        }
    }
    
    fp.close();
}
/*д�ļ�*/
void Xitong::Wirtefile(Linklist *p)
{
    Linklist t=*p;
    fstream fp;
    fp.open("C:\\shiyan\\wenjian.txt",ios::out);
    while(t!=NULL)
    {
        fp<<t->name<<" "<<t->sex<<" "<<t->birthday<<" "<<t->emile<<" "<<t->UID<<" "<<t->coin<<" "<<t->age<<endl;
        t=t->next;
    }
    fp.close();
}