
#include <iostream>
#include "Graph.h"
#include "_util.h"


int main(int argc, char *argv[]){
  graph g;
  std::vector<graph::vertex_label> bfs_rpt;
  std::vector<graph::vertex_label> dfs_rpt;

  header(argc, argv);

  if(argc != 3) {
    std::cout << "usage:  ./bfs <filename> <source-vertex>\n";
    return 0;
  }
  else {
    if(!g.read_file(argv[1])){
      std::cout << "could not open file '" << argv[1] << "'\n";
      return 0;
    }
  }

  show_graph(g);

  if(!g.bfs(argv[2], bfs_rpt)) {
    std::cout << "bfs failed -- bad source vertex name '" <<
      argv[2] << "'\n";
    return 0;
  }
  else {
    std::cout << "\nBFS REPORT:\n\n";
    disp_report(g, bfs_rpt, 1,0,0,1,0);
    std::cout << "\nEND BFS REPORT\n\n";
  }

  return 0;
}

