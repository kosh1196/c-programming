#include "cards.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>


void test_card_correct(card_t c, unsigned value, suit_t suit)
{
  printf(" assert card_correct with c.value(%d), c.suit(%d), value(%d), suit(%d)\n",c.value,c.suit,value,suit);
  if(c.value==0 && c.suit==0){
    printf(" assert print");}
  else{
    assert(c.value==value && c.suit==suit);
  }
}
void test_card_num()
{
  printf(" test card_from_num");
  test_card_correct(card_from_num(0),2,SPADES);
  test_card_correct(card_from_num(13),5,HEARTS);
  test_card_correct(card_from_num(50),VALUE_ACE,CLUBS);
  test_card_correct(card_from_num(9),VALUE_KING,DIAMONDS);
  printf("PASSED\n");
}
void test_card_valid()
{
  printf(" test assert_card_valid ");
  card_t c;
  c.suit = SPADES;
  c.value = 2;
  assert_card_valid(c);
  printf(" CARD OK ");
  
}
void test_card_value()
{
  printf("test value_letter");
  card_t c;
  c.value = 2;
  assert(value_letter(c)=='2');
  c.value = 10;
  assert(value_letter(c)=='0');
  c.value = VALUE_JACK;
  assert(value_letter(c)=='J');
  printf(" TEST CARD PASS");
}
void test_card_suit()
{
  printf(" test suit_letter");
  card_t c;
  c.suit = SPADES;
  assert(suit_letter(c)== 's');
  c.suit = HEARTS;
  assert(suit_letter(c)== 'h');
  printf(" TEST SUIT PASS");
}
void test_print()
{
  printf(" test print_card");
  card_t c;
  c.value = 2;
  print_card(c);
  printf("\n");
  c.value = VALUE_ACE;
  print_card(c);
  printf("TSET PRINT CARD PASS");
}
void test_card_letter(char value_let, char suit_let)
{
  printf(" test card_from_letter");
  card_t card;
  card = card_from_letters('2', 's');
  printf("card(value %d, suit %d)\n",card.value, card.suit);
  assert(card.value== 2 && card.suit== SPADES);
  card = card_from_letters('A', 'd');
  printf("card(value %d, suit %d)\n",card.value, card.suit);
  assert(card.value== VALUE_ACE && card.suit== DIAMONDS);
}
int main(void) {
  test_card_valid();
  test_card_num();
  test_card_value();
  test_card_suit();
  test_print();
  test_card_letter('2', 's');
}
