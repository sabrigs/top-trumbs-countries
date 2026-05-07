#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

/*
Challenge 'Super Trunfo' - Countries (theme)
*/

/*
Country = 8 states, A-H
States = 4 cities, 01-04
Card code = state letter + city's number
Ex: A01, A02, B01
*/

// Global variables
#define MAX_CODE 4
#define MAX_CITY 20

typedef struct card
{
  char code[MAX_CODE];
  char city[MAX_CITY];
  char state;
  unsigned long int pop;
  unsigned int places;
  double area;
  double pib;
  double pop_density;
  double pib_pcap;
  double spower;
}card;

/* Prototype functions */
// Create cards
card create_card(void);
card random_card(void);

// Calculate
double calc_pop_density(card card);
double calc_pib_pcap(card card);
double calc_spower(card card);

// Print
void print_card(card card);
void title(char *text);
void game_intro(void);
void menu(void);
void menu_fields(void);
void print_winner(int result);

int menu_choice(void);

// Compare functions
int winner_pop(card a, card b);
int winner_places(card a, card b);
int winner_area(card a, card b);
int winner_pib(card a, card b);
int winner_pop_density(card a, card b);
int winner_pib_pcap(card a, card b);
int winner_spower(card a, card b);

int main()
{
  // Local variables
  card user;
  card robot;

  // Intro explaining the game
  game_intro();

  // Show options to create cards
  menu();

  // Get user answer
  int choice = menu_choice();
  
  // Menu to select how to fill user card
  switch (choice)
  {
  case 1:
    // Manual
    title("YOUR CARD");
    user = create_card();
    break;
  case 2:
    // Random
    title("YOUR CARD");
    user = random_card();
    print_card(user);
    break;
  default:
    printf("Invalid option.");
    return 1;
    break;
  }
  
  // Create robot's card
  robot = random_card();
  title("COMPUTER CARD");
  printf("The computer's card is ready too!\n");

  // Select atributes to compare
  title("FIGHT TIME");
  menu_fields();
  int fight_field = menu_choice();

  switch (fight_field)
  {
  case 1:
    // Population
    printf("\n");
    printf("Yours: %.2lu\n", user.pop);
    printf("Computer: %.2lu\n", robot.pop);
    printf("\n");
    print_winner(winner_pop(user, robot));
    break;
  case 2:
    // Places to visit
    printf("\n");
    printf("Yours: %u\n", user.places);
    printf("Computer: %u\n", robot.places);
    printf("\n");
    print_winner(winner_places(user, robot));
    break;
  case 3:
    // Area
    printf("\n");
    printf("Yours: %.2fkm²\n", user.area);
    printf("Computer: %.2fkm²\n", robot.area);
    printf("\n");
    print_winner(winner_area(user, robot));
    break;
  case 4:
    // PIB
    printf("\n");
    printf("Yours: R$ %.2f\n", user.pib);
    printf("Computer: R$ %.2f\n", robot.pib);
    printf("\n");
    print_winner(winner_pib(user, robot));
    break;
  case 5:
    // Pop. density
    printf("\n");
    printf("Yours: %.2f\n", user.pop_density);
    printf("Computer: %.2f\n", robot.pop_density);
    printf("\n");
    print_winner(winner_pop_density(user, robot));
    break;
  case 6:
    // PIB per capita
    printf("\n");
    printf("Yours: %.2f\n", user.pib_pcap);
    printf("Computer: %.2f\n", robot.pib_pcap);
    printf("\n");
    print_winner(winner_pib_pcap(user, robot));
    break;
  case 7:
    // Super power
    printf("\n");
    printf("Yours: %.2f\n", user.spower);
    printf("Computer: %.2f\n", robot.spower);
    printf("\n");
    print_winner(winner_spower(user, robot));
    break;
  default:
    printf("Invalid option.\n");
    return 1;
    break;
  }
  return 0;
} 

/* Functions */

card create_card(void)
{
  card new_card;

  // City
  printf("City's name: ");
  scanf("%s", new_card.city);

  // State
  printf("State: ");
  scanf(" %c", &new_card.state);

  // Area
  printf("City's area (km²): ");
  scanf("%lf", &new_card.area);
  
  // Population
  printf("Habitants' number: ");
  scanf("%lu", &new_card.pop);

  // Turistic places
  printf("Turistic places' number: ");
  scanf("%u", &new_card.places);

  // PIB
  printf("City's PIB: ");
  scanf("%lf", &new_card.pib);

  // Card code
  printf("City's code: ");
  scanf("%s", new_card.code);

  // Calculate density population
  new_card.pop_density = calc_pop_density(new_card);
  
  // Calculate PIB per capita
  new_card.pib_pcap = calc_pib_pcap(new_card);

  // Calculate super power
  new_card.spower = calc_spower(new_card);

  return new_card;
}

card random_card(void)
{
  card new_card;

  strcpy(new_card.code, "B01");
  strcpy(new_card.city, "Maji");
  new_card.state = 'B';
  new_card.pop = rand() % 10000000 + 100000;
  new_card.places = rand() % 100 + 1;
  new_card.area = (double)(rand() % 5000 + 100);
  new_card.pib = (double)(rand() % 500000000 + 1000000);
  new_card.pop_density = calc_pop_density(new_card);
  new_card.pib_pcap = calc_pib_pcap(new_card);
  new_card.spower = calc_spower(new_card);

  return new_card;
}

double calc_pop_density(card card)
{
  double pop_density = (double) card.pop / card.area;
  return pop_density;
}

double calc_pib_pcap(card card)
{
  double pib_pcap = (double) card.pib / card.pop;
  return pib_pcap;
}

double calc_spower(card card)
{
  double spower = (double) card.pop + card.places + card.area + card.pib + (card.pop_density / 1) + card.pib_pcap;
  return spower;
}

void print_card(card card)
{
  printf("\n");
  printf("✦ %s\n", card.city);
  printf("Code....................%s\n", card.code);
  printf("State...................%c\n", card.state);
  printf("Population..............%lu\n", card.pop);
  printf("Places to visit.........%u\n", card.places);
  printf("Area....................%.2lf km²\n", card.area);
  printf("PIB.....................%.2lf\n", card.pib);
  printf("Pop. density............%.2lf\n", card.pop_density);
  printf("PIB per capita..........%.2lf\n", card.pib_pcap);
  printf("Super power.............%.2lf\n", card.spower);
}

int winner_pop(card a, card b)
{
  // Win the smallest number
  if (a.pop > b.pop)
  {
    return 1;
  }
  if (a.pop < b.pop)
  {
    return 2;
  }
  return 0;
}

int winner_places(card a, card b)
{
  if (a.places > b.places)
  {
    return 1;
  }
  if (a.places < b.places)
  {
    return 2;
  }
  return 0;
}

int winner_area(card a, card b)
{
  if (a.area > b.area)
  {
    return 1;
  }
  if (a.area < b.area)
  {
    return 2;
  }
  return 0;
}

int winner_pib(card a, card b)
{
  if (a.pib > b.pib)
  {
    return 1;
  }
  if (a.pib < b.pib)
  {
    return 2;
  }
  return 0;
}

int winner_pop_density(card a, card b)
{
  if (a.pop_density > b.pop_density)
  {
    return 2;
  }
  if (a.pop_density < b.pop_density)
  {
    return 1;
  }
  return 0;
}

int winner_pib_pcap(card a, card b)
{
  if (a.pib_pcap > b.pib_pcap)
  {
    return 1;
  }
  if (a.pib_pcap < b.pib_pcap)
  {
    return 2;
  }
  return 0;
}

int winner_spower(card a, card b)
{
  if (a.spower > b.spower)
  {
    return 1;
  }
  if (a.spower < b.spower)
  {
    return 2;
  }
  return 0;
}

void title(char *text)
{
  printf("\n");
  printf("---------------------- %s ---------------------- \n", text);
}

void game_intro(void)
{
  // Game intro
  title("SUPER TRUNFO: COUNTRIES");
  printf("\n");
  printf("The first thing to do is to create your card, you can\n");
  printf("choose to fill it manually or generate with random informations.\n");
  printf("Your enemy will be the Computer, it'll have a random card.\n");
  printf("After that, choose which card's field you want to battle with.\n");
  printf("\n");
  printf("---------------------------------------------------------------------\n");
}

void menu(void)
{
  printf("Let's star creating your card. \n");
  printf("\n");
  printf("[1] Create card manually\n");
  printf("[2] Create a random card\n");
  printf("\n");
  printf("What do you prefer? ");
}

int menu_choice(void)
{
  int answer;
  scanf("%i", &answer);
  return answer;
}

void menu_fields(void)
{
  printf("Cards fields:\n");
  printf("[1] Population\n");
  printf("[2] Places to visit\n");
  printf("[3] Area\n");
  printf("[4] PIB\n");
  printf("[5] Pop. density\n");
  printf("[6] PIB per capita\n");
  printf("[7] Super power\n");
  printf("\n");
  printf("Which field you want to battle with? ");
}

void print_winner(int result)
{
  if (result == 0)
  {
    printf("TIE!\n");
  }
  if (result == 1)
  {
    printf("YOU WON!\n");
  }
  if (result == 2)
  {
    printf("COMPUTER WON!\n");
  }
}