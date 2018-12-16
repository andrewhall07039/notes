#include <iostream>
#include <vector>
#include <tuple>

template<typename ... T>
auto sum(T ... t) {
    return ( t + ...);
}

template<typename ... T>
auto div1(T ... t) {
	return (t / ...);
}

template<typename ... T>
auto div2(T ... t) {
	return (... / t);
}

template<typename ... T>
auto avg(T ... t) {
	return (t + ...)/sizeof...(t);
}

template<typename... Args>
void fold_print(Args&&... args) {
	(std::cout << ... << std::forward<Args>(args)) << '\n';
}

template<typename T, typename... Args>
void fold_push_back(std::vector<T>& v, Args&&... args) {
	(v.push_back(args),...);
}

template<typename... Ts>
void print_tuple(const std::tuple<Ts...>& t) {
	std::apply([](const auto&... item) {
		((std::cout << item << std::endl), ...);
	}, t);
}

int main() {
    std::cout << sum(1, 2, 3, 4) << std::endl;
    std::cout << div1(1.0, 2.0, 3.0) << std::endl;
    std::cout << div2(1.0, 2.0, 3.0) << std::endl;
    std::cout << avg(1.0, 2.0, 3.0) << std::endl;
    fold_print("hello", ", 10", ", ", 90.0);
    
    std::vector<int> v;
    fold_push_back(v, 1, 2, 3, 4);
    for (const auto& i: v)
	    std::cout << i << std::endl;

    std::cout << "print_tuple\n";
    print_tuple(std::tuple("hello", 1, 3.4, "world"));
}
