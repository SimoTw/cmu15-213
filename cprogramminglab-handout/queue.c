/* 
 * Code for basic C skills diagnostic.
 * Developed for courses 15-213/18-213/15-513 by R. E. Bryant, 2017
 * Modified to store strings, 2018
 */

/*
 * This program implements a queue supporting both FIFO and LIFO
 * operations.
 *
 * It uses a singly-linked list to represent the set of queue elements
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "harness.h"
#include "queue.h"

/*
  Create empty queue.
  Return NULL if could not allocate space.
*/
queue_t *q_new()
{
    queue_t *q =  (queue_t *)malloc(sizeof(queue_t));
    /* What if malloc returned NULL? */
    if (q == NULL) return NULL;
    q->head = NULL;

    q->tail = NULL;
    q->length = 0;
    return q;
}

/* Free all storage used by queue */
void q_free(queue_t *q)
{
    /* How about freeing the list elements and the strings? */
    /* Free queue structure */
    list_ele_t *node, *prev;
    node = q->head;
    while (node != NULL) {
      free(node->value);
      prev = node;
      node = node->next;
      free(prev);
    }
    free(q);
}

/*
  Attempt to insert element at head of queue.
  Return true if successful.
  Return false if q is NULL or could not allocate space.
  Argument s points to the string to be stored.
  The function must explicitly allocate space and copy the string into it.
 */
bool q_insert_head(queue_t *q, char *s)
{
    /* What should you do if the q is NULL? */
    // create new q struct if it's null
    if (q == NULL) {
      return false;
    }
    list_ele_t *node;
    // alloc memory for new node
    node = (list_ele_t *)malloc(sizeof(list_ele_t));
    if (node == NULL) return false;
    /* Don't forget to allocate space for the string and copy it */
    /* What if either call to malloc returns NULL? */

    // alloce and copy string list
    node->value = (char *)malloc(strlen(s)+1);
    if (node->value == NULL) return false;
    strcpy(node->value, s);

    // insert the new node to the queue
    node->next = q->head;
    q->head = node;
    if (q->tail == NULL) q->tail = node;
  
    q->length += 1;
    return true;
}


/*
  Attempt to insert element at tail of queue.
  Return true if successful.
  Return false if q is NULL or could not allocate space.
  Argument s points to the string to be stored.
  The function must explicitly allocate space and copy the string into it.
 */
bool q_insert_tail(queue_t *q, char *s)
{
    /* You need to write the complete code for this function */
    /* Remember: It should operate in O(1) time */
    /* What should you do if the q is NULL? */
    // create new queue struct if it's null
    if (q == NULL) {
      return false;
    }
    // alloc new node
    list_ele_t *node;
    node = (list_ele_t *)malloc(sizeof(list_ele_t));
    if (node == NULL) {
      return false;
    }
    /* Don't forget to allocate space for the string and copy it */
    /* What if either call to malloc returns NULL? */

    // copy string
    node->value = (char *)malloc(strlen(s)+1);
    if (node->value == NULL) return false;
    strcpy(node->value, s);
    node->next = NULL;
    // insert node
    if (q->tail == NULL) {
      q->head = node;
      q->tail = node;
    } else {
      q->tail->next = node;
      q->tail = node;
    }
    q->length += 1;
    return true;
}

/*
  Attempt to remove element from head of queue.
  Return true if successful.
  Return false if queue is NULL or empty.
  If sp is non-NULL and an element is removed, copy the removed string to *sp
  (up to a maximum of bufsize-1 characters, plus a null terminator.)
  The space used by the list element and the string should be freed.
*/
bool q_remove_head(queue_t *q, char *sp, size_t bufsize)
{
    /* You need to fix up this code. */
    if (q->length == 0) {
      return false;
    } else if (q->length == 1) {
      list_ele_t *temp;
      temp = q->head;
      free(q->head->value);
      q->head = NULL;
      q->tail = NULL;
      free(temp);
      q->length = 0;
    } else {
      list_ele_t *temp;
      temp = q->head;
      free(q->head->value);
      q->head = q->head->next;
      free(temp);
    }
    return true;
}

/*
  Return number of elements in queue.
  Return 0 if q is NULL or empty
 */
int q_size(queue_t *q)
{
    /* You need to write the code for this function */
    /* Remember: It should operate in O(1) time */
    return q->length;
}

/*
  Reverse elements in queue
  No effect if q is NULL or empty
  This function should not allocate or free any list elements
  (e.g., by calling q_insert_head, q_insert_tail, or q_remove_head).
  It should rearrange the existing ones.
 */
void q_reverse(queue_t *q)
{
      // add a head to the new q

      // track the curr node
      // append curr node to the head of the queue
      // move to 

    list_ele_t *prev, *curr, *next;
    prev = NULL;
    next = NULL;
    curr = q->head;
    q->tail = q->head;
    while (curr != NULL) {
      next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }
    q->head = prev;
    /* You need to write the code for this function */
}

