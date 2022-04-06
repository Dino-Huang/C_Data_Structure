#include<stdio.h>
#include<string.h>

// ASCII code order:
//lower characters > capital characters > numbers
//Example 'a' order 97 , 'A' order 65, strcmp('a','A')=97-65=32
//strcmp compare the first non matching character
int main(){
    char str[5][20];
    char tmp[20];
    printf("please enter 5 words: \n");
    for(int i=0; i<5; i++){
        fgets(str[i],sizeof(str[i]),stdin);
    }
    
    for (int i = 0; i < 5; i++)
    {
        for (int j = i+1; j <5; j++){
            if(strcmp(str[i],str[j])>0)
            {
                strcpy(tmp,str[i]);
                strcpy(str[i],str[j]);
                strcpy(str[j],tmp);
            }
        }
    }
    printf("Result in order :\n");
    for(int i = 0; i < 5; i++){
        printf("%s",str[i]);
    }
    return 0;
}