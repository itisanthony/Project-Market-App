#include"admin.hpp"
#include"logn in .hpp"
#include "information.hpp"
#include"seller.hpp"
#include"seller.cpp"
#include"buyer.hpp"
#include"buyer.cpp"
void entering();
void enter_info(char *name);
void open_customer(char *name);
void sell(char *name);
void buyer(char *name);
void enter();
void entering_admin(int number)
{
    administration head;

    switch (number)
    {
        case 1:
        {
            head.output_things();
            entering();
            break;
        }
        case 2:
        {
            head.searching_things();
            entering();
            break;
        }
        case 3:
        {
            head.output_order();
            entering();
            break;
        }
        case 4:
        {
            head.output_account();
            entering();
            break;
        }
        case 5:
        {
            head.deleting_accout();
            entering();
            break;
        }
        case 6:
        {
            head.deleting_things();
            entering();
            break;
        }
        case 7:
        {
            open temp;
            system("clear");
            enter();
            break;
        }
    default:
         break;
    }
}
void entering()
{
    char number[100]={};
    cout<<"===================================================================================="<<endl;
    cout<<"1.查看所有商品 2.搜索商品 3.查看所有订单 4.查看所有用户 5.删除用户 6.下架商品 7.注销"<<endl;
    cout<<"===================================================================================="<<endl;
    cout<<"请输入操作：";
    cin >> number;
    int number1 = strtod(number,NULL);
    if(number1>=1 && number1<=7)
    {
        entering_admin(number1);
    }
    else
    {
        entering();
    }
}
void managed_system(char *name,int number)
{
    switch (number)
    {
        case 1:
        {
            open_customer(name);
            break;
        }
        case 2:
        {
            entering();
            break;
        }
        default:
            break;
    }
}
void open_customer(char *name)
{
    char nums[100]={};
    cout<<"================================================="<<endl;
    cout<<"1.注销登录 2.我是买家 3.我是卖家 4.人信息管理"<<endl;
    cout<<"================================================="<<endl;
    cout<<"请输入操作:";
    cin >> nums;
    int number1 = strtod(nums,NULL);
    if(number1<0 || number1>4)
    {
        open_customer(name);
    }
    switch (number1)
    {
        case 1:
        {
            open temp;
            system("clear");
            enter();
            break;
        }
        case 2:
        {
            buyer(name);
            break;
        }
        case 3:
        {
            sell(name);
        }
        case 4:
        {
            enter_info(name);
            break;
        }
        default:
            break;
    }
}
void enter_info(char *name)
{
    char number[100]={};
    cout<<"=========================================="<<endl;
    cout<<"1.返回用户主界面 2.修改信息 3.查看信息 4.充值"<<endl;
    cout<<"=========================================="<<endl;
    cout<<"请输入操作:";
    cin>>number;
    int number1 = strtod(number,NULL);
    if(number1>4||number1<0)
    {
        enter_info(name);
    }
    info head;
    switch (number1)
    {
        case 1:
        {
            open_customer(name);
            break;
        }
        case 2:
        {
            head.change_info(name);
            enter_info(name);
            break;
        }
        case 3:
        {
            head.output_account(name);
            enter_info(name);
            break;
        }
        case 4:
        {
            head.recharge(name,4);
            enter_info(name);
            break;
        }
        default:
            break;
    }
}
void sell(char *name)
{
    char string[100]={};
    cout<<"=================================================================================="<<endl;
    cout<<"1.发布商品 2.查看发布商品 3.修改商品信息 4.下架商品 5.查看历史订单 6.返回用户主界面"<<endl;
    cout<<"=================================================================================="<<endl;
    cout<<"输入操作：";
    cin>>string;
    int number1 = strtod(string,NULL);
    if(number1<0|| number1>6)
    {
        sell(name);
    }
    selling head;
    switch (number1)
    {
        case 1:
        {
            head.posting(name);
            sell(name);
            break;
        }
        case 2:
        {
            head.output(name);
            sell(name);
            break;
        }
        case 3:
        {
            head.change_info();
            sell(name);
            break;
        }
        case 4:
        {
            head.deleting_things(name);
            sell(name);
            break;
        }
        case 5:
        {
            head.output_order(name);
            sell(name);
            break;
        }
        case 6:
        {
            open_customer(name);
            break;
        }
        default:
            break;
    }
}
void buyer(char *name)
{
    char string[100]={};
    cout<<"==========================================================================================="<<endl;
    cout<<"1.查看商品列表 2.购买商品 3.搜索商品 4.查看历史订单 5.查看商品详细信息 6.返回用户主界面"<<endl;
    cout<<"==========================================================================================="<<endl;
    cout<<"输入操作：";
    cin>>string;
    int number1 = strtod(string,NULL);
    if(number1<0||number1>6)
    {
        buyer(name);
    }
    buying temp;
    switch (number1)
    {
        case 1:
        {
            temp.output_things();
            buyer(name);
            break;
        }
        case 2:
        {
            temp.make_order(name);
            buyer(name);
            break;
        }
        case 3:
        {
            temp.searching_things();
            buyer(name);
            break;
        }
        case 4:
        {
            temp.output_order(name);
            buyer(name);
            break;
        }
        case 5:
        {
            temp.information();
            buyer(name);
            break;
        }
        case 6:
        {
            open_customer(name);
            break;
        }
        default:
            break;
    }
}
void enter()
{
    int nums;
    cout<<"============================================="<<endl;
    cout<<"1.用户登入 2.用户注册 3.管理员登入 4.退出程序"<<endl;
    cout<<"============================================="<<endl;
    cout<<"输入操作：";
    cin >> nums;
    open head;
    if(nums==1)
    {
        head.sign_customer();
    }
    else if(nums==2)
    {
        head.sign_up();
        system("clear");
    }
    else if(nums==3)
    {
        head.sign_admin();
    }
    else if(nums==4)
    {
        return;
    }
    else
    {
         enter();
    }
}