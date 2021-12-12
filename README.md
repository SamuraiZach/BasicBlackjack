# BasicBlackjack

Made by:

Zachariah Barraza (zbarraza@udel.edu) (zach.barraza@aol.com) 


    A "deck" of cards is created and "shuffled" (randomized) seven times. The shuffle() function has been included as an example in the card.c file. Important: the head of the list may change during shuffling, and shuffle() returns the new head! Don't ignore the return value!
    A (human) player and a (computer) dealer each will have a hand of cards (a pointer to cardT).
    The player will be "dealt" two cards. The dealer will be "dealt" one. All dealt cards will be shown.
    The player will be asked to "hit" or "stand". They can type 'h', 'H', or 'hit' to hit; 's', 'S', or 'stand' to stand. 
        If they "hit", another card is dealt (added to their hand) and shown.
            If the total value of cards exceeds 21, the player loses (busts) and the game is over.
            Otherwise, go back to #4
        If they "stand", then the player's score is the sum of the value of their cards.
    If the player has not lost, then the dealer keeps getting dealt cards until their hand's total is 17 or greater.
        If the dealer's hand exceeds 21, the player wins, and the game is over.
        Otherwise, the winner is the hand with the greater total sum. If both hands have the same sum, the dealer wins.
    When the game is over, the program should print "Won!" or "Lost!" according to whether the player won or lost.
    Note: this is a simplified version of Blackjack/21.
    The rank of a card is just a number between 1-13, inclusive and are not termed Jack, Queen, King, Ace.
    1s are always only worth 1.
    The maximum value of a card is 10 (so 10-13 all score 10 points).
    All cards are immediately printed when dealt in the form "RankSuit" as: "9C", "11H". Suits are C, D, H, S. Suits do not come into play, but must be recorded and printed.
