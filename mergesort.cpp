/*
 * This is a free program to show working and implementation of a simple
 * Merge Sort  in CPP
 *
 * You are free to use it however as you want.
 *
 * Author doesnt hold responsibility to this code
 *
 * Author : Sidhin S Thomas
 * email: sidhin.thomas@gmail.com
 */

#include <iostream>

using namespace std ;

void mergsort(int [],int,int);

int main(){
    int a[100],n ;
    cin >> n ;
    for(int i=0 ; i<n; ++i)
        cin >> a[i];
    mergsort(a,0,n-1);
    for(int i=0 ; i<n; ++i)
        cout << a[i] << " ";
    cout << endl ;
}
int b[10000];
void mergsort(int a[],int l, int h){
    if(l>=h){
        return ;
    }
    int m = (l + h) / 2 ;
    mergsort(a,l,m);
    mergsort(a,m+1,h);

    int i = l ;
    int j = m+1 ;
    int k = 0 ;
    while(i<=m && j <=h){
        if(a[i] < a[j]){
            b[k++] = a[i++];
        }
        else
            b[k++] = a[j++];
    }
    while(i<=m){
        b[k++] = a[i++];
    }
    while(j<=h) {
        b[k++] = a[j++];
    }
    for(i = 0; i < k; ++i){
        a[l+i] = b[i];
    }
}