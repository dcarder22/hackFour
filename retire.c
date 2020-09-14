/*
Author: Dalton Carder
Date: 2020
simple File to print an amortization table for a 401k
*/

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    
    //get variables needed
    double initialBalance = atof(argv[1]);
    double contribution = atof(argv[2]);
    double annualRateReturn = atof(argv[3]);
    double annualInflation = atof(argv[4]);
    int yearsLeft = atol(argv[5]);
    //exit if entries are wrong
    if(contribution > 18500 || annualRateReturn > 1 || annualRateReturn < 0 || annualInflation > 1 || annualInflation < 0) {
        printf("NOT A VALID ENTRY ENDING\n");
        exit(0);
    }
    
    
    
    //get rest of variables needed
    int monthsLeft = yearsLeft * 12;
    double trueInterestRate = ((1+annualRateReturn) / (1 + annualInflation)) - 1;
    double monthlyTrueInterestRate = trueInterestRate / 12;
    double totalBalance = initialBalance;
    double monthlyTrueInterest;
    double totalInterest = 0.0;
    
    //print and calculate all needed amounts
    printf("   Month   Interest   Balance\n");
    for (int i = 1; i <= monthsLeft; ++i) {
        monthlyTrueInterest = totalBalance *monthlyTrueInterestRate;
        totalBalance = totalBalance + monthlyTrueInterest + contribution;
        totalInterest = totalInterest + monthlyTrueInterest;
        printf("%8d $%10.2f $%9.2f\n", i, monthlyTrueInterest, totalBalance);
    }
    printf("Total Interest Earned: $%10.2f\n", totalInterest);
    printf("Total Balance Earned: $%10.2f\n", totalBalance);
    
    
    
    return 0;
}