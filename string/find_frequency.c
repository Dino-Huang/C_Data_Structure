#include<stdio.h>
#include<string.h>

int main(){
    char content[100],c;
    int count = 0;
    printf("please enter the input content :\n");
    fgets(content,sizeof(content),stdin);
    printf("please enter the character you want to find : ");
    scanf("%c",&c);
    for (size_t i = 0; content[i] != '\0'; ++i)
    {
        if(content[i]==c)
        {
            ++count;
        }
    }
    printf("the %c shows %d times in content!\n",c,count);
    
    return 0;
}