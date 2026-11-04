#include <chrono>
#include <iostream>
#include <vector>

using namespace std;

vector<int> quick_sort(bool random, vector<int> arr)
{
    if (arr.size() <= 1) return arr;

    int idx   = random ? (rand() % arr.size()) : 0;
    int pivot = arr.at(idx);
    vector<int> lt, gt, eq;

    for (int i = 0; i < arr.size(); i++) {
        int val = arr.at(i);
        if      (val < pivot) lt.push_back(val);
        else if (val > pivot) gt.push_back(val);
        else eq.push_back(val); // in case there are multiple occurances
    }

    lt = quick_sort(random, lt);
    gt = quick_sort(random, gt);

    vector<int> result;
    result.reserve(arr.size());

    result.insert(result.end(), lt.begin(), lt.end());
    result.insert(result.end(), eq.begin(), eq.end());
    result.insert(result.end(), gt.begin(), gt.end());

    return result;
}

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> a(n, 0), b(n, 0);

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    srand(time(0));
    
    // auto s1 = chrono::high_resolution_clock::now();
    b = quick_sort(false, a);
    // auto e1 = chrono::high_resolution_clock::now();
    // double t1 = chrono::duration<double, milli>(e1 - s1).count();

    cout << "\nSorted array using Deterministic Quick Sort: \n"; //  << " (Time: " << t1 <<"ms)"
    for (int num : b) cout << num << " ";
    cout << endl;

    // auto s2 = chrono::high_resolution_clock::now();
    b = quick_sort(true, a);
    // auto e2 = chrono::high_resolution_clock::now();
    // double t2 = chrono::duration<double, milli>(e2 - s2).count();
    
    cout << "\nSorted array using Randomized Quick Sort: \n";  //  << " (Time: " << t2 <<"ms)"
    for (int num : b) cout << num << " ";
    cout << endl;

    return 0;
}
