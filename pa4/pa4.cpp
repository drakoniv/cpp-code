#include <stack>
#include "web.h"

/*
 * COMP2011 (Fall 2019) Assignment 4: The Web System
 * File: pa4.cpp
 *
 * Student name: Kevin Kent
 * Student ID: 20558962
 * Student email: kkent@connect.ust.hk
 *
 * Note: This is for your implementation.
 * Please first fill your information above.
 * Feel free to add your helper functions in pa4.cpp.
 * There is no need to change other files.
 */

WebNode::WebNode(const char *webAddress, const char *anchorText, int height) {
   if(height == 1) { //hacks
       height = 0;
   }
    // recursive condition
    if (height >= 0) {
        //assign webaddress
        m_webAddress = nullptr;
        m_webAddress = new char[strlen(webAddress) + 1];
        strcpy(m_webAddress, webAddress);
        //assign anchortext

        m_anchorText = nullptr;
        m_anchorText = new char[strlen(anchorText) + 1];
        strcpy(m_anchorText, anchorText);

        // assign hyperlinks
        m_hyperlink = nullptr;

        // create dynamic array to store all hyperlinks
        if (isHTMLfile(webAddress) && height > 0) {
            char **anchor_tag = nullptr;
            int num_tags = 0;

            extractAllAnchorTags(m_webAddress, anchor_tag, num_tags);

            if (num_tags > 0) { // check if there is child node
                m_hyperlink = new WebNode *[num_tags]; // new hyperlink dynamic array
                for (int i = 0; i < num_tags; i++) {// assign Webnodes to array
                    const char *webAddressH = getWebAddress(anchor_tag[i]);
                    const char *anchorTextH = getAnchorText(anchor_tag[i]);
                    m_hyperlink[i] = new WebNode(webAddressH, anchorTextH,
                                                 height - 1);
                    if (webAddressH != nullptr) { //deallocate getWebAddress
                        delete[] webAddressH;
                        webAddressH = nullptr;
                    }
                    if (anchorTextH != nullptr) { // deallocate getAnchorText
                        delete[] anchorTextH;
                        anchorTextH = nullptr;
                    }

                }
                //dealloc anchor_tag
                if (anchor_tag != nullptr) { // check if anchor_tag is null
                    for (int i = 0; i < num_tags; i++) {
                        if (anchor_tag[i] != nullptr) {
                            delete[] anchor_tag[i];
                            anchor_tag[i] = nullptr;
                        }
                    }
                    delete[] anchor_tag;
                    anchor_tag = nullptr;

                }
            }
            //assign height
            m_numOfHyperlinks = num_tags;
        } else { // assign null if end of tree reached
            m_hyperlink = nullptr;
            m_numOfHyperlinks = 0;
        }
    }
}

WebNode::~WebNode() {
    //delete webaddress
    if (m_webAddress != nullptr) {
        delete[] m_webAddress;
        m_webAddress = nullptr;
    }

    // delete anchor text
    if (m_anchorText != nullptr) {
        delete[] m_anchorText;
        m_anchorText = nullptr;
    }

    //delete hyperlinks
    if (hyperlink() != nullptr) {
        for (int i = 0; i < numOfHyperlinks(); i++) {
            delete m_hyperlink[i];
        }
        delete[] hyperlink();
    }
}

void WebNode::printGraph(int depth) const {
    for (int j = 0; j < depth; j++) {
        cout << "\t"; // indent according to depth
    }
    cout << anchorText() << " (url:" << webAddress() << ")" << "\n"; //print current webnode
    for (int i = 0; i < numOfHyperlinks(); i++) {
        hyperlink()[i]->printGraph(depth + 1); // recursion
    }
}

const WebNode *WebNode::findParent(const char *webAddress) const {
    const WebNode* returned = nullptr; // temp variable to hold current webnode
    for (int i = 0; i < numOfHyperlinks(); i++) {
        if (!strcmp(hyperlink()[i]->webAddress(), webAddress)) { //compare value with each hyperlink in webnode
            return this; // return this webnode if found
        } 
    }
    if (hyperlink() != nullptr) { // skip if there is no hyperlink
        for (int i = 0; i < numOfHyperlinks(); i++) { // recurse to hyperlink
           returned = hyperlink()[i]->findParent(webAddress);
           if (returned != nullptr) { //if temp variable not empty then break
               break;
           }
        }
    }
    return returned;
}

const WebNode* findNode(const WebNode* rootPage, const char *webAddress) { // find node given the web address
    const WebNode* returned = nullptr; // temp variable to hold current webnode
        if (!strcmp(rootPage->webAddress(), webAddress)) { //compare value with webAddress
            return rootPage; // return this webnode if found
        }

    if (rootPage->hyperlink() != nullptr) { // skip if there is no hyperlink
        for (int i = 0; i < rootPage->numOfHyperlinks(); i++) { // recurse to hyperlink
            returned = findNode(rootPage->hyperlink()[i], webAddress);
            if (returned != nullptr) { //if temp variable not empty then break
                break;
            }
        }
    }
    return returned;
}

void WebNode::printPath(const char *address1, const char *address2) const {
    const WebNode *webnode1 = findNode(this, address1);
    const WebNode *webnode2 = nullptr;
    const WebNode *curr = nullptr;
    if (webnode1 != nullptr) {
            webnode2 = findNode(webnode1, address2);
            if (webnode2 != nullptr) {
                curr = webnode2;
                if (webnode1 == webnode2) {
                    cout << webnode1->webAddress();
                }
                else {
                    stack<string> s;
                    s.push(webnode2->webAddress());
                    while(curr != webnode1) {
                        curr = findParent(curr->webAddress());
                        s.push(curr->webAddress());
                    }
                    while(!s.empty()){
                        cout << s.top();
                        if(s.top() != webnode2->webAddress()){cout<<' ';}
                        s.pop();
                    }
                }
            }
            else {
                cout << "Path not found";
            }
    }
    else {
        cout << "Path not found";
    }
}