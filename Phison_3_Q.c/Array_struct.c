#include<stdio.h>
#include<stdlib.h>

/*
Q1. Given a stuct as below, 
please program a funtion(unsinged int DATA_A, unsigned int DATA_B) 
to find the entry that match :
ListArray[Entry].DataH == DATA_A and ListArray[Entry].DataL == DATA_B

There include 2 conditions :
1. ListArray[Entry].NextPtr = ListArray[Entry2]
2. ListArray[Entry2].DataH << 16 + ListArray[Entry2].DataL >
   ListArray[Entry1].DataH << 16 + ListArray[Entry1].DataL

print out entry and prev entry if u find it 
*/

typedef struct list_struct{
    unsigned int DataH;
    unsigned int DataL;
    unsigned int NextPtr;
}ListStruct;

#define Null 0xFFFF

ListStruct list_array[1000];
unsigned int list_head = 0;

void FindEntry(unsigned int DATA_A,unsigned int DATA_B)
{
    int Found_entry = list_head;// index = 0
    int Prev_entry = Null;
    int Next_entry = Null;

    while(Found_entry!= Null)
    {
        printf("list_array[%d].DataH = %d\n",Found_entry,list_array[Found_entry].DataH);
        printf("list_array[%d].DataL = %d\n",Found_entry,list_array[Found_entry].DataL);
        //check conditions
        if(list_array[Found_entry].DataH == DATA_A && list_array[Found_entry].DataL == DATA_B)
        {
            // if find in first entry
            if(Found_entry == Null) {
                printf("found entry = listhead, prev entry = Null\n ");
                break;
            }else{
                if((list_array[Next_entry].DataH << 16) + list_array[Next_entry].DataL > (DATA_A << 16) + DATA_B)
                {
                    printf("found entry = %d, prev entry = %d\n",Found_entry,Prev_entry);
                }else{
                    printf("found entry = %d, but its bigger than next!",Found_entry);
                }
                break;
            }
        }
        
        //move to next ptr
        Prev_entry = Found_entry;
        Found_entry = list_array[Found_entry].NextPtr;
        Next_entry = list_array[Found_entry].NextPtr;
    }
}

int main()
{

    list_array[0].DataH   = 1;
    list_array[0].DataL   = 1;
    list_array[0].NextPtr = 1;
    list_array[1].DataH   = 1;
    list_array[1].DataL   = 2;
    list_array[1].NextPtr = 2;
    list_array[2].DataH   = 1;
    list_array[2].DataL   = 3;
    list_array[2].NextPtr = 3;
    list_array[3].DataH   = 1;
    list_array[3].DataL   = 4;
    list_array[3].NextPtr = 4;
    list_array[4].DataH   = 1;
    list_array[4].DataL   = 5;
    list_array[4].NextPtr = 5;
    list_array[5].DataH   = 1;
    list_array[5].DataL   = 4;
    list_array[5].NextPtr = 6;
    unsigned int a = 1;
    unsigned int b = 5;
    FindEntry(a,b);

    return 0;
}