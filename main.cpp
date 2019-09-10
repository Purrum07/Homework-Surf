#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

int swap(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}

int imprimir (vector<int>& vectornum, int tamano){
    for(int i = 0; i <tamano; i++){
        cout << vectornum[i] << " ";
    }
}

void bubble_sort (vector<int>& vectornum, string arr[], int tamano){

    bool huboIntecambio = true;
    while(huboIntecambio){
        huboIntecambio = false;
        for (int i = 0; i < tamano-1; ++i){
            if(vectornum[i+1] < vectornum[i]){
                huboIntecambio = true;
                swap(vectornum[i], vectornum[i+1]);
                swap(arr[i], arr[i+1]);
            }
        }
    }
}

int main()
{
    fstream file;
    string cosas[8];
    vector<int> vectornum;


    file.open("results.txt");

    for(int i = 0; i <= 7; i++){
        string n;
        file >> n;
        cosas[i] = n;
    }

    file.close();

    for (int i = 0; i<=7; i++){

        if(i%2) {

            vectornum.push_back(stoi(cosas[i]));
        }

    }

    bubble_sort(vectornum, cosas, 4);

    cout << "Results\n";
    cout << "\nThe first place is the person with: "<<vectornum[vectornum.size()-1]<<" points"<<endl;
    cout << "The second place is the person with: "<<vectornum[vectornum.size()-2]<<" points" << endl;
    cout << "The third place is the person with: "<<vectornum[vectornum.size()-3] <<" points"<<endl;

    return 0;
}
