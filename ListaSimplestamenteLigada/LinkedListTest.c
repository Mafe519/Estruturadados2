#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "log.h"

int main(){
    log_set_level(LOG_TRACE);
    
    LinkedList list;
    init(&list);

    return EXIT_SUCCESS;
}