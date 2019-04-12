#include <stdio.h>
#include <vector>
#include <iostream>

struct frame
{
    int frameNo;
    int pageNo;
    int counter;
};

int lru_counter(std::vector<int> ss, int noOfFrames){

    int x;
    int noOfHits = 0;
    bool pageHit;
    int noOfPgFlts = 0;
    int currCounter = 0;
    int minCounter = 0;
    int newFrameNo = 0;

    struct frame fr[noOfFrames];
    
    for(int i = 0; i < ss.size(); i++)
    {
        pageHit = false;
        ++currCounter;

        if (i < noOfFrames) {
            fr[i].frameNo = i+1;
            fr[i].pageNo = ss[i];
            fr[i].counter = currCounter;
            ++noOfPgFlts;
        }
        else
        {
            for(int j = 0; j < noOfFrames ; j++)
            {
                if (ss[i] == fr[j].pageNo) {
                    fr[j].counter = currCounter;
                    ++noOfHits;
                    pageHit = true;
                }
            }
            if (!pageHit) {
                minCounter = 10000;
                for(int j = 0; j < noOfFrames; j++)
                {
                    if (fr[j].counter < minCounter) {
                        newFrameNo = j;
                        minCounter = fr[j].counter;
                    }
                }
                // std::cout << "new frame for " << ss[i] << " is " << newFrameNo << std::endl;
                fr[newFrameNo].pageNo = ss[i];
                fr[newFrameNo].counter = currCounter;
                ++noOfPgFlts;
            }
            // This is to print frames
            // std::cout << std::endl;
            // for(int z = 0; z < noOfFrames; z++)
            // {
            //     std::cout << "Frame " << fr[z].frameNo << " -> " << fr[z].pageNo << " -> " << fr[z].counter << std::endl;
            // }
              
        }

    }
    return (noOfPgFlts - noOfFrames);/* This is to ignore initial faults for plotting graphs */
}

// int main(int argc, char const *argv[])
// {
// 	std::vector<int> v;
// 	int frames;
// 	v.push_back(2);
// 	v.push_back(3);
// 	v.push_back(2);
// 	v.push_back(1);
// 	v.push_back(5);
// 	v.push_back(2);
// 	v.push_back(4);
// 	v.push_back(5);
// 	v.push_back(3);
// 	v.push_back(2);
// 	v.push_back(5);
// 	v.push_back(2);
// 	int faults = lru_counter(v, 3);
// 	std::cout<< "No. of faults = " << faults << std::endl;
// 	return 0;
// }