#include <iostream>
#include <vector>

using namespace std;

void heapify(vector <int>& hp, int n, int i)
{
	int max = i; 
	int l = 2 * i + 1; // left child
	int r = 2 * i + 2; // right child


	if (l < n && hp[l] > hp[max])
		max = l;

	// If right child is larger than largest so far
	if (r < n && hp[r] > hp[max])
		max = r;

	// If largest is not root
	if (max != i) {
		swap(hp[i], hp[max]);

		// Recursively heapify the affected sub-tree
		heapify(hp, n, max);
	}
}

// Function to build a Max-Heap from the given hpay
void buildHeap(vector <int>& hp, int n)
{
	for (int i = (n / 2) - 1; i >= 0; i--) {
		heapify(hp, n, i);
	}
}


int minIndex(vector <int>& hp) {
	int index = 0;
	// search num in inputArray from index 0 to elementCount-1 
	for (int i = 0; i < hp.size(); i++) {
		if (hp[i] < hp[index]) {
			index = i;
		}
	}
	return index;
}


void percUp(vector <int>& hp, int n) {
	while ((n / 2-1) > 0) {
		if (hp[n] > hp[n / 2-1]) {
			swap(hp[n / 2-1], hp[n]);
		}
		n = (n / 2-1);
	}
}

void pushHeap(vector <int>& hp, int node) {
	hp.push_back(node);
	percUp(hp,hp.size()-1); // (hp.size()-1) is index num push
	
}




void popHeap(vector <int>& hp) {
	hp.erase(hp.begin() + minIndex(hp));
}

void printHeap(vector <int>& hp, int n)
{
	for (auto i = hp.begin(); i < hp.end(); i++)
		cout << *i << " ";
	cout << "\n";
}





int main()
{

	vector <int> hp = { 1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17 };

	int n = hp.size();

	cout << "All Elements in Vector Before Build Heap:" << endl;
	printHeap(hp, n);

	cout << "\n----------------------------\n";

	cout << "All Elements of Heap in Vector:" << endl;
	buildHeap(hp, n);
	printHeap(hp, n);

	cout << "\n----------------------------\n";

	int element;
	cout << "What will you Insert Now: " << endl;
	cout << ">> ";
	cin >> element;

	cout << "All Elements After Insertion:" << endl;
	pushHeap(hp, element);
	printHeap(hp, n);
	

	cout << "\n----------------------------\n";

	

	
	cout << "Delete Smallest Value in Heap Vector:" << endl;
	int smallest = hp[minIndex(hp)];
	popHeap(hp);
	printHeap(hp, n);
	cout << "Number (" << smallest << ") Has Been Deleted" << endl;
	cout << "\n----------------------------\n";
	
	
	cout << "Size of Heap: " << n << endl;

	cout << "\n----------------------------\n";

	return 0;
}
