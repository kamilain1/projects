#include <stdio.h>
#include <sys/types.h>
#include <process.h>

/* 3 fork executions - 8 processes (2^3)
  ex2 --- ex2 --- ex2 --- ex2
       |    |
       |    ex2
       |
       |--- ex2 --- ex2
       ex2

5 fork executions - 32 processes (2^5)
*/

void main(){
    for (int i = 0; i < 3; i++) {
        fork();
        sleep(5);
    }
}
