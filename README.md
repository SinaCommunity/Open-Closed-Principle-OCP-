# Open-Closed-Principle-OCP-
Open/Closed Principle (OCP) Code Example 



مثال 1: سیستم گزارش‌دهی
کد اولیه:
در این نسخه، کلاس و متدهای مشخصی برای تولید گزارش داریم که برای افزودن فرمت‌های جدید باید تغییر داده شوند.

#include <stdio.h>
#include <string.h>

void generatePDF() {
    printf("Generating PDF report\n");
}

void generateCSV() {
    printf("Generating CSV report\n");
}

void generateReport(const char* format) {
    if (strcmp(format, "PDF") == 0) {
        generatePDF();
    } else if (strcmp(format, "CSV") == 0) {
        generateCSV();
    } else {
        printf("Unsupported format\n");
    }
}

int main() {
    generateReport("PDF");
    generateReport("CSV");
    return 0;
}
---------------------------------------------------------------------------------------------------------------------------


پاسخگو با رعایت OCP:
برای رعایت اصل OCP، می‌توانیم از تابع‌اشاره‌گرها و ساختارها استفاده کنیم تا فرمت‌های جدید را بدون تغییر کدهای موجود اضافه کنیم.


#include <stdio.h>
#include <string.h>

// Define function pointer type for report generation
typedef void (*ReportGenerator)(void);

// Implementations for different formats
void generatePDF() {
    printf("Generating PDF report\n");
}

void generateCSV() {
    printf("Generating CSV report\n");
}

void generateExcel() {
    printf("Generating Excel report\n");
}

// Structure to hold format and corresponding function pointer
typedef struct {
    const char* format;
    ReportGenerator generator;
} ReportFormat;

// Array of supported formats
ReportFormat formats[] = {
    {"PDF", generatePDF},
    {"CSV", generateCSV},
    {"Excel", generateExcel}
};

// Function to generate report based on format
void generateReport(const char* format) {
    for (int i = 0; i < sizeof(formats) / sizeof(formats[0]); ++i) {
        if (strcmp(format, formats[i].format) == 0) {
            formats[i].generator();
            return;
        }
    }
    printf("Unsupported format\n");
}

int main() {
    generateReport("PDF");
    generateReport("CSV");
    generateReport("Excel");
    return 0;
}
=======================================================================================================================


در این طراحی، برای هر فرمت گزارش یک تابع اختصاصی داریم و با استفاده از ساختار ReportFormat و آرایه‌ای از آن‌ها، می‌توانیم فرمت‌های جدید را به راحتی اضافه کنیم بدون اینکه نیاز به تغییر در تابع generateReport باشد.

مثال 2: سیستم پردازش تخفیف
کد اولیه:
در این نسخه، سیستم به نوع مشتری‌ها وابسته است و تغییرات جدید نیاز به تغییر در کد دارد.

c
Copy code
#include <stdio.h>
#include <string.h>

double calculateDiscount(const char* customerType, double amount) {
    if (strcmp(customerType, "Regular") == 0) {
        return amount * 0.1; // 10% discount
    } else if (strcmp(customerType, "VIP") == 0) {
        return amount * 0.2; // 20% discount
    } else {
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

---------------------------------------------------------------------------------------------------------------------------
پاسخگو با رعایت OCP:
برای رعایت اصل OCP، می‌توانیم از تابع‌اشاره‌گرها و ساختارها برای اضافه کردن استراتژی‌های تخفیف جدید استفاده کنیم
#include <stdio.h>
#include <string.h>

// Define function pointer type for discount calculation
typedef double (*DiscountStrategy)(double amount);

// Implementations for different discount strategies
double regularDiscount(double amount) {
    return amount * 0.1; // 10% discount
}

double vipDiscount(double amount) {
    return amount * 0.2; // 20% discount
}

double seasonalDiscount(double amount) {
    return amount * 0.15; // 15% discount
}

// Structure to hold customer type and corresponding discount function pointer
typedef struct {
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
double calculateDiscount(const char* customerType, double amount) {
    for (int i = 0; i < sizeof(strategies) / sizeof(strategies[0]); ++i) {
        if (strcmp(customerType, strategies[i].customerType) == 0) {
            return strategies[i].strategy(amount);
        }
    }
    printf("Unknown customer type\n");
    return 0;
}

int main() {
    double amount = 100.0;
    printf("Regular discount: %.2f\n", calculateDiscount("Regular", amount));
    printf("VIP discount: %.2f\n", calculateDiscount("VIP", amount));
    printf("Seasonal discount: %.2f\n", calculateDiscount("Seasonal", amount));
    return 0;
}
در این طراحی، برای هر نوع مشتری یک تابع تخفیف اختصاصی داریم و با استفاده از ساختار DiscountStrategyEntry و آرایه‌ای از آن‌ها، می‌توانیم استراتژی‌های تخفیف جدید را به راحتی اضافه کنیم بدون اینکه نیاز به تغییر در تابع calculateDiscount باشد.
