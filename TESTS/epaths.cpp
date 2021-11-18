
#include <iostream>
#include "Graph.h"
#include "_util.h"

template <typename T>
void _pvec(const std::vector<T> & vec) {

  for(const T &x : vec) {
    std::cout << "@: " << x << "\n";;
  }
}


// program exercising the enum_paths function

int main(int argc, char *argv[]){
  graph g;

  header(argc, argv);

  if(argc != 3) {
    std::cout << "usage:  ./epaths <dag-filename> <destination-vertex>\n";
    return 0;
  }
  else {
    if(!g.read_file(argv[1])){
      std::cout << "could not open file '" << argv[1] << "'\n";
      return 0;
    }
  }

  show_graph(g);

  vector<string> paths, spaths;

  if(!g.enum_paths(argv[2], paths)) {
    std::cout << "enum_paths failed?\n" ;
    return 0;
  }
  else {
    std::cout << "\nINPUT PATHS ENDING AT " << argv[2] << 
      " (paths may be listed in alternate orders)\n\n";
    _pvec(paths);

    std::vector<graph::vertex_label> bfs_rpt;
    g.bfs("v1", bfs_rpt);
    std::cout << "\nBFS REPORT:\n\n";
    disp_report(g, bfs_rpt, 1,0,0,1,0);
    std::cout << "\nEND BFS REPORT\n\n";
    
    g.enum_spaths(bfs_rpt, g.name2id("v7"), spaths);
    _pvec(spaths);
  }

  return 0;
}

