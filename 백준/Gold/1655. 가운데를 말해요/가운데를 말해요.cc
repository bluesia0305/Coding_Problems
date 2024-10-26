#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
    
    int N;
    cin >> N;
    
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    int n;
    for (int i = 0; i < N; i++)
    {
        cin >> n;
        
        if (i == 0)
            maxHeap.push(n);
        else if (i == 1)
        {
            if (n >= maxHeap.top())
                minHeap.push(n);
            else
            {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
                maxHeap.push(n);
            }
        }
        else
        {
            if (n > maxHeap.top())
                minHeap.push(n);
            else
                maxHeap.push(n);
            
            if (minHeap.size() > maxHeap.size())
            {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
            else if (maxHeap.size() > minHeap.size() + 1)
            {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }
        }
        
        cout << maxHeap.top() << "\n";
    }
    
    return 0;
}