#include <stdio.h>
#include <stdlib.h>

#include "linkedlist.h"

/* Initialisation of the list
 * */
list_ptr list_new(void)
{
	return NULL;
}

/* Add a new cel to a list. 
 *  store the sprite_t to the new cel
 * */
list_ptr list_add(sprite_t sprite, list_ptr list)
{
	list_ptr new;
	new = malloc(sizeof(s_list_node_t));
	new->data = sprite;
	new->next = NULL;
	if (list == NULL)
	{
		return new;
	}
	else
	{
		new->next = list;
		return new;
	}
}

/* Return the length of a list
 * */
int list_length(list_ptr l)
{
	if (l == NULL)
		return 0;
	int total = 1;
	while (l->next != NULL)
	{
		total++;
	}
	return total;
}

/* Reverse the order of a list
 * */
void list_reverse(list_ptr *l)
{
	list_ptr inv = *l, tete;
	if (inv && inv->next)
	{
		tete = inv->next;
		list_reverse(&(inv->next));
		tete->next = inv;
		*l = inv->next;
		tete->next->next = NULL;
	}
}

/* Copy a list to another one. 
 *  Return the new list
 * */
list_ptr list_clone(list_ptr list)
{
	//A finir
	/*if (list == NULL) return NULL;
	list_ptr new;
	new = malloc(sizeof(s_list_node_t));
	new->data = list->data;
	list_ptr head = new;
	while(list->next != NULL) {
		list = list->next;
		list_ptr temp;
		temp = malloc(sizeof(s_list_node_t));
		temp->data = list->data;
		new->next = temp;
		new = new->next;
	}
	return head;*/
}

/* Return true if the list is empty
 * */
bool list_is_empty(list_ptr l)
{
	return l == NULL;
}

/* Search the first cel of the list & 
 *  return the associated sprite 
 * */
sprite_t list_head_sprite(list_ptr l)
{
	if (l == NULL)
		return NULL;
	return l->data;
}

/* Return the next cel in list or NULL
 * */
list_ptr list_next(list_ptr l)
{
	if (l == NULL)
		return NULL;
	return l->next;
	return NULL;
}

/* Search the last cel of a list 
 *  Remove the cel from the list
 *  Return the associated sprite
 * */
sprite_t list_pop_sprite(list_ptr *l)
{
	list_ptr current = *l;
	sprite_t temp;
	if (current == NULL)
	{
		return NULL;
	}
	if (current->next == NULL)
	{
		temp = current->data;
		free(*l);
		*l = NULL;
		return temp;
	}
	while (current->next->next != NULL)
	{
		current = current->next;
	}
	temp = current->next->data;
	free(current->next);
	current->next = NULL;
	return temp;
}

/* Remove the given cel in a list
 * */
void list_remove(list_ptr elt, list_ptr *l)
{
	list_ptr current = *l;

	if (elt == current)
	{
		*l = current->next;
		sprite_free(elt->data);
		free(elt);
	}
	else
	{
		while (current->next != elt)
		{
			current = current->next;
		}
		current->next = current->next->next;
		sprite_free(elt->data);
		free(elt);
	}
}

/* Wipe out a list. 
 *  Don't forget to sprite_free() for each sprite
 * */
void list_free(list_ptr l)
{
	list_ptr follower = l;
	while (l != NULL)
	{
		sprite_free(l->data);
		l = l->next;
		free(follower);
		follower = l;
	}
}
