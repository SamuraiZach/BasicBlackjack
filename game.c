#include "card.h"
#include <stdlib.h> // for drand48
#include <stdio.h>
#include <string.h>

void main(void) {
    cardT *pile = makeDeck();
    char Choice[6];
    int winCon = 0; // 1 equals win and 2 equals loss
    int breakCon = 0; //break condition for player aspect
    int dealerCon = 0; // break condition for dealer aspect
    int dealerTotal = 0;
    int permPlayerScore = 0;
    cardT *frontP = NULL;
    cardT *frontD = NULL;
    //cardT *frontPile = NULL;
    cardT *player;
    cardT *dealer;
    int x = (rand() % 50) + 1;
    int cc = 0;
    while(cc < x){
        pile = shuffle(pile);
        cc += 1;
    }
    printf("\nShowing Pile: \n");
    showPile(pile);
    printf("\nDealing Cards....\n");
    player = deal(pile);
    player->next = frontP;
    frontP = player;
    player = deal(pile);
    player->next = frontP;
    frontP = player;
    dealer = deal(pile);
    dealer->next = frontD;
    frontD = dealer;
    printf("\nDealer Cards: ");
    showPile(dealer);
    printf("\nPlayer Cards: ");
    showPile(player);
    printf("\n");
    showPile(pile);
    while(breakCon == 0){ //Player aspect
        permPlayerScore = totalPile(player);
        printf("\nHit (\'h\',\'H\',Hit) or Stand (\'s\',\'S\',Stand)");
        scanf("%s",Choice);
        if(strcmp(Choice,"s") == 0 || strcmp(Choice,"S") == 0 || strcmp(Choice,"Stand") == 0){
                permPlayerScore = totalPile(player);
                breakCon += 1;
        }else if(strcmp(Choice,"h") == 0 || strcmp(Choice,"H") == 0 || strcmp(Choice,"Hit") == 0){
                player = deal(pile);
                player->next = frontP;
                frontP = player;
                printf("\nNew Hand: ");
                showPile(player);
                if(totalPile(player) > 21){
                        printf("\nBUST! Ended at total of: %d",totalPile(player));
                        breakCon += 1;
                        winCon = 2;
                }
        }
    }
    while(dealerCon == 0 && winCon == 0){ //Dealer aspect
        dealer = deal(pile);
        dealer->next = frontD;
        frontD = dealer;
        if(totalPile(dealer) >= 17){
                int dealerTotal = totalPile(dealer);
                if(dealerTotal > 21){
                        winCon = 1;
                        printf("\nDEALER BUSTED AT %d",dealerTotal);
                }else{
                        if(dealerTotal >= permPlayerScore){
                                winCon = 2;
                                dealerCon += 1;
                                printf("\nDealer total: %d \nPlayer total: %d",dealerTotal,permPlayerScore);
                        }
                        else{
                                winCon = 1;
                                dealerCon += 1;
                                printf("\nDealer total: %d \nPlayer total: %d",dealerTotal,permPlayerScore);
                        }
                }
        }
    }
    permPlayerScore = totalPile(player);
    dealerTotal = totalPile(dealer);
    if(winCon == 1){ //win
        printf("\n\nWon!");
        printf("\nStats: \nPlayer Total: %d \nPlayer Cards: \n",permPlayerScore);
        showPile(player);
        printf("\nDealer Total: %d \nDealer Cards: \n",dealerTotal);
        showPile(dealer);
        printf("\n\n");
    }
    else if(winCon == 2){ //loss
        printf("\n\nLost!");
        printf("\nStats: \nPlayer Total: %d \nPlayer Cards: \n",permPlayerScore);
        showPile(player);
        printf("\nDealer Total: %d \nDealer Cards: \n",dealerTotal);
        showPile(dealer);
        printf("\n\n");
    }
}
