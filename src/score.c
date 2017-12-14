#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "score.h"

//get the name of the player
char *get_player_name(void)
{
    char *name;
    name = malloc(NAME_LENGTH * 6);
    printf("Enter your name (5 characters max): ");
    fgets(name, NAME_LENGTH + 1, stdin);
    name[strlen(name)] = '\0';
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

/* //open highscore file
FILE *f;
if ((f = fopen("scores.txt", "r+")) == NULL)
    printf("High score file unreachable, sorry.\n");
else
{
    //get the name for highscore
    char name[20] = "";
    printf("Enter your name : ");
    fgets(name, sizeof(name), stdin);

    char score_line[15];
    name[strlen(name) - 1] = '\0';
    sprintf(score_line, "%s:%d", name, score);

    //load the score file
    char scores[10][30];
    int nb_scores = 0;
    for (int i = 0; i < 10; i++)
    {
        if (fgets(scores[i], sizeof(scores[0]), f))
        {
            scores[i][strlen(scores[i]) - 1] = '\0';
            nb_scores++;
        }
        else
        {
            scores[i][0] = '\0';
        }
    }
    //insert score in the table if in the 10th better score
    char temp[30];
    char *token = "";
    int current_score = 0;
    int temp_score = score;
    char temp_line[15];

    if (nb_scores < 10)
    {
        nb_scores++;
    }
    for (int i = 0; i < nb_scores; i++)
    {
        if (i == nb_scores - 1)
        {
            strcpy(scores[i + 1], score_line);
            break;
        }
        strcpy(temp, scores[i]);
        token = strtok(temp, ":");
        current_score = atoi(strtok(NULL, ":"));
        if (temp_score > current_score)
        {
            if (i < 9)
            {
                strcpy(temp_line, scores[i]);
                strcpy(scores[i], score_line);
                strcpy(score_line, temp_line);
                temp_score = current_score;
            }
            strcpy(scores[i], score_line);
        }
    }

    for (int i = 0; i < 4; i++)
    {
        printf("Ligne %d : %s\n", i, scores[i]);
    }

    //free the buffers
    fclose(f); */