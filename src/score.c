#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "score.h"

//get the name of the player
char *get_player_name_terminal(void)
{
    char *name;
    name = malloc(NAME_LENGTH * 6);
    printf("\nEnter your name (5 characters max): ");
    fgets(name, NAME_LENGTH + 1, stdin);
    int empty = 1;
    for (int i = strlen(name) - 1; i >= 0; i--)
    {
        //if no name or blank name
        if (i == 0 && empty && (name[i] == ' ' || name[i] == '\n'))
            name = "GUEST";

        //test if blank character
        if ((name[i] != ' ') && name[i] != '\n')
        {
            empty = 0;
        }

        //if blank in the end or end of line
        if ((name[i] == ' ' && empty == 1) || (name[i] == '\n'))
        {
            name[i] = '\0';
        }


        //if blank in the name
        if (name[i] == ' ')
        {
            name[i] = '_';
        }
    }
    return name;
}

//Create a struct for the highscore
Highscore_ptr new_highscore(char *name, int score)
{
    Highscore_ptr new_highscore;
    new_highscore = malloc(sizeof(Highscore));
    new_highscore->name = malloc(sizeof(char) * NAME_LENGTH + 1);
    strcpy(new_highscore->name, name);
    new_highscore->score = score;
    return new_highscore;
}

//free the memory
void delete_highscore(Highscore_ptr highscore)
{
    free(highscore->name);
    free(highscore);
    highscore = NULL;
}

//return the nb of scores in the file to have the array size
int get_nb_scores(FILE *f)
{
    rewind(f);
    int i = 0;
    char current_name[20];
    int current_score = 0;
    while (fscanf(f, "%s %d", current_name, &current_score) > 0)
    {
        i++;
    }
    return i < NB_SCORES ? i : NB_SCORES;
}

//get the highscores store in the file f
Highscore_ptr *load_highscores(FILE *f)
{
    rewind(f);
    char current_name[20];
    int current_score = 0;
    Highscore_ptr *all_scores = malloc(sizeof(Highscore_ptr) * NB_SCORES);

    int i = 0;
    while (fscanf(f, "%s %d", current_name, &current_score) > 0)
    {
        Highscore_ptr current_highscore = new_highscore(current_name, current_score);
        all_scores[i] = current_highscore;
        i++;
    }
    return all_scores;
}

//add the player score in the good place. Return the place of the player, -1 if not a highscore
int add_player_score(Highscore_ptr *scores, int nb_scores, char *player_name, int player_score)
{
    int player_rank = -1;
    Highscore_ptr candidate_highscore = new_highscore(player_name, player_score);
    //file empty
    if (nb_scores == 0)
    {
        scores[0] = candidate_highscore;
        //bypassing solution, get_nb_score return 1 if the file is empty instead of 0
        return 0;
    }
    for (int i = 0; i < nb_scores; i++)
    {
        //insert here
        if (candidate_highscore->score >= scores[i]->score)
        {
            Highscore_ptr temp_highscore;
            temp_highscore = scores[i];
            scores[i] = candidate_highscore;
            candidate_highscore = temp_highscore;
            temp_highscore = NULL;

            if (player_rank == -1)
                player_rank = i + 1;
        }
        //insert in last
        if (i == nb_scores - 1 && i + 1 < NB_SCORES)
        {
            scores[i + 1] = candidate_highscore;
            if (player_rank == -1)
                player_rank = i + 2;
        }
    }
    return player_rank;
}

//save all the highscores array in the file
void save_highscores(FILE *f, Highscore_ptr *scores, int nb_scores)
{
    rewind(f);
    for (int i = 0; i < nb_scores; i++)
    {
        fprintf(f, "%s %d\n", scores[i]->name, scores[i]->score);
    }
}