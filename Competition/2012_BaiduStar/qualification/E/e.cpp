#include <iostream>  
#include <cstdio>  
#include <cstring>  
  
using namespace std;  
char str[424];  
char ans[424];  
bool _java,_cpp;  
bool _isquery()  
{  
  
   
    bool flag1=false,flag2=false;  
    int len=strlen(str);  
    if(str[0]<'a'||str[0]>'z'||str[len-1]=='_')  
    return false;  
    for(int i=0 ; i< len ; ++i)  
    {  
  
        if((str[i]>='A'&&str[i]<='Z')||str[i]=='_')  
        return false;  
  
    }  
    return true;  
  
}  
  
bool _iscpp()  
{  
  
    int len=strlen(str);  
    if(str[0]<'a'||str[0]>'z'||str[len-1]=='_')  
    return false;  
    bool flag=false;  
    int cnt=0;  
    for(int i=0 ; i< len ; ++i)  
    {  
        if(str[i]>='A'&&str[i]<='Z')  
        return false;  
        if(str[i]=='_')  
        {  
            if(str[i+1]=='_')  
            return false;  
            flag=true;  
            continue;  
        }  
        if(flag)  
        {  
  
            flag=false;  
            ans[cnt++]=toupper(str[i]);  
  
        }  
  
        else  
        ans[cnt++]=str[i];  
  
    }  
  
    ans[cnt]=0;  
    return true;  
  
}  
  
bool _isjava()  
{  
  
    int len=strlen(str);  
    if(str[0]<'a'||str[0]>'z'||str[len-1]=='_')  
        return false;  
    bool flag=false;  
    int cnt=0;  
    for(int i=0 ; i< len ; ++i)  
    {  
  
        if(str[i]=='_')  
          return false;  
        if(str[i]>='A'&&str[i]<='Z')  
  
        flag=true;  
  
        if(flag)  
        {  
            ans[cnt++]='_';  
  
            ans[cnt++]=tolower(str[i]);  
  
            flag=false;  
  
        }  
  
        else  
        ans[cnt++]=str[i];  
  
    }  
    ans[cnt]=0;  
    return true;  
}  
  
int main()  
{  
  
   while(scanf("%s",str)!=EOF)  
    {  
  
        int _query=false;  
        if(_isquery())  
        {  
            puts(str);  
            continue;  
        }  
  
        _java=_cpp=false;  
        _java=_isjava();  
        if(_java)  
        {  
            puts(ans);  
            continue;  
        }  
        _cpp=_iscpp();  
        if(_cpp)  
        {  
            puts(ans);  
            continue;  
        }  
  
        if(!_java&&!_cpp)  
               puts("Error!");  
  
    }  
  
 return 0;  
  
}  

