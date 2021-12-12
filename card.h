// note, the typedef name is "cardT", the struct name is "struct card"
typedef struct card {
    int rank;
    char suit;
    struct card *next; 
} cardT;

// Used something like this:
// cardT *pile = createCard(2,'C');
// pile->next = createCard(3,'C');
// pile->next->next = NULL;

cardT *makeCard(int rank, char suit); 
cardT *makeDeck();
void freePile(cardT *pile);
cardT *shuffle(cardT *pile); 
cardT* deal(cardT *pile);
int totalPile(cardT *pile);
int countPile(cardT *pile); 
void showPile(cardT *pile);
