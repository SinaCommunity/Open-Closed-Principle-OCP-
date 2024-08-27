
#include <stdio.h>
#include <string.h>

double calculateDiscount(const char* customerType, double amount) 
{
    if (strcmp(customerType, "Regular") == 0) 
    {
        return amount * 0.1; // 10% discount
    } 
    else if (strcmp(customerType, "VIP") == 0) 
    {
        return amount * 0.2; // 20% discount
    } 
    else 
    {
        printf("Unknown customer type\n");
        return 0;
    }
}

int main() {
    double amount = 100.0;
    printf("Regular discount: %.2f\n", calculateDiscount("Regular", amount));
    printf("VIP discount: %.2f\n", calculateDiscount("VIP", amount));
    return 0;
}

/*========================================================================
                             OCP 
========================================================================*/

#include <string.h>

// Define function pointer type for discount calculation
typedef double (*DiscountStrategy)(double amount);

// Implementations for different discount strategies
double regularDiscount(double amount) 
{
    return amount * 0.1; // 10% discount
}

double vipDiscount(double amount) 
{
    return amount * 0.2; // 20% discount
}

double seasonalDiscount(double amount)
{
    return amount * 0.15; // 15% discount
}

// Structure to hold customer type and corresponding discount function pointer
typedef struct
 {
    const char* customerType;
    DiscountStrategy strategy;
} DiscountStrategyEntry;

// Array of supported discount strategies
DiscountStrategyEntry strategies[] = {
    {"Regular", regularDiscount},
    {"VIP", vipDiscount},
    {"Seasonal", seasonalDiscount}
};

// Function to calculate discount based on customer type
double calculateDiscount(const char* customerType, double amount)
 {
    for (int i = 0; i < sizeof(strategies) / sizeof(strategies[0]); ++i)
     {
        if (strcmp(customerType, strategies[i].customerType) == 0)
        {
            return strategies[i].strategy(amount);
        }
    }
    printf("Unknown customer type\n");
    return 0;
}

int main()
 {
    double amount = 100.0;
    printf("Regular discount: %.2f\n", calculateDiscount("Regular", amount));
    printf("VIP discount: %.2f\n", calculateDiscount("VIP", amount));
    printf("Seasonal discount: %.2f\n", calculateDiscount("Seasonal", amount));
    return 0;
}
