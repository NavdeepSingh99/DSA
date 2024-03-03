#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define maxSize 1000

class MinHeap{
    public:
        vector<int>heap;
        int n;

        MinHeap(){
            heap.resize(maxSize,0);
            n = 0;
        }

        void insert(int num){
            heap[n] = num;
            int temp = heap[n], i = n;
            while (i>0 && temp < heap[i/2]){
                heap[i] = heap[i/2];
                i = i/2;
            }
            heap[i] = temp;  
            n++;
        }

        int remove(){
            if(n == 0) return -1;

            n--;
            
            int value = heap[0];
            heap[0] = heap[n];
            heap[n] = value;

            int i = 0, j = i*2 + 1;

            while(j<=n-1){
                if(j<n-1 && heap[j+1] < heap[j]) j = j+1;
                if(heap[i] > heap[j]){
                    swap(heap[i], heap[j]);
                    i = j;
                    j = i*2 + 1;
                }
                else break;
            }
            return value;
        }

        void display(){
            for(int i=0; i<n; i++) cout << heap[i] << " ";
        }

};


int main(){
    MinHeap minheap;

    int choice;
    int num;
    do{
        cout << "1: Insert\n2: Display\n3: Remove\n4: Exit\n";
        cin >> choice;
        cout << endl;

        switch (choice)
        {
            case 1:
                cout << "Enter num: ";cin >> num; cout <<endl;
                minheap.insert(num);
                break;
            case 2:
                minheap.display();
                cout << endl;
                break;
            case 3:
                cout << minheap.remove() << endl;
                break;
            case 4:
                exit(0);
                break;
            default:
                cout << "Enter number between 1 to 4" << endl;
                break;
        }

    }while(true);
    return 0;
}
