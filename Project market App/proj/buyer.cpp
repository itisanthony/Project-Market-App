#include"buyer.hpp"
#include<iostream>
#include<stdlib.h>
#include<cstring>
#include<iomanip>
using namespace std;
void buying::output_things()
{
    FILE *source = fopen("/Users/anthonyhuang/Desktop/APPLICATION/FILE/goods.txt", "r");
    if (source == NULL)
    {
        cout<<"error"<<endl;
        exit(EXIT_FAILURE);
    }
    bool temp = false;
    things *head=NULL;
    head=new things;
    while(fscanf(source, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%s\n",head->id_good,head->name_object,head->price,head->discription,head->id_name,head->timing,head->status)!=EOF)
    {
        if(strcmp(head->status,"销售中")==0)
        {
            if(temp==false)
            {
                cout<<"************************************************************************"<<endl;
                printf("%-15s %-15s %-18s %-19s %-18s\n", "ID", "名称", "价格", "上架时间","卖家ID");
                temp=true;
            }
            printf("%-15s %-15s %-15s %-15s %-15s\n",head->id_good,head->name_object,head->price,head->timing,head->id_name); 
        }
        
    }
    if(temp==false)
    {
        cout<<"没有东西"<<endl;
    }
    else
    {
        cout<<"************************************************************************"<<endl;
    }
    fclose(source);
}
void buying::searching_things()
{
    FILE *source = fopen("/Users/anthonyhuang/Desktop/APPLICATION/FILE/goods.txt", "r");
    if (source == NULL)
    {
        cout<<"error"<<endl;
        exit(EXIT_FAILURE);
    }
    char tmp[100]={};
    cout<<"请输入商品名称:";
    cin>>tmp;
    bool temp=false;
    things *head=NULL;
    head=new things;
    while(fscanf(source, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%s\n",head->id_good,head->name_object,head->price,head->discription,head->id_name,head->timing,head->status)!=EOF)
    {
        if(search(tmp,head->name_object)&&strcmp(head->status,"销售中")==0)
        {
            if(temp==false)
            {
                cout<<"***************************************"<<endl;
                printf("%-15s %-16s %-15s\n", "ID", "名称", "价格");
                temp =true;
            }
            printf("%-15s %-18s %-15s \n",head->id_good,head->name_object,head->price);
        }
        
    }
    if(temp==false)
    {
        cout<<"***************************************"<<endl;
        cout<<"没有找到您想搜索的商品！即将返回初始界面"<<endl;
    }
    cout<<"***************************************"<<endl;
    fclose(source);
}
bool buying::search(char *str, char *string)
{
    int len =0;
    if(strcmp(str, string)==0)
        return true;
    else
    {
        int j =0;
        for(int i =0; string[i]!='\0';i++)
        {
            if(str[j]==string[i])
            {
                len++;
                j++;
                for(int k=i+1; string[k]!='\0';k++)
                {
                    if(str[j] ==string[k])
                    {
                        len++;
                        j++;
                    }
                }
            }
            if(len==strlen(str))
                break;
        }
        if(len==strlen(str))
            return true;
        else
            return false;
    }
        
}
void buying::output_order(char *name)
{
    FILE *source = fopen("/Users/anthonyhuang/Desktop/APPLICATION/FILE/order.txt", "r");
    if (source == NULL)
    {
        cout<<"error"<<endl;
        exit(EXIT_FAILURE);
    }
    bool order = false;
    orders *temp=NULL;
    temp= new orders;
    while(fscanf(source, "%[^,],%[^,],%[^,],%[^,],%[^,],%s\n",temp->id_order,temp->id_good,temp->price,temp->timing,temp->id_seller,temp->id_buyer)!=EOF)
    {
        if(strcmp(name,temp->id_buyer)==0)
        {
            if(order==false)
            {
                cout<<"********************************************************************************************"<<endl;
                printf("%-16s %-16s %-21s %-18s %-18s %-15s\n", "订单ID","商品ID", "交易金额", "交易时间","买家ID","卖家ID");
                order=true;
            }
            printf("%-15s %-15s %-15s %-15s %-15s %-15s\n",temp->id_order,temp->id_good,temp->price,temp->timing,temp->id_seller,temp->id_buyer);
        }
        
    }
    if(order == false)
    {
        cout<<"***********"<<endl;
        cout<<"没有订单"<<endl;
        cout<<"***********"<<endl;
    }
    else
    {
        cout<<"********************************************************************************************"<<endl;
    }
    fclose(source);

}
void buying::information()
{
    char name[100]={};
    FILE *source = fopen("/Users/anthonyhuang/Desktop/APPLICATION/FILE/goods.txt", "r");
    if (source == NULL)
    {
        cout<<"error"<<endl;
        exit(EXIT_FAILURE);
    }
    bool info=false;
    cout<<"请输入您想查看商品ID:";
    cin >> name;
    things *head=NULL;
    head=new things;
    cout<<"*****************************"<<endl;
    while(fscanf(source, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%s\n",head->id_good,head->name_object,head->price,head->discription,head->id_name,head->timing,head->status)!=EOF)
    {
        if(strcmp(head->id_good,name)==0)
        {
            cout<<"名称:      "<<head->name_object<<endl;
            cout<<"描述:      "<<head->discription<<endl;
            cout<<"上架时间:  "<<head->timing<<endl;
            cout<<"卖家ID:    "<<head->id_name<<endl;
            cout<<"商品状态:  "<<head->status<<endl;
            info = true;
        }
    }
    if(info==false)
    {  
        cout<<"清单上没有这样的项目"<<endl;
        cout<<"*****************************"<<endl;
    }
    else
    {
        cout<<"*****************************"<<endl;
    }
    fclose(source);
}
void buying::put_zero(int sum1,char *sum)
{
    sum[0]= '0';
    sum[1]=sum1+'0';
    sum[2]='\0';
}
void buying::put_char(int sum1, char *sum)
{
    int a = sum1,count=0;
    while(a!=0)
    {
        a=a/10;
        count++;
    }
    while(sum1 != 0)
    {
        sum[count-1] = (sum1 % 10)+'0';
        sum1=sum1/10;
        count--;
    }
}
void buying::make_id(int count)
{
    int i,j,k;
    int nums = count;
    for(i =0;nums !=0;i++)
    {
        nums /=10;
    }
    id[0] = 'T';
    for(j =1; j <6-i;j++)
    {
        id[j] ='0';
    }
    for(k =j; k < 6;k++)
    {
        int temp = count %10;
        count /=10;
        id[k] =temp +'0';
    }
    id[k]='\0';
}
void buying:: make_order(char*name)
{
    char id_g[100]={};
    cout<<"输入商品ID:";
    cin >> id_g;
    cout<<endl;
    cout<<"****************"<<endl;
    cout<<"交易提醒"<<endl;
    //time
    time_t now = time(0);
    tm *ltm = localtime(&now);
    int year,month,day;
    year = 1900 + ltm->tm_year;
    month = 1 + ltm->tm_mon;
    day=ltm->tm_mday;
    cout<<"交易时间: "<<year<<"-"<<month<<"-"<<day<<endl;
    bool cond = check_object(id_g,name);
    if(cond == true)
    {
        change(id_g,name,year,month,day);
        input_person();
        change_things(id_g);
        input_object();
        cout<<"交易状态: "<<"交易成功"<<endl;
    }
    else
    {
        cout<<"交易状态: "<<"交易失败"<<endl;
    }

}
bool buying::check_object(char *thing,char *name)
{
    FILE *source = fopen("/Users/anthonyhuang/Desktop/APPLICATION/FILE/goods.txt", "r");
    FILE *source1= fopen("/Users/anthonyhuang/Desktop/APPLICATION/FILE/customer.txt", "r");
    if (source == NULL  || source1==NULL)
    {
        cout<<"error"<<endl;
        exit(EXIT_FAILURE);
    }
    char price[100]={};
    things *head=NULL;
    head = new things;
    bool cond= false,cond1=true,cond2=false;
    while(fscanf(source, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%s\n",head->id_good,head->name_object,head->price,head->discription,head->id_name,head->timing,head->status)!=EOF)
    {
        if(strcmp(head->id_good,thing)==0 && strcmp(head->status,"已售出")!=0)
        {
            cout<<"交易金额: "<<head->price<<endl;
            strcpy(price,head->price);
            cond=true;
        }
        if(strcmp(head->id_name,name)!=0)
        {
            cond2= true;
        }
    }
    if(cond==false)
    {
        cout<<"东西已经买了或者没有东西"<<endl;
    }
    info_person *temp = NULL;
    temp= new info_person;
    while(true)
    {
        if(fscanf(source1, "%[^,],%[^,],%[^,],%[^,],%[^,],%s\n",temp->id,temp->name,temp->password,temp->telephone,temp->address,temp->money)==EOF)
        {
            break;
        }
        else if(strcmp(temp->id,name)==0)
        {
            double price1 = strtod(temp->money,NULL);
            double price2 = strtod(price,NULL);
            if(price1 < price2)
            {
                cout<<"钱不够"<<endl;
                cond1=false;
            }
        }
    }
    if(cond==true && cond1 == true && cond2== true)
    {
        return true;
    }
    else
    {
        return false;
    }
    fclose(source);
    fclose(source1);
}
void buying::change(char*id_g,char*name,int year,int month,int day)
{
    char id_order[100]={},id_sell[100]={},price[100]={};
    FILE *source = fopen("/Users/anthonyhuang/Desktop/APPLICATION/FILE/goods.txt", "r");
    FILE *source1= fopen("/Users/anthonyhuang/Desktop/APPLICATION/FILE/customer.txt", "r");
    FILE *curr= fopen("/Users/anthonyhuang/Desktop/APPLICATION/FILE/remove.txt", "w");
    if (source == NULL  || source1==NULL||curr==NULL)
    {
        cout<<"error"<<endl;
        exit(EXIT_FAILURE);
    }
    things *head = new things;
    while(fscanf(source, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%s\n",head->id_good,head->name_object,head->price,head->discription,head->id_name,head->timing,head->status)!=EOF)
    {
        if(strcmp(head->id_good,id_g)==0)
        {
            strcpy(id_sell,head->id_name);
            strcpy(price,head->price);
        }
    }
    double price1 = strtod(price,NULL);
    info_person *temp = new info_person;
    while(fscanf(source1, "%[^,],%[^,],%[^,],%[^,],%[^,],%s\n",temp->id,temp->name,temp->password,temp->telephone,temp->address,temp->money)!=EOF)
    {
        if(strcmp(temp->id,name)==0)
        {
            double value1 = strtod(temp->money,NULL);
            value1= value1-price1;
            fprintf(curr,"%s,%s,%s,%s,%s,%.1f\n",temp->id,temp->name,temp->password,temp->telephone,temp->address,value1);
        }
        else if(strcmp(id_sell,temp->id)==0)
        {
            double value = strtod(temp->money,NULL);
            value=value+price1;
            fprintf(curr,"%s,%s,%s,%s,%s,%.1f\n",temp->id,temp->name,temp->password,temp->telephone,temp->address,value);
        }
        else
        {
            fprintf(curr,"%s,%s,%s,%s,%s,%s\n",temp->id,temp->name,temp->password,temp->telephone,temp->address,temp->money);
        }
    }
    output_(id_g,name,price1,year,month,day,id_sell);
    fclose(source1);
    fclose(source);
    fclose(curr);
}
void buying::change_things(char *id_g)
{
    FILE *source = fopen("/Users/anthonyhuang/Desktop/APPLICATION/FILE/goods.txt", "r");
    FILE *curr= fopen("/Users/anthonyhuang/Desktop/APPLICATION/FILE/remove.txt", "w");
    if (source == NULL  || curr==NULL)
    {
        cout<<"error"<<endl;
        exit(EXIT_FAILURE);
    }
    things *head = new things;
    while(fscanf(source, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%s\n",head->id_good,head->name_object,head->price,head->discription,head->id_name,head->timing,head->status)!=EOF)
    {
        if(strcmp(head->id_good,id_g)==0)
        {
            char status[100]="已经买";
            strcpy(head->status,status);
            fprintf(curr,"%s,%s,%s,%s,%s,%s,%s\n",head->id_good,head->name_object,head->price,head->discription,head->id_name,head->timing,head->status);
        }
        else
        {
            fprintf(curr,"%s,%s,%s,%s,%s,%s,%s\n",head->id_good,head->name_object,head->price,head->discription,head->id_name,head->timing,head->status);
        }
    }
    fclose(source);
    fclose(curr);
}
void buying::input_object()
{
    FILE *source = fopen("/Users/anthonyhuang/Desktop/APPLICATION/FILE/goods.txt", "w");
    FILE *curr = fopen("/Users/anthonyhuang/Desktop/APPLICATION/FILE/remove.txt", "r");
    if (source == NULL || curr==NULL)
    {
        cout<<"error"<<endl;
        exit(EXIT_FAILURE);
    }
    things*head=NULL;
    head = new things;
    while(fscanf(curr, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%s\n",head->id_good,head->name_object,head->price,head->discription,head->id_name,head->timing,head->status)!=EOF)
    {
        fprintf(source,"%s,%s,%s,%s,%s,%s,%s\n",head->id_good,head->name_object,head->price,head->discription,head->id_name,head->timing,head->status);
    }
    fclose(source);
    fclose(fopen("/Users/anthonyhuang/Desktop/APPLICATION/FILE/remove.txt", "w"));
    
}
void buying:: input_person()
{
    FILE *source = fopen("/Users/anthonyhuang/Desktop/APPLICATION/FILE/customer.txt", "w");
    FILE *curr = fopen("/Users/anthonyhuang/Desktop/APPLICATION/FILE/remove.txt", "r");
    if (source == NULL || curr==NULL)
    {
        cout<<"error"<<endl;
        exit(EXIT_FAILURE);
    }
    info_person*temp=NULL;
    temp = new info_person;
    while(fscanf(curr, "%[^,],%[^,],%[^,],%[^,],%[^,],%s\n",temp->id,temp->name,temp->password,temp->telephone,temp->address,temp->money)!=EOF)
    {
        fprintf(source,"%s,%s,%s,%s,%s,%s\n",temp->id,temp->name,temp->password,temp->telephone,temp->address,temp->money);
    }
    fclose(source);
    fclose(fopen("/Users/anthonyhuang/Desktop/APPLICATION/FILE/remove.txt", "w"));
}
void buying::output_(char *id_g, char*name,double price,int year,int month,int day,char *id_seller)
{
    char copy[100]={},days[100]={},months[100]={};
    if(day <10)
    {
        put_zero(day,days);
    }
    else
    {
        put_char(day,days);
    }
    if(month <10)
    {
        put_zero(month,months);
    }
    else
    {
        put_char(month,months);
    }
    int count=0;
    bool temp = false;
    FILE *order = fopen("/Users/anthonyhuang/Desktop/APPLICATION/FILE/order.txt", "r+");
    if (order == NULL )
    {
        cout<<"error"<<endl;
        exit(EXIT_FAILURE);
    }
    orders *head = new orders;
    while(fscanf(order, "%[^,],%[^,],%[^,],%[^,],%[^,],%s\n",head->id_order,head->id_good,head->price,head->timing,head->id_seller,head->id_buyer)!=EOF)
    {
        if(strcmp(head->id_order, copy)>0)
        {
            temp = true;
            memset(copy, 0, sizeof(copy));
            strcpy(copy, head->id_order);
        }
    }
    if(temp !=false)
    {
        for(int i = 1; i< 6;i++)
        {
            if(copy[i] != 0)
            {
                count = count *10 + copy[i]-'0';
            }
        }
    }
    make_id(count+1);
    fprintf(order,"%s,%s,%.1lf,%d-%s-%s,%s,%s\n",id,id_g,price,year,months,days,id_seller,name);
    fclose(order);
}