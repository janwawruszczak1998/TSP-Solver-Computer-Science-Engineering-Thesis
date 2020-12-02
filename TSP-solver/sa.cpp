#include "sa.h"
#include "strategy.h"
#include <thread>
#include <QLabel>

SA::SA(tsp::Graph<double, std::vector>& graph_, unsigned& result_, std::vector<unsigned>& route_)
: Strategy(graph_, result_, route_)
{
    algo_thread = std::thread{[this](){this->calculate_solution();}};
}

SA::~SA(){

}

void SA::calculate_solution() {
    std::vector<unsigned int> solution;
      double result = random_path(solution, graph);   //pierwsze losowe rozwiazanie
      auto permutation(solution);
      auto next_step(permutation);
      double step_val{};

      unsigned stagnation = 0; //wskaznik stagnacji

      unsigned iteration = 0;  //liczba iteracji w ramach jednego chlodzenia i wyzazania
      double temperature = 1e9;   //temperatura poczatkowa

      for (unsigned num_of_try = 0; num_of_try < 100; ++num_of_try) {
          //cout << num_of_try << "%\n";
          while (temperature > 0.1) {

              iteration++;
              unsigned rep = 3 * graph.get_order();  //liczba obrotow (sprawdzen sasiadow w pokoleniu) = 3n
              next_step = permutation;
              step_val = calculate_objective(next_step, graph);   //wartosc kroku

              while (rep-- > 0) {
                  unsigned f_pos = 0;  //wyznaczenie pierwszego miejsca swapa
                  unsigned s_pos = 0;  //wyznaczenie drugiego miejsca swapa
                  do {
                      f_pos = randoms.random_in_range(0, graph.get_order() - 1);
                      s_pos = randoms.random_in_range(0, graph.get_order() - 1);
                  } while (f_pos == s_pos);
                  if (f_pos > s_pos) std::swap(f_pos, s_pos);

                  double curr_val = step_val;

                  //wyznaczenie nastepnikow i poprzednikow miejsc swapa
                  unsigned pre_f_pos = f_pos - 1;
                  unsigned next_f_pos = f_pos + 1;
                  if (f_pos == 0) pre_f_pos = graph.get_order() - 1;

                  unsigned pre_s_pos = s_pos - 1;
                  unsigned next_s_pos = s_pos + 1;
                  if (s_pos == graph.get_order() - 1) next_s_pos = 0;

                  //sprawdzenie wartosci kroku
                  if (s_pos - f_pos == 1 || s_pos == graph.get_order() - 1 || f_pos == 0) { //krancowe przypadki
                      std::swap(next_step[f_pos], next_step[s_pos]);
                      step_val = calculate_objective(next_step, graph);
                  } else {   //ogolny przypadek
                      step_val = step_val
                                - graph.get_distance(next_step[pre_f_pos], next_step[f_pos])
                                - graph.get_distance(next_step[f_pos], next_step[next_f_pos])
                                - graph.get_distance(next_step[pre_s_pos], next_step[s_pos])
                                - graph.get_distance(next_step[s_pos], next_step[next_s_pos])
                                + graph.get_distance(next_step[pre_f_pos], next_step[s_pos])
                                + graph.get_distance(next_step[s_pos], next_step[next_f_pos])
                                + graph.get_distance(next_step[pre_s_pos], next_step[f_pos])
                                + graph.get_distance(next_step[f_pos], next_step[next_s_pos]);
                      std::swap(next_step[f_pos], next_step[s_pos]);
                  }

                  unsigned difference = static_cast<unsigned>(step_val - curr_val); //roznica rozwiazan najlepszego i aktualnego
                  if (step_val < result) {  //jesli poprawilismy, wyzeruj wskaznik stagnacji i aktualizuj rezultat
                      stagnation = 0;
                      solution = next_step;
                      {
                          std::lock_guard<std::mutex> lock(result_mutex);
                          std::cout << "xd" << std::endl;
                          if(result___ > step_val){
                              result___ = step_val;
                              route___ = solution;
                          }
                      }
                  } else {   //jesli nie poprawilismy, to zwieksz wskaznik stagnacji
                      stagnation++;
                      if (stagnation < graph.get_order()) {
                          temperature = (double) (1e9) / 2;   //jesli stagnacja jest duza, to zwieksz temperature

                          unsigned f_inv = 0;  //wyznaczenie pierwszego miejsca inverta
                          unsigned s_inv = 0;  //wyznaczenie drugiego miejsca inverta
                          do {
                              f_inv = randoms.random_in_range(0, graph.get_order() - 1);
                              s_inv = randoms.random_in_range(0, graph.get_order() - 1);
                          } while (f_inv == s_inv);

                          if (f_inv > s_inv) std::swap(f_inv, s_inv);
                          for (unsigned i = f_inv; i < (f_pos + s_inv) / 2 - 1; ++i) {   //przetasuj permutacje
                              std::swap(next_step[i], next_step[s_pos - i + f_inv]);
                              permutation = next_step;
                              break;
                          }
                      }
                  }

                  double acc = get_probability(difference, temperature);
                  auto prob = static_cast<double>(randoms.random_in_range(0, 1e9)) / static_cast<double>((1e9));

                  //decyzja o przyjeciu/odrzuceniu rozwiazania
                  if (difference < 0 || (difference > 0 && acc > prob)) {
                      permutation = next_step;
                      break;
                  } else {
                      std::swap(next_step[f_pos], next_step[s_pos]);
                  }


              }

              temperature = cooling(temperature);  //akutalizacja temperatury
              if (iteration > graph.get_order() * graph.get_order())
                  break; //jesli zbyt dlugo siedzimy w jednym miejscu

          }

          //losowanie nowego punktu startu i reset zmiennych
          random_path(permutation, graph);
          next_step = permutation;
          iteration = 0;
          stagnation = 0;
          temperature = 1e9;
      }

      std::cout << "Najlepszy wynik uzyskany SA: " << result << std::endl;

}

double SA::cooling(double temperature) {
    return (temperature *= 0.95);
}

double SA::get_probability(unsigned difference, double temperature) //Funkcja określa jak słabe jest sugerowane rozwiązanie
{
    return exp(-1 * difference / temperature);
}
