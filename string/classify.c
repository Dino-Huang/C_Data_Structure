#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main(){
    char content[100];
    int vowels,consonants,digits,spaces;
    vowels=consonants=digits=spaces=0;

    printf("please enter the content :\n");
    fgets(content,sizeof(content),stdin);
    
    for (size_t i = 0; i < content[i]!='\0'; i++)
    {
        //convert all characters to lower case
        content[i] = tolower(content[i]);
        //comput the number of vowels
        if (content[i]=='a'||content[i]=='e'||
        content[i]=='i'||content[i]=='o'||content[i]=='u')
        {
            ++vowels;
        }else if (content[i]>='a'&&content[i<='z'])
        {
            //compute the number of cons
            ++consonants;
        }else if (content[i]>='0'&&content[i]<='9')
        {
            ++digits;
        }else if (content[i]==' ')
        {
            ++spaces;
        }
    }
    printf("vowels : %d\n",vowels);
    printf("consonants : %d\n",consonants);
    printf("digits : %d\n",digits);
    printf("spaces : %d\n",spaces);
    
    return 0;
}