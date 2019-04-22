/*************************************************************************************************************************
*
*   Source.cpp
*   Rod Cutting/Dynamic Programming & Activity-Selection Problem/Greedy Algorithm
*
*   Created by Zachary Torricelli on 3/18/19.
*   Copyright © 2019 Zachary Torricelli. All rights reserved.
*
*   Implement both BFS and DFS algorithms.
*
*   You can choose either adjacency lists or adjacency matrix to represent your graphs.
*   Your graph can be hard-coded.
*   Your input graphs can be either undirected or directed.
*   In BFS, you can specify the source vertex by yourself.
*   Implement and test both BFS and DFS algorithms to solve the graph-searching problem.
*   You may use the following graph as your test example. You can also use your own graph and draw it in your report.
*
*************************************************************************************************************************/


// Include statements and using directive
#include <iostream>
#include <queue>
#include <stack>
#define SIZE 6

using namespace std;

// Function prototypes
void menu();
void testGraph();
void breadthFirstSearch(int);
void depthFirstSearch(int);


// Adjacency matrix for vertexes and edges
int adjacencyMatrix[][SIZE] = { {0, 1, 1, 0, 0, 0},
                                {1, 0, 0, 1, 1, 0},
                                {1, 0, 0, 0, 1, 0},
                                {0, 1, 0, 0, 1, 1},
                                {0, 1, 1, 1, 0, 1},
                                {0, 0, 0, 1, 1, 0} };


// Main driver function
int main()
{
    
    // Calls the menu function
    menu();
    
    
    system("pause");
    return 0;
    
}



// Function used for a menu
void menu()
{
    
    // Function variable
    int choice = 4;
    int start = 0;
    
    // Displays a welcome message to the console
    cout << "Welcome to Zac's BFS and DFS Graph Traversal!" << endl;
    cout << "Please enter a number (1-4)." << endl << endl;
    
    // Do-while loop for the activity selector menu
    do
    {
        
        // Displays a menu to the console
        cout << "1. View Test Graph" << endl;
        cout << "2. Breadth First Search" << endl;
        cout << "3. Depth First Search" << endl;
        cout << "4. Exit" << endl << endl;
        
        cin >> choice;
        
        
        // Makes sure the user inputs a valid option
        while (cin.fail())
        {
            
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << endl << "Please enter a number (1-4)." << endl << endl;
            cin >> choice;
            
        }
        
        
        // Switch statement to go between options
        switch (choice)
        {
                
                // Case 1 will display the test graph
            case 1:
                
                system("CLS");
                
                // Calls the menu function for the rod cutter
                testGraph();
                
                break;
                
                
                // Case 2 will perform a BFS
            case 2:
                
                system("CLS");
                
                // Calls the BFS function
                breadthFirstSearch(start);
                
                cout << endl << endl;
                
                break;
                
                
            case 3:
                
                system("CLS");
                
                // Calls the DFS function
                depthFirstSearch(start);
                
                cout << endl << endl;
                
                break;
                
                
                // Case 4 will exit the program
            case 4:
                
                exit(0);
                
                // Default case will collect the invalid options input and let the user try again
            default:
                
                system("CLS");
                cout << "Invalid selection. Try again" << endl;
                
        }
        
        
    } while (choice != 4);
    
}

    


// Function used to display the test graph
void testGraph()
{

    cout << "\t\t1" << endl;
    cout << "\t/" << "\t\t\\ " << endl;
    cout << "\t2" << "\t\t3" << endl;
    cout << "\t|" << "\t\\" << "\t|" << endl;
    cout << "\t4" << "\t-" << "\t5" << endl;
    cout << "\t\\" << "\t\t/" << endl;
    cout << "\t\t6" << endl;
    
    cout << endl << endl;
    
}



// Function used to perform a BFS graph traversal
void breadthFirstSearch(int start)
{
    
    // Boolean array to determine which vertices have been visited
    bool visited[SIZE];
    
    for(int i = 0; i < SIZE; i++)
    {
        
        visited[i] = false;
        
    }
    
    // Creates a queue
    queue<int> myQueue;
    
    // Pushes the starting vertex to the queue
    myQueue.push(start);
    
    // Marks the starting position as visited
    visited[start] = true;
    
    
    cout << "Breadth First Search: " << endl;
    cout << start + 1 << endl;
    
    
    // While the queue is not empty
    while (!myQueue.empty())
    {
        
        int current = myQueue.front();
        
        // Pops the value off the queue
        myQueue.pop();
        
        
        // Loop to check the front of queue
        for (int j = 0; j < SIZE; j++)
        {
            
            // Checks edges and if visited
            if (adjacencyMatrix[current][j] == 1 && visited[j] != true)
            {
                
                // Pushes next vertex to the queue
                myQueue.push(j);
                
                cout << j + 1 << endl;
                
                // Marks position as visited
                visited[j] = true;
                
            }
            
        }
        
    }
    
}



// Function used to perform a DFS graph traversal
void depthFirstSearch(int start)
{
    
    // Boolean array to determine which vertices have been visited
    bool visited[SIZE];
    
    for(int i = 0; i < SIZE; i++)
    {
        
        visited[i] = false;
        
    }
    
    // Creates a stack
    stack<int> myStack;
    
    // Pushes the starting vertex to the stack
    myStack.push(start);
    
    // Marks the starting position as visited
    visited[start] = true;
    
    
    cout << "Depth First Search: " << endl;
    cout << start + 1 << endl;
    
    
    // While the stack is not empty
    while (!myStack.empty())
    {
        
        int current = myStack.top();
        
        // Pops the value off the stack
        myStack.pop();
        
        
        // Loop to check the front of stack
        for (int j = 0; j < SIZE; j++)
        {
            
            // Checks edges and if visited
            if (adjacencyMatrix[current][j] == 1 && visited[j] != true)
            {
                
                // Pushes next vertex to the stack
                myStack.push(j);
                
                cout << j + 1 << endl;
 
                current = myStack.top();
                
                // Marks position as visited
                visited[j] = true;
                
            }
            
        }
        
    }
    
}
