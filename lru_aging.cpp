#include <iostream>
#include <vector>
#include <stdio.h>
#include <math.h>

int find_page_in_frames(int frames[], int aging_regs[], int page_num, int num_frames, int history) {
  for(int i = 0; i < num_frames; i++) {
    aging_regs[i] = aging_regs[i]>>1;
  }
  for(int i = 0; i < num_frames; i++) {
    // If found = HIT
    if(frames[i] == page_num) {
      aging_regs[i] += pow(2, history);
      return i;
    }
  }
  // If not found = MISS
  return -1;
}

// Called in case of a MISS
int replace(int frames[], int aging_regs[], int new_page, int num_frames, int history) {
  int min_idx = 0;
  int min = aging_regs[min_idx];
  for(int i = 0; i < num_frames; i++) {
    if(aging_regs[i] < min){
      min_idx = i;
      min = aging_regs[min_idx];
    }
  }

  frames[min_idx] = new_page;
  aging_regs[min_idx] += pow(2, history);

  return min_idx;
}

void print_regs(int aging_regs[], int num_frames) {
  printf("Registers values now :\n");
  for(int i = 0; i < num_frames; i++) {
    printf("      %d\n", aging_regs[i]);
  }
}

void print_frame_state(int frames[], int num_frames) {
  printf("Current values in frames are :\n");
  for(int i = 0; i < num_frames; i++) {
    printf("      %d\n", frames[i]);
  }
}

int main() {
  int num_frames = 6;
  int history = 10;
  int frames[num_frames] = {0};
  int requests_length = 15;

  // pages in memory :
  //   a: 1
  //   b: 2
  //   c: 3
  //    ....
  //   and so on...
  // request array consists of page indexes referenced
  int requests[requests_length] = {3, 5, 1, 6, 3, 6, 8, 1, 4, 9, 2, 7, 7, 9, 5};

  int aging_regs[num_frames] = {0};
  int page_faults = 0;
  int index = 0;

  for (int j = 0; j < requests_length; j++) {
    index = find_page_in_frames(frames, aging_regs, requests[j], num_frames, history);
    if (index == -1) {
      page_faults++;
      int replaced_frame_idx = replace(frames, aging_regs, requests[j], num_frames, history);
      printf("We replaced %d\n", replaced_frame_idx);
    } else {
      printf("We replaced nothing !\n");
    }
    print_frame_state(frames, num_frames);
    print_regs(aging_regs, num_frames);
  }
  printf("%d\n", page_faults);

  return 0;
}
