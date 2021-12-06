// ZadanieS³onie.cpp : Ten plik zawiera funkcjê „main”. W nim rozpoczyna siê i koñczy wykonywanie programu.
//

#include <iostream>

using namespace std;

#define MAXW 6500 //max weight of an elephant


int main()
{

    int numb, minw = MAXW; //numb - Amount of elepthants, minw - lightest elephant
    int* W, * pos, * des; //W - Weight of elephants,pos - positions of elephants,des - deisred positions of elephants, checked - already checked cycle
    bool* checked;
    cin >> numb;

    W = new int[numb];
    pos = new int[numb];
    des = new int[numb];
    checked = new bool[numb];
    for (int i = 0; i < numb; i++)
    {
        cin >> W[i];
        minw = min(minw, W[i]);
    }
    for (int i = 0; i < numb; i++)
    {
        cin >> pos[i];
        pos[i]--;
    }
    for (int i = 0; i < numb; i++)
    {
        int number;
        cin >> number;
        number--;
        des[number] = pos[i];
    }
    for (int i = 0; i < numb; i++)
    {
        checked[i] = false;
    }
    unsigned long long result = 0;
    for (int i = 0; i < numb; ++i)
    {
        if (checked[i] == false)
        {
            int minc = MAXW, curr = i, l = 0;//minc - minimal weight in cycle
            long long sum = 0; // sum of weights in cycle
            while (1)
            {
                sum += W[curr];
                minc = min(minc, W[curr]);
                curr = des[curr];
                checked[curr] = true;
                l++;
                if (curr == i) break;
            }
            result = result + (min(sum + (l - 2) * (unsigned long long)minc, sum + minc + (l + 1) * (unsigned long long)minw));
        }
    }
    cout << result;
    delete[] W, des, pos, checked;
    return 0;
}

