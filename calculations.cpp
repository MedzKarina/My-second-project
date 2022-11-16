#include "calculations.h"

float Galutinis(int egz, vector<int> paz)
{
    int sum = 0;
    int cnd = paz.size();
    for(int i=0; i < cnd; i++)
    {
        sum = sum + paz[i];
    }

    float vid = sum/(float)cnd;

    return (0.6 * egz) + (vid * 0.4);
}

int Mediana(vector<int> arr){
    int size = arr.size();
    sort(arr.begin(), arr.end());
    if (size % 2 != 0)
        return arr[size/2];
    return (arr[(size-1)/2] + arr[size/2])/2.0;
}
