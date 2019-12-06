#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct StudentInfo {
    int id;
    char dept;
    float *score; // Sub 1 ~ Sub 30 까지의 점수
} StudentInfo;

const int subjectCount = 30;
const int subjectLength = 20;

const int studentCount = 20;

void getMostDiffAverage(StudentInfo *student, char **subjectNames) {
    FILE *fp = fopen("hw3_output1.txt", "w");
    float mostDiff = 0;
    int mostDiffIndex = 0;
    char win = '\0';
    int aCount = 0, bCount = 0;

    for (int i = 0; i < studentCount; i++) {
        for (int j = 0; j < subjectCount; j++) {
            float sumA = 0;
            float sumB = 0;
            if (student[i].dept == 'A') {
                sumA += student[i].score[j];
                aCount++;
            } else if (student[i].dept == 'B') {
                sumB += student[i].score[j];
                bCount++;
            } else {
                printf("invalid student dept.\n");
                exit(1);
            }
            
            float diff = fabsf(sumB - sumA);
            win = (sumB - sumA) > 0 ? 'B' : 'A';
            if (diff > mostDiff) {
                mostDiffIndex = j;
                mostDiff = diff;
            }
        }
    }

    int count = ((win == 'A') ? aCount : (win == 'B') ? bCount : -1 );
    if (count < 0) exit(1);
    fprintf(fp, "%s : %c %f\n", subjectNames[mostDiffIndex], win, mostDiff / count);
    fclose(fp);
}

int getMostDiffIndex(StudentInfo *student) {
    float mostDiff = 0;
    int mostDiffIndex = 0;

    for (int i = 0; i < studentCount; i++) {
        for (int j = 0; j < subjectCount; j++) {
            float sumA = 0;
            float sumB = 0;
            if (student[i].dept == 'A') {
                sumA += student[i].score[j];
            } else if (student[i].dept == 'B') {
                sumB += student[i].score[j];
            } else {
                printf("invalid student dept.\n");
                exit(1);
            }
            
            float diff = fabsf(sumB - sumA);
            if (diff > mostDiff) {
                mostDiffIndex = j;
                mostDiff = diff;
            }
        }
    }

    return mostDiffIndex;
}

void getBestAndLeast(StudentInfo *student, int subjectIndex) {
    FILE *fp = fopen("hw3_output2.txt", "w");
    int bestIndex = 0;
    float bestScore = student[0].score[subjectIndex];

    int worstIndex = 0;
    float worstScore = student[0].score[subjectIndex];

    for (int i = 0; i < studentCount; i++) {
        float score = student[i].score[subjectIndex];
        if (bestScore < score) {
            bestScore = score;
            bestIndex = i;
        }
        if (worstScore > score) {
            worstScore = score;
            worstIndex = i;
        }
    }
    fprintf(fp, "수석학생 : %d, %c, %f\n", student[bestIndex].id, student[bestIndex].dept, bestScore);
    fprintf(fp, "꼴찌학생 : %d, %c, %f\n", student[worstIndex].id, student[worstIndex].dept, worstScore);
    fclose(fp);
}

int main() {
    FILE *fp = fopen("hw3.txt", "r");

    StudentInfo *students = (StudentInfo *)malloc(sizeof(StudentInfo) * studentCount /* A학과 B학과 총합 20명 */);
    StudentInfo *tmpPtr;

    if (students == NULL) exit(1);

    for (int i = 0; i < studentCount; i++) {
        students[i].score = (float *)malloc(sizeof(float) * subjectCount);
        if (students[i].score == NULL) exit(1);
    }

    char **subjectNames = (char **)malloc(sizeof(char *) * subjectCount);
    if (subjectNames == NULL) exit(1);

    for (int i = 0; i < subjectCount; i++) {
        subjectNames[i] = (char *)malloc(sizeof(char) * subjectLength);
        if (subjectNames[i] == NULL) exit(1);
    }

    tmpPtr = students;

    // 구조체 초기화
    for (int i = 0; i < studentCount; i++) {
        tmpPtr->id = 0;
        tmpPtr->dept = '\0';
        tmpPtr->score = (float *)malloc(sizeof(float) * subjectCount);
        if (tmpPtr->score == NULL) exit(1);

        for (int j = 0; j < subjectCount; j++) {
            tmpPtr->score[j] = 0;
        }
        tmpPtr++;
    }
    
    // 학번 로드
    fscanf(fp, "StudentID\t");
    tmpPtr = students;
    for (int i = 0; i < studentCount; i++) {
        fscanf(fp, "%d\t", &(tmpPtr->id));
        tmpPtr++;
    }
    fscanf(fp, "\n");

    // 학과 로드
    fscanf(fp, "type\t");
    tmpPtr = students;
    for (int i = 0; i < studentCount; i++) {
        fscanf(fp, "%c\t", &(tmpPtr->dept));
        tmpPtr++;
    }
    fscanf(fp, "\n");

    // 점수 로드
    for (int i = 1; i <= subjectCount; i++) {
        fscanf(fp, "%[^\t]", subjectNames[i-1]);
        tmpPtr = students;
        for (int j = 0; j < studentCount; j++) {
            fscanf(fp, "%f\t", &(tmpPtr->score[i-1]));
            tmpPtr++;
        }
        fscanf(fp, "\n");
    }

    getMostDiffAverage(students, subjectNames);
    getBestAndLeast(students, getMostDiffIndex(students));

    for (int i = 0; i < studentCount; i++) {
        free(students[i].score);
    }
    for (int i = 0; i < subjectCount; i++) {
        free(subjectNames[i]);
    }
    free(subjectNames);
    free(students);

    fclose(fp);
    return 0;
    
}