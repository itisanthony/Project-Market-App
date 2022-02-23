#ifndef information_hpp
#define information_hpp
#include<iostream>
#include<cstring>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

class info
{
private:
    struct info_person
    {
        char id[100];
        char name[100];
        char password[100];
        char telephone[100];
        char address[100];
        char money[100];
    };
public:
    void change_info(char*); void insert(char*,int,char*);void input();
    void output_account(char*);
    void recharge(char*,int); 
    void insert_money(char*,int,char*);
    bool checking (char *name);
};

#endif /* information_hpp */
