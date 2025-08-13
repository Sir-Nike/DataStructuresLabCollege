#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node *next;
}   node;

void create_linked_list(node **head);
void insert_element_before(node **head, int val1, int val2);
void insert_element_after(node **head, int val1, int val2);
void delete_element(node **head, int val);
void print_linked_list(node **head);
void reverse_linked_list(node **head);
void selection_sort_linked_list(node **head);
void delete_alternate_node(node **head);
void sorted_list_insert(node **head, int val);


int main() {
    node *head = NULL;
    int choice, val1, val2;

    while (1) {
        printf("\n--- Linked List Menu ---\n");
        printf("1. Create Linked List\n");
        printf("2. Insert Element Before\n");
        printf("3. Insert Element After\n");
        printf("4. Delete Element\n");
        printf("5. Print List\n");
        printf("6. Reverse List\n");
        printf("7. Sort List (Selection Sort)\n");
        printf("8. Delete Alternate Nodes\n");
        printf("9. Insert Element in Sorted List\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input!\n");
            while(getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1:
                create_linked_list(&head);
                break;

            case 2:
                printf("Enter new value to insert: ");
                scanf("%d", &val1);
                printf("Enter value before which to insert: ");
                scanf("%d", &val2);
                insert_element_before(&head, val1, val2);
                break;

            case 3:
                printf("Enter new value to insert: ");
                scanf("%d", &val1);
                printf("Enter value after which to insert: ");
                scanf("%d", &val2);
                insert_element_after(&head, val1, val2);
                break;

            case 4:
                printf("Enter value to delete: ");
                scanf("%d", &val1);
                delete_element_in_linked_list(&head, val1);
                break;

            case 5:
                print_linked_list(&head);
                break;

            case 6:
                reverse_linked_list(&head);
                printf("List reversed.\n");
                break;

            case 7:
                selection_sort_linked_list(&head);
                printf("List sorted.\n");
                break;

            case 8:
                delete_alternate_node(&head);
                printf("Alternate nodes deleted.\n");
                break;

            case 9:
                printf("Enter value to insert into sorted list: ");
                scanf("%d", &val1);
                sorted_list_insert(&head, val1);
                break;

            case 0:
                printf("Exiting program.\n");
                // Free the list before exiting
                while (head != NULL) {
                    node *temp = head;
                    head = head->next;
                    free(temp);
                }
                return 0;

            default:
                printf("Invalid choice, try again.\n");
        }
    }
    return 0;
}

void create_linked_list(node **head)
{
    int length;
    printf("Enter Length of List: ");
    scanf("%d",&length);

    for (int i = 0; i < length; i++)
    {
        node *n = malloc(sizeof(node));
        printf("Enter Value at %d node: ",i+1);
        scanf("%d",&(n->value));
        n->next = NULL;

        if (*head == NULL)*head = n;

        else
        {
            for (node *ptr = *head; ptr != NULL; ptr = ptr->next)
            {
                if (ptr->next == NULL)
                {
                    ptr->next = n;
                    break;
                }
            }
        }
    }
}

void insert_element_before(node **head, int val1, int val2)
{
    node *inserted_node = malloc(sizeof(node));
    if (inserted_node == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }
    if (*head == NULL) return;
    inserted_node->value = val1;
    if((*head)->value == val2)
    {
        inserted_node->next = (*head);
        (*head) = inserted_node;
        return;
    }
    for(node *ptr = *head; ptr != NULL ; ptr=ptr->next)
    {

        if (ptr->next != NULL && ptr->next->value == val2)
        {
            inserted_node->next = ptr->next;
            ptr->next = inserted_node;
            return;
        }
    }
    printf("There is no %d in Linked List\n", val2);
}

void insert_element_after(node **head, int val1, int val2)
{
    node *inserted_node = malloc(sizeof(node));
    if (inserted_node == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }

    inserted_node->value = val1;
    inserted_node->next = NULL;


    for(node *ptr = *head; ptr != NULL ; ptr=ptr->next)
    {
        if (ptr->value == val2)
        {
            inserted_node->next = ptr->next;
            ptr->next = inserted_node;
            return;
        }
    }
    printf("There is no %d in Linked List\n", val2);
    free(inserted_node);
}

void delete_element_in_linked_list(node **head, int val)
{
    node *list = *head;
    if (list == NULL)
    {
        printf("Linked List is Empty\n");
        return;
    }

    if (list->value == val)
    {
            node *temp = list;
            *head = list->next;
            free(temp);
            return;
    }

    for(node *ptr = list; ptr->next != NULL; ptr = ptr->next)
    {
        if (ptr->next->value == val)
        {
            node *temp = ptr->next;
            ptr->next = ptr->next->next;
            free(temp);
            return;
        }
    }
    printf("%d not in Linked List\n", val);
}

void print_linked_list(node **head)
{
    node *list = *head;
    for(node *ptr = list; ptr != NULL; ptr = ptr->next)
    {
        if (ptr->next == NULL)
        {
            printf("%d",ptr->value);
            break;
        }

        printf("%d -> ",ptr->value);
    }
    printf("\n");
}

void reverse_linked_list(node **head)
{
    node *prev = NULL;
    node *next = NULL;

    node *ptr = *head;
    while(ptr!= NULL){

        next = ptr->next;
        ptr->next = prev;
        prev = ptr;
        ptr = next;
    }

    *head = prev;
}

void selection_sort_linked_list(node **head)
{
    if (*head == NULL)
    {
        printf("Linked List is Empty.\n");
        return;
    }

    if ((*head)->next == NULL)
    {
        printf("Only one Element in Linked List\n");
        return;
    }

    for(node *ptr1 = *head; ptr1->next !=NULL; ptr1 = ptr1->next)
    {
        node *min = ptr1;

        for(node *ptr2 = ptr1->next; ptr2 != NULL; ptr2 = ptr2->next)
        {
            if(min->value > ptr2->value)
            {
                min = ptr2;
            }
        }

        int temp = ptr1->value;
        ptr1->value = min->value;
        min->value = temp;
    }
}

void delete_alternate_node(node **head) {
    if (*head == NULL || (*head)->next == NULL) return;

    node *ptr = *head;

    while (ptr != NULL && ptr->next != NULL) {
        node *temp = ptr->next;
        ptr->next = ptr->next->next;
        free(temp);

        ptr = ptr->next;
    }
}

void sorted_list_insert(node **head, int val) {
    node *insert = malloc(sizeof(node));
    if (insert == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    insert->value = val;
    insert->next = NULL;

    if (*head == NULL || (*head)->value >= val) {
        insert->next = *head;
        *head = insert;
        return;
    }

    node *ptr = *head;
    while (ptr->next != NULL && ptr->next->value < val) {
        ptr = ptr->next;
    }

    insert->next = ptr->next;
    ptr->next = insert;
}
