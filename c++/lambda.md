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

4. lambda is const as well by default, use "mutable" to change it. 

auto lamb = [i = 0] mutable { return ++i; } 

5. generic lambda = lambdas + template

auto lamb = [val=1] (auto v) { return v + val; } 

variadic lambdas:

auto lamb = [val=1](auto... v) { return sum(v..., val); }

This is like: 

class Foo {

   int val; 

public: 

   template<typename... As> 
   
   constexpr auto operator()(As... as) const { reurn sum(as..., val); } 
   
 }

6. "this" inside lambdas

[=] () { this->work(); }  // capture pointer this, so not value of the object "*this", confusing, will get deprecated in c++20;

[this] { this->work(); } // capture pointer this, 

[&] {this->work(); // same as above, capture pointer this;

[p=this] { p->work(); } // same as above, capture pointer this;

[*this] { this->work(); } // capture by value, like [obj=*this] { obj.work(); }, only applicable to "this", and only valid in c++17. 

[obj=std::move(*this)] {obj.work();} // capture by value for "*this" object;
