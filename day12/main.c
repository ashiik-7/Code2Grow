#include <stdio.h>
int main()
{
    int num_students, i, choice;
    float m1, m2, m3, total, avg;
    float class_total = 0, class_avg, highest = 0, lowest = 100;
    int passed = 0, failed = 0, record = 0;

    printf("Smart Student Result Management System\n");
    printf("Enter number of students: ");
    scanf("%d", &num_students);

    i = 1;
    while (i <= num_students) {
        printf("\n--- Student %d ---\n", i);
        printf("Enter marks for Subject 1: ");
        scanf("%f", &m1);
        printf("Enter marks for Subject 2: ");
        scanf("%f", &m2);
        printf("Enter marks for Subject 3: ");
        scanf("%f", &m3);

        total = m1 + m2 + m3;
        avg = total / 3;

        class_total += avg;
        if (avg > highest){
            highest = avg;
        }if (avg < lowest){
            lowest = avg;
        }if (avg >= 50){
            passed++;
        }else{
            failed++;
        }

        FILE *fp = fopen("results.txt", i == 1 ? "w" : "a");
        fprintf(fp, "%d %.2f\n", i, avg);
        fclose(fp);

        i++;
        record = 1;
    }

    class_avg = class_total / num_students;

    do {
        printf("\n========= Menu =========\n");
        printf("1. View All Results\n");
        printf("2. View Class Summary\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1 && record == 1) {
            printf("\n--- Result Sheet ---\n");
            FILE *fp = fopen("results.txt", "r");
            int sid;
            float a;
            while (fscanf(fp, "%d %f", &sid, &a) != EOF) {
                printf("Student %d: Avg = %.1f → ", sid, a);
                if (a >= 90)
                    printf("Grade A+\n");
                else if (a >= 80)
                    printf("Grade A\n");
                else if (a >= 70)
                    printf("Grade B\n");
                else if (a >= 60)
                    printf("Grade C\n");
                else if (a >= 50)
                    printf("Grade D\n");
                else
                    printf("Fail\n");
            }
            fclose(fp);
        }
        else if (choice == 2 && record == 1) {
            printf("\n--- Class Summary ---\n");
            printf("Total Students: %d\n", num_students);
            printf("Passed: %d\n", passed);
            printf("Failed: %d\n", failed);
            printf("Class Average: %.1f\n", class_avg);
            printf("Highest Average: %.1f\n", highest);
            printf("Lowest Average: %.1f\n", lowest);

        }else if (choice == 3) {
            printf("Thank you! Exiting system...\n");

        }else {
            printf("Invalid choice! Try again.\n");
        }
    }while (choice != 3);

    return 0;
}
