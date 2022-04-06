#include<stdio.h>

int main(){
    char str[100];
    printf("please enter the string :\n");
    fgets(str,sizeof(str),stdin);

    for (size_t i = 0; str[i]!='\0'; i++)
    {
        while ((str[i]<'a'||str[i]>'z')&&(str[i]<'A'||str[i]>'Z')&&(str[i]!='\0'))
        {
            for (int j = i; str[j] !='\0'; j++)
            {
                str[j]=str[j+1];
            }
        }
    }
    printf("result : %s\n",str);
    return 0;
}