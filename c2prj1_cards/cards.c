#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "cards.h"


void assert_card_valid(card_t c) {
  assert(2<=c.value && c.value<=VALUE_ACE);
  assert(SPADES<=c.suit && c.suit<=CLUBS);
}

const char * ranking_to_string(hand_ranking_t r) {
  switch(r){
  case STRAIGHT_FLUSH: return(" STRAIGHT_FLUSH\n"); break;
  case FOUR_OF_A_KIND: return("  FOUR_OF_A_KIND\n"); break;
  case  FULL_HOUSE: return("  FULL_HOUSE\n"); break;
  case  FLUSH: return("  FLUSH\n"); break;
  case  STRAIGHT: return("  STRAIGHT\n"); break;
  case  THREE_OF_A_KIND: return("  THREE_OF_A_KIND\n"); break;
  case  TWO_PAIR: return("  TWO_PAIR\n"); break;
  case  PAIR: return("  PAIR\n"); break;
  case    NOTHING: return("    NOTHING\n"); break;
  default: return(" Invalid rank "); break;
    }
  // return r;
}

char value_letter(card_t c) {
  switch(c.value){
  case 2:c.value = '2';; break;
  case 3:c.value = '3'; break;
  case 4:c.value = '4'; break;
  case 5:c.value = '5'; break;
  case 6:c.value = '6'; break;
  case 7:c.value = '7'; break;
  case 8:c.value = '8'; break;
  case 9:c.value = '9'; break;
  case 10:c.value = '0'; break;;
  case VALUE_JACK:c.value = 'J'; break;
  case VALUE_QUEEN:c.value = 'Q'; break;
  case VALUE_KING:c.value = 'K'; break;
  case VALUE_ACE:c.value = 'A'; break;
  default: printf(" Invalid value"); break;
  }
  return c.value;
}


char suit_letter(card_t c) {
  switch(c.suit){
  case SPADES:c.suit = 's'; break;
  case HEARTS:c.suit = 'h'; break;
  case DIAMONDS:c.suit = 'd'; break;
  case CLUBS:c.suit = 'c'; break;
  default: printf("Invalid suit"); break;
  }
  return c.suit;
}

void print_card(card_t c) {
  char v = value_letter(c);
  char s = suit_letter(c);
  printf("%c%c",v,s);
}

card_t card_from_letters(char value_let, char suit_let) {
  card_t temp;
  switch(value_let){ 
    case '2': temp.value = 2; break;
    case '3': temp.value = 3; break;
    case '4': temp.value = 4; break;
    case '5': temp.value = 5; break;
    case '6': temp.value = 6; break;
    case '7': temp.value = 7; break;
    case '8': temp.value = 8; break;
    case '9': temp.value = 9; break;
    case '0': temp.value = 10; break;
    case 'J': temp.value = VALUE_JACK; break;
    case 'Q': temp.value = VALUE_QUEEN; break;
    case 'K': temp.value = VALUE_KING; break;
    case 'A': temp.value = VALUE_ACE; break;
    }
  switch(suit_let){
  case 's': temp.suit = SPADES; break;
  case 'h': temp.suit = HEARTS; break;
  case 'd': temp.suit = DIAMONDS; break;
  case 'c': temp.suit = CLUBS; break;
  }
  assert_card_valid(temp);
  return temp;
}

card_t card_from_num(unsigned c) {
  card_t temp;
  assert(c>=0 && c<52);
  temp.value = c%13+2;
  temp.suit = c/13;
  return temp;
}
