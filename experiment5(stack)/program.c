#include<stdio.h>
#include<stdlib.h>
#define size 5

struct stack {
	int s[size];
	int top;
} st;

int stfull() {
	if(st.top>=size-1)
		return 1;
	else
		return 0;
}

int pop() {
	int item;
	item = st.s[st.top];
	st.top--;
	return(item);
}

void push(int item) {
	st.top++;
	st.s[st.top] = item;
}

int stempty() {
	if(st.top == -1)
		return 1;
	else
		return 0;
}

void displaystack() {
	int i;
	if(stempty())
		printf("\nThe stack is empty.");
	else
		for(i = st.top; i>=0; i--) {
			printf("\n%d", st.s[i]);
		}
}

int main() {
	int item, choice;
	char ans;

	st.top = -1;

	printf("----Implementation of stack----");

	do {
		printf("\nMain menu");
		printf("\n1.push\n2.pop\n3.display\n4.exit");
		printf("\nEnter your choice: ");
		scanf("%d", &choice);

		switch(choice) {
		case 1:
			printf("Enter the item to be pushed: ");
			scanf("%d", &item);
			if(stfull())
				printf("\nThe stack is full.");
			else
				push(item);
			break;

		case 2:
			if(stempty())
				printf("\nEmpty stack");
			else {
				item = pop();
				printf("\nThe popped element is %d", item);
			}
			break;

		case 3:
			displaystack();
			break;

		case 4:
			printf("\nExiting program...");
			break;

		default:
			printf("\nInvalid choice!");
		}

		printf("\nDo you want to continue? (Y/N): ");
		scanf(" %c", &ans);

	}
	while(ans=='Y'||ans=='y');

	return 0;
}
