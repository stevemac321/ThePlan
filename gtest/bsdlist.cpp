#include "test.h"
#include "/usr/src/sys/sys/queue.h"

struct snode {
        void *pdata;
        SLIST_ENTRY(snode) ptrs;
};
struct slist {
        size_t datasz;
        SLIST_HEAD(snode_list, snode) head;
};

void slist_init(struct slist *pl)
{
        SLIST_INIT(&pl->head);
}

void slist_free(struct slist *pl)
{
        struct snode *p = NULL;
        while(!SLIST_EMPTY(&pl->head)) {
                p = SLIST_FIRST(&pl->head);
                SLIST_REMOVE_HEAD(&pl->head, ptrs);
                free(p->pdata);
                free(p);
        }
}
void slist_push(struct slist *pl, const void *pd, const size_t sz)
{
        struct snode *pnew = (struct snode*)malloc(sizeof(struct snode));
        pnew->pdata = malloc(sz);
        if(!pnew->pdata) {
            perror("malloc failed");
            return;
        }
        memcpy(pnew->pdata, pd, sz);

        SLIST_INSERT_HEAD(&pl->head, pnew, ptrs);
}
void slist_foreach(struct slist *pl, void(*f)(const struct snode*))
{
        struct snode *p = NULL;
        SLIST_FOREACH(p, &pl->head, ptrs)
                f(p);
}
void print_node(const struct snode* ps)
{
    if(!ps) {
        perror("null node");
        return;
    }

    printf("%d ", *(int*)ps->pdata);
}
auto test_bsdlist()
{
    struct slist list;
    slist_init(&list);

    for(int i=0; i < 10; i++)
        slist_push(&list, &i, sizeof(int));

    slist_foreach(&list, print_node);
    puts("--------------------");
    
    slist_free(&list);
	return 0;
}

auto test_against_bsdlist()
{
    return 0;
}
