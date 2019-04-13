#include <iostream>
#include <vector>

#include "lru_clock.cpp"
#include "lru_stack.cpp"
#include "lru_counter.cpp"
#include "lru_aging.cpp"

int main(int argc, char const *argv[])
{
	std::cout << "===LRU Page Replacement Algorithm Implementation===" << std::endl;
	std::cout << "Enter the length of request string : ";
	int len_req;
	std::cin >> len_req;
	int choice;
	std::cout << "Enter the LRU Implementation to be used (1:counter  2:stack  3:aging  4:clock) : ";
	std::cin >> choice;
	int no_of_frames;
	std::cout << "Enter the number of frames to be used : ";
	std::cin >> no_of_frames;
	std::cout << "Enter the request string (Each entry followed by enter) : " << std::endl;
	int elem;
	std::vector<int> req_vec;
	int req_arr[len_req];
	for (int i = 0; i < len_req; ++i){
		
		std::cin >> elem;
		req_arr[i] = elem;
		req_vec.push_back(elem);

	}
	int faults;
	switch(choice) {

		case 1:
			faults = lru_counter(req_vec, no_of_frames);
			break;
		case 2:
			faults = lru_stack(req_arr, no_of_frames, len_req);
			break;
		case 3:
			faults = lru_aging(req_arr, no_of_frames, 16, len_req);
			break;
		case 4:
			faults = lru_clock(req_vec, no_of_frames);
			break;
		default:
			std::cout << "Wrong Choice Selected!!" << std::endl;
			return 1;
			break;
	}

	std::cout << "Number of Page Faults generated : " << faults << std::endl;

	return 0;
}