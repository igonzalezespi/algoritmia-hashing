#define LIBRE -1
#define BORRADO -2

typedef struct myreg {
  int key;
} myreg;

void h_init(myreg t_hash[], int tam);
int h_insert(myreg r, myreg t_hash[], int tam);
int h_search(int v, myreg t_hash[], int tam);
int h_remove(int v, myreg t_hash[], int tam);
float h_loadfactor(myreg t_hash[], int tam);

void h_show(myreg t_hash[], int tam);




