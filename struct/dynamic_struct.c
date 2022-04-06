#include<stdio.h>
#include<stdlib.h>
 
struct data{
    char subject[10];
    int score;
};

int main(){
    int n;
    printf("please enter the number of records : ");
    scanf("%d",&n);
    struct data *d;
    d=(struct data*)malloc(n*sizeof(struct data));

    for (int i=0;i<n;i++){
        printf("please enter subject and score of record[%d]:\n",i+1);
        printf("Subject : ");
        scanf("%s",(d+i)->subject);
        printf("Score : ");
        scanf("%d",&(d+i)->score);
    }

    printf("Display info : \n");
    for (int i=0;i<n;i++){
        printf("Record[%d] : \n",i+1);
        printf("Subject : %s / Score : %d\n",(d+i)->subject,(d+i)->score);

    }




    free(d);
    return 0;
}