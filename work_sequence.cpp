#include <bits/stdc++.h>
using namespace std;

class Activitiy {
    public:
	int start, finish;
};

bool activityCompare(Activitiy s1, Activitiy s2)
{
	return (s1.finish < s2.finish);
}

void printMaxActivities(Activitiy arr[], int n)
{
	sort(arr, arr+n, activityCompare);

	cout << "Following activities are selected : ";

	int i = 0;
	cout << "(" << arr[i].start << ", " << arr[i].finish << "), ";

	for (int j = 1; j < n; j++){
        if (arr[j].start >= arr[i].finish){
            cout << "(" << arr[j].start << ", "
                << arr[j].finish << "), ";
            i = j;
        }
	}
}

int main()
{
    int n;
    cin>>n;
    Activitiy arr[n];
    int a,b;
    for(int i=0; i<n; i++){
        scanf("%d %d",&a,&b);
        arr[i]={a, b};
    }
	printMaxActivities(arr, n);
	return 0;
}
