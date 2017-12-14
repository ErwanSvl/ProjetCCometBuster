#ifndef SCORE_H
#define SCORE_H

#define NAME_LENGTH 5

typedef struct highscore
{
  char *name;
  int score;
} Highscore, *Highscore_ptr;

char *get_player_name(void);
Highscore_ptr new_highscore(char* name, int score);
void delete_highscore(Highscore_ptr highscore);
Highscore_ptr* load_highscores(FILE* f);
int get_nb_scores(FILE* f);

/* list_ptr list_new(void);//new_empty
list_ptr list_add(sprite_t v, list_ptr l);
list_ptr list_clone(list_ptr l);
void list_reverse(list_ptr * l);
list_ptr list_next(list_ptr l);

sprite_t list_head_sprite(list_ptr l);
sprite_t list_pop_sprite(list_ptr *l);

bool list_is_empty(list_ptr l);
int  list_length(list_ptr l);
void list_free(list_ptr l);
void list_remove(list_ptr elt, list_ptr *l);
 */

#endif /* SCORE_H */
