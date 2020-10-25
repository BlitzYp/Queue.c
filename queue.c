#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char *value;
    struct node_t *next;
} node_t;

typedef struct queue
{
    node_t *first;
    node_t *last;
    size_t length;
} queue_t;

void enqueue(queue_t *queue, char *value);
void dequeue(queue_t *queue);
char *peek(queue_t *queue);
queue_t createQueue();

int main(void)
{
    queue_t queue = createQueue();
    enqueue(&queue, "John");
    enqueue(&queue, "Bob");
    enqueue(&queue, "Bob2");
    dequeue(&queue);
    dequeue(&queue);
    char *res = peek(&queue);
    printf("%s\n", res);
    free(queue.last->value);
    free(queue.last);
}

queue_t createQueue()
{
    queue_t queue = {NULL, NULL, 0};
    return queue;
}

void enqueue(queue_t *queue, char *value)
{
    node_t *newNode = malloc(sizeof(node_t));
    newNode->value = malloc(strlen(value) + 1);
    strcpy(newNode->value, value);
    if (!queue->first)
    {
        queue->first = newNode;
        queue->last = queue->first;
        return;
    }
    queue->length++;
    queue->last->next = newNode;
    queue->last = newNode;
    return;
}

void dequeue(queue_t *queue)
{
    if (queue->length == 0)
    {
        free(queue->first->value);
        free(queue->first);
        return;
    }
    queue->length--;
    queue->first = queue->first->next;
    return;
}

char *peek(queue_t *queue)
{
    return queue->length >= 0 ? queue->first->value : (char *)-1;
}