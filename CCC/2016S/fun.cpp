#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

struct Node{
    int id;
    bool isPhoRestaurant;
    vector<int> connections;
};
int numberOfRestaurants, numberOfPhoRestaurants;
vector<int> phoRestaurants;
vector<Node> nodes;


//HELPER FUNCTIONS
void initGraph(){
    nodes = vector<Node>();
    for (int i = 0; i < numberOfRestaurants; i++){
        Node node = Node();
        node.id = i;
        node.isPhoRestaurant = false;
        node.connections = vector<int>();
        nodes.push_back(node);
    }
    phoRestaurants = vector<int>();
}
 
void addPhoRestaurant(int pho){
    phoRestaurants.push_back(pho);
    nodes[pho].isPhoRestaurant = true;
}

void addConnection(int a, int b){
    nodes[a].connections.push_back(b);
    nodes[b].connections.push_back(a);
}

//END HELPER FUNCTIONS

void readInput(){
    cin >> numberOfRestaurants >> numberOfPhoRestaurants;
    initGraph();
    for (int i = 0; i < numberOfPhoRestaurants; i++)    {
        int pho;
        cin >> pho;
        addPhoRestaurant(pho);
    }
    for (int i = 0; i < (numberOfRestaurants - 1); i++)    {
        int a, b;
        cin >> a >> b;
        addConnection(a, b);
    }
}

void depthFirstSearch(int startingNode, int previousNode, int distanceToStartingNode, int &maxDistanceNode, int &maxDistance){
    for (int i = 0; i < nodes[startingNode].connections.size(); i++){ // for connection in nodes[startingNode].connections
        int currentNode = nodes[startingNode].connections[i];
        if (currentNode != previousNode){ //don't backtrack
			//record important values if maxDistance
            int distanceToCurrentNode = distanceToStartingNode + 1;
            if (distanceToCurrentNode > maxDistance && nodes[currentNode].isPhoRestaurant){
                maxDistance = distanceToCurrentNode;
                maxDistanceNode = currentNode;
            }
			
			//Keep searching
            depthFirstSearch(currentNode, startingNode, distanceToCurrentNode, maxDistanceNode, maxDistance);
        }
    }
}
 
void getFarthestPhoRestaurant(int startingNode, int &maxDistanceNode, int &maxDistance){
    depthFirstSearch(startingNode, startingNode, 0, maxDistanceNode, maxDistance);
}

bool *doesSubtreeContainPhoRestaurant;
 
void solveAllDoesSubtreeContainPhoRestaurant(int startingNode, int previousNode){
    Node node = nodes[startingNode];
    if (node.isPhoRestaurant == true)    {
        doesSubtreeContainPhoRestaurant[startingNode] = true;
    }
    for (int i = 0; i < node.connections.size(); i++)    { //for currentNode in node.connections
        int currentNode = node.connections[i];
        if (currentNode != previousNode){
            solveAllDoesSubtreeContainPhoRestaurant(currentNode, startingNode);
            if(doesSubtreeContainPhoRestaurant[currentNode] == true){
                doesSubtreeContainPhoRestaurant[startingNode] = true;
            }
        }
    }
}
 
void solveSubtree(int startingNode, int previousNode, int &cost){
    Node node = nodes[startingNode];
    for (int i = 0; i < node.connections.size(); i++)    {
        int currentNode = node.connections[i];
        if (currentNode != previousNode)        {
            if (doesSubtreeContainPhoRestaurant[currentNode]){
                cost += 2;
                solveSubtree(currentNode, startingNode, cost);
            }
        }
    }
}
 
int solveTree(int startingNode){
    doesSubtreeContainPhoRestaurant = new bool[numberOfRestaurants];
    memset(doesSubtreeContainPhoRestaurant, false, numberOfRestaurants * sizeof(bool));
    solveAllDoesSubtreeContainPhoRestaurant(startingNode, startingNode);
    int cost = 0;
    solveSubtree(startingNode, startingNode, cost);
    delete doesSubtreeContainPhoRestaurant;
    return cost;
}

int main(){
    readInput();
    int maxDistance = 0, optimalStartingNode = 0, optimalEndingNode = 0;
    getFarthestPhoRestaurant(phoRestaurants[0], optimalStartingNode, maxDistance);
    int cost = solveTree(optimalStartingNode);
    getFarthestPhoRestaurant(optimalStartingNode, optimalEndingNode, maxDistance);
    int finalCost = cost - maxDistance;
    cout << finalCost;
    return 0;
}