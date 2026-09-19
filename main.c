#include <stdio.h>
#include <stdlib.h>
#define MAX_PATIENTS 100

int main()
{
    int bedOccupancy[4][20] = {0};
    char patientName[50];
    int age;
    int triageLevel;
    int specialty;
    int wardAdmission;
    int wardID;
    int daysAdmitted;
    int queueCount =0;
    int averageTime;
    int waitingTime;
    int baseFee;
    int emergencySurcharge;
    int wardCost;
    int discount;
    int grossTotal;
    int finalPayable;
    int patientCount = 0;
    char patientNames[MAX_PATIENTS][50];
    int patientAges[MAX_PATIENTS];
    int patientTriage[MAX_PATIENTS];
    int patientSpecialty[MAX_PATIENTS];
    int patientWardAdmission[MAX_PATIENTS];
    int patientWardID[MAX_PATIENTS];
    int patientDaysAdmitted[MAX_PATIENTS];
    int patientWaitingTime[MAX_PATIENTS];
    int patientBaseFee[MAX_PATIENTS];


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

    printf("\nEnter number of patients: ");
    scanf("%d", &patientCount);

    for (int i = 0; i < patientCount; i++)
    {
    printf("\nPatient %d\n", i + 1);

    printf("Enter patient name: ");
    scanf(" %[^\n]", &patientNames[i]);

    printf("Enter age: ");
    scanf("%d", &patientAges[i]);

    printf("Enter triage level (1-Normal, 2-Urgent, 3-Critical): ");
    scanf("%d", &patientTriage[i]);

    printf("\nSelect doctor specialty:\n");
    printf("1. General Practice\n");
    printf("2. Paediatrics\n");
    printf("3. Cardiology\n");
    printf("4. Neurology\n");

    printf("Enter specialty: ");
    scanf("%d", &patientSpecialty[i]);

    if (patientSpecialty[i] == 1)
    {
    averageTime = 15;
    }
    else if (patientSpecialty[i] == 2)
    {
    averageTime = 20;
    }
    else
    {
    averageTime = 30;
    }
    patientWaitingTime[i] = i*averageTime;
    printf("Please Waiting: %d minutes\n", patientWaitingTime[i]);


    if (patientSpecialty[i] == 1)
    {
    patientBaseFee[i] = 1500;
    }
    else if (patientSpecialty[i] == 2)
    {
    patientBaseFee[i] = 2500;
    }
    else if (patientSpecialty[i] == 3)
    {
    patientBaseFee[i] = 4500;
    }
    else if (patientSpecialty[i] == 4)
    {
    patientBaseFee[i] = 5000;
    }
    if (patientTriage[i] == 1)
    {
    emergencySurcharge = 0;
    }
    else if (patientTriage[i] == 2)
    {
    emergencySurcharge = baseFee * 20 / 100;
    }
    else if (patientTriage[i] == 3)
    {
    emergencySurcharge = baseFee * 50 / 100;
    }
    printf("The Base Consultation Fee is: Rs.%d\n", baseFee);
    printf("The Emergency Surcharge is: Rs.%d\n", emergencySurcharge);

    printf("\nDo you want ward admission? (1-Yes, 0-No): ");
    scanf("%d", &patientWardAdmission[i]);

    if (patientWardAdmission[i] == 1)
    {
    printf("\nSelect ward:\n");
    printf("1. General Ward\n");
    printf("2. Paediatric Ward\n");
    printf("3. Surgical Ward\n");
    printf("4. ICU\n");

    printf("Enter ward ID: ");
    scanf("%d", &patientWardID[i]);

    printf("Enter number of days admitted: ");
    scanf("%d", &patientDaysAdmitted[i]);
    }
    else
    {
    patientWardID[i] = 0;
    patientDaysAdmitted[i] = 0;
    }
    }
    if (wardAdmission == 1)
    {
    if (wardID == 1)
    {
        wardCost = daysAdmitted * 3000;
    }
    else if (wardID == 2)
    {
        wardCost = daysAdmitted * 6000;
    }
    else if (wardID == 3)
    {
        wardCost = daysAdmitted * 12000;
    }
    else if (wardID == 4)
    {
        wardCost = daysAdmitted * 25000;
    }
    }
    else
    {
    wardCost = 0;
    }
    printf("Your wardCost is:Rs.%d\n",wardCost);

    if (age < 5 || age > 65)
    {
    discount = (baseFee + emergencySurcharge + wardCost) * 15 / 100;
    }
    else
    {
    discount = 0;
    }
    printf("Age Subsidy Discount: Rs.%d\n", discount);

    grossTotal = baseFee + emergencySurcharge + wardCost;
    finalPayable = grossTotal - discount;

    printf("Gross Total: Rs.%d\n", grossTotal);
    printf("Final Payable: Rs.%d\n", finalPayable);

    return 0;
}
