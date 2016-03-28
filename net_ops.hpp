#ifndef NET_OPS_HPP
#define NET_OPS_HPP

#include <queue>
#include <stack>
#include <set>
#include <vector>
#include <algorithm>

inline void find_cluster_sizes(Graph & net, priority_queue<int> & cluster_sizes) {
  cluster_sizes=priority_queue<int>();
  int num_nodes=net.get_num_vertices();
  bool * marked;
  marked=new bool[num_nodes];
  for (int i=0; i < num_nodes; ++i) marked[i]=false;
  stack<int> search_stack;
  int cluster_size;
  int idx_search;
  Graph::node_neighbor_iterator idx_neighbor;

  for (int idx_node=0; idx_node < num_nodes; ++idx_node) {
    if (!marked[idx_node]) {
      cluster_size=1;
      search_stack.push(idx_node);
      marked[idx_node]=true;

      while (!search_stack.empty()) {
	idx_search=search_stack.top();
	search_stack.pop();
	for (idx_neighbor=net.vertex_neighbor_begin(idx_search);
	     idx_neighbor!=net.vertex_neighbor_end(idx_search); ++idx_neighbor)
	  if (!marked[*idx_neighbor]) {
	    search_stack.push(*idx_neighbor);
	    ++cluster_size;
	    marked[*idx_neighbor]=true;
	  }
      }
      cluster_sizes.push(cluster_size);
    }
  }
  cluster_sizes.push(0); // to make at least 2 clusters
  delete []marked;
}

// find the vector of nodes within the distance R to the source node
inline void find_r_ndist(const int num_nodes, Graph net, const int idx_source, vector<int> & R_dist, int R) {
    R_dist.clear();
    set<int> all_nodes,nextshell;
    vector<int> vnowshell;
    int distance = 0;
    int node_pointer;
    Graph::node_neighbor_iterator idx_neighbor;
    set<int>::iterator iter;
    all_nodes.insert(idx_source);
    vnowshell.push_back(idx_source);
    while (distance < R) {
        distance = distance+1;
        nextshell.clear();
        while (!vnowshell.empty()) {
            node_pointer = vnowshell.back();
            vnowshell.pop_back();
            for (idx_neighbor=net.vertex_neighbor_begin(node_pointer);idx_neighbor!=net.vertex_neighbor_end(node_pointer); idx_neighbor++) {
                if(!all_nodes.count(*idx_neighbor)){
                    nextshell.insert(*idx_neighbor);
                    all_nodes.insert(*idx_neighbor);
                }
            }
        }
        vnowshell.clear();
        if (nextshell.empty()){
            break;
        }
        else{
            for (iter = nextshell.begin();iter != nextshell.end();iter++){
                vnowshell.push_back(*iter);
            }
        }
    }
    for (iter = all_nodes.begin();iter != all_nodes.end();iter++){
        R_dist.push_back(*iter);
    }
}

// find the vector of nodes within the distance R to the source node
inline void find_r_ndist_without(const int num_nodes, Graph net, const int idx_source, vector<int> & R_dist, int R) {
    R_dist.clear();
    set<int> all_nodes,nextshell,nowshell;
    vector<int> vnowshell;
    int distance = 0;
    int node_pointer;
    Graph::node_neighbor_iterator idx_neighbor;
    set<int>::iterator iter;
    all_nodes.insert(idx_source);
    vnowshell.push_back(idx_source);
    while (distance < R) {
        distance = distance+1;
        nextshell.clear();
        while (!vnowshell.empty()) {
            node_pointer = vnowshell.back();
            vnowshell.pop_back();
            for (idx_neighbor=net.vertex_neighbor_begin(node_pointer);idx_neighbor!=net.vertex_neighbor_end(node_pointer); idx_neighbor++) {
                if(!all_nodes.count(*idx_neighbor)){
                    nextshell.insert(*idx_neighbor);
                    all_nodes.insert(*idx_neighbor);
                }
            }
        }
        vnowshell.clear();
        if (nextshell.empty()){
            break;
        }
        else{
            for (iter = nextshell.begin();iter != nextshell.end();iter++){
                vnowshell.push_back(*iter);
            }
        }
    }
    for (iter = nextshell.begin();iter != nextshell.end();iter++){
        R_dist.push_back(*iter);
    }
}

/*
// find the vector of nodes at distance R to the source node
inline void find_r_ndist_new(const int num_nodes, Graph net, const int idx_source, vector<int> & R_dist, int R) {
  R_dist.clear();
  bool *marked;
  marked=new bool[num_nodes];
  for (int i=0; i < num_nodes; ++i) marked[i]=false;
  int distance = 0;
  int node_pointer;
  Graph::node_neighbor_iterator idx_neighbor;
  marked[idx_source]=true;
  vector<int> shell;
  vector<int> nextshell;
  R_dist.push_back(idx_source);
  shell.push_back(idx_source);
 // nextshell.push_back(idx_source);
  //cout<<"idx_source = "<<idx_source<<endl;
  while (distance < R) {
     // cout<<"distance = "<<distance<<'\t'<<"size of shell = "<<shell.size()<<endl;
      nextshell.clear();
      while (!shell.empty()) {
          node_pointer=shell.back();
          shell.pop_back();
          for (idx_neighbor=net.vertex_neighbor_begin(node_pointer);idx_neighbor!=net.vertex_neighbor_end(node_pointer); ++idx_neighbor) {
              if(!marked[*idx_neighbor]) {
	             nextshell.push_back(*idx_neighbor);
                 marked[*idx_neighbor]=true;
	             R_dist.push_back(*idx_neighbor);
              }
           }
      }
      distance++;
      if (distance == R) {
          break;
      }
      shell.clear();
      while (!nextshell.empty()) {
          node_pointer=nextshell.back();
          nextshell.pop_back();
          for (idx_neighbor=net.vertex_neighbor_begin(node_pointer);idx_neighbor!=net.vertex_neighbor_end(node_pointer); ++idx_neighbor) {
              if(!marked[*idx_neighbor]) {
	             shell.push_back(*idx_neighbor);
                 marked[*idx_neighbor]=true;
	             R_dist.push_back(*idx_neighbor);
              }
           }
      }
      distance++;
  }
  delete []marked;
}
*/
/*
// find the vector of nodes at distance R to the source node
inline void find_r_ndist(const int num_nodes, Graph net, const int idx_source, vector<int> & R_dist, int R) {
  R_dist.clear();
  bool * marked;
  marked=new bool[num_nodes];
  for (int i=0; i < num_nodes; ++i) marked[i]=false;
  int distance = 0;
  int node_pointer;
  Graph::node_neighbor_iterator idx_neighbor;
  marked[idx_source]=true;
  vector<int> shell;
  vector<int> nextshell;
  R_dist.push_back(idx_source);
  shell.push_back(idx_source);
 // nextshell.push_back(idx_source);
  //cout<<"idx_source = "<<idx_source<<endl;
  while (distance < R && !shell.empty()) {
     // cout<<"distance = "<<distance<<'\t'<<"size of shell = "<<shell.size()<<endl;
      nextshell.clear();
      while (!shell.empty()) {
          node_pointer=shell.back();
          shell.pop_back();
          for (idx_neighbor=net.vertex_neighbor_begin(node_pointer);idx_neighbor!=net.vertex_neighbor_end(node_pointer); ++idx_neighbor) {
              if(!marked[*idx_neighbor]) {
	             nextshell.push_back(*idx_neighbor);
                 marked[*idx_neighbor]=true;
	             R_dist.push_back(*idx_neighbor);
              }
           }
      }
      distance++;
      if (distance == R) {
          break;
      }
      //R_dist.clear();
      for (int i = 0; i < shell.size(); i++) {
          R_dist.push_back(shell[i]);
      }
  }
  R_dist.clear();
  for (int i = 0; i < marked_nodes.size(); i++) {
      R_dist.push_back(marked_nodes[i]);
  }

  delete []marked;
}

*/
inline void find_random_no_connection_set(const int num_nodes, Graph net, vector<int> & remove_list, set<int> & remove_list_count, set<int> & no_remove,vector<int> & no_remove_v) {
    vector<int> all_nodes;
   // set<int> no_remove;
   // vector<int> no_remove_v;
    Graph::node_neighbor_iterator idx_neighbor;
    for (int i = 0;i < num_nodes; i++){
        all_nodes.push_back(i);
    }
    random_shuffle (all_nodes.begin(),all_nodes.end());
    while(!all_nodes.empty()){
        int one_node = all_nodes.front();
        if(!remove_list_count.count(one_node) && !no_remove.count(one_node)){
            remove_list_count.insert(one_node);
            remove_list.push_back(one_node);
            for (idx_neighbor = net.vertex_neighbor_begin(one_node); idx_neighbor != net.vertex_neighbor_end(one_node);idx_neighbor++){
                no_remove.insert(*idx_neighbor);
                no_remove_v.push_back(*idx_neighbor);
            }
        }
        all_nodes.erase(all_nodes.begin());
    }
}

inline void find_part_no_connection_set(const int num_nodes, Graph net, vector<int> & remove_list2, vector<int> & remove_list, set<int> & remove_list_count, set<int> & no_remove, vector<int> & no_remove_v) {
        set<int> remove_list2_set;
        Graph::node_neighbor_iterator idx_neighbor;
        for (int i = 0; i < no_remove_v.size();i++){
            net.new_remove_node(no_remove_v[i]);
        }
        vector<double> all_degree;
        vector<int> all_nodes_new;
        for (int i = 0; i < remove_list.size();i++){
            all_degree.push_back(net.degree(remove_list[i])+(double)remove_list[i]/num_nodes);
        }
        sort(all_degree.begin(),all_degree.end());
        for (int i = 0; i < remove_list.size(); i++){
            if (net.degree(remove_list[i]) != 0 && net.degree(remove_list[i]) != 1){
                double number = (all_degree[i]-int(all_degree[i]))*num_nodes;
                double nnnumber = (double)((int)(number*100+0.5))/100.0;
                int nnumber = int(nnnumber);
                all_nodes_new.push_back(nnumber);
            }
        }
        no_remove.clear();
        while(!all_nodes_new.empty()){
            int one_node = all_nodes_new.back();
            if(!remove_list2_set.count(one_node) && !no_remove.count(one_node)){
                remove_list2_set.insert(one_node);
                remove_list2.push_back(one_node);
                for (idx_neighbor = net.vertex_neighbor_begin(one_node); idx_neighbor != net.vertex_neighbor_end(one_node);idx_neighbor++){
                    no_remove.insert(*idx_neighbor);
                    no_remove_v.push_back(*idx_neighbor);
                }
            }
            all_nodes_new.pop_back();
           // if (remove_list.size() >= remove_node){break;}
        }
}

inline void find_biggest_cluster(Graph & net, vector<int> & biggest_cluster) {
  biggest_cluster.clear();
  int num_nodes=net.get_num_vertices();
  bool * marked;
  marked=new bool[num_nodes];
  for (int i=0; i < num_nodes; ++i) marked[i]=false;
  stack<int> search_stack;
  int idx_search;
  Graph::node_neighbor_iterator idx_neighbor;
  vector<int> temp_cluster;

  for (int idx_node=0; idx_node < num_nodes; ++idx_node) {
    if (!marked[idx_node]) {
      temp_cluster.clear();
      temp_cluster.push_back(idx_node);
      search_stack.push(idx_node);
      marked[idx_node]=true;

      while (!search_stack.empty()) {
	idx_search=search_stack.top();
	search_stack.pop();
	for (idx_neighbor=net.vertex_neighbor_begin(idx_search);
	     idx_neighbor!=net.vertex_neighbor_end(idx_search); ++idx_neighbor)
	  if (!marked[*idx_neighbor]) {
	    search_stack.push(*idx_neighbor);
	    temp_cluster.push_back(*idx_neighbor);
	    marked[*idx_neighbor]=true;
	  }
      }
      if (temp_cluster.size() > biggest_cluster.size())
	biggest_cluster=temp_cluster;
    }
  }
  delete []marked;
}

//find all clusters, each cluster ends with -1
inline void find_clusters(Graph & net, vector<int> & clusters) {
  clusters.clear();
  int num_nodes=net.get_num_vertices();
  bool * marked;
  marked=new bool[num_nodes];
  for (int i=0; i < num_nodes; ++i) marked[i]=false;
  stack<int> search_stack;
  int idx_search;
  Graph::node_neighbor_iterator idx_neighbor;

  for (int idx_node=0; idx_node < num_nodes; ++idx_node) {
    if (!marked[idx_node]) {
      clusters.push_back(idx_node);
      search_stack.push(idx_node);
      marked[idx_node]=true;

      while (!search_stack.empty()) {
	idx_search=search_stack.top();
	search_stack.pop();
	for (idx_neighbor=net.vertex_neighbor_begin(idx_search);
	     idx_neighbor!=net.vertex_neighbor_end(idx_search); ++idx_neighbor)
	  if (!marked[*idx_neighbor]) {
	    search_stack.push(*idx_neighbor);
	    clusters.push_back(*idx_neighbor);
	    marked[*idx_neighbor]=true;
	  }
      }
      clusters.push_back(-1);
    }
  }
  delete []marked;
}


// find the number of nodes at distance n to the source node
inline void find_num_ndist(Graph & net, const int idx_source, vector<int> & num_ndist) {
  num_ndist.clear();
  int num_nodes=net.get_num_vertices();
  bool * marked;
  marked=new bool[num_nodes];
  for (int i=0; i < num_nodes; ++i) marked[i]=false;
  queue<int> search_queue;
  int numb_nodes_same_dista=1;
  int node_pointer;
  Graph::node_neighbor_iterator idx_neighbor;list<int> neighbors;
  search_queue.push(idx_source);
  marked[idx_source]=true;

  while (!search_queue.empty()) {
    node_pointer=search_queue.front();
    search_queue.pop();
    --numb_nodes_same_dista;
   // list<int> neighbors;
    for (idx_neighbor=net.vertex_neighbor_begin(node_pointer);
	 idx_neighbor!=net.vertex_neighbor_end(node_pointer); ++idx_neighbor) {
      if(!marked[*idx_neighbor]) {
	search_queue.push(*idx_neighbor);
	marked[*idx_neighbor]=true;
      }
    }
    if (!numb_nodes_same_dista) {
      numb_nodes_same_dista=search_queue.size();
      num_ndist.push_back(numb_nodes_same_dista);
    }
  }
  num_ndist.pop_back(); //remove last 0
  delete []marked;
}


// find average R (radius of gyration) at distance n to the source node
inline void find_R_ndist(Graph & net, const int idx_source, vector<float> & R_ndist) {
  R_ndist.clear();
  int num_nodes=net.get_num_vertices();
  bool * marked;
  marked=new bool[num_nodes];
  for (int i=0; i < num_nodes; ++i) marked[i]=false;
  queue<int> search_queue;
  int numb_nodes_same_dista=1;
  int node_pointer;
  Graph::node_neighbor_iterator idx_neighbor;
  search_queue.push(idx_source);
  marked[idx_source]=true;

  vector<int> marked_nodes;
  marked_nodes.push_back(idx_source);

  float total_x=idx_source;
  float avg_x;
  float total_xx;

  while (!search_queue.empty()) {
    node_pointer=search_queue.front();
    search_queue.pop();
    --numb_nodes_same_dista;
    for (idx_neighbor=net.vertex_neighbor_begin(node_pointer);
	 idx_neighbor!=net.vertex_neighbor_end(node_pointer); ++idx_neighbor) {
      if(!marked[*idx_neighbor]) {
	search_queue.push(*idx_neighbor);
	marked[*idx_neighbor]=true;

	marked_nodes.push_back(*idx_neighbor);
	total_x+=*idx_neighbor;
      }
    }
    if (!numb_nodes_same_dista) {
      numb_nodes_same_dista=search_queue.size();
      if (numb_nodes_same_dista) {
	avg_x=total_x/marked_nodes.size();
	total_xx=0;
	for (int i=0; i < marked_nodes.size(); ++i)
	  total_xx+=(marked_nodes[i]-avg_x)*(marked_nodes[i]-avg_x);
	R_ndist.push_back(sqrt(total_xx/marked_nodes.size()));
      }
    }
  }

  delete []marked;
}


inline void find_kleinberg_path_2D(const int idx_source,const int idx_sink, const int num_L, Graph & net, int & distance) {
  distance=0;
  int id_x, id_y, id_x2, id_y2;
  id_x2=idx_sink%num_L;
  id_y2=idx_sink/num_L;
  int dist, dist2;
  Graph::node_neighbor_iterator idx_neighbor;
  int node_pointer=idx_source;
  int node_pointer2;

  while (node_pointer!=idx_sink) {
    dist=2*num_L;
    for (idx_neighbor=net.vertex_neighbor_begin(node_pointer);
	 idx_neighbor!=net.vertex_neighbor_end(node_pointer); ++idx_neighbor) {
      id_x=*idx_neighbor%num_L;
      id_y=*idx_neighbor/num_L;
      dist2=abs(id_x-id_x2)+abs(id_y-id_y2);
      if (dist2<dist) {
	dist=dist2;
	node_pointer2=*idx_neighbor;
      }
    }
    ++distance;
    node_pointer=node_pointer2;
  }
}



#endif
