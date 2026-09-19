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
    int patientEmergencySurcharge[MAX_PATIENTS];
    int patientWardCost[MAX_PATIENTS];
    int patientDiscount[MAX_PATIENTS];
    int patientGrossTotal[MAX_PATIENTS];
    int patientFinalPayable[MAX_PATIENTS];
    int tempTriage;
    char tempName[50];
    int tempAge;
    int tempSpecialty;
    int tempWardAdmission;
    int tempWardID;
    int tempDaysAdmitted;
    int tempWaitingTime;
    int tempBaseFee;
    int tempEmergencySurcharge;
    int tempWardCost;
    int tempDiscount;
    int tempGrossTotal;
    int tempFinalPayable;
    int normalCount = 0;
    int urgentCount = 0;
    int criticalCount = 0;
    int totalRevenue = 0;
    int totalDiscounts = 0;


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
    patientEmergencySurcharge[i] = 0;
    }
    else if (patientTriage[i] == 2)
    {
    patientEmergencySurcharge[i] = patientBaseFee[i] * 20 / 100;
    }
    else if (patientTriage[i] == 3)
    {
    patientEmergencySurcharge[i] = patientBaseFee[i] * 50 / 100;
    }
    printf("The Base Consultation Fee is: LKR.%d\n", patientBaseFee[i]);
    printf("The Emergency Surcharge is: LKR.%d\n", patientEmergencySurcharge[i]);

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

    if (patientWardAdmission[i] == 1)
    {
    if (patientWardID[i] == 1)
    {
        patientWardCost[i] = patientDaysAdmitted[i] * 3000;
    }
    else if (patientWardID[i] == 2)
    {
        patientWardCost[i] = patientDaysAdmitted[i] * 6000;
    }
    else if (patientWardID[i] == 3)
    {
        patientWardCost[i] = patientDaysAdmitted[i] * 12000;
    }
    else if (patientWardID[i] == 4)
    {
        patientWardCost[i] = patientDaysAdmitted[i] * 25000;
    }
    else
    {
    patientWardCost[i] = 0;
    }
    printf("Your wardCost is:LKR.%d\n",patientWardCost[i]);
    }

    if (patientAges[i] < 5 || patientAges[i] > 65)
    {
    patientDiscount[i] =(patientBaseFee[i] +patientEmergencySurcharge[i] +patientWardCost[i]) * 15 / 100;
    }
    else
    {
    patientDiscount[i] = 0;
    }
    printf("Age Subsidy Discount: LKR.%d\n", patientDiscount[i]);

    patientGrossTotal[i] =patientBaseFee[i] + patientEmergencySurcharge[i] + patientWardCost[i];

    patientFinalPayable[i] =patientGrossTotal[i] - patientDiscount[i];

    printf("Gross Total: LKR.%d\n", patientGrossTotal[i]);
    printf("Final Payable: LKR.%d\n", patientFinalPayable[i]);
    }
    for (int i = 0; i < patientCount; i++)
    {
    if (patientTriage[i] == 1)
    {
        normalCount++;
    }
    else if (patientTriage[i] == 2)
    {
        urgentCount++;
    }
    else if (patientTriage[i] == 3)
    {
        criticalCount++;
    }
    }
    for (int i = 0; i < patientCount; i++)
    {
    totalRevenue += patientFinalPayable[i];
    totalDiscounts += patientDiscount[i];
    }
    for (int i = 0; i < patientCount - 1; i++)
    {
    for (int j = 0; j < patientCount - i - 1; j++)
     {
        if (patientTriage[j] < patientTriage[j + 1])
        {
            tempTriage = patientTriage[j];
            patientTriage[j] = patientTriage[j + 1];
            patientTriage[j + 1] = tempTriage;

            strcpy(tempName, patientNames[j]);
            strcpy(patientNames[j], patientNames[j + 1]);
            strcpy(patientNames[j + 1], tempName);

            tempAge = patientAges[j];
            patientAges[j] = patientAges[j + 1];
            patientAges[j + 1] = tempAge;

            tempSpecialty = patientSpecialty[j];
            patientSpecialty[j] = patientSpecialty[j + 1];
            patientSpecialty[j + 1] = tempSpecialty;

            tempWardAdmission = patientWardAdmission[j];
            patientWardAdmission[j] = patientWardAdmission[j + 1];
            patientWardAdmission[j + 1] = tempWardAdmission;

            tempWardID = patientWardID[j];
            patientWardID[j] = patientWardID[j + 1];
            patientWardID[j + 1] = tempWardID;

            tempDaysAdmitted = patientDaysAdmitted[j];
            patientDaysAdmitted[j] = patientDaysAdmitted[j + 1];
            patientDaysAdmitted[j + 1] = tempDaysAdmitted;

            tempWaitingTime = patientWaitingTime[j];
            patientWaitingTime[j] = patientWaitingTime[j + 1];
            patientWaitingTime[j + 1] = tempWaitingTime;

            tempBaseFee = patientBaseFee[j];
            patientBaseFee[j] = patientBaseFee[j + 1];
            patientBaseFee[j + 1] = tempBaseFee;

            tempEmergencySurcharge = patientEmergencySurcharge[j];
            patientEmergencySurcharge[j] = patientEmergencySurcharge[j + 1];
            patientEmergencySurcharge[j + 1] = tempEmergencySurcharge;

            tempWardCost = patientWardCost[j];
            patientWardCost[j] = patientWardCost[j + 1];
            patientWardCost[j + 1] = tempWardCost;

            tempDiscount = patientDiscount[j];
            patientDiscount[j] = patientDiscount[j + 1];
            patientDiscount[j + 1] = tempDiscount;

            tempGrossTotal = patientGrossTotal[j];
            patientGrossTotal[j] = patientGrossTotal[j + 1];
            patientGrossTotal[j + 1] = tempGrossTotal;

            tempFinalPayable = patientFinalPayable[j];
            patientFinalPayable[j] = patientFinalPayable[j + 1];
            patientFinalPayable[j + 1] = tempFinalPayable;
        }
     }

    }
    printf("\n--- Patients by Priority ---\n");

     for (int i = 0; i < patientCount; i++)
     {
     printf("\nPatient %d\n", i + 1);
     printf("Name: %s\n", patientNames[i]);
     printf("Age: %d\n", patientAges[i]);
     printf("Triage Level: %d\n", patientTriage[i]);
     }
     printf("\n--- Performance Report ---\n");
     printf("Normal Patients: %d\n", normalCount);
     printf("Urgent Patients: %d\n", urgentCount);
     printf("Critical Patients: %d\n", criticalCount);
     printf("Total Revenue: Rs.%d\n", totalRevenue);
     printf("Total Discounts: Rs.%d\n", totalDiscounts);

    return 0;
}
