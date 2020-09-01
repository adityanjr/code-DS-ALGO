/*
   This problem was asked by Facebook.

   Given a array of numbers representing the stock prices of a company in chronological order, write a function that calculates the maximum profit you could have made from buying and selling that stock once. You must buy before you can sell it.

   For example, given [9, 11, 8, 5, 7, 10], you should return 5, since you could buy the stock at 5 dollars and sell it at 10 dollars.

 */
#include <bits/stdc++.h>
using namespace std;
int main(void){
    vector<int>arr = { 9, 11, 8, 5, 7, 10 };
    int buy=arr[0];
    int profit{};
    for(auto&sell:arr){
        profit = max(profit , sell-buy);
        buy = min(buy , sell); // we will buy current stock as it have minimum price then the current we have 
        // and try to sell this one 
        // why this works :
        // let's say we buy 9 and sell it at price of 11 then we get a profit of 2 
        // but next largest value we can see is 10 so we are going to sell our stock [9] at price of 10 by making a profit of 1
        // what if we buy a stock which have minimum price value and also appear before the price at which we want to sell the current stock.
        // so to automate this current algorithm will work fine
    }
    cout<<profit<<'\n';
    return 0;
}
