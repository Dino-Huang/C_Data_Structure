#include<stdio.h>
#include<stdlib.h>

int maxProfit(int* prices, int pricesSize){
    int min = prices[0] ;
    int max = 0;
    int profit = 0;
    //sort array from max to min
    for (int i = 0; i < pricesSize; i++)
    {
        //record min price
        if(prices[i]< min)
        {
            min = prices[i];
        }
        profit = prices[i] - min;
        //updata max if have bigger profit
        if(profit>max)
        {
            max = profit;
        }
    }
    return 0;
}

int BestMethod(int* prices, int pricesSize){
    int min = prices[0] ;
    int profit = 0;

    for (int i = 0; i < pricesSize; i++)
    {
        if(prices[i]>min){
            if(prices[i]-min > profit)
            {
                profit = prices[i]- min;
            }
        }
        else// prices[i] < min
        {
            min = prices[i];
        }
    }
    return profit;
    
}

int main(){

    int prices[5] = {7,1,5,3,1};
    //int profit = maxProfit(prices,5);
    int profit = BestMethod(prices,5);
    printf("Profit : %d\n",profit);
    return 0;
}