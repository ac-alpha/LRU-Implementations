#include <iostream>
#include <vector>
#include <climits>

int find_page(int page_table[], int size, int req){

	int ind = -1;
	for (int i = 0; i < size; ++i)
	{
		if(page_table[i]==req){
			ind = i;
			return ind;
		}
	}

	return ind;

}

void print_page_tabe(int page_table[], int use[], int no_of_frames){

	for (int i = 0; i < no_of_frames; ++i)
	{
		std::cout << page_table[i] << "\t";
	}
	std::cout << std::endl;
	for (int i = 0; i < no_of_frames; ++i)
	{
		std::cout << use[i] << "\t";
	}
	std::cout << std::endl;

}

int lru_clock(std::vector<int> requests, int no_of_frames){

	int page_table[no_of_frames];
	int use[no_of_frames];
	for (int i = 0; i < no_of_frames; ++i)
	{
		use[i] = 0;
		page_table[i] = INT_MIN;
	}

	int size = requests.size();
	int pointer = 0;
	int ind_found = -1;
	int faults = 0;

	for (int i = 0; i < size; ++i)
	{
		ind_found = find_page(page_table, no_of_frames, requests[i]); 
		if(ind_found != -1){
			use[ind_found] = 1;
		}else{
			while(use[pointer]!=0){
				use[pointer] = 0;
				pointer = (pointer+1)%no_of_frames;
			}
			page_table[pointer] = requests[i];
			use[pointer] = 1;
			pointer = (pointer+1)%no_of_frames;
			faults += 1;
		}

		// print_page_tabe(page_table, use, no_of_frames);
	}

	return faults - no_of_frames;

}

int main(int argc, char const *argv[])
{
	std::vector<int> v;
	int frames;
	v.push_back(2);
	v.push_back(3);
	v.push_back(2);
	v.push_back(1);
	v.push_back(5);
	v.push_back(2);
	v.push_back(4);
	v.push_back(5);
	v.push_back(3);
	v.push_back(2);
	v.push_back(5);
	v.push_back(2);
	int faults = lru_clock(v, 3);
	std::cout<< "No. of faults = " << faults << std::endl;
	return 0;
}