#include <iostream>
#include <deque>
#include <vector>
using namespace std;

class MonotonicDeque {
private:
    deque<pair<int, int>> minDeque; 
    deque<pair<int, int>> maxDeque; 

public:
    void insert(int value, int index) {
        while (!minDeque.empty() && minDeque.back().first > value) {
            minDeque.pop_back();
        }
        minDeque.emplace_back(value, index);
        while (!maxDeque.empty() && maxDeque.back().first < value) {
            maxDeque.pop_back();
        }
        maxDeque.emplace_back(value, index);
    }
    void removeOutOfRange(int currentIndex, int rangeSize) {
        if (!minDeque.empty() && minDeque.front().second <= currentIndex - rangeSize) {
            minDeque.pop_front();
        }
        if (!maxDeque.empty() && maxDeque.front().second <= currentIndex - rangeSize) {
            maxDeque.pop_front();
        }
    }

    int getMin() {
        return minDeque.empty() ? INT_MAX : minDeque.front().first;
    }
    int getMax() {
        return maxDeque.empty() ? INT_MIN : maxDeque.front().first;
    }
};

void slidingWindowMinMax(const vector<int>& arr, int k) {
    MonotonicDeque dq;
    vector<int> minResults, maxResults;

    for (int i = 0; i < arr.size(); ++i) {
        // Remove elements outside the current window
        dq.removeOutOfRange(i, k);

        // Insert the current element
        dq.insert(arr[i], i);

        // Collect results once the window size is met
        if (i >= k - 1) {
            minResults.push_back(dq.getMin());
            maxResults.push_back(dq.getMax());
        }
    }

    // Print the results
    cout << "Minimums in sliding window: ";
    for (int val : minResults) {
        cout << val << " ";
    }
    cout << endl;

    cout << "Maximums in sliding window: ";
    for (int val : maxResults) {
        cout << val << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    slidingWindowMinMax(arr, k);

    return 0;
}
