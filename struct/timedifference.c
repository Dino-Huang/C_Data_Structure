#include<stdio.h>

struct Time{
    int hour,minute,second;
};

void calculate_time_diff(struct Time t1, 
                         struct Time t2,
                         struct Time *t_diff);

int main(){
    struct Time t1,t2,t_diff;
    printf("please enter t1 : \n");
    printf("Hour : ");
    scanf("%d",&t1.hour);
    printf("Minute : ");
    scanf("%d",&t1.minute);
    printf("Second : ");
    scanf("%d",&t1.second);

    printf("please enter t2 : \n");
    printf("Hour : ");
    scanf("%d",&t2.hour);
    printf("Minute : ");
    scanf("%d",&t2.minute);
    printf("Second : ");
    scanf("%d",&t2.second);

    calculate_time_diff(t1,t2,&t_diff);

    printf("Time difference : %d:%d:%d - %d:%d:%d\n",t1.hour,t1.minute,t1.second,
                                                     t2.hour,t2.minute,t2.second);
    printf("= %d:%d:%d\n",t_diff.hour,t_diff.minute,t_diff.second);
    return 0;
}

void calculate_time_diff(struct Time t1, 
                         struct Time t2,
                         struct Time *t_diff){
if(t2.second>t1.second)
{
    t1.minute-=1;
    (*t_diff).second=t1.second+60-t2.second;
}
(*t_diff).second=t1.second-t2.second;

if(t2.minute>t1.minute)
{
    t1.hour-=1;
    (*t_diff).minute=t1.minute+60-t2.minute;
}
(*t_diff).minute=t1.minute-t2.minute;
(*t_diff).hour=t1.hour-t2.hour;
}