int size = 5;
#include <bits/stdc++.h>
using namespace std;
int disk_size = 200;
void LOOK(int arr[], int head, string direction)
{
	int seek_count = 0;
	int distance, cur_track;
	vector<int> left, right;
	vector<int> seek_sequence;
	for (int i = 0; i < size; i++) {
		if (arr[i] < head)
			left.push_back(arr[i]);
		if (arr[i] > head)
			right.push_back(arr[i]);
	}
	std::sort(left.begin(), left.end());
	std::sort(right.begin(), right.end());
	int run = 2;
	while (run--) {
		if (direction == "left") {
			for (int i = left.size() - 1; i >= 0; i--) {
				cur_track = left[i];
				seek_sequence.push_back(cur_track);
				distance = abs(cur_track - head);
				seek_count += distance;
				head = cur_track;
			}
			direction = "right";
		}
		else if (direction == "right") {
			for (int i = 0; i < right.size(); i++) {
				cur_track = right[i];
				seek_sequence.push_back(cur_track);
				distance = abs(cur_track - head);
				seek_count += distance;
				head = cur_track;
			}
			direction = "left";
		}
	}
	cout << "Total number of seek operations = "<< seek_count << endl;
	cout << "Seek Sequence is" << endl;
	for (int i = 0; i < seek_sequence.size(); i++) {
		cout << seek_sequence[i] << endl;
	}
}
int main()
{
	int arr[size] = { 55, 58, 	60, 70, 18 };
	int head = 50;
	string direction = "right";
	cout << "Initial position of head: "
		<< head << endl;
	LOOK(arr, head, direction);
	return 0;
}


