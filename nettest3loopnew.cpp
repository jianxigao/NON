
//x=-lambertw(0, -(a*p)/exp(a*p))/(a*p)*p
#include "../statool/srand.hpp"
#include <fstream>
#include "../graph.hpp"
#include "../net_ops.hpp"
#include "../net_algo.hpp"
#include "../node.hpp"
#include <fstream>
using namespace std;
int main() {
    int link,degree;
    degree = 8;
    initsrand(1);
    ofstream n1,n2,n3;//,n4,n5;
    n1.open("oncehehenewttn1p01d8.txt",ios::app | ios::out);
    n2.open("oncehehenewttn2p01d8.txt",ios::app | ios::out);
    n3.open("oncehehenewttn3p01d8.txt",ios::app | ios::out);
  //  n4.open("newn4cycledynamicc0002d60.txt",ios::app | ios::out);
 //   n5.open("newn5cycledynamicc0002d60.txt",ios::app | ios::out);
    float p = 0.1;

   // float p0[9] = {0.21,0.22,0.23,0.24,0.25,0.26,0.27,0.28,0.29};
    for (int inter = 0; inter < 1; inter ++){
     //   p = p0[inter];
        cout<<inter<<endl;
     //  vector<int> numb_nodes;
        int num_nodes=100000;
        link = degree*num_nodes/2;
        int remove_node =  int(p*num_nodes); 
        vector<int> remove_list;
      int retime = num_nodes*num_nodes;
      //randvector(const int num_nodes, vector<int> & vect,int retime, vector<int> & vect0)
     vector<int> net13,net31,net12,net21;
     rand_vector(num_nodes,net13,net31); 
     rand_vector(num_nodes,net12,net21);

        Graph network1(num_nodes),network2(num_nodes),network3(num_nodes);//,network4(num_nodes),network5(num_nodes);
        vector<int> node_network1,node_network2,node_network3;//,node_network4,node_network5;
        RE_algo(num_nodes, network1, degree*num_nodes/2);
        RE_algo(num_nodes, network2, (degree-0)*num_nodes/2);
        RE_algo(num_nodes, network3, (degree-0)*num_nodes/2);
        //RE_algo(num_nodes, network4, (degree+0)*num_nodes/2);
       // RE_algo(num_nodes, network5, (degree+0)*num_nodes/2);

        for (int i = 0;i < num_nodes;i++){ 
             node_network1.push_back(i);
             node_network2.push_back(i);
             node_network3.push_back(i);
         //    node_network4.push_back(i);
         //    node_network5.push_back(i);
        }
       for (int i = 0; i < remove_node; i++){
            int one_remove = int(node_network1.size()*srand());
            network1.remove_node(node_network1[one_remove]);
            node_network1.erase(node_network1.begin()+one_remove);      
       }
    
//    cout<<"network1 left "<<node_network1.size()<<" nodes"<<endl;
    Remove_for_cluster(num_nodes,node_network1,network1);
 //    cout<<"network1 left "<<node_network1.size()<<" nodes"<<endl;

  //  n1<<node_network1.size()<<'\t';

bool allfinish = false;

while (1) {
    bool finish = false;

    int step = 0;
     //for (step = 0; step < 3000; step++){
     while (1) {
       step++;
       //  cout<<step<<endl;
         if (step%2 == 0) {
            Remove_one_network_effect_another_netcon(num_nodes,node_network2,node_network1,network2,network1,net12);
            Remove_for_cluster(num_nodes,node_network2,network2);
         //   n2<<node_network2.size()<<'\t';
            Remove_one_network_effect_another_netcon(num_nodes,node_network3,node_network1,network3,network1,net13);
            Remove_for_cluster(num_nodes,node_network3,network3);
         //   n3<<node_network3.size()<<'\t';

         }
           else {
                Remove_one_network_effect_another_netcon(num_nodes,node_network1,node_network3,network1,network3,net31);
                Remove_one_network_effect_another_netcon(num_nodes,node_network1,node_network2,network1,network2,net21);
                Remove_for_cluster(num_nodes,node_network1,network1);
            //    n1<<node_network1.size()<<'\t';
           }  
           if (node_network1.size()==node_network2.size() && node_network2.size()==node_network3.size() && finish) {break;}
           if (node_network1.size()==node_network2.size() && node_network2.size()==node_network3.size()) {finish = true;}
      }
       n1<<node_network1.size()<<'\t';
       n2<<node_network2.size()<<'\t';
       n3<<node_network3.size()<<'\t';
        //step = 0;
       finish = false;
       Remove_one_network_effect_another(num_nodes,node_network2,node_network3,network2,network3,remove_list);
       Remove_for_cluster(num_nodes,node_network2,network2);
          
       if (node_network1.size()==node_network2.size() && node_network2.size()==node_network3.size() && allfinish) {break;}
       if (node_network1.size()==node_network2.size() && node_network2.size()==node_network3.size()) {allfinish = true;}
       Remove_one_network_effect_another_netcon(num_nodes,node_network1,node_network3,network1,network3,net31);
       Remove_one_network_effect_another_netcon(num_nodes,node_network1,node_network2,network1,network2,net21);
       Remove_for_cluster(num_nodes,node_network1,network1);
       
       n1<<node_network1.size()<<'\t';
       n2<<node_network2.size()<<'\t';
       n3<<node_network3.size()<<'\t';
  }
       n1<<endl;n2<<endl;n3<<endl;//n4<<endl;n5<<endl;
   //    node_network1.clear();node_network2.clear();node_network3.clear();remove_list.clear();
   //    network1.Graph(0);network2.Graph(0);network3.Graph(0);

   } 
   n1.close();  n2.close();  n3.close();//   n4.close();n5.close();
}
  
