#include <iostream>
#include <vector>

using namespace std;

template <class N, class E> class Edge;

/**
 * Node class
 *
 * @tparam N - Type of the value of each node
 * @tparam E - Type of edge values
 */
template <class N, class E>
class Node {
public:
    N info;
    vector< Edge<N,E> > edges;

    explicit Node(N inf) {
        info = inf;
    }

};

/**
 * Edge class - Holds the transition between two nodes
 *
 * @tparam N - Type of the destination node
 * @tparam E - Type of value held by edge
 */
template <class N, class E>
class Edge {
public:
    /// Value of the edge
    E value;
    /// Destination of the edge
    Node<N,E> *destination;

    /**
     * Constructor of edge
     *
     * @param dest - Next node connected
     * @param val - Value of the current edge
     */
    Edge(Node<N,E> *dest, E val) {
        value = val;
        destination = dest;
    }

    bool operator == (const Edge & other){
        return value == other.value || destination->info == other.destination->info;
    }
};

/**
 * Graph Class - Contains every node and manages them
 *
 * @tparam N - Type of the nodes of the graph
 * @tparam E - Type of the edges of the graph
 */
template <class N, class E>
class Graph {

    /**
     * Vector of nodes (allocated in memory - must be freed)
     */
    vector< Node<N,E> *> nodes;
public:
    Graph() = default;
    ~Graph();
    /**
     * Adds a node to the graph
     *
     * @param inf - Node to be added
     * @return Reference to the graph
     */
    Graph & addNode(const N &inf);

    /**
     * Adds an edge betweeen two nodes
     *
     * @param begin - Origin node
     * @param end - Receptor node
     * @param val - The value of the edge
     * @return Reference to the graph
     */
    Graph & addEdge(const N &begin, const N &end, const E &val);

    /**
     * Removes an edge from the graph
     *
     * @param begin - First node's info
     * @param end - Final node's info
     * @return Referece to the graph
     */
    Graph & removeEdge(const N &begin, const N &end);

    /**
     * Info about the edge value between two nodes
     *
     * @param begin - First node's info
     * @param end - Second node's info
     * @return Edge's value
     */
    E & edgeValue(const N &begin, const N &end);

    /**
     * Number of edges in graph
     *
     * @return number of edges
     */
    unsigned numEdges() const;

    /**
     * Number of nodes in graph
     *
     * @return number of nodes
     */
    unsigned numNodes() const;

    /**
     * Function to send the info about the graph to a stream
     *
     * @param os - Correspondent stream
     */
    void print(std::ostream &os) const;
};


template <class N, class E>
std::ostream & operator<<(std::ostream &out, const Graph<N,E> &g);


// exception NodeAlreadyExists
template <class N>
class NodeAlreadyExists
{
public:
    N info;
    explicit NodeAlreadyExists(N inf) { info=inf; }
};
template <class N>
std::ostream & operator<<(std::ostream &out, const NodeAlreadyExists<N> &no)
{ out << "Node already exists: " << no.info; return out; }


// exception NodeDoesNotExist
template <class N>
class NodeDoesNotExist {
public:
    N info;
    explicit NodeDoesNotExist(N inf) {
        info = inf;
    }
};

template <class N>
std::ostream & operator<<(std::ostream &out, const NodeDoesNotExist<N> &no)
{ out << "Node does not exist: " << no.info; return out; }

template <class N>
class EdgeAlreadyExists{
public:
    N node1;
    N node2;
    EdgeAlreadyExists(N n1,N n2) : node1(n1), node2(n2){};

};

template <class N>
ostream & operator<< (ostream & os, const EdgeAlreadyExists<N> & edgeAlreadyExists){
    os << "Edge already exists: " << edgeAlreadyExists.node1 << " , " << edgeAlreadyExists.node2;
    return os;
}

template <class N>
class EdgeDoesNotExist{
public:
    N node1;
    N node2;
    EdgeDoesNotExist(N n1,N n2) : node1(n1), node2(n2){};

};

template <class N>
ostream & operator<< (ostream & os, const EdgeDoesNotExist<N> & edgeDoesNotExist){
    os << "Edge does not exist: " << edgeDoesNotExist.node1 << " , " << edgeDoesNotExist.node2;
    return os;
}



template<class N, class E>
Graph<N,E>& Graph<N, E>::addNode(const N &inf) {
    auto it = std::find_if(nodes.begin(), nodes.end(), [inf](Node<N,E> * val){return val->info == inf;});
    if (it != nodes.end()) throw NodeAlreadyExists<N>(inf);
    else {
        auto * node = new Node<N,E>(inf);
        auto it = std::find_if(nodes.begin(), nodes.end(), [inf](Node<N,E> * val){return val->info > inf;});

        nodes.insert(it, node);
        return *this;
    }
}

template<class N, class E>
Graph<N,E>& Graph<N, E>::addEdge(const N &begin, const N &end, const E &val) {
    bool n1 = false, n2 = false;
    Node<N,E>* node1;
    Node<N,E>* node2;


    for(auto & node : nodes){
        if (begin == node->info){
            n1 = true;
            node1 = node;
        }
        else if (end == node->info){
            n2 = true;
            node2 = node;
        }

        if(n1 && n2) break; // Exiting loop because everything is valid
    }

    if(!n1) throw NodeDoesNotExist<N>(begin);
    else if(!n2) throw NodeDoesNotExist<N>(end);

    Edge<N, E> edge(node2, val);

    if (std::find((node1->edges).begin(), (node1->edges).end(), edge) != node1->edges.end()){
        throw EdgeAlreadyExists<N>(begin, end);
    }
    auto it = std::find_if((node1->edges).begin(), (node1->edges).end(),
                        [end](const Edge<N,E> & e){return e.destination->info > end;});
    node1->edges.insert(it, edge);


    return *this;
}


template<class N, class E>
Graph<N, E>::~Graph() {
    for (auto & node : nodes) delete node;
}

template<class N, class E>
unsigned Graph<N, E>::numNodes() const {
    return nodes.size();
}

template<class N, class E>
unsigned Graph<N, E>::numEdges() const {
    int sum = 0;
    for(const auto & node : nodes) sum += node->edges.size();
    return sum;
}


template<class N, class E>
E& Graph<N, E>::edgeValue(const N &begin, const N &end) {
    auto node1 = std::find_if(nodes.begin(), nodes.end(), [begin](Node<N,E> * val){return val->info == begin;});
    auto node2 = std::find_if(nodes.begin(), nodes.end(), [end](Node<N,E> * val){return val->info == end;});

    if(node1 == nodes.end()) throw NodeDoesNotExist<N>(begin);
    else if(node2 == nodes.end()) throw NodeDoesNotExist<N>(end);

    auto it = std::find_if((*node1)->edges.begin(), (*node1)->edges.end(), [node2](Edge<N,E> val){return val.destination == *node2;});

    if( it == (*node1)->edges.end()) throw EdgeDoesNotExist<N>(begin, end);

    return (*it).value;
}


template<class N, class E>
Graph<N,E>& Graph<N, E>::removeEdge(const N &begin, const N &end) {

    auto node1 = std::find_if(nodes.begin(), nodes.end(), [begin](Node<N,E> * val){return val->info == begin;});
    auto node2 = std::find_if(nodes.begin(), nodes.end(), [end](Node<N,E> * val){return val->info == end;});

    if(node1 == nodes.end()) throw NodeDoesNotExist<N>(begin);
    else if(node2 == nodes.end()) throw NodeDoesNotExist<N>(end);

    auto it = std::find_if((*node1)->edges.begin(), (*node1)->edges.end(), [node2](Edge<N,E> val){return val.destination == *node2;});

    if( it == (*node1)->edges.end()) throw EdgeDoesNotExist<N>(begin, end);

    (*node1)->edges.erase(it);

    return *this;
}

template<class N, class E>
void Graph<N, E>::print(ostream &os) const {
    for (const auto & node : nodes){
        os << "( " << node->info;
        for (const auto & edge : node->edges){
            os << "[ " << edge.destination->info << " " << edge.value << "] ";
        }
        os << ") ";
    }
}

template <class N, class E>
ostream & operator << (ostream & os, const Graph<N,E> & graph){
    graph.print(os);
    return os;
}

