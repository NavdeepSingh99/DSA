#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define maxSize 1000

class SegmentTree{
    public:
        vector<int>seg;
        vector<int>arr;
        SegmentTree(){}

        void input(int n){
            arr.resize(n);
            for(int i=0; i<n; i++) {
                cin >> arr[i];
            }
            seg.resize(4*n, 0);
        }

        void build(int i, int l, int h){
            if(l == h){
                seg[i] = arr[l];
                return;
            }

            int mid = (l + h)/2;
            build(2*i+1, l, mid);
            build(2*i+2, mid+1, h);
            seg[i] = seg[2*i+1] + seg[2*i+2];
        }

        int query(int i, int ql, int qr, int low, int high){
            if(ql <= low && high <= qr) return seg[i];

            if(high < ql || low > qr) return 0;

            int mid = (low + high)/2;
            int left = query(2*i+1, ql, qr, low, mid);
            int right = query(2*i+2, ql, qr, mid+1, high);
            return left + right;
        }

        void updateUtil(int sl, int sr, int currIndex, int index, int value, int change){
            if(sl == sr){
                seg[currIndex] = value;
                return;
            }

            seg[currIndex] += change;

            int mid = (sl+sr)/2;

            if(index <= mid) updateUtil(sl, mid, 2*currIndex+1, index, value, change);
            else updateUtil(mid+1, sr, 2*currIndex+2, index, value, change);
        }

        void update(int value, int index){
            int change = value - arr[index];
            arr[index] = value;
            updateUtil(0, arr.size()-1, 0, index, value, change);
        }
};

int main(){
    SegmentTree segtree;
    int n;
    cout << "Enter size of arr: ";
    cin >> n;
    
    cout << "enter element of arr: ";
    segtree.input(n);
    segtree.build(0, 0, n-1);
    
    int ql, qr, choice, value, index;

    do{
        cout << "1: query\n2: update\n3: Exit\n";
        cin >> choice;
        cout << endl;

        switch (choice)
        {
            case 1:
                cout << "Enter ql and qr value: ";
                cin >> ql >> qr;
                cout << segtree.query(0, ql, qr, 0, n-1) << endl;
                break;
            case 2:
                cout << "Enter index and new value: ";
                cin >> index >> value;
                segtree.update(value, index);
                break;
            case 3:
                exit(0);
                break;
            default:
                cout << "Enter number between 1 to 3" << endl;
                break;
        }

    }while(true);
    return 0;
}
