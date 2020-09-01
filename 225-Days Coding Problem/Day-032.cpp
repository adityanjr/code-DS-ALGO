/*
 
   This problem was asked by Jane Street.

   Suppose you are given a table of currency exchange rates,
   represented as a 2D array. Determine whether there is a possible arbitrage: that is, 
   whether there is some sequence of trades you can make, 
   starting with some amount A of any currency, so that you can end up with some amount greater than A of that currency.

   There are no transaction costs and you can trade fractional quantities.

 */


/*   Content below can help you in understanding the below problem but keep the sequence 
 *  
 *   1) http://courses.csail.mit.edu/6.046/spring04/handouts/ps7sol.pdf
 *   2) https://briangordon.github.io/2016/07/developer-interview-questions.html
 *   
 *   solution from daily coding problem
 *   
 *   https://www.dailycodingproblem.com/blog/how-to-find-arbitrage-opportunities-in-python/
 */
#include <bits/stdc++.h>
using namespace std;

bool arbitrage(vector< vector< double > > &table){
    // let's simplify the problem by taking log of each vertex 

    vector< vector< double > > graph(2 , vector< double >(2));
    for(double i{0}; i < 2; ++i){
        for(double j{0}; j < 2; ++j){
            graph[i][j] = -log(table[i][j]);
            // we are taking -log(x) && -log(x)<0 iff x>1 
        }
    }

    vector<double> dist(3 , INT_MAX );


    // let's apply bellman ford algorithm to calculate min-cost 
    dist[0] = 0;
    
    for(double step{0}; step < 2; ++step){
        for(double i:{0 , 1}){
            for(double j:{0 , 1}){
                if(dist[j] > dist[i] + graph[i][j]){
                    dist[j] = dist[i] + graph[i][j];
                }
            }
        }
    }

    // detecting the negative cycle 

    for(double i:{0 , 1}){
        for(double j:{0 , 1}){
            if(dist[j] > dist[i] + graph[i][j]){
                return true;
            }
        }
    }

    return false;
}


int  main(void){
    vector< vector<double> > graph_1(2 , vector<double>(2)) , graph_2(2 , vector<double>(2));
    // formation of graph 1 ,,, here in graph 1 the solution is present ..i.e there is way to start
    // from a vertex and reach there again with a greater amount then we have current 
    graph_1[0] = {1 , 2};
    graph_1[1] = {2 , 1};


    // formation of graph 2 ,, here in graph 2 there no way to trade that you start from one currency 
    // and again reach at the same currency with a greater amount :( 

    graph_2[0] = {1 , 1};
    graph_2[1] = {1 , 1};
    

    // so our function should return true for the graph / table 1
    // and for graph / table 2 our graph should return false 

    assert(arbitrage(graph_1) == true);
    assert(arbitrage(graph_2) == false);


    return 0;
}

