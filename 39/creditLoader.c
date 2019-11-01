#include <stdio.h>
#include <stdlib.h>

struct CreditData {
    int accountNo;
    char LastName[17];
    char FirstName[17];
    float balance;
};

int main() {
    const int loadEntities = 5;
    struct CreditData *creditDataList = (struct CreditData *)malloc(sizeof(struct CreditData) * loadEntities);

    if (!creditDataList) {
        printf("[ MEMORY ALLOCATION FAILED ] System might be out of memory, please check your memory via htop.\n");
        return 1;
    }

    FILE *loadFile = fopen("credit.dat", "rb");

    if (!loadFile) {
        printf("[ FILE READ FAILED ] Check your file permission or disk S.M.A.R.T.\n");
        return 1;
    }

    int i = 0;
    while(!feof(loadFile)) {
        i++;
        fread(creditDataList+i, sizeof(struct CreditData), 1, loadFile);
    }
    
    printf("%s\t%-16s %-16s %s\n", "Acct", "Last Name", "First Name", "Balance");

    struct CreditData *creditData = creditDataList;
    while(feof(loadFile)) {
        printf("%d\t%16s %16s %7.2f\n", creditData->accountNo, creditData->LastName, creditData->FirstName, creditData->balance);    
    }

    fclose(loadFile);
}