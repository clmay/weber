#include <iostream>
using namespace std;

#include "PlaylistNode.h"

/*
 * ===  FUNCTION  ======================================================================
 *         Name:  PlaylistNode
 *  Description:  Default Constructor
 *  Set all strings to "none"
 *  Set integers to 0
 *  Set pointers to 0
 *  Hint: Remember to use the: "this->" pointer to access the object's data members
 * =====================================================================================
 */

PlaylistNode::PlaylistNode()
{
    this->uniqueID = "none";
    this->songName = "none";
    this->artistName = "none";
    this->songLength = 0;
    this->nextNodePtr = nullptr;
}

/*
 * ===  FUNCTION  ======================================================================
 *         Name:  PlaylistNode
 *  Description:  Constructor with parameters
 *  Set all strings to input params
 *  Set integers to input params
 *  Set pointers to input params
 *  Hint: Remember to use the: "this->" pointer to access the object's data members
 * =====================================================================================
 */

PlaylistNode::PlaylistNode(string initID, string initSongName,
                           string initArtistName, int initSongLength, PlaylistNode* nextLoc)
{
    this->uniqueID = initID;
    this->songName = initSongName;
    this->artistName = initArtistName;
    this->songLength = initSongLength;
    this->nextNodePtr = nextLoc;
}

/*
 * ===  FUNCTION  ======================================================================
 *         Name:  InsertAfter
 *  Description:  Insert a node after the last node. Connect the newly created node
 *  to the end of the list.
 * =====================================================================================
 */

void PlaylistNode::InsertAfter(PlaylistNode* nodePtr)
{
    PlaylistNode* tmpNext = nullptr;
    tmpNext = this->nextNodePtr;
    this->nextNodePtr = nodePtr;
    nodePtr->nextNodePtr = tmpNext;
}

/*
 * ===  FUNCTION  ======================================================================
 *         Name:  SetNext
 *  Description:  Setter the nextNodePtr.
 * =====================================================================================
 */

void PlaylistNode::SetNext(PlaylistNode* nodePtr)
{
    this->nextNodePtr = nodePtr;
}

/*
 * ===  FUNCTION  ======================================================================
 *         Name:  GetID
 *  Description:  Getter for uniqueID
 * =====================================================================================
 */

string PlaylistNode::GetID() const
{
    return this->uniqueID;
}

/*
 * ===  FUNCTION  ======================================================================
 *         Name:  GetSongName
 *  Description:  Getter for songName
 * =====================================================================================
 */

string PlaylistNode::GetSongName() const
{
    return this->songName;
}

/*
 * ===  FUNCTION  ======================================================================
 *         Name:  GetArtistName
 *  Description:  Getter for artistName
 * =====================================================================================
 */

string PlaylistNode::GetArtistName() const
{
    return this->artistName;
}

/*
 * ===  FUNCTION  ======================================================================
 *         Name:  GetSongLength
 *  Description:  Getter for songLength
 * =====================================================================================
 */

int PlaylistNode::GetSongLength() const
{
    return this->songLength;
}

/*
 * ===  FUNCTION  ======================================================================
 *         Name:  GetNext
 *  Description:  Getter for nextNodePtr
 * =====================================================================================
 */

PlaylistNode* PlaylistNode::GetNext() const
{
    return this->nextNodePtr;
}

/*
 * ===  FUNCTION  ======================================================================
 *         Name:  PrintPlaylistNode
 *  Description:  Print Playlist Description
 * =====================================================================================
 */

void PlaylistNode::PrintPlaylistNode()
{
    cout << "Unique ID: " << this->uniqueID << endl;
    cout << "Song Name: " << this->songName << endl;
    cout << "Artist Name: " << this->artistName << endl;
    cout << "Song Length (in seconds): " << this->songLength << endl;
    
}