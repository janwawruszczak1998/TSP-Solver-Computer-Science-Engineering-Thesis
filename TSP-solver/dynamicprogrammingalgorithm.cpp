#include "dynamicprogrammingalgorithm.h"
#include "strategy.h"
#include <thread>
#include <algorithm>

DP::DP(tsp::Graph<double, std::vector>& graph_, unsigned& result_, std::vector<unsigned>& route_)
: Strategy(graph_, result_, route_)
{
    calculate_solution();
}

DP::~DP(){

}

void DP::calculate_solution() {

    //preprocessing
    unsigned n = graph.get_order();
    std::vector<std::vector<double>> dp;
    dp.resize(1 << n);
    for (unsigned i = 0; i < (1 << n); ++i) dp[i].resize(n, 1e9);


    for (unsigned i = 0; i < n; ++i) {
        dp[(1 << i) |
           1][i] = graph.get_distance(0, i); //na początku koszt jednokrawędziowej ścieżki Hamiltona z 0 do I to po prostu koszt krawędzi
    }

    //dynamic programming
    for (unsigned bitMask = 0; bitMask < (1 << n); ++bitMask) {                        //dla każdej maski bitowej liczymy trasy
        for (unsigned v = 0; v < n; ++v) {                                             //rozważamy trasy zakończone w wierzchołku V
            if (!(bitMask & (1 << v))) {
                continue;                                                          //jeżeli w ścieżce nie ma w ogóle wierzchołja V, to pomijamy
            }
            for (unsigned j = 0; j < n; ++j) {                                         //patrzymy, do którego wierzchołka J możemy dojść z V
                if (!(bitMask & (1 << j))) {                                     //jeśli wierzchołka J nie ma w trasie
                    dp[bitMask | (1 << j)][j]
                        = std::min(dp[bitMask][v] + graph.get_distance(v, j), dp[bitMask |(1 << j)][j]);    //jeżeli koszt dojścia do V i przejścia do J jest mniejszy od aktualnie najlepszego osiągnięcia J, to zaktualizuj
                }
            }
        }
    }

    //ustalenie resultu
    unsigned result = 1e9;
    for (unsigned v = 0; v < n; ++v) {
        unsigned act = dp[(1 << n) - 1][v] +
                  graph.get_distance(v, 0); //koszt "powrotu" z wierzchołka v do wierzchołka 0
        if (result > act) result = act;
    }


    result___ = result;
    std::cout << "Najtańszy cykl Hamiltona wyznaczona DP: " << result << std::endl;
}
