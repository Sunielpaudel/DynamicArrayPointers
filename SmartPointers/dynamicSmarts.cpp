#include<iostream>

namespace dynamicSmart {
    void smartPointers() {

        std::unique_ptr<int[]> arr = std::make_unique<int[]>(1);
        int num;
        int size = 0;
        int capacity = 1;
        int sum = 0;

        std::cout << "Enter numbers (-1 to stop): " << std::endl;

        while (true) {
            std::cin >> num;

            if (num == -1) {
                break;
            }
            if (size == capacity) {

                capacity *= 2;

                std::unique_ptr<int[]> temp = std::make_unique<int[]>(capacity);


                for (int i = 0; i < size; i++) {
                    temp[i] = arr[i];
                }
                arr = move(temp);
            }
            arr[size] = num;
            size++;
        }
        for (int i = 0; i < size; i++) {
            sum += arr[i];
        }

        std::cout << "Sum of the numbers: " << sum << std::endl;
    }
}