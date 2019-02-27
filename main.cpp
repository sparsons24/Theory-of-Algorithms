#include <iostream>
#include <vector>
#include <array>
using namespace std;

int main() {

    int Capacity = 11;

    //Items Vector List
    vector<int> items = {0, 1, 2, 3, 4};
    cout << "# of Items: " << items.size() << endl;
    for (int i = 0; i < items.size(); i++) {
        cout << items.at(i);
    }

    cout << endl;

    //Weights Vector List
    vector<int> weights = {0, 1, 3, 5, 7};
    cout << "# of Weights: " << weights.size() << endl;
    for (int w = 0; w < weights.size(); w++) {
        cout << weights.at(w);
    }

    cout << endl;

    //Values Vector List
    vector<int> values = {0, 2, 4, 6, 8};
    cout << "# of Values: " << values.size() << endl;
    for (int v = 0; v < values.size(); v++) {
        cout << values.at(v);
    }

    cout << endl;

   struct Point {
        int x;
        int y;
        int z;
    };
    int k = 0;
    int h = 0;
    int knap[Capacity][Capacity];
    Point Path[Capacity][Capacity];



    //Initialize First Row
    for (int h = 0; h < weights.size(); h++) {
        knap[k][h] = 0;
        Path[k][h].x = 0;
        Path[k][h].y = 0;
        Path[k][h].z = 0;
        //knap[k][h]=0;
        cout << knap[k][h];
    }

    //Initialize First Column
    for (int k = 0; k < Capacity; k++) {
        for (int h = 0; h < 1; h++) {
            knap[k][h] = 0;
            Path[k][h].x = 0;
            Path[k][h].y = 0;
            Path[k][h].z = 0;
            cout << knap[k][h];
        }
    }

    cout << endl;

    //Fill in remaining cells
    for (int k = 1; k < Capacity; k++) {
        for (int h = 1; h < weights.size(); h++) {
            if (k - weights[h] > -1 && knap[k][h - 1] < (values[h] + knap[k - weights[h]][h - 1])) {
                knap[k][h] = values[h] + knap[k - weights[h]][h - 1];
                Path[k][h].x = (k - weights[h]);
                Path[k][h].y = h - 1;
                Path[k][h].z = 1;
                // x[k][h] = (k-weights[h]),h-1;
            } else {
                knap[k][h] = knap[k][h - 1];
                Path[k][h].x = k;
                Path[k][h].y = h - 1;
                Path[k][h].z = 0;
                //x[k][h] = k, h-1;}
                cout << knap[k][h];
            }
        }}
        cout << endl;

        //Output Knap array
        cout << "Knap: " << endl;
        cout << "   ";
        for(int h=0; h<weights.size();h++) {
            cout << h;}
            cout << endl << "   -----" << endl;
        for (int k = 0; k < Capacity; k++) {
            cout << k << "| ";
            for (int h = 0; h < weights.size(); h++) {
                cout << knap[k][h];

            }
            cout << endl;
        }

        cout << endl;

        //Output X array
        cout << "Path: " << endl;
        cout << "   ";
        for(int h=0; h<weights.size();h++) {
        cout << "     " << h << "--";}
        cout << endl;
        for (int k = 0; k < Capacity; k++) {
            cout << k << "| ";
            for (int h = 0; h < weights.size(); h++) {
                cout << Path[k][h].z << ":(" << Path[k][h].x << "," << Path[k][h].y << "); ";
            }
            cout << endl;
        }

       // cout << endl << "Maximum Path & Value:" << endl;
        cout << endl << "Maximum Value: " << knap[Capacity-1][weights.size()-1] << endl;
        cout << "Maximum Path: (" << Capacity - 1 << "," << weights.size()-1 << ") << ("
        << Path[Capacity-1][weights.size()-1].x << "," << Path[Capacity-1][weights.size()-1].y << ")";

        int s = Path[Capacity-1][weights.size()-1].x;
        int p = Path[Capacity-1][weights.size()-1].y;
        while(s != 0 && p !=0){
            cout << " << (" << Path[s][p].x << "," << Path[s][p].y << ")";
            s = Path[s][p].x;
            p = Path[s][p].y;
        }

        cout << endl << "X Values (Descending Order Starting with X" << items.size()-1 << "): " << Path[Capacity-1][weights.size()-1].z;
        int m = Path[Capacity-1][weights.size()-1].x;
        int i = Path[Capacity-1][weights.size()-1].y;
       // int y = X[Capacity-1][weights.size()-1].z;
        while (m !=0 && i !=0){
            cout << ", " << Path[m][i].z;
            m = Path[m][i].x;
            i = Path[m][i].y;
        }
        cout << endl << "Values: ";
        for(int r = values.size()-1; r > 0; r--){
            cout << values.at(r) << ", ";
        }

        return 0;
    }