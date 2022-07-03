#include "types.h"
#include "stat.h"
#include "user.h"

int limit = 20;
int base = 0;

void add(void *args)
{
    int tid = -1;

    base++;

    printf(1, "[ID] %d => ", thread_id());
    if (base < limit)
    {
        printf(1, "[SUCCESS] 0\n");
        tid = thread_creator(add, 0);
        thread_join(tid);
    }
    else
    {
        printf(1, "[FAILED] -1\n");
    }
    exit();
}

int main()
{
    int tid = thread_creator(add, 0);
    thread_join(tid);
    exit();
}