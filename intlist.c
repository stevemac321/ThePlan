#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

struct inode{
  int x;
  struct inode *next;
};

struct ilist{
  struct inode *first;
};

bool delete_inode_byval_ilist_dummy(struct ilist * pl, const int val);

void init_ilist(struct ilist *pl)
{
  assert(pl);
  pl->first = nullptr;
}
void insert_ilist(struct ilist *pl, const int val)
{

  assert(pl);
  struct inode * pnew = malloc(sizeof(struct inode));
  assert(pnew);
  
  pnew->x = val;
  
  if(pl->first == nullptr){
    pnew->next = nullptr;
    
  }else {
    pnew->next = pl->first;
  }
    pl->first = pnew;
}

void append_ilist(struct ilist *pl, const int val)
{
  assert(pl);
  struct inode * pnew = malloc(sizeof(struct inode));
  assert(pnew);
  
  pnew->x = val;
  pnew->next = nullptr;
  
  if(pl->first == nullptr){
    pl->first = pnew;    
  }else {

    struct inode * p = pl->first;

    while(p->next != nullptr) {
      p = p->next;
    }
    p->next = pnew;
  }
}
void free_ilist(struct ilist* pl)
{
  assert(pl);
  struct inode * p = pl->first;
  while(p != nullptr){
    struct inode * pdel = p;
    p = p->next;
    printf("%d\n", pdel->x);
    free(pdel);
  }
}
bool remove_dups_ilist(struct ilist * pl)
{
  return false;
}
bool delete_inode_byval_ilist(struct ilist * pl, const int val)
{
  assert(pl);
  if(pl->first == nullptr)
    return false;
  
  if(pl->first != nullptr && pl->first->x == val) {
    struct inode *pdel = pl->first;
    pl->first = pl->first->next;
    free(pdel);
    return true;
  }

  struct inode *pprev = pl->first;
  struct inode *pcur = pl->first->next;
  while(pcur != nullptr && pcur->x != val) {
    pcur = pcur->next;
    pprev =pprev->next;
  }
  
  if(pcur == nullptr || pcur->x != val)
    return false;

  // if we get here, we found it!
  struct inode *pdel = pcur;
  pprev->next = pcur->next;
  free(pdel);
  return true;
}
bool delete_inode_byaddr_ilist(struct ilist * pl, struct inode *pdel)
{
  return false;
}
struct inode *find_inode_byval_ilist(struct ilist *pl, const int val)
{
  return nullptr;
}
struct inode *find_inode_byaddr_ilist(struct ilist *pl, struct inode *pfind)
{
  return nullptr;
}
void test_insert_ilist()
{
  struct ilist list;
  init_ilist(&list);
  for(int i=0; i < 10; i++)
    insert_ilist(&list, i);

  free_ilist(&list);
}
void test_append_ilist()
{
  struct ilist list;
  init_ilist(&list);
  for(int i=0; i < 10; i++)
    append_ilist(&list, i);

  free_ilist(&list);
}
void test_delete_inode_byval_ilist()
{
  struct ilist list;
  init_ilist(&list);
  for(int i=0; i < 10; i++)
    insert_ilist(&list, i);
// test with 5, 0, 9, first and last.
  bool ret = delete_inode_byval_ilist_dummy(&list, 0);
  printf("delete returned %d\n", ret);
  free_ilist(&list);
};

int main(int argc, char *argv[])
{
  test_insert_ilist(); 
  puts("---------------------------\n");
  test_append_ilist(); 
  puts("---------------------------\n");
  test_delete_inode_byval_ilist();
  puts("---------------------------\n");
}
bool delete_inode_byval_ilist_dummy(struct ilist * pl, const int val)
{
  assert(pl);
  if(pl->first == nullptr)
    return false;

  // Create a dummy node
  struct inode dummy;
  dummy.next = pl->first;

  struct inode *pprev = &dummy;
  struct inode *pcur = pl->first;
  while(pcur != nullptr && pcur->x != val) {
    pcur = pcur->next;
    pprev = pprev->next;
  }

  if(pcur == nullptr)
    return false;

  // if we get here, we found it!
  struct inode *pdel = pcur;
  pprev->next = pcur->next;
  free(pdel);

  // Update the first node in case it was deleted
  pl->first = dummy.next;

  return true;
}


