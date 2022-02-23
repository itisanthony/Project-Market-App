#ifndef seller_hpp
#define seller_hpp

#include <stdio.h>
class selling
{
private:
    bool have;
    struct object
    {
        char id_name[100];
        char id_good[100];
        char name_object[100];
        char price[100];
        char time[100];
        char discription[100];
        char status[100];
        int year;
        int month;
        int day;
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
public:
    void posting(char*);
    void clock(object *);void convert(int count, object *);
    void id_naming(object*,int);
    
    void output(char*);

    void change_info();
    void insert(char *, int,char*,bool); 
    void input();
     
    void deleting_things(char *); void deleting_object(char *name);void input_object();

    void output_order(char *);
    void put_zero(int,char *);
    void put_char(int, char *);
};

#endif /* seller_hpp */
