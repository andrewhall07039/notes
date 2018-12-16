#include <iostream>
#include <tuple>
#include <iterator>

template<typename... Ts>
void print_tuple(const std::tuple<Ts...>& tuple) {
    if constexpr (sizeof... (Ts) > 0) {
	std::apply([] (const auto& item, const auto&... items) {
	    std::cout << "the first item is: " << item << std::endl;
	    std::cout << "the rest  items are: ";
	    ((std::cout << ", " << items), ...);
	    std::cout << std::endl;
	}, tuple);
    }
}

template<typename... Ts>
size_t total_size(const std::tuple<Ts...>& tuple) {
	return std::apply([](const auto&... item) {
		return (sizeof(item) + ...);
		}, tuple);
}
int main() {
   print_tuple(std::make_tuple("Hello world", 1, 2, 3.0));
   auto s = total_size(std::make_tuple(1, 2, 3.0));
   print_tuple(std::make_tuple("the size is", s));
}
