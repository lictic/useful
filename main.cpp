#include "shiyan.h"
int main(void)
{
    Linklist head=NULL,cur;
    Xitong p;
    int a=0;
    p.Readfile(&head);
    while(a!=6)
    {
        cout<<"1.����û��˻�"<<endl;
        cout<<"2.��������û��˻���Ϣ"<<endl;
        cout<<"3.ɾ���û����������������Ϣ"<<endl;
        cout<<"4.�����û������޸��˻�Ӳ��,������˻���Ϣ"<<endl;
        cout<<"5.����Ӳ��������"<<endl;
        cout<<"6.���沢�˳�"<<endl;
        cout<<"������Ҫʵ�ֵĹ���: ";
        cin>>a;
        if(a==1)
        {
            p.Setworker(&head);
            p.Wirtefile(&head);
        }
        else if(a==2)
        {
            p.Output(&head);
        }
        else if(a==3)
        {
            p.Remove(&head);
            p.Wirtefile(&head);
        }
        else if(a==4)
        {
            p.Fixcoin(&head);
            p.Wirtefile(&head);
        }
        else if(a==5)
        {
            p.Sort(&head);
            p.Wirtefile(&head);
            p.Output(&head);
        }
        else if(a==6)
        {
            p.Wirtefile(&head);
        }
    }
}