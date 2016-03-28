#ifndef NODE_HPP
#define NODE_HPP

class Node {

protected:
  list<int> neighbors;
  list<int> predecessor;
  int status;// down:-1, up: +1
  int cluster_status;
  int flip_status;//flip :1, don't flip 0;
  int leader_status;//leader 1, not_leader 0;
  float btwness;
  float tbtwness;
  float d;
  int level;
  bool matched;
  int match_who;

public:
  typedef list<int>::iterator neighbor_iterator;
  neighbor_iterator neighbor_begin() { return neighbors.begin(); }
  neighbor_iterator neighbor_end() { return neighbors.end(); }
  neighbor_iterator predecessor_begin(){return predecessor.begin();}

  neighbor_iterator predecessor_end(){return predecessor.end();}

  void go_match(int num,int num_nodes){
      if (num < num_nodes){
          matched = true;
          match_who = num;
      }
      else{
          matched = false;
          match_who = num;
      }
  }
  void add_a_neighbor(int other_node_index)
  {
      neighbors.push_back(other_node_index);
  }
/// remove a neighbor from node
  void remove_a_neighbor(int one_node_index) {
      for (neighbor_iterator it = neighbors.begin(); it != neighbors.end(); it++) {
          if (*it == one_node_index) {neighbors.erase(it);break;}
      }
  }
  void remove_all_neighbors() {
       neighbors.clear();
  }
  void add_a_predecessor(int node_index)
  {
    predecessor.push_back(node_index);
  }

  int get_degree() { return neighbors.size(); }
  int get_match() { return match_who; }
  bool check_matched() { return matched; }

  void rm_all_predecessor()  {    predecessor.clear();  }

  int predecessor_num()  {    return predecessor.size();  }

  void mk_status_up(){status=1;} //up
  void mk_status_down(){status=-1;} //down
  void mk_cluster_status_1(){cluster_status=1;}//alreay belong to a cluster
  void mk_cluster_status_0(){cluster_status=0;}//don't belong to any cluster yet
  void mk_flip_status_1(){flip_status=1;}//flip
  void mk_flip_status_0(){flip_status=0;}//not flip
  void mk_leader_status_1(){leader_status=1;} //leader

  int check_status(){return status;}
  int check_cluster_status(){return cluster_status;}
  int check_leader_status(){return leader_status;}

  void set_distance(double a){ d=a;}
  void set_btw(float a){btwness=a;}
  void set_tbtw(float a){tbtwness=a;}
  float get_distance(){return d;}
  float get_btw(){return btwness;}
  float get_tbtw(){return tbtwness;}
  void set_level(int a){level=a;}
  int get_level(){return level;}



  void flip_node(){status=0-status;}
  Node()
  {
    status=0; //alive
    cluster_status=0; //don't belong to any cluster yet
    flip_status=0;
    leader_status=0;
    d=0;
    tbtwness=0;
    btwness=0;
    matched = false;
  }

};

#endif
