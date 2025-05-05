





int maxProfit(vector<int>&prices){
    int maxprofit=0;
    int profit=0;
    int minPrice=prices[0];
    for(int i=0;i<prices.size();i++){
        if(minPrice<prices[i]){
            maxProfit=max(maxProfit,prices[i]-minPrice);

        }
        else if(minPrice>price[i]){
            minPrice=prices[i];
        }
    }
    return maxProfit;
}