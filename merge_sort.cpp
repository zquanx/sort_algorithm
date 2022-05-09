#include <iostream>
using namespace std;

bool compare_arr(int *a,int *c, int num){
    for(int i=0;i< num;i++){
        if (a[i]!=c[i]) {
            return false;
        }
    }
    return true;
}
void merge(int * ,int , int ,int ,int );
void merge_sort(int *a, int low ,int high ,int num ,int *c ,int level){
    
    if(low==high)return;
    int mid = (low + high)/2;
    merge_sort(a, low, mid, num ,c ,level+1);
    merge_sort(a, mid+1, high ,num ,c ,level+1);
    merge(a, low, high, mid, num);
    if(compare_arr(a, c, num)){
        merge_sort(a, low, high, num, c,level);
        cout<<"Merge Sort\n";
        for(int i=0;i<num;i++){
            cout<<a[i]<<" ";
        }
        return;
    }
}
void merge(int *a, int low, int high, int mid, int num){
    int b[num];
    int i=low, j=mid+1, s=low;
    while(i<=mid && j<=high){
        if(a[i] < a[j]){
            b[s++] = a[i++];
        }else{
            b[s++] = a[j++];
        }
    }
    while (i <= mid) {
        b[s++] = a[i++];
    }
    while (j <= high) {
        b[s++] = a[j++];
    }
    for(i = low;i < s;i++){
        a[i] = b[i];
    }
}
void insert_sort(int *a, int num , int *c){
    int i,j,t,count=0;
    for(i = 1 ; i < num ; i++){
        t = a[i];
        for( j = i-1 ; j >= 0 && a[j] > t; j-- ){
            a[j+1] = a[j];
        }
        a[++j] = t;
        if(count == 1){
            cout << "Insertion Sort\n";
            for(int i = 0;i < num; i++){
                cout << a[i] << " ";
            }
            return;
        }
        if(compare_arr(a, c, num)){
            count++;
        }
    }
}

int main(){
    int num,i;
    cin >> num;
    int a[num],c[num],b[num];
    for(i=0;i<num;i++){
        cin>>a[i];
        b[i]=a[i];
    }
    for(i=0;i<num;i++){
        cin>>c[i];
    }
    int level=1;
    merge_sort(a, 0, num-1, num , c,level);
    insert_sort(b, num ,c );
//    for(i=0;i<num;i++){
//        cout<<a[i]<<" ";
//    }
    cout<<"\n";
    return 0;
}
 
