#include <stdio.h>
#include <stdlib.h>

struct Page_frame {
    unsigned int age;
    int Page_number;
};

int main(int argc, char *argv[]) {

    FILE *input = fopen("input.txt", "r");

    int Hit_c = 0;
    int Miss_c = 0;
    int Frames_number;
    sscanf(argv[1], "%d", &Frames_number);

    struct Page_frame *frame = malloc(sizeof(struct Page_frame) * Frames_number);

    // initialize all page frames
    for (int i = 0; i < Frames_number; ++i) {
        frame[i].Page_number = -1;
        frame[i].age = 0;
    }

    int page;
    // read until the EOF (end of file)
    while (fscanf(input, "%d", &page) != EOF) {

        int WasFound = 0;
        // if we have needed page frame then flag is equal to 1
        for (int i = 0; i < Frames_number; ++i)
            if (frame[i].Page_number == page) {
                WasFound = 1;
                break;
            }

        // if we found needed page frame then we update all frames
        if (WasFound) {
            Hit_c++; // increase hit counter
            for (int i = 0; i < Frames_number; ++i) {
                if (frame[i].Page_number != -1) {
                    frame[i].age >>= 1; // shift left all pages
                    if (frame[i].Page_number == page)
                        frame[i].age |= (1 << 31); // add R bit to age for needed page frame
                }
            }
        }
        else {
            Miss_c++; // update counter for misses
            int Age_min = 0; // index of minimum age page frame
            int index; // index of empty page frame
            int EmptyWasFound = 0; // empty page frame flag
            for (int i = 0; i < Frames_number; ++i) {
                // if we found empty page frame then we save index of this page frame and update flag
                if (frame[i].Page_number == -1) {
                    index = i;
                    EmptyWasFound = 1;
                    // insert new page
                    frame[i].Page_number = page;
                    frame[i].age = 1 << 31; // add R bit to age for needed page frame
                    break;
                }
                // updating the minimum age page frame
                if (frame[i].age < frame[Age_min].age)
                    Age_min = i;
            }
            // if we found empty page frame then update all page frames but what we have already updated
            if (EmptyWasFound)
                for (int i = 0; i < Frames_number; ++i) {
                    if (frame[i].Page_number != -1 && i != index) {
                        frame[i].age >>= 1; // shift left
                    }
                }

                // if we did not find empty page frame
            else
                for (int i = 0; i < Frames_number; ++i) { // update all page frames
                    if (frame[i].Page_number != -1) {
                        frame[i].age >>= 1; // shift left
                        // insert new page
                        if (Age_min == i) {
                            frame[i].age = 1 << 31; // add R bit to age for necessary page frame
                            frame[i].Page_number = page;
                        }
                    }
                }
        }
    }

    printf("hits: %d\n", Hit_c);
    printf("misses: %d\n", Miss_c);
    printf("hit/miss: %f\n", (double) Hit_c / (double) Miss_c);

    return 0;
}