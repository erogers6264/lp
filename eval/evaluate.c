/* Load Abstract Syntax Tree from output */
mpc_ast_t* a = r.output
printf("Tag: %s\n", a->tag);
printf("Contents: %s\n", a->contents);
printf("Number of children: %i\n", a->children_num);

/* Get First Child */
mpc_ast_t* c0 = a->children[0];
printf("First Child Tag: %s\n", c0->tag);
printf("Contents: %s\n", a->contents);
printf("Number of children: %i\n", a->children_num);

int number_of_nodes(mpc_ast_t* t) {
  /* This is the base case. This is the case that ends the recursion*/
  if (t->children_num == 0) { return 1; }
  
  /* This is the recursive case. Breaks the counting computation into
  smaller parts, calls itself recursively to compute those parts, before
  combining them together. */
  if (t->children_num >= 1) {
    int total = 1;
    for (int i = 0; i < t->children_num; i++) {
      total = total + number_of_nodes(t->children[i]);
    }
    return total;
  }
  return 0;
}