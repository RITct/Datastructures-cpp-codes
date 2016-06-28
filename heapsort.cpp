/*
 * This is a free program to show working and implementation of a simple
 * Heap Sort  in CPP
 *
 * You are free to use it however as you want.
 *
 * Author doesnt hold responsibility to this code
 *
 * Author : Sidhin S Thomas
 * email: sidhin.thomas@gmail.com
 */

#include <iostream>

using namespace std;

void swap(int &a,int &b){
	int t = a ;	a = b ;	b = t;
}
void heapSort(int [], int);
void heapify(int [],int,int);
void buildHeap(int [],int);

int main(){
	int a[100], n ;
	cin >> n ;
	for(int i=0; i<n; ++i)
		cin >> a[i];
	heapSort(a,n);
	for(int i=0; i<n; ++i)
		cout << a[i] << " ";
}

void heapSort(int a[],int n){
	buildHeap(a,n);
	for(int i = n-1;i>=0;--i){
		cout << "heap: ";
		for(int j=0; j<n; ++j)
			cout << a[j] << " ";
		cout << endl ;
		swap(a[0],a[i]);
		heapify(a,0,i);		
	}

}

void buildHeap(int a[],int n){
	for(int i = n/2;i>=0;--i)
		heapify(a,i,n);
}

void heapify(int a[],int i, int n){
	int l = 2*i + 1 ;
	int r = 2*i + 2 ;
	int large = i ;
	if(l < n && a[large] < a[l]) large = l ;
	if(r < n && a[large] < a[r]) large = r ;
	if(large!=i){
		swap(a[large],a[i]);
		heapify(a,large,n);
	}
}