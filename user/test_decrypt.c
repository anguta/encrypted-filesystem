#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int argc, char *argv[]) {

    int fd, i;

    if(argc <= 1){
        exit(0);
    } 
    for(i = 1; i < argc; i++){
        if((fd = open(argv[i], 0)) < 0){
        fprintf(2, "test: cannot open %s\n", argv[i]);
        exit(1);
        }
        else {
            fd = open(argv[i], 0);
            //encrypt(fd, argc);
            printf("opened and decrypt\n");
            int i = decrypt(fd, 2);
            printf("%d\n", i);
        }

        close(fd);
    }


    return 0;
}