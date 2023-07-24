#include "shiyan.h"

/*创建用户*/
void Getname(Linklist *p)
{
    Linklist t=*p;
    cout<<"请输入姓名(不得超过15个字符): ";
    cin>>t->name;
    string a=t->name;
    while(a.length()>15)
    {
        cout<<"名字过长,请重新输入: ";
        cin>>t->name;
        a=t->name;
    }
}
void Getsex(Linklist *p)
{
    cout<<"请输入性别: ";
    cin>>(*p)->sex;
     

}
void Getbirthday(Linklist *p)
{
    char a,b,c,d;
    int sum=0;
    cout<<"请输入生日(YYYY-MM-DD): ";
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
    cout<<"请输入邮箱: ";
    cin>>(*p)->emile;
}
void GetUID(Linklist *p,int a)
{
    (*p)->UID=a;
}
void Xitong::Setworker(Linklist *p)/*输入用户信息*/
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
    cout<<"添加成功！"<<endl;
    if(head==NULL)
    {
        (*p)=enter;
    }
    else
    {
        head->next=enter;
    }
}

/*输出函数*/
void Xitong::Output(Linklist *p)
{
    Linklist t=*p;
    while(t!=NULL)
    {
        cout<<"$用户名: "<<t->name<<endl;
        cout<<"性别: "<<t->sex<<endl;
        cout<<"出生日期: "<<t->birthday<<endl;
        cout<<"邮箱: "<<t->emile<<endl;
        cout<<"UID: "<<t->UID<<endl;
        cout<<"硬币: "<<t->coin<<endl;
        cout<<"年龄: "<<t->age<<endl;
        cout<<endl;
        t=t->next;
    }
}
void Xitong::Output1(Linklist *p)/**/
{
    Linklist t=*p;
    cout<<"$用户名: "<<t->name<<endl;
    cout<<"性别: "<<t->sex<<endl;
    cout<<"出生日期: "<<t->birthday<<endl;
    cout<<"邮箱: "<<t->emile<<endl;
    cout<<"UID: "<<t->UID<<endl;
    cout<<"硬币: "<<t->coin<<endl;
    cout<<"年龄: "<<t->age<<endl;      
}

/*寻找链表地址函数*/
Linklist Xitong::Search(Linklist *p,string a)
{
    Linklist t=*p;
    while(t->name!=a&&t!=NULL)
    {
        t=t->next;
    }
    return t;
}

/*删除函数*/
void Xitong::Remove(Linklist *p)
{
    Linklist t=*p,q;
    Xitong w;
    string a;
    cout<<"请输入要删除的用户名: ";
    cin >>a;
    q=w.Search(&t,a);
    if(q==NULL)
    {
        cout<<"输入的不存在";
        return;
    }
    if(q==(*p))/*删除头指针*/
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
    cout<<"删除成功！"<<endl;
}

/*修改硬币数*/
void Xitong::Fixcoin(Linklist *p)
{
    string a;
    int b;
    Xitong w;
    Linklist t=*p,q;
    cout<<"请输入要修改的用户名和硬币数: ";
    cin>>a>>b;
    q=w.Search(&t,a);
    q->coin=b;
    cout<<endl;
    cout<<"修改成功！"<<endl;
    w.Output1(&q);
}

/*交换语句*/
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
/*排序函数*/
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

/*读文件*/
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
/*写文件*/
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