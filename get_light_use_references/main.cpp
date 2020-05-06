#include <cstdint>
#include <chrono>
#include <functional>
#include <vector>
#include <iostream>

struct LightClass {
    int x;
    int skinny[1];
};

struct HeavyClass {
    int x;
    int fat[100000];
};


int32_t benchmark(std::function<void()> f) {
  auto before = std::chrono::system_clock::now();
  f();

  auto after = std::chrono::system_clock::now();

  auto duration = after - before;
  return std::chrono::duration_cast<std::chrono::microseconds>(duration).count();
}


int main() {
  std::vector<LightClass> light_container(1000);
  std::vector<HeavyClass> heavy_container(1000);

  std::cout << "For light classes or simple data types, meh... there's hardly difference... " << std::endl;
  std::cout << "microseconds_light_iterating_without_references = " << benchmark([&]() { int total; for(const auto item : light_container) { total += item.x; } }) << std::endl;
  std::cout << "microseconds_light_iterating_using_references = " << benchmark([&]() { int total; for(const auto &item : light_container) { total += item.x; } }) << std::endl;

  std::cout << std::endl;
  std::cout << "But if each element in your container is heavy, then not using references may get expensive... " << std::endl;
  std::cout << "microseconds_heavy_iterating_without_references = " << benchmark([&]() { int total; for(const auto item : heavy_container) { total += item.x; } }) << std::endl;
  std::cout << "microseconds_heavy_iterating_using_references   = " << benchmark([&]() { int total; for(const auto &item : heavy_container) { total += item.x; } }) << std::endl;
  return 0;
}
