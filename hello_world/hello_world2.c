#include <stdio.h>

int n_hellos(int n)
  {
    for (int i = 0; i <= n; i++) {
      printf("Hello, Mr. Rogers! %d\n", i);
    }
    return 0;
  }

int main(int argc, char** argv) {
  n_hellos(45);
}