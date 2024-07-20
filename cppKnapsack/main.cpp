#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

vector<int> weights ={
                3, 1, 6, 10, 1, 4, 9, 1, 7, 2, 6, 1, 6, 2, 2, 4, 8, 1, 7, 3, 6, 2, 9, 5, 3, 3, 4, 7, 3, 5, 30, 50};
vector<int> values ={
                7, 4, 9, 18, 9, 15, 4, 2, 6, 13, 18, 12, 12, 16, 19, 19, 10, 16, 14, 3, 14, 4, 15, 7, 5, 10, 10, 13, 19,
                9, 8, 5};
const int sizee = 32;
const int wMax = 75;

long bestSubset = 0;
int bestValue = 0;
int bestWeight = 0;

const long totalCombinations = 1L << sizee;

int main() {
    for (long currentSubset = 0; currentSubset < totalCombinations; currentSubset++) {
        int totalWeight = 0;
        int totalValue = 0;

        for (int item = 0; item < sizee; item++) {
            if ((currentSubset & (1L << item)) != 0) { // if item is in the set
                totalWeight += weights[item];
                totalValue += values[item];
            }
        }

        if (totalWeight <= wMax && totalValue > bestValue) {
            bestWeight = totalWeight;
            bestValue = totalValue;
            bestSubset = currentSubset;
        }
    }

    cout << "Best subset of items: " << bitset<sizee>(bestSubset) << endl;
    cout << "Total weight: " << bestWeight << endl;
    cout << "Total value: " << bestValue << endl;

    return 0;
}
