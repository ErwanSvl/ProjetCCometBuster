#ifndef SCORE_H
#define SCORE_H

#define NAME_LENGTH 5
#define NB_SCORES 10

typedef struct highscore
{
  char *name;
  int score;
} Highscore, *Highscore_ptr;

char *get_player_name(void);
Highscore_ptr new_highscore(char *name, int score);
void delete_highscore(Highscore_ptr highscore);
Highscore_ptr *load_highscores(FILE *f);
int get_nb_scores(FILE *f);
int add_player_score(Highscore_ptr *scores, int nb_scores, char *player_name, int player_score);

#endif /* SCORE_H */
