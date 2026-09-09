#include <iostream>
#include <string>

// // 1. Node structure storing student information
// struct Node
// {
//     int id;
//     std::string name;
//     std::string major;
//     Node *next;
// };
// Node *head = nullptr;

// // 2. Insert at the Beginning
// void insertAtBeginning(int ID, std::string name, std::string major)
// {
//     Node *newNode = new Node();
//     newNode->id = ID;
//     newNode->name = name;
//     newNode->major = major;
//     newNode->next = head;
//     head = newNode;
// }

// // 3. Count Nodes
// int count()
// {
//     int Count = 0;
//     Node *current = head;
//     while (current != nullptr)
//     {
//         Count++;
//         current = current->next;
//     }
//     return Count;
// }

// // 4. Search for a Value
// bool search(int ID)
// {
//     Node *current = head;
//     while (current != nullptr)
//     {
//         if (current->id == ID)
//         {
//             return true;
//         }
//         current = current->next;
//     }
//     return false;
// }

// // 5. Delete element from the beginning
// bool deleteAtFirst()
// {
//     if (head == nullptr)
//     {
//         return false;
//     }
//     Node *temp = head;
//     head = head->next;
//     delete temp;
//     return true;
// }
// // BONUS

// // a: Delete at the end of the list
// bool deleteAtEnd()
// {
//     if (head == nullptr)
//     {
//         return false;
//     }
//     if (head->next == nullptr)
//     {
//         delete head;
//         head = nullptr;
//         return true;
//     }
//     Node *current = head;
//     while (current->next->next != nullptr)
//     {
//         current = current->next;
//     }

//     delete current->next;
//     current->next = nullptr;
//     return true;
// }

// // b: Delete a specific element in the list
// bool deleteSpecific(int ID)
// {
//     if (head == nullptr)
//     {
//         return false;
//     }
//     if (head->id == ID)
//     {
//         return deleteAtFirst();
//     }
//     Node *current = head;
//     while (current->next != nullptr && current->next->id != ID)
//     {
//         current = current->next;
//     }
//     if (current->next == nullptr)
//     {
//         return false;
//     }

//     Node *temp = current->next;
//     current->next = current->next->next;
//     delete temp;
//     return true;
// }

// //c: Clear the list (delete all data)
// void clearList()
// {
//     while (head != nullptr)
//     {
//         deleteAtFirst();
//     }
// }

// void printList()
// {
//     Node *current = head;
//     if (current == nullptr)
//     {
//         std::cout << "This list is empty";
//         return;
//     }
//     while (current != nullptr)
//     {
//         std::cout << "ID: " << current->id<< " | Name: " << current->name<< " | Major: " << current->major << "\n";
//         current = current->next;
//     }
// }
// int main()
// {
//     // 2. Test insertAtBeginning
//     insertAtBeginning(101, "Heang", "CS");
//     insertAtBeginning(102, "Thanuth", "SE");
//     insertAtBeginning(103, "Pheng", "Data Science");
//     insertAtBeginning(104, "Dara", "TNE");
//     printList();

//     // 3. Test count
//     std::cout << "\nTotal students: " << count() << "\n\n";

//     // 4. Test search
//     std::cout << "Search ID 101 " << (search(101) ? "Found" : "Not Found") << "\n";
//     std::cout << "Search ID 102: " << (search(102) ? "Found" : "Not Found") << "\n";
//     std::cout << "Search ID 102: " << (search(103) ? "Found" : "Not Found") << "\n";
//     std::cout << "Search ID 104: " << (search(104) ? "Found" : "Not Found") << "\n";
//     std::cout << "Search ID 105: " << (search(105) ? "Found" : "Not Found") << "\n\n";

//     // 5. Test deleteAtFirst
//     if (deleteAtFirst())
//     {
//         std::cout << "Deleted successfully.\n";
//     }
//     std::cout << "List after deletion:\n";
//     printList();
//     std::cout << "New student count: " << count() << "\n";

//     // Bonus Work: 
//     std::cout << "\nBonus a: Delete at End \n";
//     deleteAtEnd(); // Removes 101
//     printList();

//     std::cout << "\n Bonus b: Delete Specific (103)\n";
//     deleteSpecific(103); // Removes 103
//     printList();

//     std::cout << "\nBonus c: Clear List\n";
//     clearList();
//     printList();

//     return 0;
// }

// PART 2: DOUBLY LINK LIST

struct CNode
{
    int data;
    CNode *next;
};
CNode *cllHead = nullptr;

// Helper to insert into CLL for testing
void insertCLL(int val)
{
    CNode *newNode = new CNode();
    newNode->data = val;

    if (cllHead == nullptr)
    {
        newNode->next = newNode;
        cllHead = newNode;
        return;
    }

    CNode *current = cllHead;
    while (current->next != cllHead)
    {
        current = current->next;
    }
    current->next = newNode;
    newNode->next = cllHead;
}

// 1. Delete function to remove the head node in the Circular Linked List
bool deleteHeadCLL()
{
    if (cllHead == nullptr)
    {
        return false;
    }

    if (cllHead->next == cllHead)
    {
        delete cllHead;
        cllHead = nullptr;
        return true;
    }

    CNode *last = cllHead;
    while (last->next != cllHead)
    {
        last = last->next;
    }

    CNode *temp = cllHead;
    cllHead = cllHead->next; 
    last->next = cllHead;    
    delete temp;
    return true;
}

// 2. Search method to find a node in Circular Linked List
bool searchCLL(int val)
{
    if (cllHead == nullptr)
    {
        return false;
    }

    CNode *current = cllHead;
    do
    {
        if (current->data == val)
        {
            return true;
        }
        current = current->next;
    } while (current != cllHead);

    return false;
}

void printCLL()
{
    if (cllHead == nullptr)
    {
        std::cout << "This list is empty\n";
        return;
    }

    CNode *current = cllHead;
    do
    {
        std::cout << current->data << " ";
        current = current->next;
    } while (current != cllHead);
    std::cout << "(head: " << cllHead->data << ")\n";
}

// 3 & 4. Doubly Linked List (DLL)

struct DNode
{
    int data;
    DNode *prev;
    DNode *next;
};
DNode *dllHead = nullptr;

// 3. Insert at the beginning in the Doubly Linked List
void insertAtBeginningDLL(int val)
{
    DNode *newNode = new DNode();
    newNode->data = val;
    newNode->prev = nullptr;
    newNode->next = dllHead;

    if (dllHead != nullptr)
    {
        dllHead->prev = newNode;
    }
    dllHead = newNode;
}

// 4. Delete the last node in the Doubly Linked List
bool deleteLastDLL()
{
    if (dllHead == nullptr)
    {
        return false;
    }

    if (dllHead->next == nullptr)
    {
        delete dllHead;
        dllHead = nullptr;
        return true;
    }

    DNode *current = dllHead;
    while (current->next != nullptr)
    {
        current = current->next;
    }

    current->prev->next = nullptr;
    delete current;
    return true;
}

void printDLL()
{
    if (dllHead == nullptr)
    {
        std::cout << "This list is empty\n";
        return;
    }
    DNode *current = dllHead;
    while (current != nullptr)
    {
        std::cout << current->data;
        if (current->next != nullptr)
        {
            std::cout << " ";
        }
        current = current->next;
    }
    std::cout << "\n";
}

// 5. Music Playlist (Circular Linked List)

struct SongNode
{
    std::string title;
    SongNode *next;
};
SongNode *currentSong = nullptr;

void addSong(std::string title)
{
    SongNode *newNode = new SongNode();
    newNode->title = title;

    if (currentSong == nullptr)
    {
        newNode->next = newNode;
        currentSong = newNode;
        return;
    }

    SongNode *temp = currentSong;
    while (temp->next != currentSong)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = currentSong;
}

void playNext()
{
    if (currentSong == nullptr)
    {
        std::cout << "Playlist is empty.\n";
        return;
    }
    currentSong = currentSong->next;
    std::cout << "Now Playing: " << currentSong->title << "\n";
}
// 6. Browser History (Doubly Linked List)

struct HistoryNode
{
    std::string url;
    HistoryNode *prev;
    HistoryNode *next;
};
HistoryNode *currentHistory = nullptr;

void visit(std::string url)
{
    HistoryNode *newNode = new HistoryNode();
    newNode->url = url;
    newNode->prev = currentHistory;
    newNode->next = nullptr;

    if (currentHistory != nullptr)
    {
        currentHistory->next = newNode;
    }
    currentHistory = newNode;
    std::cout << "Visited: " << currentHistory->url << "\n";
}

void back()
{
    if (currentHistory != nullptr && currentHistory->prev != nullptr)
    {
        currentHistory = currentHistory->prev;
        std::cout << "Back to: " << currentHistory->url << "\n";
    }
    else
    {
        std::cout << "Cannot go back.\n";
    }
}

void forward()
{
    if (currentHistory != nullptr && currentHistory->next != nullptr)
    {
        currentHistory = currentHistory->next;
        std::cout << "Forward to: " << currentHistory->url << "\n";
    }
    else
    {
        std::cout << "Cannot go forward.\n";
    }
}

// 7. Undo-Redo System (Doubly Linked List)

struct ActionNode
{
    std::string command;
    ActionNode *prev;
    ActionNode *next;
};
ActionNode *currentAction = nullptr;

void execute(std::string cmd)
{
    ActionNode *newNode = new ActionNode();
    newNode->command = cmd;
    newNode->prev = currentAction;
    newNode->next = nullptr;

    if (currentAction != nullptr)
    {
        currentAction->next = newNode;
    }
    currentAction = newNode;
    std::cout << "Executed: " << currentAction->command << "\n";
}

void undo()
{
    if (currentAction != nullptr)
    {
        std::cout << "Undo: " << currentAction->command << "\n";
        currentAction = currentAction->prev;
    }
    else
    {
        std::cout << "Nothing to undo.\n";
    }
}

void redo()
{
    if (currentAction != nullptr && currentAction->next != nullptr)
    {
        currentAction = currentAction->next;
        std::cout << "Redo: " << currentAction->command << "\n";
    }
    else
    {
        std::cout << "Nothing to redo.\n";
    }
}

int main()
{
    // Step 1 & 2: Circular Linked List
    insertCLL(10);
    insertCLL(20);
    insertCLL(30);
    printCLL();

    std::cout << "Search 20: " << (searchCLL(20) ? "Found" : "Not Found") << "\n";
    std::cout << "Search 35: " << (searchCLL(35) ? "Found" : "Not Found") << "\n";

    deleteHeadCLL();
    printCLL();

    // Step 3 & 4: Doubly Linked List
    insertAtBeginningDLL(300);
    insertAtBeginningDLL(200);
    insertAtBeginningDLL(100);
    printDLL();

    deleteLastDLL();
    std::cout << "After deleteLastDLL(): ";
    printDLL();

    // Step 5: Music Playlist
    addSong("Song A");
    addSong("Song B");
    addSong("Song C");
    playNext();
    playNext();
    playNext();

    // Step 6: Browser History
    visit("google.com");
    visit("youtube.com");
    visit("github.com");
    back();
    back();
    forward();

    // Step 7: Undo-Redo System
    execute("Type 'Hello'");
    execute("Type ' World'");
    undo();
    redo();

    return 0;
}
