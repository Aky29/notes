# About 

In arrays data is stored in a sequential format, it is a homogenous collection of data meaning that every data in this collection is the same, you can think of it as a single line grid where you know about the first cell from where the dataset starts then to know what is at the nth position in the data take n steps from the start position and you will reach the data.
All of the Data structure relays on array, in fact it is a good practice to implement all the data structures in array 

# Traversal 

traversal in array is simple start at the first position then move to the next address till the array ends

```
#include<iostream>

using namespace std;  

int main(){
    int a[11] = {0,1,2,3,4,5,6,7,8,9,10};
    
    for(int i =0 ; i<11; i++){
        cout<<a[i]<<endl;
    }

    cout << "completed";

    return 0;

}
```

time complexity of traversal is **N**

# Accessing particular element 

To access nth element in the array you just have take n steps from the beginning to get to the n point

```
#include<iostream>

using namespace std;

int main(){
    int a[11] = {0,1,2,3,4,5,6,7,8,9,10};
    int n;

    cin>> n;
    cout << a[n] << endl;
    
    return 0;
}
```

time complexity to access an element is **1**

# 