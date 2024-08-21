#include <stdio.h>
#include <stdlib.h>

void find_peaks(double data[], int n, const char *dataset_name) {
    printf("Maxima in %s:\n", dataset_name);
    for (int i = 1; i < n - 1; i++) {
        if (data[i] > data[i - 1] && data[i] > data[i + 1]) {
            printf("Maxima at index %d, value: %f\n", i, data[i]);
        }
    }
    printf("Minima in %s:\n", dataset_name);
    for (int i = 1; i < n - 1; i++) {
        if (data[i] < data[i - 1] && data[i] < data[i + 1]) {
            printf("Minima at index %d, value: %f\n", i, data[i]);
        }
    }
}

int main() {
    FILE *file1 = fopen("Data_1.txt", "r");
    if (file1 == NULL) {
        printf("Error opening Data_1.txt.\n");
        return 1;
    }

    int count1 = 0;
    double value1;
    double data1[1000]; 

    while (fscanf(file1, "%lf", &value1) == 1) {
        data1[count1++] = value1;
    }
    fclose(file1);

    find_peaks(data1, count1, "Data_1");

    FILE *file2 = fopen("Data_2.txt", "r");
    if (file2 == NULL) {
        printf("Error opening Data_2.txt.\n");
        return 1;
    }

    int count2 = 0;
    double value2;
    double data2[1000];
    
    while (fscanf(file2, "%lf", &value2) == 1) {
        data2[count2++] = value2;
    }
    fclose(file2);

    find_peaks(data2, count2, "Data_2");

    return 0;
}
