template<typename Func>
auto timed(Func f) {
    return [f](auto&&... args) {
        auto start = std::chrono::high_resolution_clock::now();
        auto result = f(std::forward<decltype(args)>(args)...);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = end - start;
        std::cout << "Elapsed time: " << elapsed.count() << " seconds\n";
        return result;
    };
}
