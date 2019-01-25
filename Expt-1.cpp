/*Write a program to perform the following:
Sequential search (for both array and linked list)
Binary search
Also calculate its space and time requirement*/

//Sequential Search for array
#include<iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;
#define size 100

int main()
{
    auto start = high_resolution_clock::now();
    int arr[size], n, ele, pos=-1;
    cout<<"\n Enter size of array: ";
    cin>>n;
    cout<<"\n Enter elements of array: ";
    for (int i=0;i<n;i++)
        cin>>arr[i];

    cout<<"\n Enter the element to be searched: ";
    cin>>ele;

    for (int i=0;i<n;i++)
    {
        if (arr[i]==ele)
        {
            pos=i;
            cout<<"\n Search successful at index no. "<<pos+1;
            break;
        }
    }

    if (pos==-1)
        cout<<"\n Element not found!";
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "\n Time taken: "<< duration.count() << " microseconds" << endl;

return 0;
}


//Sequential search for linked list
#include<iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;
struct link
{
    int data;
    struct link *next;
};

int main()
{
    auto start = high_resolution_clock::now();
    int n, ele, pos=-1, i=0;
    struct link* p= NULL;

    cout<<"\n Enter size of array: ";
    cin>>n;
    cout<<"\n Enter elements of array: ";
    for (i=0;i<n;i++)
    {
        struct link* new_node= (struct link*) malloc(sizeof(struct link));
        cin>>new_node->data;
        new_node->next = p;
        p = new_node;
    }

    cout<<"\n Enter the element to be searched: ";
    cin>>ele;

    i=0;
    for (link*x=p;x!=NULL;x=x->next)
    {
        if (x->data==ele)
        {
            pos=i;
            cout<<"\n Search successful at index no. "<<n-pos;
            break;
        }
        i++;
    }

    if (pos==-1)
        cout<<"\n Element not found!";
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "\n Time taken by function: "<< duration.count() << " microseconds" << endl;
return 0;
}


//Binary search
#include<iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;
#define size 100

int arr[size], n, ele, pos=-1;
void sort_arr()
{
    int temp;
    for(int i=0;i<n;i++)
    {
        for (int j=i+1;j<n;j++)
        {
            if (arr[i]>arr[j])
            {
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
}

int main()
{
    auto start = high_resolution_clock::now();
    cout<<"\n Enter size of array: ";
    cin>>n;
    cout<<"\n Enter elements of array: ";
    for (int i=0;i<n;i++)
        cin>>arr[i];

    sort_arr();
    cout<<"\n Enter the element to be searched: ";
    cin>>ele;

    int first=0;
    int last=n-1;
    int mid =(int)(first+last)/2;
    while (first!=last)
    {
        int mid =(int)(first+last)/2;
        if (arr[mid]==ele)
        {
            pos=mid;
            cout<<"\n Search successful!";
            break;
        }
        else if(arr[mid]<ele)
                first=mid+1;
            else
                last=mid-1;
    }
    if (pos==-1)
        cout<<"\n Element not found!";

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "\n Time taken: "<< duration.count() << " microseconds" << endl;

return 0;
}
