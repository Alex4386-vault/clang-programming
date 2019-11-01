#include <stdio.h>
#include <string.h>

void clearBuffer(char *buffer, int bufferSize) {
    for (int i = 0; i < bufferSize; i++) {
        buffer[i] = 0;
    }
    return;
}

/**
 * 주어진 input, output FILE 포인터에서
 * num 인수의 줄을 삭제합니다.
 * @param input 처리할 파일 포인터를 넘겨 받습니다. (read 모드)
 * @param output 처리하고 출력할 포인터를 넘겨 받습니다. (write 모드)
 * @param num 삭제할 줄 번호를 입력합니다.
 **/
void lineDeleter(FILE *input, FILE *output, int num) {
    char buffer[1001] = {0,};
    for (int i = 1; !feof(input); i++) {
        clearBuffer(buffer, 1001);
        //printf("%d... ", i);
        fgets(buffer, 1001, input);
        //printf("%s, ", buffer);
        if (num == i) { printf("\n"); continue; }
        fputs(buffer, output);
        //printf("writing!\n");
    }
}

int howManyLines(FILE *input) {
    int count = 1;
    char buffer[1001] = {0,};
    for (count = 0; !feof(input); count++) {
        fgets(buffer, 1001, input);
    }
    fseek(input, 0, SEEK_SET);
    return count;
}

int main() {
    FILE* in = fopen("input.txt", "r");
    if (!in) {
        printf("[ERROR] Unable to read the file.\nPlease check read permission or Disk's S.M.A.R.T.\n");
        return 1;
    }

    FILE* out = fopen("output.txt", "w");
    if (!out) {
        printf("[ERROR] Unable to write the file.\nPlease check read permission or Disk's S.M.A.R.T.\n");
        return 1;
    }

    int line = 0;
    int totalLine = howManyLines(in);

    while(1) {
        printf("Enter line number to delete: ");
        scanf("%d", &line);

        if (line <= 0 || line > totalLine) {
            printf("Invalid line number! Enter again!\n");
        } else {
            break;
        }
    }
    lineDeleter(in, out, line);

    fclose(in);
    fclose(out);

    return 0;
}