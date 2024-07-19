
#pragma once
enum insert_state { INSERTED, EXISTS, TABLEFULL };
typedef struct open_table open_table;
typedef open_table* tableptr;
typedef void* genptr;

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include "heap.h"
#include "open_table.h"
#include "algo.h"
#include "functor.h"


