#include "mpc.h"
#include <stdio.h>
#include <stdlib.h>

/* If we are compiling on Windows compile these functions */
#ifdef _WIN32
#include <string.h>

/* Create some parsers */
mpc_parser_t* Number = mpc_new("number");
mpc_parser_t* Operator = mpc_new("operator");
mpc_parser_t* Expr = mpc_new("expr");
mpc_parser_t* Lispy = mpc_new("lispy");

/* Define them with the following language */
mpca_lang(MPCA_LANG_DEFAULT,
  "                                                     \
    number    : /-?[0-9]+/ ;                            \
    operator  : '+' | '-' | '*' | '/' ;                 \
    expr      : <number> | '(' <operator> <expr>+ ')' ; \
    lispy     : /^/ <operator> <expr>+ /$/ ;            \
  ",
  Number, Operator, Expr, Lispy);

static char buffer[2048];

/* Fake readline function */
char* readline(char* prompt) {
  fputs(prompt, stdout);
  fgets(buffer, 2048, stdin);
  char* cpy = malloc(strlen(buffer)+1);
  strcpy(cpy, buffer);
  cpy[strlen(cpy-1)] = '\0';
  return cpy;
}

/* Fake add_history function */
void add_history(char* unused) {}

/* Otherwise include the editline headers */
#else
#include <editline/readline.h>
#include <editline/history.h>
#endif

int main(int argc, char** argv) {
  
  /* Print Version and Exit Information */
  puts("Lispy Version 0.0.0.0.1");
  puts("Built with love by Ethan Rogers");
  puts("Press Ctrl+c to Exit\n");
  
  /* In a never ending loop (1: true) */
  while (1) {
    
    /* Output our prompt & get input*/
    char* input = readline("leather> ");
    
    /* Add input to history */
    add_history(input);
    
    /* Echo input back to user */
    printf("OMG I JUST LOVE %s\n", input);
    
    /* Free retrieved input */
    free(input);
    
  }
  
  return 0;
}
