#include "patch.h"

#include <cstring>
#include <iostream>
using namespace std;

/**
* Append a new line to the tail.
*
* @param patch: a patch pointer
* @param line: a line pointer
*/
void append_to_bottom(Patch *patch, Line *line)
{

        //insert line to head an tail if there is no item
        if (patch->head == nullptr) {
            patch->head = patch->tail = line;
        } else {
            //insert new line to end of linked list
            patch->tail->next = line;
            //assign tail to new line
            while (patch->tail->next != nullptr) {
                patch->tail = patch->tail->next;
            }
        }
}

/**
* Delete the patch and the resources owned by it.
*
* @param patch, a patch pointer.
*/
void clear(Patch *&patch)
{
    if(patch!= nullptr) {
        Line *currentPtr = patch->head;
        if (patch->head == nullptr) {
            delete patch;
            patch = nullptr;
            return;
        } else {
            while (patch->head != nullptr) {
                currentPtr = patch->head;
                patch->head = patch->head->next;
                delete currentPtr;
                currentPtr = nullptr;
            }

            patch->tail = nullptr;
            patch->head = nullptr;
            delete patch;
            patch = nullptr;
        }
    }
}

/**
* Reverse the linked list of lines.
*
* @param patch, a patch pointer.
*/
void reverse(Patch *patch)
{
    if(patch != nullptr) {
        Line *currentPtr = patch->head;
        Line *nextPtr = nullptr;
        Line *prevPtr = nullptr;
        while (currentPtr != nullptr) {
            nextPtr = currentPtr->next;
            currentPtr->next = prevPtr;
            prevPtr = currentPtr;
            currentPtr = nextPtr;
        }
        patch->head = prevPtr;
        while (patch->tail->next != nullptr) {
            patch->tail = patch->tail->next;
        }
    }
}