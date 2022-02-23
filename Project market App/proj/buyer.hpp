#ifndef buyer_hpp
#define buyer_hpp

#include <stdio.h>
class buying
{
private:
    char id[100];
    struct things
    {
        char id_name[100];
        char id_good[100];
        char name_object[100];
        char price[100];
        char timing[100];
        char discription[100];
        char status[100];
    };
    struct orders
    {
        char id_order[100];
        char id_good[100];
        char price[100];
        char timing[100];
        char id_seller[100];
        char id_buyer[100];
    };
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
    void output_things();
    void searching_things(); bool search(char *,char*);
    void output_order(char *);
    void information();

    void make_order(char*);
    void put_zero(int sum1,char *sum);
    void put_char(int sum1, char *sum);
    void make_id(int);
    bool check_object(char *,char*);
    void change(char *,char *,int ,int ,int );
    void change_things(char *);
    void input_object();
    void input_person();
    void output_(char *, char*,double ,int ,int ,int ,char *);
};
#endif /* buyer_hpp */

