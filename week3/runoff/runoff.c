// make it out of CS50 IDE conform!
// #include <cs50.h>
// number only accept number > use while...!!!
// follow the error messages
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    char name[20];
    int votes;
    bool eliminated;
}
candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, char name[]);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, char *argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        strcpy(candidates[i].name, argv[i + 1]);
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    // voter_count = get_int("Number of voters: ");
    printf("Number of voters: ");
    scanf("%d", &voter_count);

    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            // string name = get_string("Rank %i: ", j + 1);
            char name[20];
            printf("Rank %i: ", j + 1);
            scanf("%s", name);

            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// Record preference if vote is valid
// voter > passed i, rank > passed j
bool vote(int voter, int rank, char name[])
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i].name) == 0)
        {
            // name found > update the global preferences[i][j]
            preferences[voter][rank] = i;
            return true;
        }
    }
    return false;
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    // TODO
    for (int i = 0; i < voter_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if (candidates[preferences[i][j]].eliminated == false)
            {
                candidates[preferences[i][j]].votes += 1;
                // after the first match > stop
                // count only the top rated candidates in game!!!
                break;
            }
        }

    }
    return;
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        // winner > has min half of the votes
        if (candidates[i].votes > voter_count / 2)
        {
            printf("%s\n", candidates[i].name);
            return true;
        }
    }
    return false;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    // TODO
    // start the min_vote from the biggest possible value
    // than look for smaller
    // check only that candidates who is still in game!!!
    int min_vote = voter_count;
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].eliminated == false && candidates[i].votes < min_vote)
        {
            min_vote = candidates[i].votes;
        }
    }
    return min_vote;
}

// Return true if the election is tied between all candidates, false otherwise
// if each candidates[i].vote in game == min > true
bool is_tie(int min)
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        // if just 1 of the candidates is not equal to the min >
        // not all of them has the same votes...
        if (candidates[i].eliminated == false && candidates[i].votes != min)
        {
            return false;
        }
    }
    return true;
}

// Eliminate the candidate (or candidiates) in last place
// with min score
void eliminate(int min)
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        // candidates[i].eliminated == false && > not neccessary
        // only false can be switched to true...
        if (candidates[i].votes == min)
        {
            candidates[i].eliminated = true;
        }
    }
    return;
}