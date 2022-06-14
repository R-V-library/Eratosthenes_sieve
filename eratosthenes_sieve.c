# include <stdio.h>
# include <stdbool.h>
# include <stdlib.h>

// define struct linked list
struct Node {
	int value;
	struct Node * next;
};


// Actual sift of erastothenes
// n = stop point
void erastothenes(int n){
	
	// Make linked list
	struct Node * first_node = (struct Node *) malloc (sizeof(struct Node));
    struct Node * head = first_node;
	int i;
    for (i = 2; i <= n; i++){
        head->value = i;
        if (i < n){
          head->next =  (struct Node *) malloc (sizeof(struct Node));
          head = head->next; 
        } else {
          head->next = NULL;
        }
    }
	
	
	
	// actual sieve
	struct Node * temp;
    struct Node * start;
    
    // actual sieve
    start = first_node;
    while (start->value * start->value < n){
        
        head = start;
        while (head->next != NULL){
            if ((head->next->value % start->value) == 0){
                temp = head->next->next; // node after next node
                free(head->next); // free next node
                head->next = temp; // node after deleted node is next node
            }
            if (head->next != NULL){
              head = head->next;
            } 
        }
        start = start->next; // reset head to next node 
    }
	
	
		// print resulting list + free memory
		head  = first_node;
		while(head != NULL){
			temp = head;
			printf("%d ",head->value);
			head = head->next;
			free(temp);
		}		
}


int main(){
	erastothenes(2000000);
	return 0;
}
