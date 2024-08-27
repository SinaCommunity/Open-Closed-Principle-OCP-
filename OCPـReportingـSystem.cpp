#include <stdio.h>
#include <string.h>

void generatePDF() 
{
    printf("Generating PDF report\n");
}

void generateCSV() 
{
    printf("Generating CSV report\n");
}

void generateReport(const char* format) 
{
    if (strcmp(format, "PDF") == 0) 
    {
        generatePDF();
    } else if (strcmp(format, "CSV") == 0) 
    {
        generateCSV();
    } else {
        printf("Unsupported format\n");
    }
}

int main() 
{
    generateReport("PDF");
    generateReport("CSV");
    return 0;
}


/*======================================================================
                             OCP 
========================================================================*/


#include <stdio.h>
#include <string.h>

// Define function pointer type for report generation
typedef void (*ReportGenerator)(void);

// Implementations for different formats
void generatePDF()
{
    printf("Generating PDF report\n");
}

void generateCSV()
{
    printf("Generating CSV report\n");
}

void generateExcel()
{
    printf("Generating Excel report\n");
}

// Structure to hold format and corresponding function pointer
typedef struct 
{
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
void generateReport(const char* format) 
{
    for (int i = 0; i < sizeof(formats) / sizeof(formats[0]); ++i) 
    {
        if (strcmp(format, formats[i].format) == 0) 
        {
            formats[i].generator();
            return;
        }
    }
    printf("Unsupported format\n");
}

int main() 
{
    generateReport("PDF");
    generateReport("CSV");
    generateReport("Excel");
    return 0;
}



