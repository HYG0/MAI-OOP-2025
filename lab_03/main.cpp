#include <iostream>
#include <string>
#include "custom_memory.h"
#include "array.h"

CustomMemoryResource resource;
DynamicArray<Person> people(&resource);

CustomMemoryResource resource;
DynamicArray<Person> people(&resource);

int main() {
    CustomMemoryResource resource;
    DynamicArray<Person> people(&resource);
    
    people.push_back(Person(1, "Егор", 28.04));
    people.push_back(Person(2, "Витя", 05.06));
    people.push_back(Person(3, "Маша", 11.09));
    
    std::cout << "Сотрудники:" << "\n";
    for (auto it = people.begin(); it != people.end(); ++it) {
        std::cout << *it << "\n";
    }
    
    std::cout << "Размер массива: " << people.size() << "\n";
    
    people.pop_back();
    std::cout << "\n";
    std::cout << "После удаления сотрудника:" << "\n";
    for (auto it = people.begin(); it != people.end(); ++it) {
        std::cout << *it << "\n";
    }

    std::cout << "Размер массива: " << people.size() << "\n";
    std::cout << "\n";

    {
        DynamicArray<Person> arr1(&resource);
        arr1.push_back(Person(4, "Илья", 10.09));
        arr1.push_back(Person(5, "Сергей", 30.07));
        std::cout << "Создан первый массив с элементами: \n";
        for (auto it = arr1.begin(); it != arr1.end(); ++it) {
            std::cout << *it << "\n";
        }
        std::cout << "\n";
    }
    // arr1 уничтожается, память освобождается

    {
        DynamicArray<int> arr2(&resource);
        arr2.push_back(300);
        arr2.push_back(400);
        std::cout << "Создан второй массив, который уже переиспользует память: ";
        for (auto it = arr2.begin(); it != arr2.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << "\n";
    }
    
    return 0;
}