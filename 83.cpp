#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int sort(const void* a, const void* b)
{
    return(*(int*)a - *(int*)b);
}

int main()
{
    ifstream file;
    string line;
    ofstream out;

    out.open("output.txt");
    file.open("input.txt");

    if (!file)
    {
        cout << "error opening file" << endl;
        return 0;
    }
    
    int n, m;
    int i = 0;
    int j = 0;
    int k = 0;

    const int ip = 10 ^ 6;

    int mas1[ip];
    int mas2[ip];

    for (i = 0; i < 2; i++)
    {
        if (i == 0)
            file >> n;
        else if (i == 1)
            file >> m;
    }
    
    i = 0;

    while (!file.eof())
    {
        if (i < n)
        {
            file >> mas1[j];
            j++;
        }
        else
        {
            file >> mas2[k];
            k++;
        }
        i++;
    }

    qsort(mas1, n, sizeof(int), sort);
    qsort(mas2, m, sizeof(int), sort);
   
    int same[ip];
    i = 0, j = 0, k = 0;
    while (i < n && j < m)
    {
        if (mas1[i] == mas2[j])
        {
            same[k] = mas1[i];
            k++;
            i++;
            j++;
        }
        else if (mas1[i] > mas2[j])
            j++;
        else
            i++;
    }
    
    for (i = 0; i < k; i++)
    {
        if (same[i] != same[i + 1])
            cout << same[i] << endl;
    }

    if (out.is_open())
    {
        for (i = 0; i < k; i++)
        {
            out << same[i] << endl;
        }
    }

    out.close();
    file.close();

    return 0;
}