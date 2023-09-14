#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>

int main( void )
{
    std::cout << "________________________________________" << std::endl;
    std::vector<int>            vect;
    std::vector<int>::iterator  vectIter;
    int                         i;

    vect.push_back(10);
    vect.push_back(15);
    vect.push_back(3);
    vect.push_back(42);

    std::cout << "Vector: \t";
    for (i = 0; i < (int)vect.size(); i++)
        std::cout << "[" << vect.at(i) << "] ";
    std::cout << std::endl;

    std::cout << "easyfind: " << std::endl;
    std::cout << " (trying to find value 42 in Vector)" << std::endl;
    try {
        vectIter = easyfind(vect, 42);
        std::cout << "\tFind: [" << *vectIter << "]" << " at index " << std::distance(vect.begin(), vectIter) << std::endl;
    } catch(std::exception &e){
 		std::cout << "\tException: \t" << e.what() <<std::endl;
 	}
    std::cout << " (trying to find value 505 in Vector)" << std::endl;
    try {
        vectIter = easyfind(vect, 505);
        std::cout << "\tFind: [" << *vectIter << "]" << " at index " << std::distance(vect.begin(), vectIter) << std::endl;
    } catch(std::exception &e){
 		std::cout << "\tException: " << e.what() <<std::endl;
 	}

    std::cout << "________________________________________" << std::endl;
    std::list<int>            list;
    std::list<int>::iterator  listIter;

    list.push_back(3);
    list.push_back(42);
    list.push_front(15);
    list.push_front(10);

    listIter = list.begin();
    std::cout << "List: \t\t";
    while (listIter != list.end())
        std::cout << "[" << (*listIter++) << "] ";
    std::cout << std::endl;

    std::cout << "easyfind: " << std::endl;
    std::cout << " (trying to find value 42 in List)" << std::endl;
    try {
        listIter = easyfind(list, 42);
        std::cout << "\tFind: [" << *listIter << "]" << " at index " << std::distance(list.begin(), listIter) << std::endl;
    } catch(std::exception &e){
 		std::cout << "\tException: \t" << e.what() <<std::endl;
 	}
    std::cout << " (trying to find value 505 in List)" << std::endl;
    try {
        listIter = easyfind(list, 505);
        std::cout << "\tFind: [" << *listIter << "]" << " at index " << std::distance(list.begin(), listIter) << std::endl;
    } catch(std::exception &e){
 		std::cout << "\tException: " << e.what() <<std::endl;
 	}

    std::cout << "________________________________________" << std::endl;

    std::deque<int>                     doubleEndedQueue;
    std::deque<int>::iterator           doubleEndedQueueIter;
    std::deque<int>::const_iterator     doubleEndedQueueConstIter;

    doubleEndedQueue.push_back(33);
    doubleEndedQueue.push_back(505);
    doubleEndedQueue.push_back(22);
    doubleEndedQueue.push_back(3901);

    i = 0;
    std::cout << "Deque: \t\t";
    while (i != (int)doubleEndedQueue.size())
        std::cout << "[" << doubleEndedQueue.at(i++) << "] ";
    std::cout << std::endl;

    std::cout << "easyfind: " << std::endl;
    std::cout << " (trying to find value 42 in Deque)" << std::endl;
    try {
        doubleEndedQueueIter = easyfind(doubleEndedQueue, 42);
        std::cout << "\tFind: [" << *doubleEndedQueueIter << "]" << " at index " << std::distance(doubleEndedQueue.begin(), doubleEndedQueueIter) << std::endl;
    } catch(std::exception &e){
 		std::cout << "\tException: \t" << e.what() <<std::endl;
 	}
    std::cout << " (trying to find value 505 in Deque)" << std::endl;
    try {
        doubleEndedQueueIter = easyfind(doubleEndedQueue, 505);
        std::cout << "\tFind: [" << *doubleEndedQueueIter << "]" << " at index " << std::distance(doubleEndedQueue.begin(), doubleEndedQueueIter) << std::endl;
    } catch(std::exception &e){
 		std::cout << "\tException: " << e.what() <<std::endl;
 	}
    std::cout << " (trying to find value 404 in Deque)" << std::endl;
    try {
        doubleEndedQueueConstIter = easyfind(doubleEndedQueue, 404);
        std::cout << "\tFind: [" << *doubleEndedQueueIter << "]" << std::endl;
    } catch(std::exception &e){
 		std::cout << "\tException: " << e.what() <<std::endl;
 	}
    std::cout << " (trying to find value 33 in Deque)" << std::endl;
    try {
        doubleEndedQueueConstIter = easyfind(doubleEndedQueue, 33);
        std::cout << "\tFind: [" << *doubleEndedQueueConstIter << "]" << std::endl;
    } catch(std::exception &e){
 		std::cout << "\tException: " << e.what() <<std::endl;
 	}

    std::cout << "________________________________________" << std::endl;
    const std::vector<int>            constVect(10, 2);
    std::vector<int>::const_iterator  constVectIter;

    std::cout << "Const Vector: \t";
    for (i = 0; i < (int)constVect.size(); i++)
        std::cout << "[" << constVect.at(i) << "] ";
    std::cout << std::endl;

    std::cout << "easyfind: " << std::endl;
    std::cout << " (trying to find value 2 in Const Vector)" << std::endl;
    try {
        constVectIter = easyfind(constVect, 2);
        std::cout << "\tFind: [" << *constVectIter << "]" << std::endl;
    } catch(std::exception &e){
 		std::cout << "\tException: \t" << e.what() <<std::endl;
 	}
    std::cout << " (trying to find value 505 in Const Vector)" << std::endl;
    try {
        constVectIter = easyfind(constVect, 505);
        std::cout << "\tFind: [" << *constVectIter << "]" << std::endl;
    } catch(std::exception &e){
 		std::cout << "\tException: " << e.what() <<std::endl;
 	}

    std::cout << "________________________________________" << std::endl;
    
    return 0;
}
