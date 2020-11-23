#ifndef TSP_SOLVER_POINT_HPP
#define TSP_SOLVER_POINT_HPP

template<typename T>
    class Point {
    public:
        Point(T &x_, T &y_) : x(x_), y(y_) {

        }

        bool operator==(const Point<T> &compare_point) {
            return x == compare_point.x && y == compare_point.y;
        }

        decltype(auto) calculate_distance(const T &x_, const T &y_) const {
            return sqrt((x - x_) * (x - x_) + (y - y_) * (y - y_));
        }

        T get_x() const {
            return x;
        }

        T get_y() const {
            return y;
        }

    private:
        T x, y;
    };

#endif // TSP_SOLVER_POINT_HPP
