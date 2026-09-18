#include <stdio.h>
#include <stdlib.h>

int main()
{
    int bedOccupancy[4][20] = {0};
    char patientName[50];
    int age;
    int triageLevel;
    int specialty;
    int wardAdmission;
    int wardID;


    printf("Smart Hospital & Resource Allocation System\n");
     printf("\nDoctor Specialties:\n");
    printf("1. General Practice - Rs.1500 - 15 min - Daily Cap: 30\n");
    printf("2. Paediatrics      - Rs.2500 - 20 min - Daily Cap: 20\n");
    printf("3. Cardiology       - Rs.4500 - 30 min - Daily Cap: 12\n");
    printf("4. Neurology        - Rs.5000 - 30 min - Daily Cap: 10\n");

    printf("\nHospital Wards:\n");

    printf("1] General Ward    - Rs.3000/day    - Capacity: 20\n");
    printf("2] Paediatric Ward - Rs.6000/day    - Capacity: 10\n");
    printf("3] Surgical Ward   - Rs.12000/day   - Capacity: 10\n");
    printf("4] ICU             - Rs.25000/day   - Capacity: 5\n");

    printf("\nPlease Enter patient Name: ");
    scanf(" %s", &patientName);

    printf("\nEnter age: ");
    scanf("%d", &age);

    printf("\nPlease Enter the triage level (1-Normal, 2-Urgent, 3-Critical): ");
    scanf("%d", &triageLevel);

    printf("1. General Practice\n");
    printf("2. Paediatrics\n");
    printf("3. Cardiology\n");
    printf("4. Neurology\n");
    printf("\nEnter the specialty(1,2,3,4):");

    scanf("%d", &specialty);

    printf("\nWhat Do you want ward admission? (1-Yes, 0-No): ");
    scanf("%d", &wardAdmission);
    if (wardAdmission == 1)
    {
    printf("\nSelect ward:\n");
    printf("1. General Ward\n");
    printf("2. Paediatric Ward\n");
    printf("3. Surgical Ward\n");
    printf("4. ICU\n");

    printf("Enter ward ID: ");
    scanf("%d", &wardID);
    }


    return 0;
}
