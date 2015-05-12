/**************************************************************************
* AUTHOR        : Austin Vaday
**************************************************************************/

#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include "heap.h"
#include "comparators.h"
#include <queue>
#include <stack>

//#define INFINITY 999999999999999

using namespace std;

// Enumeration types used for this graph
enum VertexEnum
{
    UNEXPLORED_VERTEX,
    VISITED_VERTEX
};

enum EdgeEnum
{
    UNEXPLORED_EDGE,
    DISCOVERY_EDGE,
    FORWARD_EDGE,
    BACK_EDGE,
    CROSS_EDGE
};

enum GraphType
{
    UNDIRECTED_GRAPH,
    DIRECTED_GRAPH
};

/**************************************************************************
* VERTEX CLASS
* 	Generic "VertexType" indicates what's being stored in the vertex
* 		(Can be a number, a letter, a class, etc)
*
* 		 temporarily, the cost is an integer
*		 (assuming weightType is an integer type).
*		 Add in template type WeightType
*		 if you'd like more generality
**************************************************************************/
template <typename VertexType>
class Vertex
{
    public:
        Vertex();
        Vertex(VertexType setVertexData, int setVertexIndex);
        ~Vertex();

        void setExploration(int setExplorationStatus);
        void setArriveTime(int arTime);
        void setDepartTime(int dpTime);
        void setCost(int cost);
        void setParent(Vertex<VertexType> *parentVertex);

        VertexType& operator* ();

        int  getExploration() const;
        int  getVertexIndex() const;
        int  getArriveTime() const;
        int  getDepartTime() const;
        int  getCost() const;
        Vertex<VertexType>*  getParent() const;


    private:
        VertexType 			vertexData;
        int 				vertexIndex;
        VertexEnum  		explorationStatus;
        int 				arrivalTime;
        int					departureTime;
        int					cost;
        Vertex<VertexType> *parent;

};

template <typename VertexType>
Vertex<VertexType>::Vertex()
                  : vertexData(VertexType()),
                    vertexIndex(-1),
                    explorationStatus(UNEXPLORED_VERTEX),
                    arrivalTime(0),
                    departureTime(9999999),
                    cost(INFINITY),
                    parent(NULL)
{

}
template <typename VertexType>
Vertex<VertexType>::Vertex(VertexType setVertexData, int setVertexIndex)
                  : vertexData(setVertexData),
                    vertexIndex(setVertexIndex),
                    explorationStatus(UNEXPLORED_VERTEX),
                    arrivalTime(0),
                    departureTime(9999999),
                    cost(INFINITY),
                    parent(NULL)
{

}

template <typename VertexType>
Vertex<VertexType>::~Vertex()
{


}

template <typename VertexType>
VertexType& Vertex<VertexType>::operator*()
{
    return vertexData;
}

template <typename VertexType>
void Vertex<VertexType>::setExploration(int setExplorationStatus)
{
    // type cast into enumeration type
    explorationStatus = VertexEnum(setExplorationStatus);
}

template <typename VertexType>
void Vertex<VertexType>::setArriveTime(int arTime)
{
    arrivalTime = arTime;
}

template <typename VertexType>
void Vertex<VertexType>::setDepartTime(int dpTime)
{
    departureTime = dpTime;
}
template <typename VertexType>
void Vertex<VertexType>::setCost(int cost)
{
    this->cost = cost;
}
template <typename VertexType>
void Vertex<VertexType>::setParent(Vertex<VertexType> *parentVertex)
{
    parent = parentVertex;
}

template <typename VertexType>
int  Vertex<VertexType>::getExploration() const
{
    // return appropriate exploration status
    switch (explorationStatus)
    {
        case UNEXPLORED_VERTEX: return UNEXPLORED_VERTEX;
            break;
        case VISITED_VERTEX:	return VISITED_VERTEX;
            break;
    }
}

template <typename VertexType>
int  Vertex<VertexType>::getVertexIndex() const
{
    if (vertexIndex == -1)
    {
        throw IndexNotSet();
    }

    return vertexIndex;
}

template <typename VertexType>
int  Vertex<VertexType>::getArriveTime() const
{
    return arrivalTime;
}
template <typename VertexType>
int  Vertex<VertexType>::getDepartTime() const
{
    return departureTime;
}

template <typename VertexType>
int  Vertex<VertexType>::getCost() const
{
    return cost;
}
template <typename VertexType>
Vertex<VertexType>*  Vertex<VertexType>::getParent() const
{
    return parent;
}


/**************************************************************************
* EDGE CLASS
*	 Generic "VertexType" indicates what's being stored in the vertex
* 		(Can be a number, a letter, a class, etc)
* 		Edge needs to know this type so that it can point to multiple vertices
* 	 Generic "WeightType" indicates the weight along the edge
**************************************************************************/
template <typename VertexType, typename WeightType>
class Edge
{
    public:
        Edge();
        Edge(Vertex<VertexType>& setVertex1,
             Vertex<VertexType>& setVertex2,
             WeightType setWeight);
        Edge(const Edge<VertexType, WeightType>& otherEdge); // Copy Constructor
        ~Edge();

//		Edge<VertexType, WeightType>& operator= (const Edge<VertexType, WeightType> &otherEdge);

        // M U T A T O R S
        // setEdgeData uses setWeight and setVertices method.
        void setEdgeData(Vertex<VertexType>& setVertex1,
                         Vertex<VertexType>& setVertex2,
                         WeightType setWeight);
        void setWeight(WeightType setWeight);
        void setVertices(Vertex<VertexType>& setVertex1,
                         Vertex<VertexType>& setVertex2);
        void insertVertex(const Vertex<VertexType>& setVertex);	// (Is this needed?)
        void freeVertex(const Vertex<VertexType>& rmVertex);
        void freeEdge();
        void setExploration(int setExplorationStatus);

        // A C C E S S O R S
        int  getExploration() const;
        Vertex<VertexType>* getVertex1() const;
        Vertex<VertexType>* getVertex2() const;
        Vertex<VertexType>* getOpposite(const Vertex<VertexType>& vertex) const;
        bool isIncidentTo(const Vertex<VertexType>& vertex) const;
        bool isAdjacentTo(const Edge<VertexType, WeightType>& otherEdge) const;
        WeightType getWeight() const;

    private:
        Vertex<VertexType> *vertex1;
        Vertex<VertexType> *vertex2;
        WeightType weight;
        EdgeEnum  explorationStatus;


};


template <typename VertexType, typename WeightType>
Edge<VertexType,WeightType>::Edge()
                           : vertex1(NULL),
                             vertex2(NULL),
                             weight(WeightType()),
                             explorationStatus(UNEXPLORED_EDGE)
{

}
template <typename VertexType, typename WeightType>
Edge<VertexType,WeightType>::Edge(Vertex<VertexType>& setVertex1,
                                  Vertex<VertexType>& setVertex2,
                                  WeightType setWeight)
                           : vertex1(&setVertex1),
                             vertex2(&setVertex2),
                             weight(setWeight),
                             explorationStatus(UNEXPLORED_EDGE)

{

}
template <typename VertexType, typename WeightType>
Edge<VertexType,WeightType>::Edge(const Edge<VertexType, WeightType>& otherEdge) // Copy Constructor
{
    // overloaded op=
    *this = otherEdge;
}
template <typename VertexType, typename WeightType>
Edge<VertexType,WeightType>::~Edge()
{
    vertex1 = NULL;
    vertex2 = NULL;
}

//template <typename VertexType, typename WeightType>
//Edge<VertexType, WeightType>& Edge<VertexType,WeightType>::
//	operator= (const Edge<VertexType, WeightType> &otherEdge)
//{
////	if (this != &otherEdge)
////	{
////		this->weight = otherEdge.weight;
////		this->explorationStatus = otherEdge.explorationStatus;
////
////		if (vertex1 != NULL)
////		{
////
////		}
////
////		if (vertex2 != NULL)
////		{
////			delete vertex2;
////			vertex2 = new Vertex<VertexType>;
////		}
////
////		*vertex1 = *(otherEdge.vertex1);
////		*vertex2 = *(otherEdge.vertex2);
////
////	}
////
////	return *this;
//}
// setEdgeData uses setWeight and setVertices method.
template <typename VertexType, typename WeightType>
void Edge<VertexType,WeightType>::setEdgeData(Vertex<VertexType>& setVertex1,
                                              Vertex<VertexType>& setVertex2,
                                              WeightType setWeight)
{
    setVertices(setVertex1, setVertex2);
    setWeight(setWeight);

}
template <typename VertexType, typename WeightType>
void Edge<VertexType,WeightType>::setWeight(WeightType setWeight)
{
    weight = setWeight;
}
template <typename VertexType, typename WeightType>
void Edge<VertexType,WeightType>::setVertices(Vertex<VertexType>& setVertex1,
                                              Vertex<VertexType>& setVertex2)
{
    vertex1 = &setVertex1;
    vertex2 = &setVertex2;
}

template <typename VertexType, typename WeightType>
void Edge<VertexType,WeightType>::insertVertex(const Vertex<VertexType>& setVertex)
{
    // Set the vertex to any available vertex. If no vertex available,
    // throw error
    if (vertex1 == NULL)
    {
        vertex1 = &setVertex;
    }
    else if (vertex2 == NULL)
    {
        vertex2 = &setVertex;
    }
    else
    {
        throw Full();
    }
}

template <typename VertexType, typename WeightType>
void Edge<VertexType,WeightType>::freeVertex(const Vertex<VertexType>& rmVertex)
{
    // Set the vertex to null if rmVertex found. If no vertex found,
    // throw error
    // NOTE: this class does not allocate memory, and thus should not
    // deallocate memory. Deallocation of memory of a vertex object should
    // be handled by an external class (i.e. the graph class)
    if (vertex1 == &rmVertex)
    {
        vertex1 = NULL;
    }
    else if (vertex2 == &rmVertex)
    {
        vertex1 = NULL;
    }
    else
    {
        throw NotFound();
    }
}

template <typename VertexType, typename WeightType>
void Edge<VertexType,WeightType>::freeEdge()
{
    vertex1 = NULL;
    vertex2 = NULL;
    weight  = WeightType();
    explorationStatus = EdgeEnum(UNEXPLORED_EDGE);
}

template <typename VertexType, typename WeightType>
void Edge<VertexType,WeightType>::setExploration(int setExplorationStatus)
{
    // type cast into enumeration type
    explorationStatus = EdgeEnum(setExplorationStatus);
}

template <typename VertexType, typename WeightType>
int Edge<VertexType,WeightType>::getExploration() const
{
    // return appropriate exploration status
    switch (explorationStatus)
    {
        case UNEXPLORED_EDGE: 	return UNEXPLORED_EDGE;
            break;
        case DISCOVERY_EDGE:	return DISCOVERY_EDGE;
            break;
        case BACK_EDGE:			return BACK_EDGE;
            break;
        case FORWARD_EDGE:		return FORWARD_EDGE;
            break;
        case CROSS_EDGE:		return CROSS_EDGE;
            break;
    }
}

template <typename VertexType, typename WeightType>
Vertex<VertexType>* Edge<VertexType,WeightType>::getVertex1() const
{
    return vertex1;
}
template <typename VertexType, typename WeightType>
Vertex<VertexType>* Edge<VertexType,WeightType>::getVertex2() const
{
    return vertex2;
}
template <typename VertexType, typename WeightType>
Vertex<VertexType>* Edge<VertexType,WeightType>::getOpposite(const Vertex<VertexType>& vertex) const
{
    // return opposite to vertex
    // checks if vertex1 points to same location as the indicated vertex
    if (vertex1->getVertexIndex() == vertex.getVertexIndex())
    {
        return  vertex2;
    }
    else if (vertex2->getVertexIndex() == vertex.getVertexIndex())
    {
        return vertex1;
    }
    else
    {
        return NULL;
    }
}
template <typename VertexType, typename WeightType>
bool Edge<VertexType,WeightType>::isIncidentTo(const Vertex<VertexType>& vertex) const
{
    // checks if either of the two vertices of this edge are the indicated
    // vertex. If so, then the edge is incident to this vertex.
    if (vertex1 == &vertex || vertex2 == &vertex)
    {
        return true;
    }
    else
    {
        return false;
    }
}
template <typename VertexType, typename WeightType>
bool Edge<VertexType,WeightType>::isAdjacentTo(const Edge<VertexType, WeightType>& otherEdge) const
{
    // checks if the edges share a common vertex
    if (this->getVertex1() == otherEdge.getVertex1() ||
        this->getVertex1() == otherEdge.getVertex2() ||
        this->getVertex2() == otherEdge.getVertex1() ||
        this->getVertex2() == otherEdge.getVertex2())
    {
        return true;
    }
    else
    {
        return false;
    }
}
template <typename VertexType, typename WeightType>
WeightType Edge<VertexType,WeightType>::getWeight() const // could use operator*, but this suffices
{
    return weight;
}


/**************************************************************************
*  GRAPH CLASS (implemented as an adjacency matrix)
*	 Generic "VertexType" indicates what's being stored in the vertex
* 		(Can be a number, a letter, a class, etc)
* 		Graph needs to know this type so that it can create an Edge.
* 		Edge needs to know this type so that it can point to multiple vertices
* 	 Generic "WeightType" indicates the weight along the edge of the graph
*
*
* 	 Can be either DIRECTED or UNDIRECTED, you must specify this upon
* 	 object instantiation. Else, it will set default as UNDIRECTED.
*
* 	 BIG OH ANALYSIS:
*		<coming soon>
*
***************************************************************************/
template <typename VertexType, typename WeightType>
class Graph
{
    public:
        /******************************************************************
         * Typedefs
         *****************************************************************/
        typedef Heap<TopLowestWeight<HeapItem<Edge<VertexType,WeightType>* > >,
                                     Edge<VertexType,WeightType>* >
                                     GraphEdgeHeap;
        /******************************************************************
         * Constructors & Destructors
         *****************************************************************/
        Graph(int numSize = 10, GraphType setGraphType = UNDIRECTED_GRAPH);
        // Copy constructor
        Graph(const Graph<VertexType, WeightType>& otherGraph);
        ~Graph();

        /******************************************************************
         * Overloaded operators
         *****************************************************************/
        Graph<VertexType, WeightType>& operator=(const Graph<VertexType, WeightType>& otherGraph);

        /******************************************************************
         * Mutator methods
         *****************************************************************/
        void insert(VertexType vertexData1,						// MODIFIED FOR DIRECTED GRAPH
                    VertexType vertexData2,
                    WeightType weight);
        void insertVertex(VertexType vertexData);
        void removeVertex(VertexType vertexData);
        void removeVertex(Vertex<VertexType>& rmVertex);		// MODIFIED FOR DIRECTED GRAPH
        void removeEdge(Edge<VertexType,WeightType>& rmEdge);
        void removeEdge(VertexType vertexData1,					// MODIFIED FOR DIRECTED GRAPH
                        VertexType vertexData2,
                        WeightType weight);
        void destroy();
        void reverseEdges();

        /******************************************************************
         * Accessor methods
         *****************************************************************/
        vector<Vertex<VertexType>* >& vertices() const;
        vector<Edge<VertexType,WeightType>* >& edges() const;
        void incidentEdges(VertexType vertexData, GraphEdgeHeap& incidentEdgeList) const;
        vector<Vertex<VertexType>* >& incidentVertices(Edge<VertexType,WeightType>& edge) const;

        /******************************************************************
         * Graph traversals and functionality methods
         *****************************************************************/
        void DepthFirstSearch(VertexType vertexData);
        void DepthFirstSearch(VertexType vertexData, vector<Vertex<VertexType>* >& vertices);
        void DepthFirstSearch(Vertex<VertexType> &vertex);
        void DepthFirstSearch(Vertex<VertexType> &vertex, vector<Vertex<VertexType>* >& vertices);
        void BreadthFirstSearch(VertexType vertexData);
        void BreadthFirstSearch(Vertex<VertexType> &vertex);
        bool isStronglyConnected(VertexType beginVertex);
        bool isAncestor(Vertex<VertexType> &vDescendant, Vertex<VertexType> &vAncestor);
        void Dijkstra(VertexType sourceVertexData);
        void DijkstraShortestPath(VertexType sourceVertexData, VertexType endVertexData, vector<Vertex<VertexType> *> &vertexVector, WeightType &totalCost);

        void MST(vector<Edge<Vertex<VertexType>,WeightType> *> &edgeVector, WeightType &totalCost);

        /******************************************************************
         * Display-to-console methods
         *****************************************************************/
        // General method to display any possible exploration category of
        // the edges
        void displayEdges(int explorationType) const;
        // Output testing
        void display() const;

    private:

        /******************************************************************
         * Private Class Methods
         *****************************************************************/
        void DijkstrasComputation(Vertex<VertexType> &sourceVertex);
        void PrimJarnikMSTComputation();

        /* given a vertex index (for the matrix), returns a pointer to a
         * vertex if found, or NULL if not found */
        Vertex<VertexType>* returnVertexFromIndex(int vertexIndex) const;
        Vertex<VertexType>* returnVertexFromData(VertexType vertexData) const;
        Edge<VertexType,WeightType>* returnEdgeFromData(VertexType vertexData1,
                                                        VertexType vertexData2,
                                                        WeightType weight) const;
        int returnAvailableMatrixIndex() const;
        void resetVertexEdgeExploration();


        /******************************************************************
         * Private Class Attributes
         *****************************************************************/
        int vertexCount;
        int edgeCount;
        int size;
        GraphType graphType;
        int time;
        vector<vector<Edge<VertexType,WeightType>* > > edgeMatrix;
            // 2D-array of pointers to edges (matrix of pointers to edges)
        vector<Vertex<VertexType>* > vertexList;
            // keeps track of our vertices
        vector<Edge<VertexType,WeightType>* > edgeList;
            // keeps track of our edges


};
template <typename VertexType, typename WeightType>
Graph<VertexType,WeightType>::Graph(int numSize, GraphType setGraphType)
                                      : edgeMatrix(numSize),
                                        vertexList(),
                                        edgeList(),
                                        vertexCount(0),
                                        edgeCount(0),
                                        size(numSize),
                                        graphType (setGraphType),
                                        time(0)
{
    /* Create [size x size] matrix */
    for (int i = 0; i < size; i++)
    {
        (edgeMatrix[i]).resize(size);
    }

    /* initialize every location to NULL */
    for (int row = 0; row < size; row++)
    {
        for (int col = 0; col < size; col++)
        {
            edgeMatrix[row][col] = NULL;
        }
    }

}
//--> Copy Constructor HERE <--
template <typename VertexType, typename WeightType>
Graph<VertexType,WeightType>::Graph(const Graph<VertexType, WeightType>& otherGraph)
{
    // overloaded operator does the hard-copy
    *this = otherGraph;
}

template <typename VertexType, typename WeightType>
Graph<VertexType,WeightType>::~Graph()
{
    destroy();

}

template <typename VertexType, typename WeightType>
Graph<VertexType, WeightType>& Graph<VertexType,WeightType>::
    operator=(const Graph<VertexType, WeightType>& otherGraph)
{
    if (this != &otherGraph)
    {

        this->destroy();

        if (!otherGraph.vertexList.empty() || !otherGraph.edgeList.empty())
        {

            typename vector<Edge<VertexType,WeightType>* >::const_iterator edgeIt;

            Vertex<VertexType> *v1;
            Vertex<VertexType> *v2;
            // create the vertices, edges, and edgeMatrix
            for(edgeIt = otherGraph.edgeList.begin();
                edgeIt != otherGraph.edgeList.end();
                ++edgeIt)
            {
                v1 = (*edgeIt)->getVertex1();
                v2 = (*edgeIt)->getVertex2();
                this->insert(**v1, **v2, (*edgeIt)->getWeight());
            }


        }

        this->vertexCount= otherGraph.vertexCount;
        this->edgeCount  = otherGraph.vertexCount;
        this->size		 = otherGraph.size;
        this->graphType  = otherGraph.graphType;
        this->time		 = otherGraph.time;

    }

    return *this;
}


// M U T A T O R S

/**************************************************************************
 *
 * @param vertexData1 : START VERTEX (if direted)
 * @param vertexData2 : END VERTEX (if directed)
 * @param weight
 *************************************************************************/
template <typename VertexType, typename WeightType>
void Graph<VertexType,WeightType>::insert(VertexType vertexData1,	// start vertex
                                          VertexType vertexData2,	// end vertex
                                          WeightType weight)
{


    Vertex<VertexType> 			*vertex1;
    Vertex<VertexType> 			*vertex2;

    Edge<VertexType,WeightType> *newEdge;
    Edge<VertexType,WeightType> *edgePtr;


    typename vector<Vertex<VertexType>* >::iterator vectorIt1;
    typename vector<Vertex<VertexType>* >::iterator vectorIt2;
    typename vector<Edge<VertexType, WeightType>* >::iterator edgeIt;
    int newIndex;

    newIndex = this->returnAvailableMatrixIndex();

    vertex1 = this->returnVertexFromData(vertexData1);
    vertex2 = this->returnVertexFromData(vertexData2);

    // if no such existing vertices, create both
    if (vertex1 == NULL && vertex2 == NULL)
    {
        // If you can't add 2 more vertices...
        if (vertexList.size() > (size - 2))
        {
            throw Full();
        }

        vertex1 = new Vertex<VertexType>(vertexData1, newIndex);

        vertexList.push_back(vertex1);
        ++vertexCount;

        /* generate new vertex index for second vertex */
        newIndex = this->returnAvailableMatrixIndex();

        vertex2 = new Vertex<VertexType>(vertexData2, newIndex);

        vertexList.push_back(vertex2);
        ++vertexCount;
    }
    else if (vertex1 == NULL)
    {
        // If you can't add 1 more vertex...
        if (vertexList.size() > (size - 1))
        {
            throw Full();
        }
        vertex1 = new Vertex<VertexType>(vertexData1, newIndex);

        vertexList.push_back(vertex1);
        ++vertexCount;
    }
    else if (vertex2 == NULL)
    {
        // If you can't add 1 more vertex...
        if (vertexList.size() > (size - 1))
        {
            throw Full();
        }
        vertex2 = new Vertex<VertexType>(vertexData2, newIndex);

        vertexList.push_back(vertex2);
        ++vertexCount;
    }

    newEdge = this->returnEdgeFromData(**vertex1, **vertex2, weight);


    // if edge was not found, add it to list
    if (newEdge == NULL)
    {

        typename vector<Edge<VertexType,WeightType>* >::iterator edgeIt;

        if (edgeMatrix[vertex1->getVertexIndex()][vertex2->getVertexIndex()] != NULL)
        {
            // delete the edge and remove from edgeList
            edgePtr = edgeMatrix[vertex1->getVertexIndex()][vertex2->getVertexIndex()];

            edgeIt = edgeList.begin();
            while (edgeIt != edgeList.end() && *edgeIt != edgePtr)
            {
                edgeIt++;
            }

            if (edgeIt == edgeList.end())
            {
                qDebug() << "ERROR OCCURED LINE 553 GRAPH HEADER.h";
            }
            else
            {
                edgeList.erase(edgeIt);
                edgePtr->freeEdge();

                delete edgePtr;

                edgePtr = NULL;

                if (graphType == UNDIRECTED_GRAPH)
                {
                    // set transpose location to NULL
                    edgeMatrix[vertex2->getVertexIndex()][vertex1->getVertexIndex()] = NULL;
                }
            }
        }

        if (edgeMatrix[vertex2->getVertexIndex()][vertex1->getVertexIndex()] != NULL)
        {
            // delete the edge and remove from edgeList
            edgePtr = edgeMatrix[vertex2->getVertexIndex()][vertex1->getVertexIndex()];

            edgeIt = edgeList.begin();
            while (edgeIt != edgeList.end() && *edgeIt != edgePtr)
            {
                edgeIt++;
            }

            if (edgeIt == edgeList.end())
            {
                qDebug() << "ERROR OCCURED LINE 579 GRAPH HEADER.h";
            }
            else
            {
                edgeList.erase(edgeIt);
                edgePtr->freeEdge();

                delete edgePtr;

                edgePtr = NULL;

            }

        }

        /* create the edge */
        newEdge = new Edge<VertexType,WeightType>(*vertex1, *vertex2, weight);

        edgeList.push_back(newEdge);
        edgeCount++;
    }

    if (vertexCount > size)
    {
        throw Full();
    }

    /* have the edgeMatrix point to this newly created edge */
    /*NOTE: if this is a undirected graph, we shall equate the transposes */
    edgeMatrix[vertex1->getVertexIndex()][vertex2->getVertexIndex()] = newEdge;

    if (graphType == UNDIRECTED_GRAPH)
    {
        edgeMatrix[vertex2->getVertexIndex()][vertex1->getVertexIndex()] = newEdge;
    }


}
template <typename VertexType, typename WeightType>
void Graph<VertexType,WeightType>::insertVertex(VertexType vertexData)
{
    /* FOR NOW, the graph must be connected (use other insertion method) */
}
template <typename VertexType, typename WeightType>
void Graph<VertexType,WeightType>::removeVertex(VertexType vertexData)
{
    Vertex<VertexType> *vertexPtr;


    /* Check if vertex exists*/
    vertexPtr = this->returnVertexFromData(vertexData);


    if (vertexPtr!= NULL)
    {
        removeVertex(*vertexPtr);
    }
    else
    {
        throw NotFound();
    }
}
template <typename VertexType, typename WeightType>
void Graph<VertexType,WeightType>::removeVertex(Vertex<VertexType>& rmVertex)
{
    typename vector<Vertex<VertexType>* >::iterator vertexIt;
    typename vector<Edge<VertexType,WeightType>* >::iterator edgeIt;

    Vertex<VertexType> *rmVertexPtr;
    Edge<VertexType,WeightType> *rmEdge;
    int index;

    rmVertexPtr = &rmVertex;

    /* iterate to location of vertex in vertexList */
    vertexIt = vertexList.begin();
    while (vertexIt != vertexList.end() && *vertexIt != &rmVertex)
    {
        ++vertexIt;
    }

    /* if vertex not found, throw exception */
    if (vertexIt == vertexList.end())
    {
        throw NotFound();
    }

    /* delete vertex, remove from list, set the respective vertex pointer
     *  in edge to NULL  */

    // find the edge O(n)
    index = 0;

    // since this is an undirected graph, delete by looping thru
    // only either a row or a column (set to NULL as well).
    while (index < size)
    {
        // we'll loop through columns
        rmEdge = edgeMatrix[rmVertexPtr->getVertexIndex()][index];

        edgeIt = edgeList.begin();
        while (edgeIt != edgeList.end() && *edgeIt != rmEdge)
        {
            ++edgeIt;
        }

        // free the pointers that any edges may have
        if (rmEdge != NULL)
        {

            qDebug() << "rmEdge val is: " << rmEdge->getWeight() << endl;
            rmEdge->freeEdge();

            // ADDED RECENTLY (Fixes weird data displayal in matrix output)
            edgeMatrix[rmVertexPtr->getVertexIndex()][index] = NULL;

            // set transpose location (if undirected graph) to NULL
            if (graphType == UNDIRECTED_GRAPH)
            {
                edgeMatrix[index][rmVertexPtr->getVertexIndex()] = NULL;
            }

            // remove from edge list
            edgeList.erase(edgeIt);
            edgeCount--;


            // delete the edge
            delete rmEdge;
        }

        index++;

    }

    /* if graph type is directed, we have to loop through rows as well */

    if (graphType == DIRECTED_GRAPH)
    {
        // find the edge O(n)
        index = 0;

        // since this is an undirected graph, delete by looping thru
        // only either a row or a column (set to NULL as well).
        while (index < size)
        {
            rmEdge = edgeMatrix[index][rmVertexPtr->getVertexIndex()];

            edgeIt = edgeList.begin();
            while (edgeIt != edgeList.end() && *edgeIt != rmEdge)
            {
                ++edgeIt;
            }

            // free the pointers that any edges may have
            if (rmEdge != NULL)
            {
                qDebug() << "rmEdge val is: " << rmEdge->getWeight() << endl;

                rmEdge->freeEdge();

                // remove from edge list
                edgeList.erase(edgeIt);
                edgeCount--;

                // delete the edge
                delete rmEdge;

                edgeMatrix[index][rmVertexPtr->getVertexIndex()] = NULL;
            }

            index++;

        }

    }

    /* delete vertex itself */
    delete rmVertexPtr;

    /* remove vertex from the vertexList */
    vertexList.erase(vertexIt);
    vertexCount--;

}
template <typename VertexType, typename WeightType>
void Graph<VertexType,WeightType>::removeEdge(Edge<VertexType,WeightType>& rmEdge)
{
    typename vector<Edge<VertexType,WeightType>* >::iterator edgeIt;
    Edge<VertexType,WeightType> *rmEdgePtr;
    int indexV1 = -1;
    int indexV2 = -1;

    rmEdgePtr = &rmEdge;

    /* iterate to location of edge in edge list */
    edgeIt = edgeList.begin();
    while (edgeIt != edgeList.end() && *edgeIt != rmEdgePtr)
    {
        ++edgeIt;
    }

    /* if vertex not found, throw exception */
    if (edgeIt == edgeList.end())
    {
        throw NotFound();
    }

    /* find inidices of two vertices */
    indexV1 = rmEdgePtr->getVertex1()->getVertexIndex();
    indexV2 = rmEdgePtr->getVertex2()->getVertexIndex();

    /* detach the vertices from the edge */
    rmEdgePtr->freeEdge();

    /* reset positions in edgeMatrix to NULL */
    edgeMatrix[indexV1][indexV2] = NULL;

    if (graphType == UNDIRECTED_GRAPH)
    {
        edgeMatrix[indexV2][indexV1] = NULL;
    }

    /* deallocate memory for edge */
    delete rmEdgePtr;

    /* remove the edge from edge list */
    edgeList.erase(edgeIt);
    edgeCount--;


}
template <typename VertexType, typename WeightType>
void Graph<VertexType,WeightType>::removeEdge(VertexType vertexData1,
                                                        VertexType vertexData2,
                                                        WeightType weight)
{

    Edge<VertexType,WeightType>* edgePtr;

    /* check to see if edge exists */
    edgePtr = this->returnEdgeFromData(vertexData1, vertexData2, weight);

    if (edgePtr != NULL)
    {
        removeEdge(*edgePtr);
    }
    else
    {
        throw NotFound();
    }

}

template <typename VertexType, typename WeightType>
void Graph<VertexType,WeightType>::destroy()
{
    //NOTE: You can re-implement this method by looping (wrapping)
    // over the removeVertex method!

    typename vector<Vertex<VertexType>* >::iterator vertexIt;

//	// Part 1
//	if (incidentEdgeList != NULL)
//	{
//		delete incidentEdgeList;
//		incidentEdgeList = NULL;
//	}

    // Part 2
    for (vertexIt = vertexList.begin(); vertexIt != vertexList.end(); ++vertexIt)
    {
        if (*vertexIt != NULL)
        {
            delete *vertexIt;
            *vertexIt = NULL;
        }
    }

    typename vector<Edge<VertexType, WeightType>* >::iterator edgeIt;

    for (edgeIt = edgeList.begin(); edgeIt != edgeList.end(); ++edgeIt)
    {
        if (*edgeIt != NULL)
        {
            delete *edgeIt;

            *edgeIt = NULL;
        }

    }

    vertexList.clear();
    edgeList.clear();



    //reset matrix back to defaults
    /* initialize every location to NULL */
    for (int row = 0; row < size; row++)
    {
        for (int col = 0; col < size; col++)
        {
            edgeMatrix[row][col] = NULL;
        }
    }

}

template <typename VertexType, typename WeightType>
void Graph<VertexType,WeightType>::reverseEdges()
{
    // Iterates through edge list, exchanges vertex1 (origin)
    // and vertex2 (destination)
    typename vector<Edge<VertexType,WeightType>* >::const_iterator edgeIt;
    Vertex<VertexType> *v1;
    Vertex<VertexType> *v2;

    if (edgeList.empty())
    {
        qDebug() << "Cannot reverse edges -- error \n";
    }
    else
    {
        for (edgeIt = edgeList.begin(); edgeIt != edgeList.end(); ++edgeIt)
        {
            v1 = (*edgeIt)->getVertex1();
            v2 = (*edgeIt)->getVertex2();

            (*edgeIt)->setVertices(*v2, *v1);
        }
    }

    vector<vector<Edge<VertexType,WeightType>* > > oldEdgeMatrix;

    oldEdgeMatrix = edgeMatrix;

    // Also update the adjacency matrix by swapping rows and columns
    for (int col = 0; col < size; col++)
    {
        for (int row = 0; row < size; row++)
        {
            edgeMatrix[col][row] = oldEdgeMatrix[row][col];
        }
    }


}

/**************************************************************************
 *  A wrapper for the true DFS (for user simplicity)
 **************************************************************************/
template <typename VertexType, typename WeightType>
void Graph<VertexType,WeightType>::DepthFirstSearch(VertexType vertexData)
{
    Vertex<VertexType> *vertex;

    vertex = returnVertexFromData(vertexData);

    // reset all vertices/edges to unexplored
    resetVertexEdgeExploration();

    /* finds the vertex from the data provided, calls real DFS */
    DepthFirstSearch(*vertex);

}

/**************************************************************************
 *  Another wrapper for the true DFS (for user simplicity)
 **************************************************************************/
template <typename VertexType, typename WeightType>
void Graph<VertexType,WeightType>::DepthFirstSearch(VertexType vertexData, vector<Vertex<VertexType>* >& vertices)
{
    Vertex<VertexType> *vertex;

    vertex = returnVertexFromData(vertexData);

    // reset all vertices/edges to unexplored
    resetVertexEdgeExploration();

    /* finds the vertex from the data provided, calls real DFS */
    DepthFirstSearch(*vertex, vertices);

}

/**************************************************************************
 *  A recursive definition for a depth-first search!
 **************************************************************************/
template <typename VertexType, typename WeightType>
void Graph<VertexType,WeightType>::DepthFirstSearch(Vertex<VertexType> &vertex)
{
    GraphEdgeHeap listOfEdges; // list of edges sorted by lowest weight
    Edge<VertexType, WeightType> *edgePtr = NULL;
    Vertex<VertexType> *oppositeVertex = NULL;
    bool graphTypeAcceptable = true;
    int size = 0;

    if (vertex.getExploration() == UNEXPLORED_VERTEX)
    {
        qDebug() << "Vertex visited: " << *vertex << endl;
    }

    // need to use arrival/departure times for directed graph
    if (graphType == DIRECTED_GRAPH)
    {
        time++;
        vertex.setArriveTime(time);
    }

    /* Set vertex VISITED */
    vertex.setExploration(VISITED_VERTEX);

    /* Retrieve all possible edges */
    incidentEdges(*vertex, listOfEdges);

    /* call method incidentDIRECTEDEdges if directed graph */

    /* compute size of this list */
    size = listOfEdges.getNumElements();

    /* iterate throughout list -- by removing the front */
    for (int i = 0; i < size; i++)
    {

        /* remove top from list and have edgePtr point to the item */
        edgePtr = listOfEdges.removeTop().getData();

        // make sure we're allowed to go in this direction
        if (graphType == DIRECTED_GRAPH)
        {
            // vertex must be the starting vertex
            if (&vertex != edgePtr->getVertex1())
            {
                graphTypeAcceptable = false;
            }
        }

        /* perform operations ONLY if edge is unexplored! */
        if (edgePtr->getExploration() == UNEXPLORED_EDGE && graphTypeAcceptable)
        {
            /* locate the opposite vertex and have oppositeVertex point to it */
            oppositeVertex = edgePtr->getOpposite(vertex);

            /* If the opposite vertex has not been visited, recursively call
             * this method */
            if (oppositeVertex->getExploration() == UNEXPLORED_VERTEX)
            {
                /* set edge status to a discovery edge */
                edgePtr->setExploration(DISCOVERY_EDGE);

                /* recurse other adjacent edges*/
                DepthFirstSearch(*oppositeVertex);
            }
            else /* we have a back edge! */
            {

                if (graphType == UNDIRECTED_GRAPH)
                {
                    edgePtr->setExploration(BACK_EDGE);
                }
                else
                {
                    // check arrival/departure time functionalities
                    // to determine different kinds of edges
                    if (vertex.getArriveTime() <
                            oppositeVertex->getArriveTime() &&
                        vertex.getDepartTime() >
                            oppositeVertex->getDepartTime())
                    {
                        edgePtr->setExploration(FORWARD_EDGE);
                    }
                    else if (vertex.getArriveTime() >
                            oppositeVertex->getArriveTime() &&
                        vertex.getDepartTime() ==
                            oppositeVertex->getDepartTime())
                    {
                        edgePtr->setExploration(BACK_EDGE);
                    }
                    else
                    {
                        edgePtr->setExploration(CROSS_EDGE);
                    }
                }
            }
        }

    }


    // need to use arrival/departure times for directed graph
    if (graphType == DIRECTED_GRAPH)
    {
        time++;
        vertex.setDepartTime(time);
    }



}

/**************************************************************************
 *  A recursive definition for a depth-first search (returns a data structure)!
 **************************************************************************/
template <typename VertexType, typename WeightType>
void Graph<VertexType,WeightType>::DepthFirstSearch(Vertex<VertexType> &vertex, vector<Vertex<VertexType>* >& vertices)
{
    GraphEdgeHeap listOfEdges; // list of edges sorted by lowest weight
    Edge<VertexType, WeightType> *edgePtr = NULL;
    Vertex<VertexType> *oppositeVertex = NULL;
    bool graphTypeAcceptable = true;
    int size = 0;

    if (vertex.getExploration() == UNEXPLORED_VERTEX)
    {
//		qDebug() << "Vertex visited: " << *vertex << endl;
        // instead of outputting to console, add to persistent data structure
        vertices.push_back(&vertex);
    }

    // need to use arrival/departure times for directed graph
    if (graphType == DIRECTED_GRAPH)
    {
        time++;
        vertex.setArriveTime(time);
    }

    /* Set vertex VISITED */
    vertex.setExploration(VISITED_VERTEX);

    /* Retrieve all possible edges */
    incidentEdges(*vertex, listOfEdges);

    /* call method incidentDIRECTEDEdges if directed graph */

    /* compute size of this list */
    size = listOfEdges.getNumElements();

    /* iterate throughout list -- by removing the front */
    for (int i = 0; i < size; i++)
    {

        /* remove top from list and have edgePtr point to the item */
        edgePtr = listOfEdges.removeTop().getData();

        // make sure we're allowed to go in this direction
        if (graphType == DIRECTED_GRAPH)
        {
            // vertex must be the starting vertex
            if (&vertex != edgePtr->getVertex1())
            {
                graphTypeAcceptable = false;
            }
        }

        /* perform operations ONLY if edge is unexplored! */
        if (edgePtr->getExploration() == UNEXPLORED_EDGE && graphTypeAcceptable)
        {
            /* locate the opposite vertex and have oppositeVertex point to it */
            oppositeVertex = edgePtr->getOpposite(vertex);

            /* If the opposite vertex has not been visited, recursively call
             * this method */
            if (oppositeVertex->getExploration() == UNEXPLORED_VERTEX)
            {
                /* set edge status to a discovery edge */
                edgePtr->setExploration(DISCOVERY_EDGE);

                /* recurse other adjacent edges*/
                DepthFirstSearch(*oppositeVertex, vertices);
            }
            else /* we have a back edge! */
            {

                if (graphType == UNDIRECTED_GRAPH)
                {
                    edgePtr->setExploration(BACK_EDGE);
                }
                else
                {
                    // check arrival/departure time functionalities
                    // to determine different kinds of edges
                    if (vertex.getArriveTime() <
                            oppositeVertex->getArriveTime() &&
                        vertex.getDepartTime() >
                            oppositeVertex->getDepartTime())
                    {
                        edgePtr->setExploration(FORWARD_EDGE);
                    }
                    else if (vertex.getArriveTime() >
                            oppositeVertex->getArriveTime() &&
                        vertex.getDepartTime() ==
                            oppositeVertex->getDepartTime())
                    {
                        edgePtr->setExploration(BACK_EDGE);
                    }
                    else
                    {
                        edgePtr->setExploration(CROSS_EDGE);
                    }
                }
            }
        }

    }


    // need to use arrival/departure times for directed graph
    if (graphType == DIRECTED_GRAPH)
    {
        time++;
        vertex.setDepartTime(time);
    }



}


/**************************************************************************
 *  A wrapper for the true BFS (for user simplicity)
 **************************************************************************/
template <typename VertexType, typename WeightType>
void Graph<VertexType,WeightType>::BreadthFirstSearch(VertexType vertexData)
{
    Vertex<VertexType> *vertex;

    vertex = returnVertexFromData(vertexData);

    // reset all vertices/edges to unexplored
    resetVertexEdgeExploration();

    /* finds the vertex from the data provided, calls real DFS */
    BreadthFirstSearch(*vertex);

}

/**************************************************************************
 *  A definition for a depth-first search using a queue datastructure!
 **************************************************************************/
template <typename VertexType, typename WeightType>
void Graph<VertexType,WeightType>::BreadthFirstSearch(Vertex<VertexType> &vertex)
{
    Edge<VertexType, WeightType> *edgePtr = NULL;
    Vertex<VertexType> *oppositeVertex = NULL;
    Vertex<VertexType> *beginVertex = NULL;
    bool graphTypeAcceptable = true;
    int size = 0;
    queue<Vertex<VertexType> *> queue;

    /* Set vertex VISITED */
    vertex.setExploration(VISITED_VERTEX);

    /* Add vertex to Queue of vertices */
    queue.push(&vertex);

    while (!queue.empty())
    {
        GraphEdgeHeap listOfEdges; // list of edges sorted by lowest weight

        beginVertex = queue.front();
        queue.pop();

        qDebug() << "Vertex visited: " << **beginVertex << endl;

        /* Retrieve all possible edges */
        incidentEdges(**beginVertex, listOfEdges);

        /* compute size of this list */
        size = listOfEdges.getNumElements();

        /* iterate throughout list -- by removing the front */
        for (int i = 0; i < size; i++)
        {

            /* remove top from list and have edgePtr point to the item */
            edgePtr = listOfEdges.removeTop().getData();

            // make sure we're allowed to go in this direction
            if (graphType == DIRECTED_GRAPH)
            {
                // vertex must be the starting vertex
                if (beginVertex != edgePtr->getVertex1())
                {
                    graphTypeAcceptable = false;
                }
            }

            /* perform operations ONLY if edge is unexplored! */
            if (edgePtr->getExploration() == UNEXPLORED_EDGE && graphTypeAcceptable)
            {
                /* locate the opposite vertex and have oppositeVertex point to it */
                oppositeVertex = edgePtr->getOpposite(*beginVertex);

                /* If the opposite vertex has not been visited, recursively call
                 * this method */
                if (oppositeVertex->getExploration() == UNEXPLORED_VERTEX)
                {
                    /* set edge status to a discovery edge */
                    edgePtr->setExploration(DISCOVERY_EDGE);

                    oppositeVertex->setExploration(VISITED_VERTEX);

                    queue.push(oppositeVertex);

                }
                else /* we have a non-tree edge! */
                {

                    if (graphType == UNDIRECTED_GRAPH)
                    {
                        edgePtr->setExploration(BACK_EDGE);
                    }
                    else
                    {
                        // directed BFS can have only back edge or
                        // cross edge (forward edges are tree edges in
                        // this case)
                        // beginVertex --------> oppositeVertex
                        if (isAncestor(*beginVertex, *oppositeVertex))
                        {
                            edgePtr->setExploration(BACK_EDGE);
                        }
                        else
                        {
                            edgePtr->setExploration(CROSS_EDGE);
                        }
                    }
                }
            }



        }
    }

}

template <typename VertexType, typename WeightType>
bool Graph<VertexType,WeightType>::isStronglyConnected(VertexType beginVertex)
{
    // Check if all vertices are accessed by DFS for a regular and
    // reversed graph (all edges reversed)
    vector<Vertex<VertexType>* > dfsVertexList;
    vector<Vertex<VertexType>* > dfsVertexListReversedGraph;

    DepthFirstSearch(beginVertex, dfsVertexList);

    this->reverseEdges();

    DepthFirstSearch(beginVertex, dfsVertexListReversedGraph);

    // set back to default
    this->reverseEdges();

    // if sizes of DFS and this graph's vertex list are equal, it is
    // strongly connected.
    if (dfsVertexList.size() 			   == this->vertexList.size() &&
        dfsVertexListReversedGraph.size()  == this->vertexList.size())
    {
        return true;
    }
    else
    {
        return false;
    }
}

// perform a DFS from end vertex to beginning vertex. We're trying
// to determine if vAncestor is an ancestor of vDescendant. To do this, we
// perform a (directed) DFS from the ancestor, and then we see if the
// descendant was reached. If so, then vAncestor is an ancestor of vDescendant
template <typename VertexType, typename WeightType>
bool Graph<VertexType,WeightType>::
    isAncestor(Vertex<VertexType> &vDescendant, Vertex<VertexType> &vAncestor)
{
    // Check if all vertices are accessed by DFS for a regular and
    // reversed graph (all edges reversed)
    vector<Vertex<VertexType>* > dfsVertexList;
    typename vector<Vertex<VertexType>* >::iterator iterator;

    GraphEdgeHeap *listOfEdges; // list of edges sorted by lowest weight
    Edge<VertexType,WeightType> *edgePtr;
    Vertex<VertexType> *vertexPtr;
    Vertex<VertexType> *oppositeVertexPtr;
    queue<Vertex<VertexType> *> queue;
    bool found = false;

    vertexPtr = &vAncestor;

    queue.push(vertexPtr);

    while (!queue.empty() && !found)
    {
        vertexPtr = queue.front();
        queue.pop();

        listOfEdges = new GraphEdgeHeap;
        this->incidentEdges(**vertexPtr,*listOfEdges);

        while (listOfEdges->getNumElements() != 0 && !found)
        {
            edgePtr = listOfEdges->removeTop().getData();

            if (edgePtr!= NULL)
            {
                if (edgePtr->getExploration() == DISCOVERY_EDGE)
                {

                    if (edgePtr->getOpposite(*vertexPtr) == &vDescendant)
                    {
                        found = true;
                    }
                    else
                    {
                        queue.push(edgePtr->getOpposite(*vertexPtr));
                    }
                }
            }
            else
            {
                qDebug() << "Edgeptr is null, something went wrong!\n";
            }
        }

        vertexPtr = (edgePtr->getOpposite(*vertexPtr));

        delete listOfEdges;
    }

    if (found)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <typename VertexType, typename WeightType>
void Graph<VertexType,WeightType>::Dijkstra(VertexType sourceVertexData)
{
    Vertex<VertexType> *sourceVertex;
    Vertex<VertexType> *currentVertex;
    int totalCost = 0;

    typename vector<Vertex<VertexType>* >::iterator vertexIt;
    stack<Vertex<VertexType> *> vertexStack;

    sourceVertex = returnVertexFromData(sourceVertexData);

    // reset all vertices/edges to unexplored
    resetVertexEdgeExploration();

    /* finds the vertex from the data provided, calls Dijkstra's Computation */
    DijkstrasComputation(*sourceVertex);

    qDebug() << left;
    // Output ALL shortest paths to screen
    for (vertexIt = vertexList.begin(); vertexIt != vertexList.end(); vertexIt++)
    {

        currentVertex = *vertexIt;

        // Only output the nodes that were used
        if (currentVertex->getCost() != int(INFINITY))
        {
            totalCost = currentVertex->getCost();

            // Search backwards until we reach source vertex
            while (currentVertex != sourceVertex)
            {
                vertexStack.push(currentVertex);
                currentVertex = currentVertex->getParent();
            }

            qDebug() << "Shortest path from " << **sourceVertex << " to " << /*setw(8) <<  */***vertexIt << " is: ";

            // output source since it is not on stack
            qDebug() << **sourceVertex;

            // pop from stack and display in reverse order since we start from end vertex
            // and backtrack to source!
            while (!vertexStack.empty())
            {
                qDebug() << " -> ";

                currentVertex = vertexStack.top();

                qDebug() << **currentVertex;

                vertexStack.pop();

            }

            qDebug() << endl << "\t : WITH TOTAL COST: " << totalCost << endl;

        }
    }
    qDebug() << right;

}

template <typename VertexType, typename WeightType>
void Graph<VertexType,WeightType>::DijkstraShortestPath(VertexType sourceVertexData, VertexType endVertexData, vector<Vertex<VertexType> *>& vertexVector, WeightType &totalCost)
{
    Vertex<VertexType> *sourceVertex;
    Vertex<VertexType> *currentVertex;
    Vertex<VertexType> *endVertex;

    totalCost = 0;

    stack<Vertex<VertexType> *> vertexStack;

    sourceVertex = returnVertexFromData(sourceVertexData);
    endVertex    = returnVertexFromData(endVertexData);

    // reset all vertices/edges to unexplored
    resetVertexEdgeExploration();

    /* finds the vertex from the data provided, calls Dijkstra's Computation */
    DijkstrasComputation(*sourceVertex);

    currentVertex = endVertex;

    // Only output the nodes that were used
    if (currentVertex->getCost() != int(INFINITY))
    {
        totalCost = currentVertex->getCost();

        // Search backwards until we reach source vertex
        while (currentVertex != sourceVertex)
        {
            vertexStack.push(currentVertex);
            currentVertex = currentVertex->getParent();
        }

//        qDebug() << "Shortest path from " << **sourceVertex << " to " << /*setw(8) <<  */**endVertex << " is: ";

//        // output source since it is not on stack
//        qDebug() << **sourceVertex;
        vertexVector.push_back(sourceVertex);

        // pop from stack and display in reverse order since we start from end vertex
        // and backtrack to source!
        while (!vertexStack.empty())
        {
//            qDebug() << " -> ";

            currentVertex = vertexStack.top();

            vertexVector.push_back(currentVertex);

//            qDebug() << **currentVertex;

            vertexStack.pop();

        }

//        qDebug() << endl << "\t : WITH TOTAL COST: " << totalCost << endl;

    }

//    qDebug() << right;
}


template <typename VertexType, typename WeightType>
void Graph<VertexType,WeightType>::MST(vector<Edge<Vertex<VertexType>,WeightType> *> &edgeVector, WeightType &totalCost)


{
    Edge<VertexType,WeightType> *currentEdge;
//    int totalCost = 0;
    totalCost = 0;
    int cost = 0;
    typename vector<Edge<VertexType,WeightType>* >::iterator edgeIt;
    stack<Vertex<VertexType> *> vertexStack;

    // reset all vertices/edges to unexplored
    resetVertexEdgeExploration();

    /* finds the vertex from the data provided, calls MST Computation */
    PrimJarnikMSTComputation();

//    qDebug() << left;

    // Output ALL MST paths to screen (and add up all total costs)
    for (edgeIt = edgeList.begin(); edgeIt != edgeList.end(); edgeIt++)
    {
        currentEdge = *edgeIt;

        // If minimum spanning tree edge
        if (currentEdge->getExploration() == DISCOVERY_EDGE)
        {
            cost = currentEdge->getWeight();
            totalCost = totalCost + cost;

            edgeVector.push_back(currentEdge);

//            qDebug() << "MST edge between ";
//            qDebug() << /*setw(8) << */ **(currentEdge->getVertex1())  << " and ";
//            qDebug() << /*setw(8) << */ **(currentEdge->getVertex2())  << " has cost: ";
//            qDebug() << cost << endl;

        }

    }

//    qDebug() << "TOTAL MST COST IS: " << totalCost << endl;

//    qDebug() << right;

}




// A C C E S S O R S
template <typename VertexType, typename WeightType>
vector<Vertex<VertexType>* >& Graph<VertexType,WeightType>::vertices() const
{
    return vertexList;
}
template <typename VertexType, typename WeightType>
vector<Edge<VertexType,WeightType>* >& Graph<VertexType,WeightType>::edges() const
{
    return edgeList;
}

template <typename VertexType, typename WeightType>
void Graph<VertexType,WeightType>::
    incidentEdges(VertexType vertexData, GraphEdgeHeap& incidentEdgeList) const
{
    Edge<VertexType,WeightType> * edgePtr = NULL;
    Vertex<VertexType> *vertexPtr = NULL;

    /* Find the vertex from the given vertex data */
    vertexPtr = this->returnVertexFromData(vertexData);

    if (vertexPtr != NULL)
    {
        int index = 0;

        /* Point edgePtr to an edge (if it exists) in the specified row
         * that corresponds to the vertex index */
        edgePtr = edgeMatrix[vertexPtr->getVertexIndex()][index];

        /* loop through a column of the adjacency matrix (const row) */
        while (index < size)
        {
            /* if the element is not equal to NULL, push it on vector
             * this means that an edge is connected to this vertex */
            if (edgePtr != NULL)
            {
                incidentEdgeList.insert(edgePtr);

            }

            index++;
            edgePtr = edgeMatrix[vertexPtr->getVertexIndex()][index];

        }

    }
    else
    {
        throw NotFound();
    }
}

template <typename VertexType, typename WeightType>
vector<Vertex<VertexType>* >& Graph<VertexType,WeightType>::
    incidentVertices(Edge<VertexType,WeightType>& edge) const
{
    vector<Vertex<VertexType>* > incidentVerticesList;

    incidentVerticesList.push_back(edge.getVertex1());
    incidentVerticesList.push_back(edge.getVertex2());

    /* return the vector */
    return incidentVerticesList;
}

// General method to display any possible exploration category of
// the edges
template <typename VertexType, typename WeightType>
void Graph<VertexType,WeightType>::displayEdges(int explorationType) const
{
    qDebug() << endl;

    QString explorationString;

    switch (explorationType)
    {
    case UNEXPLORED_EDGE: 	explorationString = "UNEXPLORED EDGE";
        break;
    case DISCOVERY_EDGE:	explorationString = "DISCOVERY EDGE";
        break;
    case BACK_EDGE: 		explorationString = "BACK EDGE";
        break;
    case FORWARD_EDGE: 		explorationString = "FORWARD EDGE";
        break;
    case CROSS_EDGE:		explorationString = "CROSS EDGE";
        break;
    default : qDebug() << "Error, edge type not found\n"; return;
        break;
    }

    qDebug() << explorationString << "S: " << endl;

    typename vector<Edge<VertexType,WeightType>* >::const_iterator edgeIt;
    bool atLeastOne = false;

    if (edgeList.empty())
    {
        qDebug() << "N/A\n";
    }
    else
    {
        for (edgeIt = edgeList.begin(); edgeIt != edgeList.end(); ++edgeIt)
        {
            if ((*edgeIt)->getExploration() == explorationType)
            {
                qDebug() << "The edge that connects "
//                     << setw(10)
                     << **((*edgeIt)->getVertex1())
                     << " and "
//                     << setw(10)
                     << **((*edgeIt)->getVertex2())
                     << " with weight: "
                     << (*edgeIt)->getWeight()
                     << " is a " << explorationString
                     <<  endl;

                atLeastOne = true;

            }
        }
    }

    if (!atLeastOne)
    {
        qDebug() << "N/A\n";
    }
}

template <typename VertexType, typename WeightType>
void Graph<VertexType,WeightType>::display() const
{
    Vertex<VertexType> *vertexPtr;

    qDebug() << left;

//    qDebug() << "THE ADJACENCY MATRIX:\n";
//    qDebug() << "=================================================================\n";

//    // outputs vertex horizontal header
////    qDebug() << setw(15) << "";

//    // loop throughout (width) size of matrix, output horizontal HEADER
//    for (int index = 0; index < size; index++)
//    {
////        qDebug() << setw(9);

//        /* returns a vertex that has a vertexIndex of index.
//         * returns NULL if not found */
//        vertexPtr = returnVertexFromIndex(index);

//        if (vertexPtr == NULL)
//        {
//            qDebug() << "N/A ";
//        }
//        else
//        {
//            // output vertex data
//            qDebug() << **vertexPtr << " ";		}

//    }

//    qDebug() << endl;

//    // outputs vertex horizontal dashes beneath header
////    qDebug() << setw(15) << "";
//    for (int i = 0; i < size; i++)
//    {
//        qDebug() /*<< setw(10) */<< "----- ";
//    }

//    qDebug() << endl;

//    // loop throughout (width) size of matrix, output vertical HEADER
//    for (int row = 0; row < size; row++)
//    {
////        qDebug() << setw(15);

//        /* returns a vertex that has a vertexIndex of index.
//         * returns NULL if not found */
//        vertexPtr = returnVertexFromIndex(row);

//        if (vertexPtr == NULL)
//        {
//            qDebug() << "N/A" << "| ";
//        }
//        else
//        {
//            // output vertex data
//            qDebug() << **vertexPtr << "| ";
//        }

//        // outputs element in each column (of the same row)
//        for (int col = 0; col < size; col++)
//        {
////            qDebug() << setw(10);
//            if (edgeMatrix[row][col] == NULL)
//            {
//                qDebug() << "0";
//            }
//            else
//            {
//                qDebug() << edgeMatrix[row][col]->getWeight();
//            }
//        }
//        qDebug() << endl << endl;


//    }


    /* OUTPUT VERTEX DATA */
    qDebug() << endl << "VERTEX INFO:\n";
    qDebug() << "There exists " << vertexList.size() << " vertices.\n";

    typename vector<Vertex<VertexType>* >::const_iterator vertexIt;

    if (vertexList.empty())
    {
        qDebug() << "N/A\n";
    }
    else
    {
        for (vertexIt = vertexList.begin(); vertexIt != vertexList.end(); ++vertexIt)
        {
            if (*vertexIt != NULL)
            {
                qDebug() << "The vertex " << ***vertexIt
                     << " has index: " << (*vertexIt)->getVertexIndex() << endl;
            }
        }
    }

    /* OUTPUT EDGE DATA */
    qDebug() << endl << "EDGE INFO:\n";
    qDebug() << "There exists " << edgeList.size() << " edges.\n";

    typename vector<Edge<VertexType,WeightType>* >::const_iterator edgeIt;

    if (edgeList.empty())
    {
        qDebug() << "N/A\n";
    }
    else
    {
        for (edgeIt = edgeList.begin(); edgeIt != edgeList.end(); ++edgeIt)
        {
            qDebug() << "The edge connecting "
//                 << setw(10)
                 << **((*edgeIt)->getVertex1())
                 << " and "
//                 << setw(10)
                 << **((*edgeIt)->getVertex2())
                 << " has weight: "
                 << (*edgeIt)->getWeight() << endl;
        }
    }

    qDebug() << right;

    qDebug() << "=================================================================\n";
}

// This method is private so that it can only be used by the class.
// The purpose behind this computation is to modify the cost & parent
// methods of EVERY VERTEX. It's the job of another method to display/store
// the shortest pathways. This is precisely what the public method
// "Dijkstra" does.
template <typename VertexType, typename WeightType>
void Graph<VertexType,WeightType>::DijkstrasComputation(Vertex<VertexType> &sourceVertex)
{
    vector<Vertex<VertexType>* > unvisitedVertices = vertexList;
    Vertex<VertexType> *currentVertex = NULL;
    Vertex<VertexType> *oldCurrentVertex = NULL;
    Vertex<VertexType> *oppositeVertex= NULL;
    Edge<VertexType,WeightType> *edge;
    typename vector<Vertex<VertexType>* >::iterator vertexIt;
    typename vector<Vertex<VertexType>* >::iterator foundVertexIt;
    int edgeListSize = 0;
    int alternate = INFINITY;
    bool finished = false;

    // Set all vertex costs to INFINITY
    // Set all vertex parents to NULL
    for (vertexIt = unvisitedVertices.begin(); vertexIt != unvisitedVertices.end(); vertexIt++)
    {
        (*vertexIt)->setCost(INFINITY);
        (*vertexIt)->setParent(NULL);
    }

    // Set the sourceVertex to 0 cost and keep its parent NULL
    sourceVertex.setCost(0);


    // Iterate all possible vertices
    while (!unvisitedVertices.empty() && !finished)
    {
        GraphEdgeHeap listOfEdges; // list of edges sorted by lowest weight
        int lowest = INFINITY;


        oldCurrentVertex = currentVertex;

        // Find vertex with smallest vertex cost, assign it into currentVertex
        for (vertexIt = unvisitedVertices.begin(); vertexIt != unvisitedVertices.end(); vertexIt++)
        {
            if ((*vertexIt)->getCost() < lowest)
            {
                currentVertex = *vertexIt;
                // store the iterator into such an iterator
                // that will allow for us to remove it in the future
                foundVertexIt = vertexIt;

                //update lowest
                lowest = currentVertex->getCost();
            }

        }
        if (currentVertex == oldCurrentVertex)
        {
            finished = true;
        }


        // make sure we actually have a currentVertex
        if (currentVertex != NULL && !finished)
        {

            // remove the current vertex from the set of unvisited vertices.
            unvisitedVertices.erase(foundVertexIt);

            // store all incident edges from the currentVertex
            incidentEdges(**currentVertex, listOfEdges);

            // get the size of edge list
            edgeListSize = listOfEdges.getNumElements();


            // iterate through ALL edges
            for (int i = 0; i < edgeListSize; i++)
            {

                edge = listOfEdges.removeTop().getData();

                // store opposite vertex from current
                oppositeVertex = edge->getOpposite(*currentVertex);

                // find the shortest total path from vertex
                alternate = currentVertex->getCost() + edge->getWeight();

                // if the alternate is shortest, set it as new cost
                // and label new parent vertex
                if (alternate < oppositeVertex->getCost())
                {
                    oppositeVertex->setCost(alternate);
                    oppositeVertex->setParent(currentVertex);

//					qDebug() << "Setting " << **oppositeVertex << " cost to " << alternate << endl;
//					qDebug() << "Setting " << **oppositeVertex << " parent to " << **currentVertex << endl;
                }

            }

        }
        else if (currentVertex == NULL)
        {
            qDebug() << "Uh oh, current vertex not found!\n";
        }
    }


}

// This method is private so that it can only be used by the class.

// The purpose behind this computation is to modify the cost & parent

// methods of EVERY VERTEX. It's the job of another method to display/store

// the shortest pathways. This is precisely what the public method

// "MST" does.

template <typename VertexType, typename WeightType>

void Graph<VertexType,WeightType>::PrimJarnikMSTComputation()

{
    vector<Vertex<VertexType>* > unvisitedVertices = vertexList;
    Vertex<VertexType> *currentVertex = NULL;
    Vertex<VertexType> *oppositeVertex= NULL;
    Vertex<VertexType> *sourceVertex = NULL;
    Edge<VertexType,WeightType> *edge;
    typename vector<Vertex<VertexType>* >::iterator vertexIt;
    typename vector<Vertex<VertexType>* >::iterator foundVertexIt;
    int edgeListSize = 0;
    int weight = INFINITY;

    // Set all vertex costs to INFINITY
    // Set all vertex parents to NULL
    for (vertexIt = unvisitedVertices.begin(); vertexIt != unvisitedVertices.end(); vertexIt++)
    {
        (*vertexIt)->setCost(INFINITY);
        (*vertexIt)->setParent(NULL);
    }

    // set an arbritrary vertex as sourceVertex...
    // in this case, the first element
    sourceVertex = *(unvisitedVertices.begin());

    // Set the sourceVertex to 0 cost and keep its parent NULL
    sourceVertex->setCost(0);

    // Iterate all possible vertices
    while (!unvisitedVertices.empty())
    {

        GraphEdgeHeap listOfEdges; // list of edges sorted by lowest weight
        int lowest = INFINITY;

        // Find vertex with smallest vertex cost, assign it into currentVertex
        for (vertexIt = unvisitedVertices.begin(); vertexIt != unvisitedVertices.end(); vertexIt++)
        {
            if ((*vertexIt)->getCost() < lowest)
            {
                currentVertex = *vertexIt;

                // store the iterator into such an iterator
                // that will allow for us to remove it in the future
                foundVertexIt = vertexIt;

                //update lowest
                lowest = currentVertex->getCost();
            }
        }

        // make sure we actually have a currentVertex
        if (currentVertex != NULL)
        {
            // remove the current vertex from the set of unvisited vertices.
            unvisitedVertices.erase(foundVertexIt);

            // store all incident edges from the currentVertex
            incidentEdges(**currentVertex, listOfEdges);

            // get the size of edge list
            edgeListSize = listOfEdges.getNumElements();

            // iterate through ALL edges
            for (int i = 0; i < edgeListSize; i++)
            {
                edge = listOfEdges.removeTop().getData();

                // store opposite vertex from current
                oppositeVertex = edge->getOpposite(*currentVertex);

                // find the shortest total path from vertex
                weight = edge->getWeight();

                // if the alternate is shortest, set it as new cost
                // and label new parent vertex
                if (weight < oppositeVertex->getCost())
                {
                    oppositeVertex->setCost(weight);
                    oppositeVertex->setParent(currentVertex);

                    // Allows us to easily locate the minimum spanning tree edges
                    edge->setExploration(DISCOVERY_EDGE);

                }
                else
                {
                    // The below if statement is VERY IMPORTANT
                    // If you do not do such a check, the shortest tree edge
                    // will be overwritten! Don't want this to happen.
                    if (currentVertex->getCost() != weight)
                    {
                        edge->setExploration(UNEXPLORED_EDGE);
                    }
                }
            }
        }

        else
        {
            qDebug() << "Opposite vertex not found, uh oh!";
            throw NotFound();
        }
    }

}


//   given a vertex index (for the matrix), returns a pointer to a
//   vertex if found, or NULL if not found
template <typename VertexType, typename WeightType>
 Vertex<VertexType>* Graph<VertexType,WeightType>::returnVertexFromIndex(int searchVertexIndex) const
{
    typename vector<Vertex<VertexType>* >::const_iterator vertexIt;

    vertexIt = vertexList.begin();
    while (vertexIt != vertexList.end())
    {
        if ((*vertexIt)->getVertexIndex() == searchVertexIndex)
        {
            return *vertexIt;
        }

        ++vertexIt;
    }

    return NULL;

}

template <typename VertexType, typename WeightType>
 Vertex<VertexType>* Graph<VertexType,WeightType>::returnVertexFromData(VertexType vertexData) const
{
    typename vector<Vertex<VertexType>* >::const_iterator vertexIt;

    /* Check if vertex exists*/
    vertexIt = vertexList.begin();
    while (vertexIt != vertexList.end())
    {
        // compare the two vertex VALUES
        if (***vertexIt == vertexData)
        {
//            qDebug() << "It exists!!";
            return *vertexIt;
        }
        else
        {
            ++vertexIt;
        }
    }
//    qDebug() << "It does not exist!!";


    return NULL;

}

template <typename VertexType, typename WeightType>
 Edge<VertexType,WeightType>* Graph<VertexType,WeightType>::
     returnEdgeFromData(VertexType vertexData1,
                        VertexType vertexData2,
                        WeightType weight) const
{
    typename vector<Edge<VertexType,WeightType>* >::const_iterator edgeIt;

    Vertex<VertexType> *v1;
    Vertex<VertexType> *v2;

    /* Check if vertex exists*/
    edgeIt = edgeList.begin();

    while (edgeIt != edgeList.end() )
    {
        v1 = (*edgeIt)->getVertex1();
        v2 = (*edgeIt)->getVertex2();

        // compare to see if edge has same vertex values and weight
        if (**v1 == vertexData1 &&
            **v2 == vertexData2 &&
           (*edgeIt)->getWeight() == weight)
        {
            return *edgeIt;
        }
        else
        {
            ++edgeIt;
        }

    }

    return NULL;

}

//Returns the first available index that may represent a vertex
template <typename VertexType, typename WeightType>
int Graph<VertexType,WeightType>::returnAvailableMatrixIndex() const
{
    int index = 0;
    bool indexFound = false; /*Outer While loop*/
    bool indexExists = false;/*Inner While loop*/
    typename vector<Vertex<VertexType>* >::const_iterator vertexIt;

    while (index < size && !indexFound)
    {
        vertexIt = vertexList.begin();

        /* attempt to find the smallest available index possible */
        while (vertexIt != vertexList.end() && !indexExists)
        {
            /* if the indices match,  exists */
            if (index == (*vertexIt)->getVertexIndex())
            {
                indexExists = true;
            }
            else
            {
                vertexIt++;
            }
        }

        if (!indexExists)
        {
            indexFound = true;
        }
        else
        {
            indexExists = false;
            index++;
        }
    }

    return index;

}

template <typename VertexType, typename WeightType>
void Graph<VertexType,WeightType>::resetVertexEdgeExploration()
{
    /* RESET VERTEX EXPLORATION */
    typename vector<Vertex<VertexType>* >::const_iterator vertexIt;

    if (!vertexList.empty())
    {
        for (vertexIt = vertexList.begin(); vertexIt != vertexList.end(); ++vertexIt)
        {
            (*vertexIt)->setExploration(UNEXPLORED_VERTEX);
            (*vertexIt)->setArriveTime(0);
            (*vertexIt)->setDepartTime(9999999);

        }
    }

    /* RESET EDGE EXPLORATION */
    typename vector<Edge<VertexType,WeightType>* >::const_iterator edgeIt;

    if (!edgeList.empty())
    {
        for (edgeIt = edgeList.begin(); edgeIt != edgeList.end(); ++edgeIt)
        {
            (*edgeIt)->setExploration(UNEXPLORED_EDGE);
        }
    }

}


#endif // GRAPH_H
