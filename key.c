#include <stdio.h>
#include <string.h>
#include "key.h"

void execute(char* path, int opCode) {
    process = popen(path, "r");
    if (process == NULL) {
        printf("Keyboard Error: Unable to get bash file!\n");
    } else {
        while (fgets(done, 5, process) != NULL) {
            switch (strcmp(done, "done")) {
                case 0:
                    switch (opCode) {
                        case 0:
                            printf("Keyboard: Enabled successfully.\n");
                            break;

                        case 1:
                            printf("Keyboard: Disabled successfully.\n");
                            break;
                        
                        default:
                            printf("Keyboard Warning: Modified Software!\n");
                            break;
                    }
                    break;
                
                default:
                    printf("Keyboard Error: Error in bash file! Code 0.\n");
                    break;
            }
            return;
        }
        printf("Keyboard Error: Error in bash file! Code 1.\n");
        return;
    }
}

int main(int argc, char* argv[]) {
    switch (strcmp(argv[1], "hab")) {
        case 0:
            execute(ENABLEPATH, 0);
            break;
        
        default:
            switch (strcmp(argv[1], "dis")) {
                case 0:
                    execute(DISABLEPATH, 1);
                    break;
                
                default:
                    printf("Keyboard Error: Unknown Command!\n");
                    break;
            }
            break;
    }
    return 0;
}