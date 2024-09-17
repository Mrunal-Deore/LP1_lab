#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<climits>
using namespace std;
const int N=100005;

int n;
int frame_size;
int pages[N];

void lru_page_replacement()
{
	unordered_set<int>s;
	unordered_map<int,int>indexes;
	
	int page_faults=0;
	for(int i=0;i<n;i++)
	{
		 if(s.find(pages[i])!=s.end()) {
		 	cout<<"Reference to page " << pages[i] <<" did not cause a page fault\n"; //page hit
		 }
		 else
		 {
		 	if(s.size()<frame_size)
		 	{
		 		s.insert(pages[i]);
		 		page_faults++;
			 }
			 else
			 {
			 	int lru = INT_MAX ,val;
			 	for(int i : s) {
			 		if(indexes[i]<lru) {
			 			lru=indexes[i];
			 			val=i;
					}
				}
				
                s.erase(val);
				s.insert(pages[i]);
				page_faults++;
			}
			cout<<"Reference to page "<<pages[i]<<" caused a page fault\n";   //page miss
		}
		indexes[pages[i]]=i;
	}
	cout<<"\nTotal Miss : "<<page_faults;
    cout<<"\nTotal Hit : "<<(n-page_faults);
}
int main()
{
	cout<<"Number of frames : ";
	cin>>frame_size;
	cout<<"Page reference stream length : ";
	cin>>n;
	
	cout<<"Page reference stream :\n";
	for(int i=0;i<n;i++)
	{
		cin>>pages[i];
	}
		lru_page_replacement();
		return 0;
}

/*OUTPUT
Number of frames : 4
Page reference stream length : 14
Page reference stream :
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
Reference to page 7 caused a page fault
Reference to page 0 caused a page fault
Reference to page 1 caused a page fault
Reference to page 2 caused a page fault
Reference to page 0 did not cause a page fault
Reference to page 3 caused a page fault
Reference to page 0 did not cause a page fault
Reference to page 4 caused a page fault
Reference to page 2 did not cause a page fault
Reference to page 3 did not cause a page fault
Reference to page 0 did not cause a page fault
Reference to page 3 did not cause a page fault
Reference to page 2 did not cause a page fault
Reference to page 1 caused a page fault

Total Miss : 7
Total Hit : 7
*/