#include <iostream>
#include <future>
#include <chrono>
#include <vector>

using namespace std;

int square(int x) {
    return x * x;
}

int main() {

    vector< future<int> > vals; 
    int result = 0;

    for (int i = 0; i < 20; ++i)
    {
      vals.push_back(async(launch::async, &square, i + 1));
    }

    for (int i = 0; i < 20; ++i)
    {
      result += vals[i].get();
    }

    cout << "The threads returned " << result << endl;
    return 0;
}
