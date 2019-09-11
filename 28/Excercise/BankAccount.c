
enum WeekDay { Sun, Mon, Tue, Wed, Thu, Fri, Sat };

struct Date {
    int year;
    int month;
    int date;
    enum WeekDay weekday;
};

struct BankAccount {
    char name[15];
    int accountNumber[10];
    double balance;
    struct Date birthday;
};

int main() {
    struct BankAccount bankAccount;
    bankAccount.birthday.weekday = Wed;
}
