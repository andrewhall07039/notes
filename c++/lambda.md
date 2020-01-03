presentation: https://www.youtube.com/watch?v=3jCOwajNch0

Notes:
1. capture:

auto title = "hello"s;

caputre by value:

auto a = [t=title](const std::string& prefix) { return prefix + t; }

auto a = [title](const std::string& prefix) { return prefix + t; } 

auto a = [=](const std::string& prefix) { return prefix + t; } 

capture by reference:

auto a = [&t = title] (const auto& prefix) { return prefix + t; }

auto a = [&title] (const auto& prefix) .....

auto a = [&] .....

2. if caputure nothing, then it is like a raw function pointer. 

int (*fp)(int)  = [](int x) { return x + 1; };

3. lambda is constexpr by default (so we can call it in statis_assert), but not noexcept.

auto lamb = [](int x) { return x + 1; }

static_assert(lamb(30) == 31);

static_assert(not noexcept(lamb(30));

