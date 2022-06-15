# include <stdio.h>
# include <stdbool.h>
# include <stdlib.h>

/**
 * Define node structure type linked list.
 */
struct Node {
	int value;
	struct Node * next;
};


/** @brief Searches primes uptil value of n via the Eratosthenes sieve method.
 *  @param n the max value wherein primes are searched.
 */
void eratosthenes(int n){
	int i;
	struct Node * temp;
    struct Node * start;
	struct Node * first_node = (struct Node *) malloc (sizeof(struct Node));
    struct Node * head = first_node;
	
	/* Construct linked list up to value n. */
    for (i = 2; i <= n; i++){
        head->value = i;
        if (i < n){
			head->next =  (struct Node *) malloc (sizeof(struct Node));
			head = head->next; 
        } else {
			head->next = NULL;
        }
    }
    
    /* Sift through linked list to find primes. */
    start = first_node;
    while (start->value * start->value < n){
        head = start;
        while (head->next != NULL){
			
			/* If multiple of starting point, drop node from linked list. */
            if ((head->next->value % start->value) == 0){ 
				temp = head->next->next; 
				free(head->next); 
				head->next = temp; 
            }
			
            if (head->next != NULL){
				head = head->next;
            } 
        }
		
		/* Reset start to next node in linked list. */
        start = start->next; 
    }
	
	/* Print resulting list and free memory */
	head  = first_node;
	while(head != NULL){
		temp = head;
		printf("%d ",head->value);
		head = head->next;
		free(temp);
	}		
}

/* Main */
int main(){
	eratosthenes(2000000);
	return 0;
}
