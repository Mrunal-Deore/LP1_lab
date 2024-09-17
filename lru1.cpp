#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<climits>
#include<vector>
using namespace std;
const int N=100005;

int n;
int frame_size;
int pages[N];

void mru_page_replacement(vector<int>& pages, int frameCount )
{
      int page_faults=0;
      unordered_map<int>pagetoframe;
      vector<int>framequeue;

      int pagehits =0;
      int pagemisses =0;

      for(int page: pages)
      {
        if(pagetoframe.find(page) != pagetoframe.end())
        {
            pagehits++;
            int frameindex = pagetoframe[pages];
            framequeue.erase(framequeue.begin() + frameindex);
            framequeue.insert(framequeue.begin(),pages);
            for(int i=0 ; i<framequeue.size() ; ++i)
            {
                pagetoframe[framequeue[i]] = i;
            }
        }
        else
        {
           pagemisses++;
           if(framequeue.size() == frameCount)
           {
            int mostrecentpage = framequeue.front();
            pagetoframe.erase(mostrecentpage);
            framequeue.pop_back();
           }
           framequeue.insert(framequeue.begin(),pages);
           pagetoframe[pages] = 0;  
        }
    }
      cout<<"MRU page replacement algorithm - page hits : "<<pagehits<<" and page misses : "<<pagemisses;
}

int main()
{
    cout<<"\nEnter frame size : ";
    cin>>frame_size;

    cout<<"\nEnter length of page reference stream : ";
    cin>>n;

    cout<<"\nEnter pages :\n";
    for(int i =0 ; i<n ; i++)
    {
        cin>>pages[i];
    }

    mru_page_replacement(vector<int>& pages, int frameCount);

    return 0;

}