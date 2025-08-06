#include <stdio.h>
typedef struct {
    char name[100];
    int roll_no;
    char grade;
} Student;
void readStudents(Student s[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Name: ");
        scanf(" %[^\n]", s[i].name);
        printf("Roll No: ");
        scanf("%d", &s[i].roll_no);
        printf("Grade: ");
        scanf(" %c", &s[i].grade);
    }
}
void displayStudents(Student s[], int n) {
    printf("\nName, Roll No, Grade\n");
    for (int i = 0; i < n; i++)
        printf("%s , %d,  %c\n", s[i].name, s[i].roll_no, s[i].grade);
}
void insertionSort(Student s[], int n) {
    for (int i = 1; i < n; i++) {
        Student key = s[i];
        int j = i - 1;
        while (j >= 0 && s[j].roll_no > key.roll_no) {
            s[j + 1] = s[j];
            j--;
        }
        s[j + 1] = key;
    }
}
int main() {
    int n; Student s[100];
    printf("Number of students: ");
    scanf("%d", &n);
    if (n <= 0 || n > 100) return 1;
    readStudents(s, n);
    displayStudents(s, n);
    insertionSort(s, n);
    displayStudents(s, n);
}
