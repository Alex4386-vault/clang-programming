#include <stdio.h>

struct CreditData {
    int accountNo;
    char LastName[17];
    char FirstName[17];
    float balance;
};

int main() {
    struct CreditData creditDataList[5] = {
        {29, "Brown", "Nancy", -24.54},
        {33, "Dunn", "Stacey", 314.33},
        {37, "Barker", "Doug", 0.00},
        {88, "Smith", "Dave", 258.34},
        {96, "Stone", "Sam", 34.98},
    };

    FILE *saveFile = fopen("credit.dat", "wb");

    if (!saveFile) {
        printf("[ FILE WRITE FAILED ] Check your disk space, file permission or disk S.M.A.R.T.\n");
    }
    fwrite(creditDataList, sizeof(struct CreditData), 5, saveFile);

    fclose(saveFile);
}