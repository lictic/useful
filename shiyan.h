#include<iostream>
#include<string>
#include<string.h>
#include<stdlib.h>
#include<sstream>
#include<fstream>
#define LEN sizeof(struct linklist)
using namespace std;

struct linklist{
    char name[20];
    char sex[10];
    char birthday[12];
    char emile[20];
    int UID;
    int coin; 
    int age;
    struct linklist *next;
};
typedef struct linklist *Linklist;


class Xitong
{
public:
    void Setworker(Linklist *p);
    void Output(Linklist *p);
    void Output1(Linklist *p);
    Linklist Search(Linklist *p,string a);
    void Remove(Linklist *p);
    void Fixcoin(Linklist *p);
    void Sort(Linklist *p);
    void Readfile(Linklist *p);
    void Wirtefile(Linklist *p);
};

