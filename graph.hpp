//2 D
#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <list>
#include <vector>
#include "statool/srand.hpp"
#include "node.hpp"
#include <algorithm>

class Graph {

protected:
  vector<Node> vertices;

public:

  void insert_connection(int n1,int n2);
  void insert_di_connection(int n1,int n2);
  void match_nodes(int n0, int n1, int n2);
  void remove_node(int n0);
  void new_remove_node(int n0);
  void remove_link(int node1,int node2);
  bool connection_check(int node1, int node2);
  bool di_connection_check(int node1, int node2);
  void clear() { vertices.clear(); }
//  void set_btwness();
  typedef list<int>::iterator node_neighbor_iterator;
  node_neighbor_iterator vertex_neighbor_begin(size_t index) { return vertices[index].neighbor_begin(); }
  node_neighbor_iterator vertex_neighbor_end(size_t index) { return vertices[index].neighbor_end(); }

  node_neighbor_iterator vertex_predecessor_begin(size_t index) { return vertices[index].predecessor_begin(); }
  node_neighbor_iterator vertex_predecessor_end(size_t index) { return vertices[index].predecessor_end(); }

  typedef vector<int>::iterator vertices_iterator;

  Graph(int num_nd) {
    vertices.resize(num_nd);
  }
  int get_deg_vertex(int idx_vertex) {
    return vertices[idx_vertex].get_degree();
  }

  int get_num_vertices() {
  return vertices.size();
  }

  int degree(int node_index)  {    return vertices[node_index].get_degree();  }
  void set_distance(int node_index,double a) {return vertices[node_index].set_distance(a);}
  void mk_cluster_status_1(int node_index) {return vertices[node_index].mk_cluster_status_1();}
  void mk_cluster_status_0(int node_index) {return vertices[node_index].mk_cluster_status_0();}

  void flip_node(int node_index)  {    vertices[node_index].flip_node();  }
  void add_a_predecessor(int node1, int node2)  {    vertices[node1].add_a_predecessor(node2);  }

  void rm_all_predecessor(int node_index)  {    vertices[node_index].rm_all_predecessor();  }

  int predecessor_num(int node_index)  {    return vertices[node_index].predecessor_num();  }


  int check_status(int node_index)  {    return vertices[node_index].check_status();  }
  int check_cluster_status(int node_index)  {    return vertices[node_index].check_cluster_status();  }
  int check_leader_status(int node_index)  {    return vertices[node_index].check_leader_status();  }
  void cluster_status_0(int node_index)  {    vertices[node_index].mk_cluster_status_0();  }
  void cluster_status_1(int node_index)  {    vertices[node_index].mk_cluster_status_1();  }
  void resize(int num_nodes)  {    vertices.resize(num_nodes);  }

  float get_distance(int node_index)  {    return vertices[node_index].get_distance();  }

   void set_btw(int node_index,float a)  {    return vertices[node_index].set_btw(a);  }
   void set_tbtw(int node_index,float a)  {    return vertices[node_index].set_tbtw(a);  }

  float get_btw(int node_index)  {    return vertices[node_index].get_btw();  }
  float get_tbtw(int node_index)  {    return vertices[node_index].get_tbtw();  }

  void set_level(int node_index, int level)  {    vertices[node_index].set_level(level);  }

  int get_level(int node_index)  {    return vertices[node_index].get_level();  }
  int get_degree(int node_index)  {    return vertices[node_index].get_degree();  }
  int get_match(int node_index)  {    return vertices[node_index].get_match();  }
  bool check_matched(int node_index) {    return vertices[node_index].check_matched();  }

};

//-------------------------------------------------------------------------------------------------------
bool Graph::connection_check(int node1, int node2){
node_neighbor_iterator it;
for(it=vertex_neighbor_begin(node1);it!=vertex_neighbor_end(node1);++it)
	if(*it==node2)
	return true;
return false;
}

bool Graph::di_connection_check(int node1, int node2){
node_neighbor_iterator it;
for(it=vertex_neighbor_begin(node1);it!=vertex_neighbor_end(node1);++it)
	if(*it==node2)
	return true;
return false;
}

//match nodes
void Graph::match_nodes(int n0, int n1, int n2) {
  vertices[n0].go_match(n1,n2);
}

//insert additional connections
void Graph::insert_connection(int n1,int n2) {
  vertices[n1].add_a_neighbor(n2);
  vertices[n2].add_a_neighbor(n1);
}

//insert additional connections
void Graph::insert_di_connection(int n1,int n2) {
  vertices[n1].add_a_neighbor(n2);
}

// remove a node from graph
void Graph::remove_node(int n0) {
       vector<int> remove_list;
      for (node_neighbor_iterator it = vertices[n0].neighbor_begin(); it != vertices[n0].neighbor_end(); it++){
          remove_list.push_back(*it);
      }
      for (int i = 0; i < remove_list.size(); i++){
          vertices[remove_list[i]].remove_a_neighbor(n0);
      }
      vertices[n0].remove_all_neighbors();
}
void Graph::new_remove_node(int n0) {
      vector<int> remove_list;
      for (node_neighbor_iterator it = vertices[n0].neighbor_begin(); it != vertices[n0].neighbor_end(); it++){
          remove_list.push_back(*it);
      }
      for (int i = 0; i < remove_list.size(); i++){
          vertices[remove_list[i]].remove_a_neighbor(n0);
      }
      vertices[n0].remove_all_neighbors();
}
void Graph::remove_link(int node1,int node2) {
    vertices[node1].remove_a_neighbor(node2);
}
/*
void Graph::remove_node(int n0) {
      vector<int> remove_list;
      int num_neighbor = vertices[n0].get_degree();
      for (node_neighbor_iterator it = vertices[n0].neighbor_begin(); it != vertices[n0].neighbor_end(); it++){
          remove_list.push_back(*it);
      }
      for (int i = 0; i < remove_list.size(); i++){
          vertices[i].remove_a_neighbor(n0);
      }
      vertices[n0].remove_all_neighbors();
}
*/
#endif
