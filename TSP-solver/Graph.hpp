//
// Created by Jan on 2020-10-06.
//

#ifndef TSP_SOLVER_GRAPH_HPP
#define TSP_SOLVER_GRAPH_HPP

#include <iostream>
#include <algorithm>
#include <math.h>
#include <cmath>

#include "Point.hpp"

namespace tsp {

    template<typename T, template<typename, typename = std::allocator<T>> class Container>
    class Graph {
    public:
        void add_vertex(T &&, T &&);

        void remove_vertex(int);

        void remove_vertex(T &&, T &&);

        void display_graph() const;

        int get_order() const;

        T get_distance(int, int) const;

    private:
        int order_{0};
        Container<std::pair<int, Point<T>>> vertices_localization;
        Container<Container<std::pair<int, T>>> graph_representation;
    };

    template<typename T, template<typename, typename> class Container>
    int Graph<T, Container>::get_order() const {
        return order_;
    }


    template<typename T, template<typename, typename> class Container>
    void Graph<T, Container>::add_vertex(T &&x, T &&y) {
        vertices_localization.push_back(std::make_pair(order_++, Point<T>(x, y)));
        graph_representation.push_back(Container<std::pair<int, T>, std::allocator<T>>());

        const auto added_vertex_id = order_ - 1;
        static auto vertex_id = 0;
        for (auto &distances : graph_representation) {
            distances.push_back({added_vertex_id,
                                 std::find_if(vertices_localization.begin(), vertices_localization.end(),
                                              [](std::pair<int, Point<T>> number) {
                                                  return vertex_id == number.first;
                                              })->second.calculate_distance(x, y)});
            if (vertex_id != added_vertex_id) {
                graph_representation.back().push_back({vertex_id, distances.back().second});
            }

            vertex_id++;
        }
        vertex_id = 0;

    }

    template<typename T, template<typename, typename> class Container>
    void Graph<T, Container>::display_graph() const {
        std::cout << "============= Graph =============" << std::endl;
        static auto vertex_id = 0;
        for (auto outer_iterator = graph_representation.cbegin();
             outer_iterator != graph_representation.cend(); ++outer_iterator) {
            auto it = vertices_localization.begin();
            std::advance(it, vertex_id);
            std::cout << "Vertex id: " << it->first << ", coords: " << it->second.get_x() << " " << it->second.get_y()
                      << ", distances: ";
            for (auto inner_iterator = outer_iterator->cbegin();
                 inner_iterator != outer_iterator->cend(); ++inner_iterator) {
                std::cout << inner_iterator->second << " ";
            }
            std::cout << std::endl;
            vertex_id++;
        }
        vertex_id = 0;
    }

    template<typename T, template<typename, typename> class Container>
    void Graph<T, Container>::remove_vertex(const int index) {
        if (index < 0 || index >= order_) return;

        if (--order_ == 0) {
            graph_representation.clear();
        } else {
            graph_representation.erase(
                    std::find_if(graph_representation.begin(), graph_representation.end(), [&index](auto &distances) {
                        return std::any_of(distances.begin(), distances.end(), [&index](auto &vertex) {
                            return vertex.first == index && static_cast<int>(vertex.second) == 0;
                        });
                    }));
        }


        for (auto &distances : graph_representation) {
            for (auto iterator = distances.begin(); iterator != distances.end();) {
                if (iterator->first == index) {
                    iterator = distances.erase(iterator);
                } else {
                    if(iterator->first > index){
                        --iterator->first;
                    }
                    ++iterator;
                }
            }
        }

        vertices_localization.erase(vertices_localization.begin() + index);
        int i = 0;
        for (auto it = vertices_localization.begin(); i < order_; ++i, ++it) {
            if(it->first > index){
                it->first = i;
            }
        }

    }

    template<typename T, template<typename, typename> class Container>
    void Graph<T, Container>::remove_vertex(T &&x, T &&y) {
        bool removal_done_correctly = false;
        Point<T> point_to_delete(x, y);
        for (const auto &vertex : vertices_localization) {
            if (std::abs(point_to_delete.get_x() - vertex.second.get_x()) < 15
                && std::abs(point_to_delete.get_y() - vertex.second.get_y()) < 15) {
                remove_vertex(vertex.first);
                removal_done_correctly = true;
                break;
            }
        }
        if(removal_done_correctly){
            std::cout << "Vertex removed" << std::endl;
        }
        else{
            std::cout << "Fail! No vertex removed" << std::endl;
        }
    }

    template<typename T, template<typename, typename> class Container>
    T Graph<T, Container>::get_distance(int i, int j) const {

        if (i < 0 or j < 0 or i >= order_ or j >= order_) return 0;

        return graph_representation[i][j].second;

    }

}

#endif //TSP_SOLVER_GRAPH_HPP
