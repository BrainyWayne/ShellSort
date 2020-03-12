#include <iostream>
#include <cmath>
using namespace std;

//Francis Eshun
//1649617


double calculatedPowers [50];
int calculatedPowersIndexer = 0;
double calculatedPowersFormula;


void checkPowers(int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){

            calculatedPowersFormula = pow(2,i) * pow(3,j);

            if(calculatedPowersFormula < n){
                cout << i << "," << j << " gives " << calculatedPowersFormula << endl;
                calculatedPowers[calculatedPowersIndexer] = calculatedPowersFormula;
                calculatedPowersIndexer++;


            }
        }
    }


    cout << "Numbers in array: ";
    //Checking if the numbers have been stored well in the array
    for (int i = 0; i < sizeof(calculatedPowers[0]) - 1; i++)
        cout << calculatedPowers[i] << " ";
}

//Sorting the calculated powers in descending order
void sortCalculatedPowers(double arr[], int n){

    int i, j;
    double temp;
    for (i = 0; i < n-1; i++)
    {
        for (j = 0; j < n-i-1; j++)
        {
            if (arr[j] < arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }


    }

    cout << endl << "Sorted powers: ";

    for (int i = 0; i < sizeof( calculatedPowers[0] ) ; i++)
        cout <<" "<<calculatedPowers[i];
}

void shellSort(double sortedPowers[], double items[], int no){
    int temp;
    int numberOfUseCases = sizeof( sortedPowers[0] ) / 2;
    cout << endl << "Number of use cases = " << numberOfUseCases;
    cout << endl << "Use cases cancelled = " << sizeof(sortedPowers[0]) - numberOfUseCases;

    int currentUseCase = sortedPowers[--numberOfUseCases];
    cout << endl << "Current use case: " << currentUseCase;

    int i, j, k;
    // Gap 'i' between index of the element to be compared, initially n/2.
    while (currentUseCase > 0)
    {
        for(j = currentUseCase; j < no; j++)
        {
            for(k = j-i; k >= 0; k = k-i)
            {
                if(items[k+i] >= items[k])
                    break;
                else
                {
                    temp = items[k];
                    items[k] = items[k+i];
                    items[k+i] = temp;
                }
            }
        }
        currentUseCase = sortedPowers[++numberOfUseCases];
    }

}

int main()
{
    int n, i;
    cout<<"\nEnter the number of data element to be sorted: ";
    cin>>n;

    double itemsToSort[n];


    for(i = 0; i < n; i++)
    {
        cout<<"Enter item "<<i+1<<": ";
        cin>>itemsToSort[i];
    }

    checkPowers(n);
    sortCalculatedPowers(calculatedPowers,n);
    shellSort(calculatedPowers, itemsToSort, n);


    // Printing the sorted data.
    cout<<"\nThe sorted numbers are ";
    for (i = 0; i < n; i++)
        cout<<" "<<itemsToSort[i];

    return 0;
}