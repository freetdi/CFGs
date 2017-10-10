#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

#include <boost/algorithm/string/replace.hpp>

#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/graphviz.hpp>
//#include <libs/graph/src/read_graphviz_new.cpp>
#include <boost/graph/copy.hpp>

#ifndef TD_TREEDEC
#define TD_TREEDEC

struct _Vertex{
    unsigned int id;
};

struct _bag{
    std::set<unsigned int> bag;
};

#endif

typedef boost::adjacency_list<boost::setS, boost::vecS, boost::undirectedS, _Vertex> graph_t;
typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::undirectedS, _bag> decomp_t;

template <typename T_t>
int get_width(T_t &T){
    int max = -1;
    typename boost::graph_traits<T_t>::vertex_iterator tIt, tEnd;
    for(boost::tie(tIt, tEnd) = boost::vertices(T); tIt != tEnd; tIt++){
        max = ((int)T[*tIt].bag.size() > max)? (int)T[*tIt].bag.size() : max;
    }

    return (max-1);
}

template <typename G_t>
void read_dot_graph(std::string &src, G_t &G){
    G.clear();
    //try to read as a directed graph
    try{
        typename boost::adjacency_list<boost::vecS, boost::vecS, boost::directedS, _Vertex> dotG;

        boost::dynamic_properties dp(boost::ignore_other_properties); 
        dp.property("node_id",get(&_Vertex::id, dotG));

        std::ifstream dot_graph(src.c_str());
        read_graphviz(dot_graph, dotG, dp);
    
        boost::copy_graph(dotG, G);
    }
    //try to read as a undirected graph
    catch(...){
        typename boost::adjacency_list<boost::vecS, boost::vecS, boost::undirectedS, _Vertex> dotG;

        boost::dynamic_properties dp(boost::ignore_other_properties); 
        dp.property("node_id",get(&_Vertex::id, dotG));

        std::ifstream dot_graph(src.c_str());
        read_graphviz(dot_graph, dotG, dp);
    
        boost::copy_graph(dotG, G);
    }
}


/* GR -> DOT */

unsigned int from_gr_to_dot(std::string &fname_in, std::string &fname_out){
    std::ifstream fin;
    fin.open(fname_in.c_str());

    unsigned int errorcode = 0;

    std::ofstream fout;
    fout.open(fname_out.c_str());

    fout << "graph G {\n";


    if(!fin.is_open()){
        errorcode = 1;
    }
    else{
        std::string line;
        std::string delimiter = " ";

        int n = 0;
        int e = 0;
        unsigned int type = 0;
        bool exists_descriptor = false;
        unsigned int edges_count = 0;

        while(std::getline(fin, line) && errorcode == 0){
            if(line == "" || line == "\n"){
                break;
            }
            unsigned int c = 0;
            std::vector<std::string> tokens;
            unsigned int oldpos = 0;
            unsigned int newpos = 0;
            while(true){
                newpos = line.find(delimiter, oldpos);
                if(newpos > line.size()){
                    tokens.push_back(line.substr(oldpos, newpos-oldpos));
                    break;
                }
                else{
                    tokens.push_back(line.substr(oldpos, newpos-oldpos));
                }
                oldpos = newpos+1;
            }
            //comment line
            if(tokens[0] == "c"){
                type = 0;
            }
            //problem descriptor
            else if(tokens[0] == "p"){
                if(exists_descriptor){ errorcode = 4; }
                else{
                    exists_descriptor = true;
                    if(tokens.size() != 4){ errorcode = 2; }
                    else if(type != 0){ errorcode = 3; }
                    else if(tokens[1] != "tw"){ errorcode = 5; }
                    else{
                        n = atoi(tokens[2].c_str());
                        e = atoi(tokens[3].c_str());
                        if(n < 0 || e < 0){ errorcode = 6; }
                        else{
                            //prefix of vertex idenfifiers
                            for(unsigned int i = 0; i < n; i++){
                                fout << i << ";\n";
                            }
                        }
                    }
                }
            }
            //an edge
            else{
                edges_count++;
                int s, d;
                s = atoi(tokens[0].c_str());
                d = atoi(tokens[1].c_str());
                if(s < 1 || e < 1){ errorcode = 7; }
                else{
                    fout << (s-1) << " -- " << (d-1) << ";\n";
                }
            }
        }
        if(errorcode == 0){
            if(!exists_descriptor){ errorcode = 8; }
            else if(edges_count != e){ errorcode = 9; }
        }
        fout << "}\n";

        fin.close();
        fout.close();
    }
    return 0;
}

/* DOT -> GR */

void from_dot_to_gr(std::string &fname_in, std::string &fname_out){
    graph_t G;
    read_dot_graph(fname_in, G);

    unsigned n = boost::num_vertices(G);
    unsigned e = boost::num_edges(G);

    std::ofstream fout(fname_out.c_str());

    fout << "p " << "tw " << n << " " << e << std::endl;
    boost::graph_traits<graph_t>::edge_iterator eIt, eEnd;
    for(boost::tie(eIt, eEnd) = boost::edges(G); eIt != eEnd; eIt++){
        unsigned s = boost::source(*eIt, G);
        unsigned t = boost::target(*eIt, G);
		  assert( G[s].id < n );
		  assert( G[t].id < n );
        fout << G[s].id+1 << " " << G[t].id+1 << std::endl;
    }
    fout.close();
}





int main(int argc, char * const * argv){
    std::cout.setf( std::ios_base::unitbuf );

    std::vector<std::string> sources;

    const char* st = argv[0];
    const char* dt = argv[0];

    if(argc>3){
        st = argv[1];
        dt = argv[2];

        if(!(
        (strcmp(st,"dot") == 0 and strcmp(dt,"gr") == 0)
       or (strcmp(st,"gr") == 0 and strcmp(dt,"dot") == 0))){
            std::cerr << "error: invalid combination of graph types" << std::endl;
            exit(1);
        }
        int x=3;
        const char* token = argv[x];
        while(true){
            if(x == argc){
                break;
            }
            sources.push_back(token);
            token = argv[++x];
            continue;
        }
    }else{
        std::cout << "usage:\n"
          << argv[0] << " [source type] [dest type] [graphname1, graphname2, ..]\n";
        exit(1);
    }

    for(unsigned int i = 0; i < sources.size(); i++){
        if(strcmp(st,"dot") == 0 && strcmp(dt,"gr") == 0){
            std::string dest = sources[i];
            boost::replace_all(dest, ".dot", ".gr");
            from_dot_to_gr(sources[i], dest);
        }
        if(strcmp(st,"gr") == 0 && strcmp(dt,"dot") == 0){
            std::string dest = sources[i];
            boost::replace_all(dest, ".gr", ".dot");
            from_gr_to_dot(sources[i], dest);
        }
    }
}

