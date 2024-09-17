#include<iostream>
#include<vector>
using namespace std;
const int N = 100005;

int n ;
int frame_size;
int pages[N];

void optimal_page_replacement()
{
    vector<int>fr;
    int page_faults = 0 ;
    for(int i=0 ; i<n ; i++)
    {
        int k;
        for( k=0 ; k<fr.size() ; k++)
        {
            if(fr[k] == pages[i])
            {
                break;
            }
            if( k == fr.size())
            {
                if(fr.size() < frame_size)
                {
                    fr.push_back(pages[i]);
                }
                else
                {
                    int index = i+1;
                    int res = -1 , farthest = index;
                    for(int i=0 ; i < fr.size() ; i++)
                    {
                        int j;
                        for( j=index ; j<n ; j++)
                        {
                            if(fr[i] == pages[i])
                            {
                                if( j > farthest)
                                {
                                    farthest = j;
                                    res = i;
                                }
                                break;
                            }
                        }
                        if( j == n )
                        {
                            res = i;
                            break;
                        }
                    }
                    fr[res] = pages[i];
                }
                page_faults++;
                cout<<"Reference to page "<<pages[i]<<" caused a page fault\n";
            }
            else
            {
                cout<<"Reference to page "<<pages[i]<<" did not cause a page fault\n";
            }
        }
    }
    cout<<"\nTotal page fault : "<<page_faults;
    cout<<"\nTotal page hit : "<<(n-page_faults);
}
int main()
{
    cout<<"Number of frames : ";
    cin>>frame_size;
    cout<<"Page reference stream length : ";
    cin>>n;

    cout<<"Page reference stream : ";
    for(int i=0 ; i<n ; i++)
    {
        cin>>pages[i];
    }

    optimal_page_replacement();
    return 0;
}