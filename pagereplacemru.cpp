#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int length ,size;
    cout<<"Enter the length reference stream : ";
    cin>>length;
    cout<<"Enter the number of page frame  : ";
    cin>>size;

    vector<int>reference_string(length);

    cout<<"Enter the page reference stream :\n ";
    for(int i=0 ; i<length ; i++)
    {
        cin>>reference_string[i];
    }
    
    vector<int>pages(size,-1);   //initialize frame with -1 (empty)
    int faults=0;
    int hits=0;
    
    for(int ref_page : reference_string)
    {
        auto it = find(pages.begin(),pages.end(),ref_page);
        
        if(it != pages.end())
        {
            hits++;
            pages.erase(it); //remove page from its current position
            pages.push_back(ref_page);  //add the page at the current end
        }
        else
        {
            faults++;
            if(pages.size() >= size)
            {
                pages.pop_back();  //remove mru page
            }
            pages.insert(pages.begin(),ref_page); //add current page at front
        }
    }

    cout<<"\nTotal page hits : "<<hits;
    cout<<"\nTotal page faults :  "<<faults;

    return 0;
}

/*output
Enter the length reference stream : 14
Enter the number of page frame  : 4
Enter the page reference stream :
7
0
1
2
0
3
0
4
2
3
0
3
2
1

Total page hits : 6
Total page faults :  8
*/