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
    return noOfPgFlts;
}

// int main(){

//     int noOfFrames, x;
//     int noOfHits = 0;
//     bool pageHit;
//     int noOfPgFlts = 0;
//     int currCounter = 0;
//     int minCounter = 0;
//     int newFrameNo = 0;
//     std::vector<int> ss;

//     std::cout << "Input for no. of frames in memory : ";
//     std::cin >> noOfFrames;
//     struct frame fr[noOfFrames];

//     std::cout << "Enter the sequence string (input any non-integer value to stop) : ";
//     while(std::cin >> x){
//         ss.push_back(x);
//     }
    
//     for(int i = 0; i < ss.size(); i++)
//     {
//         pageHit = false;
//         ++currCounter;

//         if (i < noOfFrames) {
//             fr[i].frameNo = i+1;
//             fr[i].pageNo = ss[i];
//             fr[i].counter = currCounter;
//             ++noOfPgFlts;
//         }
//         else
//         {
//             for(int j = 0; j < noOfFrames ; j++)
//             {
//                 if (ss[i] == fr[j].pageNo) {
//                     fr[j].counter = currCounter;
//                     ++noOfHits;
//                     pageHit = true;
//                 }
//             }
//             if (!pageHit) {
//                 minCounter = 10000;
//                 for(int j = 0; j < noOfFrames; j++)
//                 {
//                     if (fr[j].counter < minCounter) {
//                         newFrameNo = j;
//                         minCounter = fr[j].counter;
//                     }
//                 }
//                 // std::cout << "new frame for " << ss[i] << " is " << newFrameNo << std::endl;
//                 fr[newFrameNo].pageNo = ss[i];
//                 fr[newFrameNo].counter = currCounter;
//                 ++noOfPgFlts;
//             }
//             std::cout << std::endl;
//             for(int z = 0; z < noOfFrames; z++)
//             {
//                 std::cout << "Frame " << fr[z].frameNo << " -> " << fr[z].pageNo << " -> " << fr[z].counter << std::endl;
//             }
              
//         }

//     }
//     std::cout << "\nNo of page Faults " << noOfPgFlts << std::endl;
//     return 0;
// }