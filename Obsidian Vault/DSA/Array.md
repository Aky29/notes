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

# Insertion 
## Inserting in the beginning 

to insert an element at the beginning of an array you will have to move every element forward by one and then out that element in the beginning 

```
#include<iostream>

using namespace std;

int main(){
    int a[11] = {0,1,2,3,4,5,6,7,8,9,10};
    int b[12];
    int k;

    cin >> k;

    for(int i =0 ; i<11;i++){
        b[i+1] = a[i];
    }

    b[0] = k;

    for(int i =0 ; i<12;i++){
        cout << b[i]<<endl;
    }

    return 0;

}
```

NOTE :- memory allocation in c ++ is done by new and delete 
`int* arr = new(std::nothrow) int[n];`
`delete[] arr;`

Time complexity is **N** as you would have to move all the elements

## Inserting at the end

to insert an element at the end an array you would need to create a new array again as by nature array addresses are in a sequence which means the data is stored continuously but when you try to insert an element which would increase the size of the array then you would need more space then you allocated which is why you would need to create a new array.

NOTE :- for dynamic sized array in C++ we use vector which handles the memory allocation and in C you use malloc and realloc to allocate memory to the array 

```
#include<iostream>

using namespace std;

int main(){

    int a[11] = {0,1,2,3,4,5,6,7,8,9,10};
    int b[12];
    int k;

    cin >> k;
    
    for(int i =0 ; i<11;i++){
        b[i] = a[i];
    }
    b[11] = k;
    for(int i =0 ; i<12;i++){
        cout << b[i]<<endl;
    }

    return 0;
}
```

## Inserting in middle

to insert an element in the middle of the array we would need to first create a new array then shift all the elements from the first array to this then add the element to that position 


```
#include<iostream>

using namespace std;

int main(){

    int a[11] = {0,1,2,3,4,5,6,7,8,9,10};
    int b[12];
    int k,o;
    
    cin >> k;
    cin >> o;
    
    for(int i =0 ; i<11;i++){
	    if(i == 0){
		    b[o] = k;
		    i++;
	    }
	    b[i] = a[i];
    }
    for(int i =0 ; i<12;i++){
        cout << b[i]<<endl;
    }

    return 0;
}
```

## Deletion 

For deletion just shift all the elements to the left