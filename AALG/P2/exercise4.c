/**************************************************/
/* Programa: ejercise4       Date: 03/11/2020     */
/* Authors: Lucía Gil and Paula Beltrán           */
/*                                                */
/* Program that checks MergeSort                  */
/*                                                */
/* Input: Command Line                            */
/* -size: number of elements of each permutation  */
/* Output: 0: OK, -1: ERR                         */
/**************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "permutations.h"
#include "sorting.h"

int main(int argc, char** argv)
{
  int tamano, i, j, ret;
  int* perm = NULL;

  srand(time(NULL));

  if (argc != 3) {
	fprintf(stderr, "Error in input parameters:\n\n");
    fprintf(stderr, "%s -size <int>\n", argv[0]);
    fprintf(stderr, "Where:\n");
    fprintf(stderr, " -size : number of elements in the permutation.\n");
    return 0;
  }
  printf("Practice number 2, section 1\n");
  printf("Done by: Lucía Gil and Paula Beltrán\n");
  printf("Group: 1291\n");

  /* check command line */
  for(i = 1; i < argc; i++) {
    if (strcmp(argv[i], "-size") == 0) {
      tamano = atoi(argv[++i]);
    } else {
      fprintf(stderr, "Wrong paramenter %s\n", argv[i]);
    }
  }

  perm = generate_perm(tamano);

  if (perm == NULL) { /* error */
    printf("Error: Out of memory\n");
    exit(-1);
  }

  ret = quicksort(perm, 0, tamano-1);

  if (ret == ERR) {
    printf("Error: Error in MergeSort\n");
    free(perm);
    exit(-1);
  }

  for(j = 0; j < tamano; j++) {
    printf("%d \t", perm[j]);
  }
  printf("\n");

  free(perm);

  return 0;
}

