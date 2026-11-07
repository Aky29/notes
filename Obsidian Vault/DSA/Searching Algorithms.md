
# Linear Search

it is a simple algorithm where we check each element in a sequence if the element is found the loop breaks otherwise it iterates the complete loop but it does not depend on the input order like binary search

## Time complexity 

the whole array is being traversed thus the time complexity comes out to be ***N***

## Space Complexity

as we are not creating other variables the space complexity is ***Constant***

## C++ implementation

```
#include<iostream>

using namespace std;

int main(){
    int a[11] = {0,1,2,3,4,5,6,7,8,9,10};
    int k ;

    cin >> k;

    for(int i =0 ; i<11; i++){
        if(a[i]==k){
            cout<<"found";
            return 0;
        }
    }

    cout<< "not found";
    return 0;
}
```
---------

# Binary Search

it is a divide and conquer algorithm where we take a sorted list as input then we divide it from the middle and check whether the middle element is the correct element or not if it is not then we check if it is greater then or less then the correct element then accordingly we change our high and low variable to the middle then we run the search again till we find the element or the high is lower then low in which case the element does not exist in the list 

## Time Complexity 

as the array is becoming half after each check thus the time complexity is ***log(n)***

## Space Complexity

as we are not creating other variables the space complexity is ***Constant***
### C++ implementation

```
#include<iostream>
using namespace std;

  /* i have used recurrsion here but you can use loops by updating the low, middle and high inside loop*/
  
bool bs(int a[] , int k,int high,int low){
	if(low>high)return false;
	int mid = low + (high-low)/2;

    if(a[mid]==k)return true;
     else if(a[mid]>k)return bs(a,k,mid-1,low);
    else return bs(a,k,high,mid+1);
}

int main(){
    int n ;
    int arr[] = {0,1,2,3,4,5,6,7,8,9,10};
    int k ;
    cin >> k;

    if(bs(arr,k,10,0))cout<<"found"<<endl;
    else cout<<"not found"<<endl;
    
    return 0;

}
```

----

