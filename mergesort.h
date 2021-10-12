#include <iostream>
#include <vector>

template <typename T> void mergeSortInOrder(std::vector<T>& data, 
                                    unsigned int leftNum, 
                                    unsigned int midNum, 
                                    unsigned int rightNum) {
   int position = 0;
   int leftHalf = leftNum;                  
   int rightHalf = midNum + 1;    
   int mergedLeftRight = rightNum - leftNum + 1;    

   std::vector<T> mergedData(mergedLeftRight);

   while (leftHalf <= midNum && rightHalf <= rightNum) {
      if (data.at(leftHalf) < data.at(rightHalf)) {
         mergedData.at(position) = data.at(leftHalf);
         ++leftHalf;
         ++position;
      }
      else {
         mergedData.at(position) = data.at(rightHalf);
         ++rightHalf;
         ++position;
      }
   }

   while (leftHalf <= midNum) {
      mergedData.at(position) = data.at(leftHalf);
      ++leftHalf;
      ++position;
   }
   
   while (rightHalf <= rightNum) {
      mergedData.at(position) = data.at(rightHalf);
      ++rightHalf;
      ++position;
   }

   for (int i = 0; i < mergedLeftRight; ++i) {
      data.at(leftNum + i) = mergedData.at(i);
   }

}


template <typename T> void mergeSort(std::vector<T>& data, 
                                       unsigned int firstToSort, 
                                       unsigned int lastToSort) {
   
   if (firstToSort < lastToSort) {
      int findMidPoint = (lastToSort + firstToSort) / 2;
      
      mergeSort(data, firstToSort, findMidPoint);
      mergeSort(data, findMidPoint + 1, lastToSort);
      
      mergeSortInOrder(data, firstToSort, findMidPoint, lastToSort);
   }
}