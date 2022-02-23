#include"logn in .hpp"
#include"admin.hpp"
#include"control.cpp"

void open::sign_up()
{
    FILE *source = fopen("/Users/anthonyhuang/Desktop/APPLICATION/FILE/customer.txt", "r+");
    if (source == NULL)
    {
        cout<<"error"<<endl;
        exit(EXIT_FAILURE);
    }
    char copy[100]={},koma=',',string,name[100]={},a[100]={},b[100]={},c[100]={},d[100]={},e[100]={},f[100]={};
    int count =0,temp =0,i=0,tmp=0;
    cout<<"用户名:";
    cin>>name;
    while((string = fgetc(source)) != EOF)
    {
        if(string==',')
        {
            i=0;
            tmp++;
        }
        else if(tmp == 0)
        {
            a[i]= string;
            i++;
            a[i]= '\0';
        }
        else if(tmp==1)
        {
            b[i] =string;
            i++;
            b[i]= '\0';
        }
        else if(tmp==2)
        {
            c[i] =string;
            i++;
            c[i]= '\0';
        }
        else if(tmp==3)
        {
            d[i] = string;
            i++;
            d[i]= '\0';
        }
        else if(tmp==4)
        {
            e[i]=string;
            i++;
            e[i]= '\0';
        }
        else if(tmp==5)
        {
            f[i] = string;
            i++;
            f[i]= '\0';
        }
        if(string=='\n')
        {
            if(strcmp(a, copy)>0)
            {
                memset(copy, 0, sizeof(copy));
                strcpy(copy, a);
            }
            if(strcmp(name,b)==0)
            {
                cout<<"修改名称"<<endl;
                sign_up();
            }
            memset(a, 0, sizeof(a));
            memset(b, 0, sizeof(b));
            memset(c, 0, sizeof(c));
            memset(d, 0, sizeof(d));
            memset(e, 0, sizeof(e));
            memset(f, 0, sizeof(f));
            tmp=0;
            temp=1;
            i=0;
        }
    }
    if(temp !=0)
    {
        for(int i = 1; i< 6;i++)
        {
            if(copy[i] != 0)
            {
                count = count *10 + copy[i]-'0';
            }
        }
    }
    char pass[100]={},telephone[100]={},address[100]={}, str[100]={};
    make_id(count+1);
    cout<<"请输入密码：";
    cin>>pass;
    cout<<"请输入电话号码：";
    cin>>telephone;
    cout<<"用户的地址：";
    cin>>address;
    cout<<"钱包余额:";
    cin>>str;
    
    fputs(id, source);
    fputc(koma, source);
    fputs(name,source);
    fputc(koma, source);
    fputs(pass, source);
    fputc(koma, source);
    fputs(telephone, source);
    fputc(koma, source);
    fputs(address, source);
    fputc(koma, source);
    fputs(str, source);
    fputs("\n", source);
    fclose(source);
    cout<<"注册成功"<<endl;
    enter();
}
void open::make_id(int count)
{
    int i,j,k;
    int nums = count;
    for(i =0;nums !=0;i++)
    {
        nums /=10;
    }
    id[0] = 'U';
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
void open::sign_customer()
{
    cout<<"请输入用户名：";
    cin >> head.str;
    cout <<"请输入密码：";
    cin >>head.pass;
    FILE *admin = fopen("/Users/anthonyhuang/Desktop/APPLICATION/FILE/customer.txt", "r");
    if(admin == NULL)
    {
        cout<<"error"<<endl;
        exit(EXIT_FAILURE);
    }
    system = false;
    char string,a[100],b[100],c[100],d[100],e[100],f[100];
    int tmp =0,i=0;
    while((string = fgetc(admin)) != EOF)
    {
        if(string==',')
        {
            i=0;
            tmp++;
        }
        else if(tmp == 0)
        {
            a[i]= string;
            i++;
            a[i]='\0';
        }
        else if(tmp==1)
        {
            b[i] =string;
            i++;
            b[i]='\0';
        }
        else if(tmp==2)
        {
            c[i] =string;
            i++;
            c[i]='\0';
        }
        else if(tmp==3)
        {
            d[i] = string;
            i++;
            d[i]='\0';
        }
        else if(tmp==4)
        {
            e[i]=string;
            i++;
            e[i]='\0';
        }
        else if(tmp==5)
        {
            f[i] = string;
            i++;
            f[i]='\0';
        }
        if(string=='\n')
        {
            if(strcmp(b,head.str)==0 && strcmp(c,head.pass)==0)
            {
                system = true;
                break;
            }
            memset(a, 0, sizeof(a));
            memset(b, 0, sizeof(b));
            memset(c, 0, sizeof(c));
            memset(d, 0, sizeof(d));
            memset(e, 0, sizeof(e));
            memset(f, 0, sizeof(f));
            tmp=0;
            i=0;
        }
    }
    
    if(system == true)
    {
        cout<<"******登入成功******"<<endl;
        managed_system(a,1);
        
    }
    else
    {
        cout<<"******登入失败,即将返回主菜单******"<<endl;
        enter();
    }
    fclose(admin);
}
void open::sign_admin()
{
    cout<<"请输入管理员姓名：";
    cin >>head.str ;
    cout <<"请输入密码：";
    cin >>head.pass;
    FILE *admin = fopen("/Users/anthonyhuang/Desktop/APPLICATION/FILE/admin.txt", "r");
    if(admin == NULL)
    {
        cout<<"error"<<endl;
        exit(EXIT_FAILURE);
    }
    system = false;
    char a[100],b[100],string;
    int i =0,tmp=0,temp=0;
    while(true)
    {
        string = fgetc(admin);
        if(string==',')
        {
            i=0;
            tmp++;
        }
        else if(tmp == 0 && string != EOF)
        {
            a[i]= string;
            i++;
            a[i]='\0';
        }
        else if(tmp==1 && string != EOF)
        {
            b[i] =string;
            i++;
            b[i]='\0';
        }
        if(string=='\n'||string==EOF)
        {
            if(strcmp(a,head.str)==0 && strcmp(b,head.pass)==0)
            {
                system = true;
                break;
            }
            else if(string==EOF)
                break;
            memset(a, 0, sizeof(a));
            memset(b, 0, sizeof(b));
            tmp=0;
            temp=0;
            i=0;
        }
    }
    if(system == true)
    {
        cout<<"******登入成功******"<<endl;
        managed_system(head.str,2);
    }
    else
    {
        cout<<"******登入失败,即将返回主菜单******"<<endl;
        enter();
    }
    fclose(admin);
}
