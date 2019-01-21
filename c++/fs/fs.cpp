#include <filesystem>
#include <fstream>
#include <iostream>
#include <chrono>
#include <algorithm>
#include <string_view>
using namespace std;
using namespace std::chrono;

template <class F, class ... Args>
auto test(F f, Args &&... args) {
   auto pre = high_resolution_clock::now();
   auto res = f(std::forward<Args>(args)...);
   auto post = high_resolution_clock::now();
   return pair{ res, post - pre };
}
int main() {
   enum { N = 10'000 };
   
   const auto fileName = "a.out"sv;
   
   auto[r0, dt0] = test([](string_view name) {
      uintmax_t sum_sz = 0;
      for (int i = 0; i != N; ++i)
         sum_sz += filesystem::file_size(name);
      return sum_sz / N;
   }, fileName);
   
   auto homemade = [](string_view name) {
      return ifstream { name.data(), ios::ate }.tellg();
   };
   
   auto[r1, dt1] = test([homemade](string_view name) {
      streamoff sum_sz = 0;
      for (int i = 0; i != N; ++i)
         sum_sz += homemade(name);
      return sum_sz / N;
   }, fileName);
   
      auto[r2, dt2] = test([](string_view name) {
      uintmax_t sum_sz = 0;
      filesystem::directory_entry en{name};
      for (int i = 0; i != N; ++i)
         sum_sz += en.file_size();
      return sum_sz / N;
   }, fileName);
   
    cout << "filesystem::file_size     : " << r0 << " in "
        << duration_cast<milliseconds>(dt0).count() << " ms." << endl;
    cout << "homemade file_size        : " << r1 << " in "
        << duration_cast<milliseconds>(dt1).count() << " ms." << endl;
    cout << "directory_entry file_size : " << r2 << " in "
        << duration_cast<milliseconds>(dt2).count() << " ms." << endl;
}
