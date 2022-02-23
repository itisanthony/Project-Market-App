#ifndef logn_in_hpp
#define logn_in_hpp
#include <stdio.h>

#include <stdio.h>
#include<iostream>
#include<stdlib.h>
#include<string>
#include<cstring>
using namespace std;

class open
{
private:
    struct info
    {
        char str[100];
        char pass[100];
    }head;
    char id[100],name[100], pass[100],telephone[100],address[100], str[100];
    bool system;
public:
    void sign_admin();
    void sign_customer();
    void sign_up();
    void make_id(int);
};
#endif /* logn_in_hpp */