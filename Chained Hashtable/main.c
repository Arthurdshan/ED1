#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

#include "hashtable_ed.h"

#define __SEED__ 42

int main(int argc, char** argv){
    
    int m = 7;
    int n = 1000;
    
    HT *HT = insert_random_n(n, m, __SEED__);

    
    HT_destroy(HT);
}
