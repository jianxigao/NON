#ifndef NET_ALGO_HPP
#define NET_ALGO_HPP

#include "statool/srand.hpp"
#include <math.h>
#include "graph.hpp"
#include "node.hpp"
#include <set>
#include <algorithm>
#include <vector>

inline void copy_neta2netb(const int num_nodes, Graph neta, Graph & netb) {
    Graph::node_neighbor_iterator idx_neighbor;
    for(int i = 0; i < num_nodes; i ++){
        for (idx_neighbor=neta.vertex_neighbor_begin(i);idx_neighbor!=neta.vertex_neighbor_end(i); ++idx_neighbor){
            if (!netb.connection_check(i,*idx_neighbor))
                netb.insert_connection(i,*idx_neighbor);
        }
    }
}


inline void RE_algo(const int num_nodes, Graph & lt_net, int link) {
  int numer = 0;
  while (1) {
     if (link==numer) {break;}
     int first = int(num_nodes*srand());
     int secon = int(num_nodes*srand());
      if (!lt_net.connection_check(first,secon) && first!=secon) {
           ++numer;
          lt_net.insert_connection(first,secon);
      }
  }
}

inline void RE_algo_di_graph(const int num_nodes, Graph & lt_net, int link) {
  int numer = 0;
  while (1) {
     if (link==numer) {break;}
     int first = int(num_nodes*srand());
     int secon = int(num_nodes*srand());
      if (!lt_net.di_connection_check(first,secon) && first!=secon) {
           ++numer;
          lt_net.insert_di_connection(first,secon);
          cout<<first<<'\t'<<secon<<endl;
      }
  }
}

inline void RE_algo_self_di_graph(const int num_nodes, Graph & lt_net, int link){
    int numer = 0;
    while (1) {
        if (link==numer) {break;}
        int first = int(num_nodes*srand());
        int secon = int(num_nodes*srand());
        if (!lt_net.di_connection_check(first,secon) && first!=secon) {
            ++numer;
            lt_net.insert_di_connection(first,secon);
           // cout<<first<<'\t'<<secon<<endl;
        }
    }
}
inline void lt_SF_algo(int num_nodes,Graph &net, const double lamda){
  int k,h; //degree of a node
  int haha = 2;
  vector<int> v;
  for(int j=0;j<num_nodes;++j){
    k=int(haha*pow(srand(),1./(1-lamda)));
    for(int i=0;i<k;++i)
      v.push_back(j);
  }
 // cout<<"size at the beginning: "<<v.size()<<endl;
  int mm=0;
  int n=0,size=v.size();
  bool mark=true;
  while(mark){
    k=0;h=0;
    while((v[k]==v[h])||net.connection_check(v[h],v[k])){
      if(++n>1000000){
    mark=false;break;
      }
      k=int(srand()*size);
      h=int(srand()*size);
    }
    if(!mark) {break;}
    net.insert_connection(v[k],v[h]);
    if(k<(size-2)&&h<(size-2)) {
      v[k]=v[size-1];
      v[h]=v[size-2];
    }
    else if(k>=size-2 && h>=size-2)
      ;
    else if(h>=size-2){
      n=(h==size-2)?size-1:size-2;
      v[k]=v[n];
    }
    else if(k>=size-2){
      n=(k==size-2)?size-1:size-2;
      v[h]=v[n];
    }
    size-=2;n=0;
  }
//  cout<<"size at the end: "<<size<<endl;
  return;
}

inline void RR_algo(const int num_nodes, Graph & net, int link) {

  int k,h; //degree of a node
//  int haha = 2;
  vector<int> v;
  for(int j=0;j<num_nodes;++j){
//    k=int(haha*pow(srand(),1./(1-lamda)));
    k = link;
    for(int i=0;i<k;++i)
      v.push_back(j);
  }
 // cout<<"size at the beginning: "<<v.size()<<endl;
  int mm=0;
  int n=0,size=v.size();
  bool mark=true;
  while(mark){
    k=0;h=0;
    while((v[k]==v[h])||net.connection_check(v[h],v[k])){
      if(++n>1000000){
    mark=false;break;
      }
      k=int(srand()*size);
      h=int(srand()*size);
    }
    if(!mark) {break;}
    net.insert_connection(v[k],v[h]);
    if(k<(size-2)&&h<(size-2)) {
      v[k]=v[size-1];
      v[h]=v[size-2];
    }
    else if(k>=size-2 && h>=size-2)
      ;
    else if(h>=size-2){
      n=(h==size-2)?size-1:size-2;
      v[k]=v[n];
    }
    else if(k>=size-2){
      n=(k==size-2)?size-1:size-2;
      v[h]=v[n];
    }
    size-=2;n=0;
  }
  return;

}


inline void rand_vector(const int num_nodes, vector<int> & vect, vector<int> & vect0) {
  vector<int> nettemp;
  int a_num;
  for (int i = 0; i < num_nodes;i++) {nettemp.push_back(i);vect0.push_back(i);}

  for (int i = 0; i < num_nodes; i++){
      a_num = int((num_nodes-i)*srand());
      vect.push_back(nettemp[a_num]);
      nettemp.erase(nettemp.begin()+a_num);
  }
  for (int i = 0; i < num_nodes; i++){
      vect0[vect[i]] = i;
  }
}

inline void new_rand_vector(int part1, int part2, const int num_nodes, vector<int> & vect1, vector<int> & vect2, vector<int> & vect10, vector<int> & vect20) {
  vector<int> nettemp;
  int a_num;
  for (int i = 0; i < num_nodes;i++) {nettemp.push_back(i);vect20.push_back(i);vect2.push_back(i);}

  for (int i = 0; i < num_nodes; i++){
      a_num = int((num_nodes-i)*srand());
      vect10.push_back(nettemp[a_num]);
      vect1.push_back(nettemp[a_num]);
      nettemp.erase(nettemp.begin()+a_num);
  }

  for (int i = 0; i < num_nodes; i++){
      vect20[vect10[i]] = i;
      vect2[vect10[i]] = i;
  }

  for (int i = 0; i < part1; i++){
      a_num = int((num_nodes-i)*srand());
      vect1.erase(vect1.begin()+a_num);
  }
  for (int i = 0; i < part2; i++){
      a_num = int((num_nodes-i)*srand());
      vect2.erase(vect2.begin()+a_num);
  }
}

inline void new_rand_vector_feedback(int part1, int part2, const int num_nodes, vector<int> & vect1, vector<int> & vect2, vector<int> & vect10, vector<int> & vect20) {
  vector<int> nettemp;
  int a_num;
  for (int i = 0; i < num_nodes;i++) {nettemp.push_back(i);vect20.push_back(i);vect2.push_back(i);}

  for (int i = 0; i < num_nodes; i++){
      a_num = int((num_nodes-i)*srand());
      vect10.push_back(nettemp[a_num]);
      vect1.push_back(nettemp[a_num]);
      nettemp.erase(nettemp.begin()+a_num);
  }

  for (int i = 0; i < part1; i++){
      a_num = int((num_nodes-i)*srand());
      vect1.erase(vect1.begin()+a_num);
  }
  for (int i = 0; i < part2; i++){
      a_num = int((num_nodes-i)*srand());
      vect2.erase(vect2.begin()+a_num);
  }
}

inline void rand_vector_p(int part, const int num_nodes, vector<int> & vect) {
//  vector<int> nettemp;
  int a_num;
  for (int i = 0; i < num_nodes;i++) {vect.push_back(i);vect.push_back(i);}

  for (int i = 0; i < part; i++){
      a_num = int((num_nodes-i)*srand());
      vect.erase(vect.begin()+a_num);
  }
}

inline void target_attack(int part, float alpha, const int num_nodes, vector<int> & vect, Graph  network1) {
  float sum_weight;
  vector<int> weight;
  for (int i = 0; i < num_nodes;i++) {
        sum_weight += pow(network1.get_deg_vertex(i),alpha);
   }

   for (int i = 0; i < num_nodes;i++) {
        int k = int(pow(network1.get_deg_vertex(i),alpha)/sum_weight*100000);
        for (int j = 0; j < k ; j++){
             weight.push_back(i);
        }
   }
    int number,ended;
  for (int i = 0; i < part; i++){
      int k = int(weight.size()*srand());
      vect.push_back(weight[k]);
        number = 0;
       for (int j = 0;j < weight.size();j ++){
              if (weight[k]==weight[j]){
                 number += 1;
                 ended = j;
              }
         }
        weight.erase(weight.begin()+ended-number+1,weight.begin()+ended+1);
  }

}



inline void new_rand_vector_p(int part, const int num_nodes, vector<int> & vect, vector<int> & vect0) {
    vector<int> nettemp;
    int a_num;
    for (int i = 0; i < num_nodes;i++) {nettemp.push_back(i);}
    for (int i = 0; i < num_nodes; i++){
        a_num = int((num_nodes-i)*srand());
        vect0.push_back(nettemp[a_num]);
        vect.push_back(nettemp[a_num]);
        nettemp.erase(nettemp.begin()+a_num);
    }
    for (int i = 0; i < part; i++){
        a_num = int((num_nodes-i)*srand());
        vect.erase(vect.begin()+a_num);
    }
}


// network2 remove nodes because of network1
inline void Remove_one_network_effect_another(const int num_nodes,vector<int> & node_network2, vector<int>  node_network1,Graph & network2, Graph  network1, vector<int> & remove_list) {
//   vector<int> remove_list;
   remove_list.clear();
   set<int> set1;
   for (int i = 0; i < node_network1.size();i++){
        set1.insert(node_network1[i]);
   }

   for (int i = 0; i < node_network2.size(); i ++){
       if (!set1.count(node_network2[i])) {remove_list.push_back(node_network2[i]);}
   }

    for (int i = 0; i < remove_list.size(); i++){
        network2.remove_node(remove_list[i]);
       // node_network2.erase(node_network1.begin()+remove_list[i]);
    }
 //   cout<<"network2 left "<<node_network2.size()<<" nodes"<<endl;
    node_network2.clear();
    for (int i = 0;i < num_nodes;i++){
        if (network2.get_deg_vertex(i) != 0)
            node_network2.push_back(i);
    }
   // cout<<"network2 left "<<node_network2.size()<<" nodes"<<endl;
}


// network2 remove nodes because of network1
inline void Remove_one_network_effect_another_part(const int num_nodes,vector<int> & node_network2, vector<int>  node_network1,Graph & network2, Graph  network1, vector<int> part_list) {
   vector<int> remove_list;
   remove_list.clear();
   set<int> set1,set2;
   for (int i = 0; i < node_network1.size();i++){
        set1.insert(node_network1[i]);
   }

   for (int i = 0; i < part_list.size();i++){
        set2.insert(part_list[i]);
   }
  // cout<<"part_list.size() = "<<part_list.size()<<endl;
   for (int i = 0; i < node_network2.size(); i ++){
       if (!set1.count(node_network2[i]) && set2.count(node_network2[i])) {remove_list.push_back(node_network2[i]);}
   }

    for (int i = 0; i < remove_list.size(); i++){
        network2.remove_node(remove_list[i]);
       // node_network2.erase(node_network1.begin()+remove_list[i]);
    }

    node_network2.clear();
    for (int i = 0;i < num_nodes;i++){
        if (network2.get_deg_vertex(i) != 0)
            node_network2.push_back(i);
    }

}

// network2 remove nodes because of network1
inline void Remove_one_network_effect_another_part_new(const int num_nodes,vector<int> & node_network2, vector<int>  node_network1,Graph & network2, Graph  network1, vector<int> part_list, vector<int> part_list_all) {
   vector<int> remove_list;
   remove_list.clear();
   set<int> set1,set2;
   for (int i = 0; i < node_network1.size();i++){
        set1.insert(part_list_all[node_network1[i]]);
   }

   for (int i = 0; i < part_list.size();i++){
        set2.insert(part_list[i]);
   }
  // cout<<"part_list.size() = "<<part_list.size()<<endl;
   for (int i = 0; i < node_network2.size(); i ++){
       if (!set1.count(node_network2[i]) && set2.count(node_network2[i])) {remove_list.push_back(node_network2[i]);}
   }

    for (int i = 0; i < remove_list.size(); i++){
        network2.remove_node(remove_list[i]);
       // node_network2.erase(node_network1.begin()+remove_list[i]);
    }
 //   cout<<"network2 left "<<node_network2.size()<<" nodes"<<endl;
    node_network2.clear();
    for (int i = 0;i < num_nodes;i++){
        if (network2.get_deg_vertex(i) != 0)
            node_network2.push_back(i);
    }
   // cout<<"network2 left "<<node_network2.size()<<" nodes"<<endl;
}

// Find the critical nodes at the critical points
inline void Remove_one_network_effect_another_part_new_critical(const int num_nodes,vector<int> & node_network2, vector<int>  node_network1,Graph & network2, Graph  network1, vector<int> part_list, vector<int> part_list_all, vector<int> & remove_list) {

   remove_list.clear();
   set<int> set1,set2;
   for (int i = 0; i < node_network1.size();i++){
        set1.insert(part_list_all[node_network1[i]]);
   }

   for (int i = 0; i < part_list.size();i++){
        set2.insert(part_list[i]);
   }
  // cout<<"part_list.size() = "<<part_list.size()<<endl;
   for (int i = 0; i < node_network2.size(); i ++){
       if (!set1.count(node_network2[i]) && set2.count(node_network2[i])) {remove_list.push_back(node_network2[i]);}
   }

    for (int i = 0; i < remove_list.size(); i++){
        network2.remove_node(remove_list[i]);
       // node_network2.erase(node_network1.begin()+remove_list[i]);
    }
 //   cout<<"network2 left "<<node_network2.size()<<" nodes"<<endl;
    node_network2.clear();
    for (int i = 0;i < num_nodes;i++){
        if (network2.get_deg_vertex(i) != 0)
            node_network2.push_back(i);
    }
   // cout<<"network2 left "<<node_network2.size()<<" nodes"<<endl;
}


// network2 remove nodes because of network1 including control interdependency links
inline void Remove_one_network_effect_another_part_new_control(const int num_nodes,vector<int> & node_network2, vector<int>  node_network1,Graph & network2, Graph  network1, vector<int> part_list, vector<int> part_list_all) {
   vector<int> remove_list;
   remove_list.clear();
   set<int> set1,set2;
   for (int i = 0; i < node_network1.size();i++){
        set1.insert(part_list_all[node_network1[i]]);
   }

   for (int i = 0; i < part_list.size();i++){
        set2.insert(part_list[i]);
   }
  // cout<<"part_list.size() = "<<part_list.size()<<endl;
   for (int i = 0; i < node_network2.size(); i ++){
       if (!set1.count(node_network2[i]) && set2.count(node_network2[i])) {remove_list.push_back(node_network2[i]);}
   }
    if (remove_list.size()>1){
        for (int i = 1; i < remove_list.size(); i++){
            network2.remove_node(remove_list[i]);
        }
        node_network2.clear();
        for (int i = 0;i < num_nodes;i++){
            if (network2.get_deg_vertex(i) != 0)
                node_network2.push_back(i);
        }
    }
}

inline void Remove_one_network_effect_another_part_new_control_percent(float percent_control, const int num_nodes,vector<int> & node_network2, vector<int>  node_network1,Graph & network2, Graph  network1, vector<int> part_list, vector<int> part_list_all) {
   vector<int> remove_list;
  // float percent_control = 0.001;
   int control = int(percent_control*num_nodes);
   remove_list.clear();
   set<int> set1,set2;
   for (int i = 0; i < node_network1.size();i++){
        set1.insert(part_list_all[node_network1[i]]);
   }

   for (int i = 0; i < part_list.size();i++){
        set2.insert(part_list[i]);
   }
   for (int i = 0; i < node_network2.size(); i ++){
       if (!set1.count(node_network2[i]) && set2.count(node_network2[i])) {remove_list.push_back(node_network2[i]);}
   }
   int a, suiji1, suiji2;

   for (int i = 0; i < 100; i++){
       suiji1 = int(srand()*remove_list.size());
       suiji2 = int(srand()*remove_list.size());
       a = remove_list[suiji1];
       remove_list[suiji1] = remove_list[suiji2];
       remove_list[suiji2] = a;
    }

    if (remove_list.size()>control){
        for (int i = control; i < remove_list.size(); i++){
            network2.remove_node(remove_list[i]);
        }
        node_network2.clear();
        for (int i = 0;i < num_nodes;i++){
            if (network2.get_deg_vertex(i) != 0)
                node_network2.push_back(i);
        }
    }
}


inline void Remove_one_network_effect_another_part_new_control_degree(const int num_nodes,vector<int> & node_network2, vector<int>  node_network1,Graph & network2, Graph  network1, vector<int> part_list, vector<int> part_list_all) {
   vector<int> remove_list;
   remove_list.clear();
   set<int> set1,set2;
   for (int i = 0; i < node_network1.size();i++){
        set1.insert(part_list_all[node_network1[i]]);
   }

   for (int i = 0; i < part_list.size();i++){
        set2.insert(part_list[i]);
   }
  // cout<<"part_list.size() = "<<part_list.size()<<endl;
   for (int i = 0; i < node_network2.size(); i ++){
       if (!set1.count(node_network2[i]) && set2.count(node_network2[i])) {remove_list.push_back(node_network2[i]);}
   }
    if (remove_list.size()>1){
        int large_degree = 0;
        for (int i = 1; i < remove_list.size(); i++) {
            if (network2.get_deg_vertex(remove_list[i])>network2.get_deg_vertex(remove_list[large_degree])) {large_degree = i;}
         }

        for (int i = 0; i < remove_list.size(); i++){
            if (i != large_degree){
                network2.remove_node(remove_list[i]);
            }
        }
        node_network2.clear();
        for (int i = 0;i < num_nodes;i++){
            if (network2.get_deg_vertex(i) != 0)
                node_network2.push_back(i);
        }
    }
}

// network2 remove nodes because of network1 data analysis
inline void Remove_one_network_effect_another_part_new_data(const int num_nodes,vector<int> & node_network2, vector<int>  node_network1,Graph & network2, Graph  network1, vector<int> part_list_network1, vector<int> part_list_network12) {
   vector<int> remove_list;
   remove_list.clear();
   set<int> set1,set2,set3,set12;

   for (int i = 0; i < part_list_network1.size();i++) {
        set3.insert(part_list_network1[i]);
   }

   for (int i = 0; i < part_list_network12.size();i++) {
        set12.insert(part_list_network12[i]);
   }

   for (int i = 0; i < node_network1.size();i++){
        set1.insert(node_network1[i]);
   }
   for (int i = 0; i < node_network1.size();i++){
        if (set1.count(node_network1[i]) & set3.count(node_network1[i])) {
            set2.insert(part_list_network12[i]);
        }
   }

   for (int i = 0; i < node_network2.size(); i ++){
       if (!set1.count(node_network2[i]) && set2.count(node_network2[i])) {remove_list.push_back(node_network2[i]);}
   }

    for (int i = 0; i < remove_list.size(); i++){
        network2.remove_node(remove_list[i]);
       // node_network2.erase(node_network1.begin()+remove_list[i]);
    }
 //   cout<<"network2 left "<<node_network2.size()<<" nodes"<<endl;
    node_network2.clear();
    for (int i = 0;i < num_nodes;i++){
        if (network2.get_deg_vertex(i) != 0)
            node_network2.push_back(i);
    }
   // cout<<"network2 left "<<node_network2.size()<<" nodes"<<endl;
}


inline void Remove_for_cluster(const int num_nodes, vector<int> & node_network,Graph & network) {
    vector<int> remove_list;
    vector<int> cluster_network;
    find_biggest_cluster(network, cluster_network);
    remove_list.clear();
   set<int> set1;
   for (int i = 0; i < cluster_network.size();i++){
        set1.insert(cluster_network[i]);
   }
   for (int i = 0; i < node_network.size(); i ++){
       if (!set1.count(node_network[i])) {remove_list.push_back(node_network[i]);}
   }
   for (int i = 0; i < remove_list.size(); i++){
       network.new_remove_node(remove_list[i]);
   }
   node_network.clear();
   for (int i = 0;i < num_nodes;i++){
       if (network.get_deg_vertex(i) != 0)
          node_network.push_back(i);
   }
}

inline void Remove_for_cluster_get_nodes(const int num_nodes, vector<int> & node_network,Graph & network, vector<int> & nodes_remove) {
    vector<int> remove_list;
    vector<int> cluster_network;
    find_biggest_cluster(network, cluster_network);
    remove_list.clear();
    set<int> set1;
    for (int i = 0; i < cluster_network.size();i++){
        set1.insert(cluster_network[i]);
    }
    for (int i = 0; i < node_network.size(); i ++){
       if (!set1.count(node_network[i])) {
           remove_list.push_back(node_network[i]);
           nodes_remove.push_back(node_network[i]);
        }
    }
    for (int i = 0; i < remove_list.size(); i++){
       network.remove_node(remove_list[i]);
    }
    node_network.clear();
    for (int i = 0;i < num_nodes;i++){
       if (network.get_deg_vertex(i) != 0)
          node_network.push_back(i);
    }
}

inline void Remove_one_network_effect_another_netcon(const int num_nodes,vector<int> & node_network3, vector<int>  node_network1,Graph & network3, Graph  network1,vector<int> net13) {
   vector<int> remove_list;
   remove_list.clear();
   set<int> set1;
   for (int i = 0; i < node_network1.size();i++){
        set1.insert(net13[node_network1[i]]);
   }
   for (int i = 0; i < node_network3.size(); i ++){
       if (!set1.count(node_network3[i])) {remove_list.push_back(node_network3[i]);}
   }
    for (int i = 0; i < remove_list.size(); i++){
        network3.remove_node(remove_list[i]);
    }
    node_network3.clear();
    for (int i = 0;i < num_nodes;i++){
        if (network3.get_deg_vertex(i) != 0)
            node_network3.push_back(i);
    }

}



//breadth-first searching
void find_shortest_length(Graph & net, int idx_source, int idx_sink, int & length) {
   length=0;
   int num_nodes=net.get_num_vertices();
   bool * mark=new bool[num_nodes];
   memset(mark, false, num_nodes*sizeof(bool));

   std::queue<int> search_queue;
   int numb_nodes_same_dista=1;
   int node_pointer;
   Graph::node_neighbor_iterator idx_neighbor;
   search_queue.push(idx_source);
   mark[idx_source]=true;

   while (!search_queue.empty()) {
       node_pointer=search_queue.front();
       search_queue.pop();
       --numb_nodes_same_dista;
       for (idx_neighbor=net.vertex_neighbor_begin(node_pointer);
               idx_neighbor!=net.vertex_neighbor_end(node_pointer); ++idx_neighbor) {
           if(!mark[*idx_neighbor]) {
               mark[*idx_neighbor]=true;
               if(*idx_neighbor==idx_sink) {
                   node_pointer=idx_sink;
                   ++length;
                   break;
               }
               search_queue.push(*idx_neighbor);
           }
       }
       if (node_pointer==idx_sink) break;
       if (!numb_nodes_same_dista) {
           numb_nodes_same_dista=search_queue.size();
           ++length;
       }
   }

   if (!mark[idx_sink]) length=-1;
   delete[] mark;
}

//with the source and sink given, this fuction finds the shortest path, using Breadth First Search algorithm
//(i.e. chemical distance, without thinking about weight)

inline void find_shortest_path(const int idx_source,const int idx_sink, Graph net, int & distance) {
  int num_nodes=net.get_num_vertices();
  //array "marked" is used to store the mark showing whether the node has been visited
  bool * marked;
  marked=new bool[num_nodes];
  for (int i=0; i< num_nodes; ++i) marked[i]=false;
  queue<int> search_queue;
 // vector<int> search_vect;
  distance=0;
  int numb_nodes_same_dista=1;
  int node_pointer;
  Graph::node_neighbor_iterator idx_neighbor;

  search_queue.push(idx_source);
  //search_vect.push_back(idx_source);
  marked[idx_source]=true;

  while (!search_queue.empty()) {
    node_pointer=search_queue.front();
    search_queue.pop();
    --numb_nodes_same_dista;
    for (idx_neighbor=net.vertex_neighbor_begin(node_pointer);
	 idx_neighbor!=net.vertex_neighbor_end(node_pointer); ++idx_neighbor) {
      if(*idx_neighbor==idx_sink) {
	node_pointer=idx_sink;
	++distance;
   //     search_vect.push_back(node_pointer);
	break;
      }
      if(!marked[*idx_neighbor]) {
	search_queue.push(*idx_neighbor);
	marked[*idx_neighbor]=true;
      }
    }
    if (node_pointer==idx_sink) {
      marked[idx_sink]=true;
      break;
    }
    if (numb_nodes_same_dista==0) {
      ++distance;
      //now every node in the queue has this distance.
      numb_nodes_same_dista=search_queue.size();
    }

  }
   while(search_queue.size()>0)  {
        cout<<search_queue.front()<<endl;
        search_queue.pop();
  }
  if (!marked[idx_sink])
      distance=-1;

  delete []marked;
}

inline void find_betweenness(const int num_nodes,Graph & network) {
  list<int> q;
  list<int>::iterator it;
  int k=0;
  float max_d=0;

  for(int i=0; i < num_nodes; i++){
      max_d=0;
      for(int j=0;j<num_nodes; j++)
	{
	  network.set_distance(j,-1);
	  network.set_level(j,0);
	}
      q.push_back(i);
      network.set_distance(i,0);
      network.mk_cluster_status_1(i);
      while(!q.empty())
	{
	  k=q.front();
	  q.pop_front();
	  //cout<<"the node "<<k<<" is out the queue1"<<endl;
	  for(it=network.vertex_neighbor_begin(k); it!=network.vertex_neighbor_end(k);it++)
	    {

	      if(network.check_cluster_status(*it)==0)
		{
                  network.set_distance(*it,1+network.get_distance(k));
		  max_d=network.get_distance(*it);
                   network.add_a_predecessor(*it,k);
		  q.push_back(*it);
		  network.mk_cluster_status_1(*it);
		}
	      else if(network.get_distance(*it)==network.get_distance(k)+1 )
		{
		  network.add_a_predecessor(*it,k);
		}
	    }
	}
      q.clear();
      for(int j=0; j<num_nodes; j++)
	{
	  network.mk_cluster_status_0(j);
	  network.set_btw(j,1.0);
	}
      for(int m=int(max_d); m>0;m--)
	{
	  for(int j=0;j<num_nodes;j++)
	    {
	      if(network.get_distance(j)==m)
		{
		  q.push_back(j);
		  network.mk_cluster_status_1(j);
		}
	    }
	}

      while(!q.empty())
	{
	  k=q.front();
	  q.pop_front();
	  for(it=network.vertex_predecessor_begin(k); it!=network.vertex_predecessor_end(k); it++)
	    {
	      int j = network.predecessor_num(k);
	      float test=network.get_btw(*it)+double(network.get_btw(k)/float (j));
	      network.set_btw(*it,test);
	    }
	}
      for(int j=0;j<num_nodes;j++)
	{
	  network.set_tbtw(j,double(network.get_tbtw(j)+network.get_btw(j)));
	  network.mk_cluster_status_0(j);
	  network.rm_all_predecessor(j);
	}
    }

}




/*
inline void get_betweenness(const int num_nodes, vector<int> & node_network,Graph & network,vector<float> C) {
vector<float> L; vector<int> remove_list;

L.clear(); remove_list.clear();
network.set_btwness();
for (int i = 0; i < num_nodes; i ++){     L.push_back(network.get_btw(i));}

for (int i = 0; i < num_nodes; i ++)
{
    if (L[i] > C[i]) {        remove_list.push_back(i);     }
}
//cout<<L.size()<<"    "<<C.size()<<"    "<<L[1]<<"    "<<C[1]<<"    "<<remove_list.size()<<endl;
for (int i = 0; i < remove_list.size(); i++) {
      network.remove_node(remove_list[i]);
      vector<int>::iterator iter=find(node_network.begin(),node_network.end(),remove_list[i]);
      if (iter !=node_network.end()) node_network.erase(iter);
}

}
*/

inline void Remove_for_cluster_copy(const int num_nodes, vector<int> & node_network,Graph & network) {
    vector<int> remove_list;
    vector<int> cluster_network;
    find_biggest_cluster(network, cluster_network);
    remove_list.clear();
       for (int i = 0; i < node_network.size(); i ++){
           bool i_not_in = true;
           for (int j = 0; j< cluster_network.size();j++){
                if (node_network[i] == cluster_network[j]) {i_not_in = false;break;}
           }
           if (i_not_in) {remove_list.push_back(node_network[i]);}
       }
       for (int i = 0; i < remove_list.size(); i++){
           network.remove_node(remove_list[i]);
       }
    node_network.clear();
    for (int i = 0;i < num_nodes;i++){
        if (network.get_deg_vertex(i) != 0)
            node_network.push_back(i);
    }
}




inline void Remove_one_network_effect_another_copy(const int num_nodes,vector<int> & node_network2, vector<int>  node_network1,Graph & network2, Graph  network1, vector<int> & remove_list) {
//   vector<int> remove_list;
   remove_list.clear();

   for (int i = 0; i < node_network2.size(); i ++){
       bool i_not_in = true;
       for (int j = 0; j< node_network1.size();j++){
           if (node_network2[i] == node_network1[j]) {i_not_in = false;break;}
       }
           if (i_not_in) {remove_list.push_back(node_network2[i]);}
   }

    for (int i = 0; i < remove_list.size(); i++){
        network2.remove_node(remove_list[i]);
       // node_network2.erase(node_network1.begin()+remove_list[i]);
    }
 //   cout<<"network2 left "<<node_network2.size()<<" nodes"<<endl;
    node_network2.clear();
    for (int i = 0;i < num_nodes;i++){
        if (network2.get_deg_vertex(i) != 0)
            node_network2.push_back(i);
    }
   // cout<<"network2 left "<<node_network2.size()<<" nodes"<<endl;
}

inline void Remove_one_network_effect_another_netcon_copy(const int num_nodes,vector<int> & node_network3, vector<int>  node_network1,Graph & network3, Graph  network1,vector<int> net13) {
   vector<int> remove_list;
   remove_list.clear();

   for (int i = 0; i < node_network3.size(); i ++){
       bool i_not_in = true;
       for (int j = 0; j< node_network1.size();j++){
           if (node_network3[i] == net13[node_network1[j]]) {i_not_in = false;break;}
       }
           if (i_not_in) {remove_list.push_back(node_network3[i]);}
   }

    for (int i = 0; i < remove_list.size(); i++){
        network3.remove_node(remove_list[i]);
    }
    node_network3.clear();
    for (int i = 0;i < num_nodes;i++){
        if (network3.get_deg_vertex(i) != 0)
            node_network3.push_back(i);
    }
   // cout<<"network2 left "<<node_network2.size()<<" nodes"<<endl;
}



#endif
