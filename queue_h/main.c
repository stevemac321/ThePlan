#include "/usr/src/sys/sys/queue.h"
#include "/usr/src/sys/sys/proc.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define _countof(x) sizeof(x) / sizeof(x[0])
enum insert_type {HEAD, TAIL};
bool alloc_insert(const char * name, const int pri, struct proc* parent, enum insert_type type);
void foreach_thread(struct proc *parent);
void free_threads(struct proc *parent);

int main()
{
    struct proc myproc;
    TAILQ_INIT(&myproc.p_threads);
    
    const char * names[] = {"thread 0", "thread 1", "thread 2", "thread 3", "thread 4"};

    alloc_insert(names[0], 0, &myproc, HEAD); 

    for(size_t i = 1; i < _countof(names); i++) {
        alloc_insert(names[i], i, &myproc, TAIL);
    }

    foreach_thread(&myproc);
    free_threads(&myproc);
}

bool alloc_insert(const char * name, const int pri, struct proc* parent, enum insert_type type)
{
    struct thread* t = malloc(sizeof(struct thread));
    
    if(!t) {
        perror("alloc failed");
        return false;
    }

    size_t len = strlen(name);
    size_t cplen = len <= MAXCOMLEN + 1 ? len : MAXCOMLEN + 1;
    strncpy(t->td_name, name, cplen);
    t->td_priority = pri;
    t->td_proc = parent;

   if(type == HEAD) { 
        TAILQ_INSERT_HEAD(&parent->p_threads, t, td_plist);
   }else {

        TAILQ_INSERT_TAIL(&parent->p_threads, t, td_plist);
   }
    return true;
}

void foreach_thread(struct proc *parent)
{
    struct thread *t, *tmp;
    TAILQ_FOREACH(t, &parent->p_threads, td_plist) {
        printf("Thread Name: %s, Priority: %d\n", t->td_name, t->td_priority);
    }
}
void free_threads(struct proc *parent)
{
    struct thread *t, *tmp;
    TAILQ_FOREACH_SAFE(t, &parent->p_threads, td_plist, tmp) {
        // Remove the thread from the queue
        TAILQ_REMOVE(&parent->p_threads, t, td_plist);
        // Free the memory allocated for the thread
        free(t);
    }
}
