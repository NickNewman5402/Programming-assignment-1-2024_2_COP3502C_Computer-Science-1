//Student Info
/*
  COP3502C Assigment 1 
  This program is written by: Nicholas Eric Newman
  */
// Overview
/*
  This assignment is intended to make you work with dynamic memory allocation, pointers, and arrays of pointers. The
  difficulty level is not actually very high, but it might take sometimes to do it depending on your understanding of
  Dynamic Memory Allocation - don't wait until the weekend it's due to start it!
  Your solution should follow a set of requirements to get credit
*/

// Problem Description
/*
  It’s hot summer. Let’s have some smoothies to stay hydrated and feel cool! A smoothie is a blended drink
  concoction, with several ingredients. Each different type of smoothie has a different ratio of its ingredients. For
  example, the "StrawberryBreeze" has the following ratios of items:
  2 units strawberry
  1 unit banana
  1 unit kiwi
  2 units yogurt
  If a store manager sells 18 pounds of Strawberry Breeze smoothie a week, then his weekly order ought to have 6
  lbs of strawberries, 3 lbs of banana, 3 lbs of kiwi and 6 lbs of yogurt.
  Of course, there are other types of smoothies a store manager must sell, so to figure out her weekly order, she has
  to go through how much of each smoothie she'll sell and each smoothie's recipe and put together these
  calculations.
  For your program, you'll read in information about several smoothie recipes and several stores expected sales for
  the week, and determine what raw ingredients (and how much of each) each store should order.

*/

//The problem
/*
  Given a list of possible smoothie ingredients, a list of smoothie recipes, and lists of sales from several stores,
  determine how much of each ingredient each store must order.

  */


typedef struct item {
int itemNo;
int portions;
} item;

typedef struct recipe {
int itemCount;
item* itemList;
int totalPortions;
} recipe;


#include <stdio.h>

int main(void) {

  recipe** smoothieList;


  
  return 0;
}