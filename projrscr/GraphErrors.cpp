/**************************************************************************
* AUTHOR        : Austin Vaday
* Assignment #  : 11
* CLASS         : CS1D
* SECTION       : T TH: 5:30 - 7:20 P.M.
* DUE DATE      : 4/7/15
**************************************************************************/
#include "header.h"

//#define TESTING

void AustinsMain();

int main()
{
    try{
    
    cout << "Trying to break the graph...\n\n";
    cout << "Let's create 1000 of the same edge and see what happens.";
    Graph<string, int> graph1(1000, UNDIRECTED_GRAPH);
    for (int i = 0; i < 1000; i++)
    {
        graph1.insert("Los Angeles", "Kansas City", 1663);
    }
    cout << endl;
    // graph1.display();       // This doesn't crash. Commented out because it takes forever to run.
    cout << "\nThat works but I didn't print because it took forever.";
    
    //////////////////////// Test 2 ////////////////////////////////////
    
    cout << "\n\nCreating a new graph with 5 edges.";
    Graph<string, int> graph2(10, UNDIRECTED_GRAPH);
    graph2.insert("Los Angeles", "Kansas City", 1663);
    graph2.insert("Kansas City", "Atlanta", 864);
    graph2.insert("Atlanta", "New York", 888);
    graph2.insert("New York", "Boston", 214);   
    graph2.insert("Boston", "Chicago", 983);     
    cout << endl;
    graph2.display();  
    cout << "\nLet's try to use a really large number for mileage and see if that works.";
    cout << "\nLet's build a stadium on the moon.";
    graph2.insert("Los Angeles", "The Moon", 238855);
    graph2.display();
    cout << "\nWhat about on Mars? When it is at the farthest point from earth, of course.";
    graph2.insert("Los Angeles", "Mars", 225000000);       
    graph2.display();
    cout << "\nThat works.";
    
    ////////////////////// Test 3 //////////////////////////////////////////
    cout << "\nLet's try to delete a valid vertex.";
    graph2.removeVertex("Los Angeles");
    cout << "\nLet's try to remove a vertex that never existed.";
    // graph2.removeVertex("San Diego");   // Crashes here. "terminate called after throwing an instance of 'NotFound'"
    // graph2.display();
    cout << "\nThat caused a crash.";
    
    /////////////////////// Test 4 //////////////////////////////////////////
    cout << "\n\nCreating a new graph.";
    Graph<string, int> graph3(10, UNDIRECTED_GRAPH);
    graph3.insert("Los Angeles", "Kansas City", 1663);
    graph3.insert("Kansas City", "Atlanta", 864);
    graph3.insert("Atlanta", "New York", 888);
    graph3.insert("New York", "Boston", 214);   
    graph3.insert("Boston", "Chicago", 983);  
    graph3.display();
    cout << "\nLet's remove an existing edge. Removing LA to Kansas City.";
    graph3.removeEdge("Los Angeles", "Kansas City", 1663);
    graph3.display();
    cout << "\nLet's try to remove an edge that doesn't exist.";
    // graph3.removeEdge("Los Angeles", "Chicago", 1234);    // Crashes here. "terminate called after throwing an instance of 'NotFound'"
    // graph3.display();
    cout << "\nThat caused a crash.";
    
    ///////////////////////// Test 5 //////////////////////////////////////////
    
    cout << "\n\nCreating a new graph.";
    Graph<string,int> graph4(12, UNDIRECTED_GRAPH); // 12 vertices
    graph4.insert("Seattle", "San Francisco", 807);
    graph4.insert("Seattle", "Denver", 1331);
    graph4.insert("Chicago", "Seattle", 2097);
    graph4.insert("Chicago", "Boston", 983);
    graph4.insert("Denver","San Francisco", 1267);
    graph4.insert("Denver", "Chicago", 1003);
    graph4.insert("San Francisco", "Los Angeles", 381);
    graph4.insert("Los Angeles", "Denver", 1015);
    graph4.insert("Kansas City","Los Angeles", 1663);
    graph4.insert("Kansas City", "Chicago", 533);
    graph4.insert("Kansas City", "Denver", 599);
    graph4.insert("Kansas City", "New York", 1260);
    graph4.insert("Kansas City", "Atlanta", 864);
    graph4.insert("Dallas", "Los Angeles", 1435);
    graph4.insert("Dallas", "Kansas City", 496);
    graph4.insert("Dallas", "Atlanta", 781);
    graph4.insert("New York", "Chicago", 787);
    graph4.insert("New York", "Atlanta", 888);
    graph4.insert("Houston", "Dallas", 239);
    graph4.insert("Houston", "Atlanta", 810);
    graph4.insert("Miami", "Houston", 1187);
    graph4.insert("Boston", "New York", 214);
    graph4.insert("Atlanta", "Miami", 661);
    graph4.display();
    cout << "\nLet's try the following sequence for vertices.";
    cout << "\nremove - remove - add - add - remove";
    cout << "\nRemoving Atlanta";
    graph4.removeVertex("Atlanta");
    cout << "\nRemoving Boston";
    graph4.removeVertex("Boston");
    cout << "\nAdding edge from San Diego to Sacramento\n";
    graph4.insert("San Diego", "Sacramento", 504);
    graph4.display();
    cout << "\nAdding edge from Las Vegas to Austin\n";
    // graph4.insert("Las Vegas", "Austin", 1085);  // crashes here because I tried to add another edge to a full matrix
    cout << "\nThat caused a crash. Can't add another edge because the matrix was already full.";
    
    ///////////////////// Test 6 /////////////////////////////////////////////
    cout << "\n\nTrying to create graph with 0 vertices.";
    Graph<string,int> graph5(0, UNDIRECTED_GRAPH); 
    graph5.display();
    
    ////////////////////////////Test 7 ////////////////////////////////////
    cout << "Trying to create a graph with a name that's already been used.";
    // Graph<string,int> graph5(10, UNDIRECTED_GRAPH);  // compile error here because graph5 already declared
    cout << "\nThat caused a compile error because graph5 is previously declared.";
    
    ///////////////////////////// Test 8 ///////////////////////////////////////
    cout << "\n\nLet's run some tests with Dijkstra and MST.";
    cout << "\nTesting the sequence Dijkstra - Dijkstra - MST - Remove - Add";
    // graph4.Dijkstra("Sacramento");   // Crashes here. Maybe because Sacramento and San Diego are not connected to other vertices
    
    /////////////////////////// Test 9 /////////////////////////////////////////
    cout << "\n\nLet's recreate the graph from homework 12.";
    Graph<string,int> graph6(12, UNDIRECTED_GRAPH); 
    graph6.insert("Seattle", "SF", 807);
    graph6.insert("Seattle", "Denver", 1331);
    graph6.insert("Chicago", "Seattle", 2097);
    graph6.insert("Chicago", "Boston", 983);
    graph6.insert("Denver","SF", 1267);
    graph6.insert("Denver", "Chicago", 1003);
    graph6.insert("SF", "LA", 381);
    graph6.insert("LA", "Denver", 1015);
    graph6.insert("KC","LA", 1663);
    graph6.insert("KC", "Chicago", 533);
    graph6.insert("KC", "Denver", 599);
    graph6.insert("KC", "New York", 1260);
    graph6.insert("KC", "Atlanta", 864);
    graph6.insert("Dallas", "LA", 1435);
    graph6.insert("Dallas", "KC", 496);
    graph6.insert("Dallas", "Atlanta", 781);
    graph6.insert("New York", "Chicago", 787);
    graph6.insert("New York", "Atlanta", 888);
    graph6.insert("Houston", "Dallas", 239);
    graph6.insert("Houston", "Atlanta", 810);
    graph6.insert("Miami", "Houston", 1187);
    graph6.insert("Boston", "New York", 214);
    graph6.insert("Atlanta", "Miami", 661);
    graph6.display();
    cout << "\nDijkstra's Shortest Path Algorithm starting from Seattle: \n";
    graph6.Dijkstra("Seattle");
    cout << "\nDijkstra's Shortest Path Algorithm starting from Chicago: \n";
    graph6.Dijkstra("Chicago");
    cout << "\nMST";
    graph6.MST();
    cout << "\nDeleting edge from Boston to New York";
    graph6.removeEdge("Boston", "New York", 214);
    graph6.insert("Boston", "Miami", 1256);
    graph6.display();
    graph6.Dijkstra("Boston");
    graph6.MST();
    //////////////////////// Test 10 //////////////////////////////////
    Graph<string,int> graph7(12, UNDIRECTED_GRAPH); 
    graph7 = graph6;
    graph6.destroy();
    cout << "\nGraph 6:";
    graph6.display();
    cout << "\nGraph 7:";
    graph7.display();
    
    
    }
    
    catch (const OutOfRange&)
	{
		cout << "Inside Catch -- OutOfRange\n";

	}
	catch (const NotFound&)
	{
		cout << "Inside Catch -- NotFound\n";

	}
	catch (const Full&)
	{
		cout << "Inside Catch -- Full\n";

	}
	catch (const Empty&)
	{
		cout << "Inside Catch -- Empty\n";

	}
	catch (const NoParent&)
	{
		cout << "Inside Catch -- No Parent\n";

	}
	catch (const ExternalNode&)
	{
		cout << "Inside Catch -- External Node\n";

	}
	catch (const RootAlreadyExists&)
	{
		cout << "Inside Catch -- Root Already Exists\n";

	}
	catch (const TreeError&)
	{
		cout << "Inside Catch -- Tree Error\n";
		cout << "Check your tree insertions and/or deletions\n";

	}
	catch (const BadHash&)
	{
		cout << "Inside Catch -- Bad Hash\n";
		cout << "Please check your hashing class!\n";
	}
	catch (const IndexNotSet&)
	{
		cout << "Inside Catch -- IndexNotSet\n";
		cout << "Please check your Vertex class!\n";
	}
	catch(...)
	{
		cout << "Inside Catch All\n";
	}
    
    
    
    
    
    
    
    
    
    
    // AustinsMain();

    return 0;

}

void AustinsMain()
{
    	// Calls the function "PrintHeader" to output a class header
	cout << PrintHeader ("Dijkstra's Algorithm and MST", 'A', 12);

	try
	{

	#ifdef TESTING
		Graph<string,int> graph(8, DIRECTED_GRAPH);

		graph.insert("v1","v2",1);

		graph.insert("v2","v3",10);

		graph.insert("v3","v1",1);

		graph.insert("v3","v4",2);

		graph.insert("v4","v1",2);

		graph.display();


		graph.removeVertex("v4");
		graph.removeVertex("v2");

		graph.insert("v1","v2",1);

		graph.insert("v2","v3",10);

		graph.insert("v3","v4",2);

		graph.insert("v4","v1",2);





		graph.display();

		cout << "DFS: \n";
		graph.DepthFirstSearch("v1");

		graph.displayEdges(DISCOVERY_EDGE);
		graph.displayEdges(BACK_EDGE);
		graph.displayEdges(FORWARD_EDGE);
		graph.displayEdges(CROSS_EDGE);


		cout << endl << endl;

		cout << "The graph is ";
		if (!graph.isStronglyConnected("v1"))
		{
			cout << "NOT ";
		}
		cout << "strongly connected!\n";




	#else

		Graph<string,int> graph(12, UNDIRECTED_GRAPH); // 12 vertices
//		UndirectedGraph<string,int>::GraphEdgeHeap *gHeap;

		/* connect all nodes of graph */
		graph.insert("Seattle", "San Fran", 807);
		graph.insert("Seattle", "Denver", 1331);

		graph.insert("Chicago", "Seattle", 2097);
		graph.insert("Chicago", "Boston", 983);

		graph.insert("Denver","San Fran", 1267);
		graph.insert("Denver", "Chicago", 1003);

		graph.insert("San Fran", "Los Ang", 381);

		graph.insert("Los Ang", "Denver", 1015);

		graph.insert("Kansas C","Los Ang", 1663);
		graph.insert("Kansas C", "Chicago", 533);
		graph.insert("Kansas C", "Denver", 599);
		graph.insert("Kansas C", "New York", 1260);
		graph.insert("Kansas C", "Atlanta", 864);

		graph.insert("Dallas", "Los Ang", 1435);
		graph.insert("Dallas", "Kansas C", 496);
		graph.insert("Dallas", "Atlanta", 781);

		graph.insert("New York", "Chicago", 787);
		graph.insert("New York", "Atlanta", 888);

		graph.insert("Houston", "Dallas", 239);
		graph.insert("Houston", "Atlanta", 810);

		graph.insert("Miami", "Houston", 1187);

		graph.insert("Boston", "New York", 214);

		graph.insert("Atlanta", "Miami", 661);

		graph.display();

		cout << endl;

		cout << "PART A\n";
		cout << "----------------------------------------------------\n";

		cout << "Dijkstra's Shortest Path Algorithm: \n";
		graph.Dijkstra("Seattle");

		cout << endl;

		cout << "PART B\n";
		cout << "----------------------------------------------------\n";

		cout << "Prim Jarnik's Minimum Spanning Tree Algorithm: \n";
		graph.MST();

	#endif /*TESTING*/


	}
	catch (const OutOfRange&)
	{
		cout << "Inside Catch -- OutOfRange\n";

	}
	catch (const NotFound&)
	{
		cout << "Inside Catch -- NotFound\n";

	}
	catch (const Full&)
	{
		cout << "Inside Catch -- Full\n";

	}
	catch (const Empty&)
	{
		cout << "Inside Catch -- Empty\n";

	}
	catch (const NoParent&)
	{
		cout << "Inside Catch -- No Parent\n";

	}
	catch (const ExternalNode&)
	{
		cout << "Inside Catch -- External Node\n";

	}
	catch (const RootAlreadyExists&)
	{
		cout << "Inside Catch -- Root Already Exists\n";

	}
	catch (const TreeError&)
	{
		cout << "Inside Catch -- Tree Error\n";
		cout << "Check your tree insertions and/or deletions\n";

	}
	catch (const BadHash&)
	{
		cout << "Inside Catch -- Bad Hash\n";
		cout << "Please check your hashing class!\n";
	}
	catch (const IndexNotSet&)
	{
		cout << "Inside Catch -- IndexNotSet\n";
		cout << "Please check your Vertex class!\n";
	}
	catch(...)
	{
		cout << "Inside Catch All\n";
	}

}

