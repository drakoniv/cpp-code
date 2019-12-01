#include "canvas.h"

#include <iostream>

using namespace std;

/**
* Append to the bottom.
*
* @param canvas: a canvas pointer
* @param patch: a patch pointer
*/
void append_to_bottom(Canvas *canvas, Patch *patch)
{
    PatchNode* insNode = new PatchNode;
    insNode->above = nullptr;
    insNode->below = nullptr;
    insNode->patch = patch;
    if(canvas->top == nullptr) {
        canvas->top = canvas->bottom = insNode;
    } else{
        insNode->above = canvas->bottom;
        canvas->bottom->below = insNode;
        while(canvas->bottom->below != nullptr) {
            canvas->bottom = canvas->bottom->below;
        }
    }
}

/**
* Delete the canvas and the resources owned by it.
*
* @param canvas, a canvas pointer.
*/
void clear(Canvas *&canvas)
{
    PatchNode* currentPtr = nullptr;
    if (canvas->top == nullptr) {
        return;
    } else {
        while(canvas->top != nullptr) {
            currentPtr = canvas->top;
            clear(currentPtr->patch);
            canvas->top = canvas->top->below;
            delete currentPtr;
            currentPtr = nullptr;
        }
        canvas->bottom = nullptr;
        canvas->top = nullptr;
        delete canvas;
        canvas = nullptr;
    }
}

/**
* Render the canvas to a buffer without border. Selected patch will be hightlighted as '@'.
*
* @param canvas, a canvas pointer.
* @return buffer, a height x width 2d array, required by the provided print function.
*/
char **render(const Canvas *canvas)
{
    char **buffer = new char *[canvas->height];
    for (int i = 0; i < canvas->height; i++) {
        buffer[i] = new char[canvas->width];
    }
	for (int i = 0; i < canvas->height; i++) {
		for (int j = 0; j < canvas->width; j++) {
			buffer[i][j] = ' ';
		}
	}
    PatchNode *currPtr = canvas->top;
	//forward traverse
	while(currPtr->below != nullptr) {
	    currPtr = currPtr->below;
	}
    //reverse traverse
    while (currPtr != nullptr) {
        // set initial patch x
        int x = currPtr->patch->x;
        // loop thru patch
        for (const Line *l = currPtr->patch->head; l; l = l->next) {
            // set y patch position
            int y= currPtr->patch->y;
            for (char c: l->data) {
                //loop thru string
                if(x>=0 && y>=0 &&y < canvas->width && x < canvas->height) {
                   
					if (canvas->selected != nullptr && (canvas->selected == currPtr)&& c != ' ') {
						buffer[x][y] = '@';
					} else if(c != ' ') {
                        buffer[x][y] = c;
                    }
                }
                y++;
            }
            x++;
        }
        currPtr = currPtr->above;
    }
    
    return buffer;
}

/**
* Bring the selected patch node above by one node, do nothing if not applicable.
*
* @param canvas, a canvas pointer.
*/
void bring_selected_above(Canvas *canvas)
{
    if(canvas->selected != nullptr ){
        if(canvas->selected->above != nullptr){
            PatchNode* above = canvas->selected->above;
            PatchNode* below = canvas->selected->below;
            canvas->selected->above = above->above;
			if(above->above != nullptr)
            above->above->below = canvas->selected;

            canvas->selected->below = above;
            above->above = canvas->selected;
            above->below = below;

            if(below!= nullptr)
            below->above = above;
        }
    }
    while(canvas->top->above != nullptr) {
        canvas->top = canvas->top->above;
    }
        while(canvas->bottom->below != nullptr){
            canvas->bottom = canvas->bottom->below;
        }
}

/**
* Send the selected patch node below by one node, do nothing if not applicable.
*
* @param canvas, a canvas pointer.
*/
void send_selected_below(Canvas *canvas)
{
    if(canvas->selected != nullptr ){
        if(canvas->selected->below != nullptr){
            PatchNode* above = canvas->selected->above;
            PatchNode* below = canvas->selected->below;
            canvas->selected->below = below->below;
            if(below->below != nullptr)
            below->below->above = canvas->selected;

            canvas->selected->above = below;
            below->below = canvas->selected;
            if(above != nullptr)
            above->below = below;

            below->above = above;
        }
    }
    while(canvas->bottom->below != nullptr){
        canvas->bottom = canvas->bottom->below;
    }
    while(canvas->top->above != nullptr){
        canvas->top = canvas->top->above;
    }
}

/**
* Select the top patch among the patches that covers (x, y). A patch conver a position means it has an non-transparant character on it. Selection of out of bound position should be allowed, despite that the position is not rendered.
*
* @param canvas, a canvas pointer.
* @param x, canvas row to select.
* @param y, canvas column to select.
*/
void select_at(Canvas *canvas, int x, int y)
{
    PatchNode* currPtr = canvas->top;
}

/**
* Erase all characters at (x, y) until there is no non-transparant character on (x, y). If a patch node contains no non-transparant character after the erasing, it will be deleted. Erasing of out of bound position should be allowed, despite that the position is not rendered.
*
* @param canvas, a canvas pointer.
* @param x, canvas row to erase.
* @param y, canvas column to erase.
*/
void erase_pixel_at(Canvas *canvas, int x, int y)
{

}