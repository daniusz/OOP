#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


struct node
{
	int data;
	struct node * next;
	struct node * last;

};

struct nodeDouble
{
	int data;
	struct nodeDouble * next;
	struct nodeDouble * prev;

};

void insertFront(struct nodeDouble **head, int data)
{
	struct nodeDouble *newNode = (struct nodeDouble *) malloc(sizeof(struct nodeDouble));;

	newNode->data = data;
	newNode->next = (*head);
	newNode->prev = NULL;

	if ((*head) != NULL)

		(*head)->prev = newNode;

	(*head) = newNode;

}

void insertAfter(struct nodeDouble *prev_node, int data)
{
	if (prev_node == NULL)
	{
		return;
	}

	struct nodeDouble *newNode = (struct nodeDouble *) malloc(sizeof(struct nodeDouble));;

	newNode->data = data;
	newNode->next = prev_node->next;
	prev_node->next = newNode;
	newNode->prev = prev_node;

	if (newNode->next != NULL)
		newNode->next->prev = newNode;
}

void insertEnd(struct nodeDouble **head, int data)
{
	struct nodeDouble *newNode = (struct nodeDouble *) malloc(sizeof(struct nodeDouble));;

	newNode->data = data;
	newNode->next = NULL;

	struct nodeDouble *temp = *head;

	if (*head == NULL)
	{
		newNode->prev = NULL;
		*head = newNode;

		return;
	}

	while (temp->next != NULL)

    temp = temp->next;

	temp->next = newNode;

	newNode->prev = temp;

}

void append(struct node **head, int data)
{
	if ((*head) == NULL)
	{
		(*head) = (struct node *) malloc(sizeof(struct node));

		(*head)->data = data;
	}
	else
	{
		struct node *add = (struct node *) malloc(sizeof(struct node));

		add->data = data;

		struct node *tail = *head;

		while (tail->next != NULL)
		{
			tail = tail->next;
		}

		tail->next = add;

		add->last = tail;

		add->next = NULL;
	}
}

void prepend(struct node **head, int data)
{
	if (head == NULL)
	{
		(*head) = (struct node *) malloc(sizeof(struct node));

		(*head)->data = data;
	}
	else
	{
		struct node *add = (struct node *) malloc(sizeof(struct node));

		add->data = data;

		add->next = (*head);

		(*head)->last = add;

		(*head) = add;
	}
}

void reverse(struct node **head)
{
	if (head == NULL)
	{
		printf("Add elements for reverse :)) ");
	}
	else
	{
		struct node *tail = *head;

		while (tail->next != NULL)
		{
			tail = tail->next;
		}

		struct node *temp = tail;

		struct node * trans;

		while (temp != NULL)
		{
			trans = temp->last;

			temp->last = temp->next;

			temp->next = trans;

			temp = temp->next;
		}

		(*head) = tail;
	}
}

// get the size of the head

int getSize(struct node *node)
{
	int size = 0;

	while (node != NULL)
	{
		node = node->next;

		size++;
	}

	return size;

}

//function to insert after nth node

void add_value_to_index(struct node **head, int pos, int data)

{
	int size = getSize(*head);

	struct node *add = (struct node *) malloc(sizeof(struct node));

	add->data = data;

	add->next = NULL;

	if (pos < 0 || pos > size)

		printf("Incorrect value. Enter an existing value \n");

	else if (pos == 0)
	{
		add->next = *head;

		*head = add;
	}
	else
	{
		// backwards traversal

		struct node *temp = *head;

		while (--pos)

			temp = temp->next;

		add->next = temp->next;

		temp->next = add;
	}
}

void remove_value(struct node **head, int pos)

{
	if (pos <= 0)
	{
		printf("Enter an existing value :)) ");
	}

	struct node *temp = (*head);

	int value = 1;

	while (temp != NULL)
	{
		if (value == pos)
		{
			struct node *remove = temp;

			if (temp->last != NULL)
			{
				temp->last->next = temp->next;
			}

			if (temp->next != NULL)
			{
				temp->next->last = temp->last;
			}

			if (value == 1 && temp->next == NULL)
			{ 	*head = NULL;
			}

			free(remove);

			break;
		}
		else
		{
			value++;

			temp = temp->next;
		}
	}

	if (value < pos)
	{
		printf("Elements don't exist :))");
	}
}

void sortedInsert(struct node **head, struct node *newNode)

{
	struct node dummy;

	struct node *current = &dummy;

	dummy.next = *head;

	while (current->next != NULL && current->next->data < newNode->data)
	{
		current = current->next;
	}

	newNode->next = current->next;

	current->next = newNode;

	*head = dummy.next;

}

void insertSort(struct node **head)

{
	struct node *result = NULL;

	struct node *current = *head;

	struct node * next;

	while (current != NULL)
	{
		next = current->next;

		sortedInsert(&result, current);

		current = next;
	}

	(*head) = result;

}

bool search_for_value(struct node *head, int value)

{
	struct node *temp = head;

	while (temp != NULL)
	{
		if (temp->data == value)

			return true;

		temp = temp->next;
	}

	return false;

}

void combineTwoLists(struct node **head, struct node **head2)
{
	struct node *val = *head2;

	while (val != NULL)
	{
		append(head, val->data);

		val = val->next;
	}
}

void backwards_traversal(struct nodeDouble **head)
{
	struct nodeDouble *tail = *head;

	while (tail->next != NULL)

		tail = tail->next;

	struct nodeDouble *temp = tail;

	while (temp != NULL)
	{
		printf("%d ", temp->data);

		temp = temp->prev;
	}

	printf("\n");

}

void show_ls(struct node *head)
{
	struct node *temp = head;

	while (temp != NULL)
	{
		printf("%d ", temp->data);

		temp = temp->next;
	}

	printf("\n");

}

int main()
{
	int number = 1;

	int element;

	int index;

	struct node *head = NULL;

	struct node *head2 = NULL;

	int len;

	// double linked lists

	/*Initialize nodes */

	struct nodeDouble * heado;

	/*Assign data values */

	while (number != 20)
	{
		printf("- 1 Append \n");

		printf("- 2 Prepend \n");

		printf("- 3 Reverse \n");

		printf("- 4 Add a value to the specific index \n");

		printf("- 5 Remove a value from index \n");

		printf("- 6 Sort the linked list \n");

		printf("- 7 Search for a value \n");

		printf("- 8 Add elements for second list to combine the lists : \n");

		printf("- 9 Join two linked lists \n");

		printf("- 10 Backwards traversal \n");

		printf("- 11 Load the data structure \n");

		printf("- 12 Insert at the beginning \n");

		printf("- 13 Insert at the middle \n");

		printf("- 14 Insert at the end \n");

		printf("- 15 Save data in the file \n");

		printf("\n");

		printf("Enter a number to execute a command : ");

		scanf("%d", &number);

		switch (number)
		{
			case 1:

				printf("\n Append element :");

				scanf("%d", &element);

				printf("\n");

				append(&head, element);

				printf("The list is : ");

				show_ls(head);

				printf("\n");

				break;

			case 2:

				printf("\n Prepend element :");

				scanf("%d", &element);

				printf("\n");

				prepend(&head, element);

				printf("The list is : ");

				show_ls(head);

				printf("\n");

				break;

			case 3:

				printf("\n Reverse the list :");

				printf("\n");

				reverse(&head);

				printf("The reversed list is : ");

				show_ls(head);

				printf("\n");

				break;

			case 4:

				printf("\n Add value : ");

				scanf("%d", &element);

				printf("\n");

				printf("\n Add index : ");

				scanf("%d", &index);

				printf("\n");

				add_value_to_index(&head, index, element);

				printf("The list is : ");

				show_ls(head);

				printf("\n");

				break;

			case 5:

				printf("\n Enter index of the number to remove :");

				scanf("%d", &element);

				remove_value(&head, element);

				show_ls(head);

				printf("\n");

				break;

			case 6:

				printf("\n Sort the linked list :");

				insertSort(&head);

				show_ls(head);

				printf("\n");

				break;

			case 7:

				printf("\n Enter value for search :");

				scanf("%d", &element);

				printf("\n");

				printf("\n");

				search_for_value(head, element) ? printf("Exist \n") : printf("Don't exist ! \n");

				printf("\n");

				break;

			case 8:

				printf("\n Add element for second list :");

				scanf("%d", &element);

				printf("\n");

				append(&head2, element);

				printf("The list is : ");

				show_ls(head2);

				printf("\n");

				break;

			case 9:

				printf("The combined lists : ");

				combineTwoLists(&head, &head2);

				show_ls(head);

				printf("\n");

				break;

			case 10:

				printf("Backwards traversal: ");

				backwards_traversal(&heado);

				printf("\n");

				break;

			case 11:

				FILE * fp;

				fp = fopen("file.txt", "r");

				int f = 0;

				while (!feof(fp))
				{
					fscanf(fp, "%d ", &element);

					append(&head, element);
				}

				fclose(fp);

				printf("The list is : ");

				show_ls(head);

				printf("\n");

				break;
			case 12:
				printf("\n Append element :");
				scanf("%d", &element);
				insertFront(&heado, element);
				break;

			case 13:
				printf("\n Append element :");
				scanf("%d", &element);
				insertAfter(heado, element);
				break;

			case 14:
				printf("\n Append element :");
				scanf("%d", &element);
				insertEnd(&heado, element);
				break;

			case 15:

				fp = fopen("file.txt", "w");

				struct node *ptr = head;

				while (ptr != NULL)
				{
					fprintf(fp, "%d ", ptr->data);

					ptr = ptr->next;
				}

				fclose(fp);

				break;

			default:

				printf("Error 404!");

				printf("\n");
		}
	}

	return 0;

}
