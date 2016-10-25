struct knot_s;
typedef struct knot_s *knot;

struct knot_s
{
    char *key;
    int val;
    knot next;
};

/*This function receives a pointer to a poiter to the first item list, and a 
 * string to put into the list, and puts it at the start of the list*/
void insertFirst(knot *start, char *x);

/*This function receives a poiter to the start*/
knot find(knot start, char *x);

/*Creates a new list and returns a poiter to its first item*/
knot newList();
