#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

char** readIngredients(int *numIngredients);
recipe* readRecipe();
recipe** readAllRecipes(int *numRecipes);
double* calculateOrder(int ingredientCount, int numSmoothies, recipe** recipeList);
void printOrder(char** ingredientNames, double* orderList, int numIngredients);
void freeIngredients(char** ingredientList, int numIngredients);
//void freeRecipes(recipe** allRecipes, int numRecipes);


// Confirmed to be good as of 5/27/24 @ 10:37am
char **readIngredients(int *numIngredients) {

  char name[21];// creates a char array of size 20 allowing the \0 at the end of a string
  char **ingredients = (char**)malloc(sizeof(char*)*(*numIngredients)); // creates a pointer to numIngredient pointers. 
  for (int i = 0; i < *numIngredients; i++) {
    printf("Enter ingredient [%d] name: ", i + 1);
    scanf("%s", name);
    ingredients[i] = (char*)malloc((strlen(name) + 1) * sizeof(char));// creates a box of size of the name + 1 (for the \0) * the size of char that is pointed to by ingredients[i].
    strcpy(ingredients[i], name);// populates ingredients[i] with the name entered.
  }

  return ingredients;

}

// takes in number of recipes and then runs the function readRecipe
recipe **readAllRecipes(int *numRecipes) {

  recipe **smoothies = (recipe**)malloc(*numRecipes * sizeof(recipe*)); // NULL was put in due to "C4700 uninitialized local variable 'smoothies' used compiler error
  for (int i = 0; i < *numRecipes; i++) {
    smoothies[i] = readRecipe(); // returns a recipe pointer
  }
  return smoothies;

}

// Creates a smoothie with info saved in smootie[i] created in readAllRecepies
recipe *readRecipe() {

  // sample input:
  /*
    m I1 R1 I2 R2 … Im Rm
    m represents the number of different ingredients in the smoothie (1 ≤ m ≤ 100)
    I1 represents the ingredient number of the first ingredient (0 ≤ I1 < n)
    R1 represents the number of parts (ratio) of the first ingredient (1 ≤ R1 ≤ 1000) in the smoothie recipe

    The rest of the I and R variables represent the corresponding information for the rest of the smoothie ingredients.
  */

  recipe *smoothie = (recipe*)malloc(sizeof(recipe));
  int numItems;
  printf("\nEnter number of items: ");
  scanf("%d", &numItems);
  smoothie->itemCount = numItems;// m CODE IS BREAKING HERE
  smoothie->itemList = (item*)malloc(numItems * sizeof(item));
  smoothie->totalPortions = 0;

  for (int i = 0; i < numItems; i++) {
    printf("Enter item [%d] name: ", i);
    scanf("%d", &smoothie->itemList[i].itemNo);// item number is storing the number to be referenced later by infredients[i]? Im
    printf("Enter ratio amout of item [%d]: ", i);
    scanf("%d", &smoothie->itemList[i].portions);// Rm
    smoothie->totalPortions += smoothie->itemList[i].portions;
  }

  return smoothie;


}

int main(void) {

  int numIngredients;
  int numRecipes;
  int numStores;
  int numSmoothies;
  int numItems;

  char **ingredients;
  recipe **smoothieList;
  double **amountOfEachItem;
  recipe **recipeList;

  /*The first line will contain a single positive integer, n (n ≤ 105 ), representing the number of possible smoothie ingredients.
  */
  printf("Enter number of ingrdients: ");
  scanf("%d", &numIngredients);
  ingredients = readIngredients(&numIngredients);
  //Used to confirm ingredients came back to main. Up to here is confirmed as operational as of 5/27/24 @ 10:37am
  /*
  printf("ingrdients confirmation:\n");
  for(int i = 0; i < numIngredients; i++){
    printf("ingredient %d: %s\n", i+1, ingredients[i]); // this is not printing for some reason. Program crashes... This was not printing because I was writing directly to ingredients[i]. I needed to create an array names[21] and then use strcpy to copy the string into ingrdeints[i] with strcpy(ingredients[i], name);
  }
  */





  /*The following n lines will each contain a single word string of in between 1 and 20 characters (all letters, digits or underscores). The ith (0 ≤ i ≤ n-1) of these will contain the name of the ith smoothie ingredient. (Thus, the ingredients are numbered from 0 to n-1.)
*/
  printf("\nEnter number of smoothie recipes: ");
  scanf("%d", &numRecipes);
  recipeList = readAllRecipes(&numRecipes);



  /********* Finished here on page 3: The following line of input will contain a single positive            integer, k (1 ≤ k ≤ 100), representing the number of stores making orders for smoothie ingredients. (Number the stores 1 to k, in the order they appear in the input.)
  *******************/
  printf("\nEnter number of stores: ");
  scanf("%d", &numStores);
  printf("\nEnter number of smoothies each store will buy: ");
  scanf("%d", &numSmoothies);

  //calculateOrder(numIngredients, numSmoothies, recipeList);// Double check these inputs...


  /***************************************************************************************/






  //smoothieList = readAllRecipes(&numRecipes);
  //amountOfEachItem = calculateOrder(numIngredients, numSmoothies, smoothieList);
  //printOrder(ingredientNames, amountOfEachItem, numIngredients);

  return 0;
}

/*Imported code from MSVC at 10:07pm in order to verify compile and such. I am now making it to line 166 time to implement store info*/