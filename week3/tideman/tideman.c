// #include <cs50.h>
// make it out of CS50 conform!!!

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
  int winner;
  int loser;
} pair;

// Array of candidates
char *candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, char name[], int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);
bool is_cycle(int n, int m);

int main(int argc, char *argv[])
{
  // Check for invalid usage
  if (argc < 2)
  {
    printf("Usage: tideman [candidate ...]\n");
    return 1;
  }

  // Populate array of candidates
  candidate_count = argc - 1;
  if (candidate_count > MAX)
  {
    printf("Maximum number of candidates is %i\n", MAX);
    return 2;
  }
  for (int i = 0; i < candidate_count; i++)
  {
    candidates[i] = argv[i + 1];
  }

  // Clear graph of locked in pairs
  for (int i = 0; i < candidate_count; i++)
  {
    for (int j = 0; j < candidate_count; j++)
    {
      locked[i][j] = false;
    }
  }

  pair_count = 0;
  // int voter_count = get_int("Number of voters: ");
  int voter_count;
  printf("Number of voters: ");
  scanf("%d", &voter_count);

  // Query for votes
  for (int i = 0; i < voter_count; i++)
  {
    // ranks[i] is voter's ith preference
    int ranks[candidate_count];

    // Query for each rank
    for (int j = 0; j < candidate_count; j++)
    {
      // string name = get_string("Rank %i: ", j + 1);
      char name[20];
      printf("Rank %i: ", j + 1);
      scanf("%s", name);

      if (!vote(j, name, ranks))
      {
        printf("Invalid vote.\n");
        return 3;
      }
    }

    record_preferences(ranks);

    printf("\n");
  }

  add_pairs();
  sort_pairs();
  lock_pairs();
  print_winner();
  return 0;
}

// Update ranks given a new vote
bool vote(int rank, char name[], int ranks[])
{
  // TODO
  for (int i = 0; i < candidate_count; i++)
  {
    if (strcmp(name, candidates[i]) == 0)
    {
      ranks[rank] = i;
      return true;
    }
  }
  return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
  // TODO
  for (int i = 0; i < candidate_count; i++)
  {
    for (int j = i + 1; j < candidate_count; j++)
    {
      preferences[ranks[i]][ranks[j]]++;
    }
  }
  return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
  // TODO > fill up pairs[]
  // set pair_count to 0 to have it as the first index of
  // the pairs[]
  pair_count = 0;
  for (int i = 0; i < candidate_count; i++)
  {
    for (int j = i + 1; j < candidate_count; j++)
    {
      if (preferences[i][j] > preferences[j][i])
      {
        pairs[pair_count].winner = i;
        pairs[pair_count].loser = j;
        pair_count++;
      }
      else if (preferences[i][j] < preferences[j][i])
      {
        pairs[pair_count].winner = j;
        pairs[pair_count].loser = i;
        pair_count++;
      }
    }
  }
  return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
  // TODO
  for (int i = 0; i < pair_count; i++)
  {
    for (int j = i + 1; j < pair_count; j++)
    {
      if (preferences[pairs[i].winner][pairs[i].loser] < preferences[pairs[j].winner][pairs[j].loser])
      {
        pair smaller_pair = pairs[i];
        pairs[i] = pairs[j];
        pairs[j] = smaller_pair;
      }
    }
  }
  return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
  // TODO
  // // non- recursive
  // // Before locking pair, search for a loser to be a winner in some locked node >
  // // if there is some - skip it.
  // // set first locked pair
  // if (pair_count > 0)
  // {
  //   locked[pairs[0].winner][pairs[0].loser] = true;
  // }

  // for (int i = 1; i < pair_count; i++)
  // {
  //   bool cycle = false;
  //   for (int j = 0; j < pair_count; j++)
  //   {
  //     if (locked[pairs[i].loser][j])
  //     {
  //       cycle = true;
  //       break;
  //     }
  //   }

  //   // check if adding this node will create a cycle
  //   if (!cycle)
  //   {
  //     locked[pairs[i].winner][pairs[i].loser] = true;
  //   }
  // }

  for (int i = 0; i < pair_count; i++)
  {
    if (!is_cycle(pairs[i].winner, pairs[i].loser))
    {
      locked[pairs[i].winner][pairs[i].loser] = true;
    }
  }
  return;
}

// Print the winner of the election
void print_winner(void)
{
  // TODO
  for (int i = 0; i < candidate_count; i++)
  {
    bool source = true;

    for (int j = 0; j < candidate_count; j++)
    {
      if (locked[j][i] == true)
      {
        source = false;
        break;
      }
    }

    if (source == true)
    {
      printf("%s\n", candidates[i]);
    }
  }
  return;
}

// additional function > checking for cycle
// think about recursion!!!
bool is_cycle(int n, int m)
{
  if (locked[m][n] == true)
  {
    return true;
  }

  for (int i = 0; i < candidate_count; i++)
  {
    if (locked[i][n] == true)
    {
      return is_cycle(i, m) ? true : false;
    }
  }
  return false;
}
