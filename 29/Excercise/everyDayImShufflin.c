#include <stdio.h>

struct Song {
    char name[25];
    float length;
};

void printSongDetail(struct Song song) {
    printf("%s - length: %.2f\n", song.name, song.length);
}

int main() {
    struct Song 
        Title1 = {"Marvelous Grace", 2.50},
        Title2 = {"I surrender All", 3.0},
        Title3;

    Title3 = Title1;
    Title1 = Title2;
    Title2 = Title3;

    printSongDetail(Title1);
    printSongDetail(Title2);

    return 0;
}
