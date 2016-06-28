/*
 * This is a free program to show working and implementation of a simple
 * Quick Sort  in CPP
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
void swap(int &a ,int &b){
    int t = a ; a = b ; b = t ;
}

void quicksort(int a[],int l,int h);

int main(){
    int a[100], n ;
    cin >> n ;
    for(int i=0; i<n; i++)
        cin >> a[i];
    quicksort(a,0,n-1);
    for(int i=0; i<n; ++i)
        cout << a[i] << " ";
    cout << endl ;
}

void quicksort(int a[], int l, int h){
    if(l >= h )
        return ;

    int p = l ;
    int i = l+1 ;
    int j = h ;

    while(i<=j){
        if(a[i] < a[p])
            i++ ;
        if(a[p] < a[j])
            j--;
        if(i>j)
            break;
        swap(a[i],a[j]);
    }
    swap(a[p],a[j]);
    quicksort(a,l,j-1);
    quicksort(a,j+1,h);
}