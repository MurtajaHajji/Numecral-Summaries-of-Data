#include <iostream>
#include <cmath>
using namespace std;

struct Data
{
    int *data;
    int size;
};

Data GetData()
{
    Data Thedata;

    cout << "Enter the number of elements: ";
    cin >> Thedata.size;

    Thedata.data = new int[Thedata.size];

    cout << "Enter the elements: ";
    for (int i = 0; i < Thedata.size; i++)
    {
        cin >> Thedata.data[i];
    }
    return Thedata;
}

void DisplayData(const Data &Thedata)
{
    cout << "The data is: ";
    for (int i = 0; i < Thedata.size; i++)
    {
        cout << Thedata.data[i] << " ";
    }
    cout << endl;
}

void SortData(Data &Thedata)
{
    for (int i = 0; i < Thedata.size - 1; i++)
    {
        for (int j = 0; j < Thedata.size - i - 1; j++)
        {
            if (Thedata.data[j] > Thedata.data[j + 1])
            {
                int temp = Thedata.data[j];
                Thedata.data[j] = Thedata.data[j + 1];
                Thedata.data[j + 1] = temp;
            }
        }
    }
}

int SampleMean(const Data &Thedata)
{
    int sum = 0;
    for (int i = 0; i < Thedata.size; i++)
    {
        sum += Thedata.data[i];
    }
    return sum / Thedata.size;
}

int SampleVariance(const Data &Thedata)
{
    int sum = 0;
    int mean = SampleMean(Thedata);
    for (int i = 0; i < Thedata.size; i++)
    {
        sum += (Thedata.data[i] - mean) * (Thedata.data[i] - mean);
    }
    return sum / Thedata.size;
}

int SampleStandardDeviation(const Data &Thedata)
{
    return sqrt(SampleVariance(Thedata));
}

int SampleRange(Data &Thedata)
{
    SortData(Thedata);
    return Thedata.data[Thedata.size - 1] - Thedata.data[0];
}

int SampleMedian(Data &Thedata)
{
    SortData(Thedata);
    return Thedata.data[Thedata.size / 2];
}

int SampleMode(const Data &Thedata)
{
    int *count = new int[Thedata.size];
    for (int i = 0; i < Thedata.size; i++)
    {
        count[i] = 0;
    }
    for (int i = 0; i < Thedata.size; i++)
    {
        for (int j = 0; j < Thedata.size; j++)
        {
            if (Thedata.data[i] == Thedata.data[j])
            {
                count[i]++;
            }
        }
    }
    int max = count[0];
    int index = 0;
    for (int i = 1; i < Thedata.size; i++)
    {
        if (count[i] > max)
        {
            max = count[i];
            index = i;
        }
    }
    return Thedata.data[index];
}

int main()
{
    int c;
    Data DATA;

    do
    {
        cout << "-------------------------------------------------\n";
        cout << "1. Get Data.\n";
        cout << "2. Display Data.\n";
        cout << "3. Display Data After Sorting\n";
        cout << "4. Calculate Sample Mean.\n";
        cout << "5. Calculate Sample Variance.\n";
        cout << "6. Calculate Sample standard Deviation.\n";
        cout << "7. Calculate Sample Range.\n";
        cout << "8. Calculate Sample Median.\n";
        cout << "9. Calculate Sample Mode.\n";
        cout << "10. Show all\n";
        cout << "11. Exit.\n";
        cout << "-------------------------------------------------\n";
        cin >> c;

        switch (c)
        {
        case 1:
            DATA = GetData();
            break;
        case 2:
            DisplayData(DATA);
            break;
        case 3:
            cout << "The data after sorting: ";
            SortData(DATA);
            DisplayData(DATA); // Display sorted data
            break;
        case 4:
            cout << "The Sample Mean is: " << SampleMean(DATA) << endl;
            break;
        case 5:
            cout << "The Sample Variance is: " << SampleVariance(DATA) << endl;
            break;
        case 6:
            cout << "The Sample Standard Deviation is: " << SampleStandardDeviation(DATA) << endl;
            break;
        case 7:
            cout << "The Sample Range is: " << SampleRange(DATA) << endl;
            break;
        case 8:
            cout << "The Sample Median is: " << SampleMedian(DATA) << endl;
            break;
        case 9:
            cout << "The Sample Mode is: " << SampleMode(DATA) << endl;
            break;
        case 10:
            DisplayData(DATA);
            cout << "The data after sorting: ";
            SortData(DATA);
            DisplayData(DATA); // Display sorted data
            cout << "The Sample Mean is: " << SampleMean(DATA) << endl;
            cout << "The Sample Variance is: " << SampleVariance(DATA) << endl;
            cout << "The Sample Standard Deviation is: " << SampleStandardDeviation(DATA) << endl;
            cout << "The Sample Range is: " << SampleRange(DATA) << endl;
            cout << "The Sample Median is: " << SampleMedian(DATA) << endl;
            cout << "The Sample Mode is: " << SampleMode(DATA) << endl;
            break;
        case 11:
            cout << "Exiting Program..\n";
            break;
        default:
            cout << "Invalid choice. Please choose again.\n";
        }
    } while (c != 11);

    return 0;
}
