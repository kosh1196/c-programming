#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include "cards.h"
#include "deck.h"
#include "eval.h"
#include "future.h"
#include "input.h"

void free_future(future_cards_t * fc){
  for(int i = 0;i < fc->n_decks ; i++){
    free(fc->decks[i].cards);
    // free(fc->decks[i]);
  }
  free(fc->decks);
}

void copy_hands(deck_t *d1,deck_t *d2){
  for(int i = 0;i < d2->n_cards;i++){
    add_card_to(d1, *(d2->cards[i]));
  }
}

int main(int argc, char ** argv) {
  unsigned long trials = 10000;
  FILE * f ;
  if(argc < 2){
    fprintf(stderr,"required valid input file\n");
    exit(EXIT_FAILURE);
  }
  else if(argc == 2){
    f = fopen(argv[1],"r");
  }
  else if(argc == 3){
    f = fopen(argv[1],"r");
    trials = atoi(argv[2]);
  }
  else{
    fprintf(stderr,"too many aguments\n");
    exit(EXIT_FAILURE);
  }

  deck_t ** hands_array = NULL;
  deck_t * remaining_deck = NULL;
  size_t n_hands = 0;

  future_cards_t  *fc = malloc(sizeof(*fc));;
  fc->decks = NULL;
  fc->n_decks = 0;

  int cmp_hands = 0,win_index = 0;

  hands_array = read_input(f,&n_hands,fc);
  /*
  
  printf("\ninput_hands with zeros for unknowns\n");
  for(int i = 0;i < n_hands;i++){
    print_hand(hands_array[i]);
    printf("\n");
  }
  */

  remaining_deck = build_remaining_deck(hands_array, n_hands);

  /*
  printf("\nremaining deck before shuffle\n");
  print_hand(remaining_deck);
  printf("\n");
  */

  unsigned win_count[n_hands+1];
  size_t tie_flag = 0;
  for(int i = 0;i < n_hands + 1;i++){
    win_count[i] = 0;
  }

  for(int i = 0;i < trials;i++){

    shuffle(remaining_deck);

    /*
    printf("\nremaining deck after shuffle\n");
    print_hand(remaining_deck);
    */

    future_cards_from_deck(remaining_deck, fc);
    /*
    printf("\ninput_hands after drawing cards\n");
    for(int i = 0;i < n_hands;i++){
      print_hand(hands_array[i]);
      printf("\n");
    }
    */
    deck_t *d1 = malloc(sizeof(*d1));
    d1->cards = NULL;
    d1->n_cards = 0;

    deck_t *d2 = malloc(sizeof(*d2));
    d2->cards = NULL;
    d2->n_cards = 0;

    for(int j = 1;j < n_hands;j++){
      tie_flag = 0;
      copy_hands(d1,(hands_array[win_index]));
      copy_hands(d2,(hands_array[j]));
      // d1 = *(hands_array[win_index]);
      // d2 = *(hands_array[j]);

      cmp_hands = compare_hands(d1,d2);
      //printf("cmp_hands -> %d\n ", cmp_hands);

      d1->cards = NULL;
      d1->n_cards = 0;
      d2->cards = NULL;
      d2->n_cards = 0;

      if(cmp_hands == 1){
	win_index = j;
      }
      else if(cmp_hands == 0){
	tie_flag = 1;
      }
      /*
      printf("\n");
       print_hand(d1);
       printf("\n");
       print_hand(d2);
       printf("\n");
      */
      //  print_hand(hands_array[0]);
    }
    /*   
    printf("\ninput_hands after comparing\n");
    for(int i = 0;i < n_hands;i++){
      print_hand(hands_array[i]);
      printf("\n");
    }
    */
    if(tie_flag){
      win_count[n_hands]++;
    }
    else{
      win_count[win_index]++;
    }
  }
  for(size_t i = 0;i < n_hands;i++){
    printf("Hand %zu won %u / %ld times (%.2f%%)\n",i,win_count[i],trials,(float)win_count[i]/(float)trials*100);
  }
  printf("And there were %u ties\n",win_count[n_hands]);
  fclose(f);
  free_deck(remaining_deck);
  for(int i = 0;i < n_hands;i++){
    free_deck(hands_array[i]);

  }
  free(hands_array);
  free_future(fc);
  free(fc);
  return EXIT_SUCCESS;
}
