#include <stdio.h>
#include <stdlib.h> // for drand48
#include "card.h"

cardT *makeCard(int rank, char suit){
        int count = 0;
        cardT *card;
        card = malloc(sizeof(cardT *));
        card->rank = rank;
        card->suit = suit;
        if(rank >= 14 || rank <= 0){
                count += 1;
        }
        if(suit != 'C' && suit != 'D' && suit != 'H' && suit != 'S'){
                count += 1;
        }
        if(count ==0){
                return card;
        }else{
                return NULL;
        }
}

cardT *makeDeck(){
        cardT *front = NULL;
        cardT *card = NULL;
        for(int i = 1; i < 14; i++){
                card = makeCard(i,'C');
                card->next = front;
                front = card;
                card = makeCard(i,'D');
                card->next = front;
                front = card;
                card = makeCard(i,'S');
                card->next = front;
                front = card;
        }
        return front;
}

void freePile(cardT *pile){
        cardT *card = pile;
        cardT *discard = NULL;
        while(card != NULL){
                discard = card;
                card = card->next;
                free(discard);
        }
}

cardT* deal(cardT *pile){
        if(pile == NULL || pile->next==NULL){
                return pile;
        }

        cardT *card = pile;
        cardT *lastCard = NULL;
        while(card->next != NULL){
                lastCard = card;
                card = card->next;
        }
        lastCard->next = NULL;
        return card;
}

int totalPile(cardT *pile){
        cardT *card = pile;
        int totalCardsPoints = 0;
        while(card != NULL){
                if(card->rank>10){
                        totalCardsPoints += 10;
                }else{
                        totalCardsPoints += card->rank;
                }
                card = card->next;
        }
        return totalCardsPoints;
}

/* counts the number of cards in the list headed by "deck" */
int countPile(cardT *pile) {
    int count=0;
    /* When "deck" is NULL (zero), it's at the end. Otherwise,
     * move to the next card and increment the count.
     */
    for(count=0; pile; pile=pile->next)
    {
        count++;
    }
    return count;
}

/* just shows the top card right now */
void showPile(cardT *pile) {
        cardT *card = pile;
        while(card != NULL){
                printf("%d%c ",card->rank,card->suit);
                card = card->next;
        }
}

/* Emulates a "riffle shuffle" of "deck". */
cardT *shuffle(cardT *deck) {
    int size = countPile(deck);
    cardT *cut=deck;
    for(int i=0; i<size/2; i++){
        cut=cut->next;
    }
    /* cut is now the card 1/2 way through the deck */
    cardT *riffle=cut->next;
    cut->next = 0; /* deck and riffle now head separate lists */
    /* Shuffle the deck by randomly pulling a card from the head of "deck" or "riffle"
       and make it the new head of "retdeck" */
    cardT *retdeck=0;
    for(;deck || riffle;) { /* just like a while loop */
        cardT *temp;
        if(deck && (!riffle || drand48()<0.5)) {
            /* next card comes from the top of 'deck' */
            temp=deck;
            deck=deck->next;
        } else if(riffle) {
            /* next card comes from the top of 'riffle' */
            temp=riffle;
            riffle=riffle->next;
        }
        /* put the card at the top of the "retdeck" */
        temp->next=retdeck;
        retdeck=temp;
    }
    return retdeck;
}
