#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Student Info
/*
  COP3502C Assigment 1
  This program is written by: 
  Nicholas Eric Newman
  Due date June 2, 2024
  student ID 5292926
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

  Sample Input:															Sample Output:
  8// ingredients														List of items for store 1:
  yogurt// ingrdient[0]													yogurt 8.444444
  chocolate																chocolate 4.444444
  raspberry																banana 2.222222	
  banana																	mango 12.888889
  mango																	spinach 2.000000
  spinach								
  kiwi																List of items for store 2:
  strawberry																yogurt 6.000000
  3// 3 recipes															banana 3.000000
  4 7 2 3 1 6 1 0 2// 4 ingrdients ingrdient[7] portion(2) etc...			kiwi 3.000000
  3 0 2 5 1 4 2															strawberry 6.000000
  4 0 2 4 4 3 1 1 2					
  3// 3 stores														List of items for store 3:
  2 1 10 2 20// 2 recipes, recipe 1, weight of 10, recipe 2 weight 20		yogurt 8.666667
  1 0 18																	chocolate 3.333333
  3 0 10 1 5 2 15															banana 3.333333
                                      mango 8.666667
                                      spinach 1.000000	
                                      kiwi 1.666667
                                      strawberry 3.333333

  */


typedef struct item {
  int itemNo;
  double portions;// made double as leaving it as int did not produce a double in the end
} item;

typedef struct recipe {
  int itemCount;
  item* itemList;
  double totalPortions;// made double as leaving it as int did not produce a double in the end
} recipe;

char** readIngredients(int *numIngredients);
recipe* readRecipe();
recipe** readAllRecipes(int *numRecipes);
double* calculateOrder(int ingredientCount, int numSmoothies, recipe** recipeList);
void printOrder(char** ingredientNames, double* orderList, int numIngredients);
void freeIngredients(char** ingredientList, int numIngredients);
void freeRecipes(recipe** allRecipes, int numRecipes);


// puts ingredients in a char array to be refrenced later 
char **readIngredients(int *numIngredients) {

  scanf("%d", numIngredients);
  char name[21];// creates a char array of size 20 allowing the \0 at the end of a string
  char **ingredients = (char**)malloc(sizeof(char*)*(*numIngredients));  

  for (int i = 0; i < *numIngredients; i++) {

    scanf("%s", name);
    ingredients[i] = (char*)malloc((strlen(name) + 1) * sizeof(char));
    strcpy(ingredients[i], name);// populates ingredients[i] with the names entered.

  }

  return ingredients;

}

// takes in number of recipes and then runs the function readRecipe
recipe** readAllRecipes(int *numRecipes) {

  scanf("%d", numRecipes);

  recipe **smoothies = (recipe**)malloc(*numRecipes * sizeof(recipe*));
  for (int i = 0; i < *numRecipes; i++) {

    smoothies[i] = readRecipe(); // returns a recipe pointer

  }

  return smoothies;

}

// Creates a smoothie with ingrdient info and ratio info saved in smootie[i] created in readAllRecepies
recipe *readRecipe() {


  recipe *smoothie = (recipe*)malloc(sizeof(recipe));
  int numItems;

  scanf("%d", &numItems);

  smoothie->itemCount = numItems;

  smoothie->itemList = (item*)malloc(numItems * sizeof(item));
  smoothie->totalPortions = 0;

  for (int i = 0; i < numItems; i++) {

    scanf("%d", &smoothie->itemList[i].itemNo);
    scanf("%lf", &smoothie->itemList[i].portions);// made %lf to reflect the double data type

    smoothie->totalPortions += smoothie->itemList[i].portions;
  }

  return smoothie;


}

double* calculateOrder(int ingredientCount, int numSmoothies, recipe** recipeList) {

  double* amountOfEachItem = (double*)calloc(ingredientCount, sizeof(double));
  int numOfRecipes;
  int recipeNum;
  double unitInPounds;// made double as leaving it as int did not produce a double in the end

  scanf("%d", &numOfRecipes);


  for (int i = 0; i < numOfRecipes; i++) {

    scanf("%d", &recipeNum);
    scanf("%lf", &unitInPounds);// made %lf to reflect the double data type

    for (int j = 0; j < recipeList[recipeNum]->itemCount; j++) {

        amountOfEachItem[recipeList[recipeNum]->itemList[j].itemNo] 
        += (unitInPounds * recipeList[recipeNum]->itemList[j].portions) 
        / recipeList[recipeNum]->totalPortions;

    }
  }

  return amountOfEachItem;
}

void printOrder(char** ingredientNames, double* orderList, int numIngredients) {

  for (int i = 0; i < numIngredients; i++) {

    if (orderList[i] > 0) {

      printf("%s %.6f\n", ingredientNames[i], orderList[i]);

    }
  }
  printf("\n");
}

void freeIngredients(char** ingredientList, int numIngredients) {

  for (int i = 0; i < numIngredients; i++) {
    free(ingredientList[i]);
  }

  free(ingredientList);
}

void freeRecipes(recipe** allRecipes, int numRecipes) {

  for (int i = 0; i < numRecipes; i++) {
    free(allRecipes[i]->itemList);
    free(allRecipes[i]);
  }

  free(allRecipes);

}

int main(void) {

  int numIngredients;
  int numRecipes;
  int numStores;
  int numItems;

  char **ingredientNames;
  recipe **smoothieList;
  double *amountOfEachItem;
  recipe **recipeList;


  ingredientNames = readIngredients(&numIngredients);//readIngredients returns char **

  smoothieList = readAllRecipes(&numRecipes);// readAllRecipes returns recipe **

  scanf("%d", &numStores);
  for (int i = 0; i < numStores; i++) {

    amountOfEachItem = calculateOrder(numIngredients, numRecipes, smoothieList);// calculateOrder returns double *
    printf("List of items for store %d:\n", i+1);
    printOrder(ingredientNames, amountOfEachItem, numIngredients);
    free(amountOfEachItem);

  }

  freeIngredients(ingredientNames, numIngredients);
  freeRecipes(smoothieList, numRecipes);

  return 0;
}