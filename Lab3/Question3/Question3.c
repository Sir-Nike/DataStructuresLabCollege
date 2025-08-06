#include <stdio.h>
typedef struct {
    char name[50];
    int roll_no;
    float marks;
} Student;
void readStudents(Student *s, int n) {
    for (int i = 0; i < n; i++) {
        printf("Name: "); scanf(" %[^\n]", s[i].name);
        printf("Roll No: "); scanf("%d", &s[i].roll_no);
        printf("Marks: "); scanf("%f", &s[i].marks);
    }
}
void displayStudents(Student *s, int n) {
    printf("\nStudents:\nName\tRoll No\tMarks\n");
    for (int i = 0; i < n; i++)
        printf("%s\t%d\t%.2f\n", s[i].name, s[i].roll_no, s[i].marks);
}
void topStudent(Student *s, int n) {
    Student *top = s;
    for (int i = 1; i < n; i++)
        if (s[i].marks > top->marks) top = &s[i];
    printf("\nTop student: %s (Roll No: %d) with marks %.2f\n", top->name, top->roll_no, top->marks);
}
int main() {
    int n; printf("Number of students: "); scanf("%d", &n);
    Student s[n];
    readStudents(s, n);
    displayStudents(s, n);
    topStudent(s, n);
    return 0;
}
