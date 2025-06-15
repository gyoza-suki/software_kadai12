// 8-3 高階関数（関数を返す or 関数を引数に取る）
// int n と 関数 f を引数に持ち、fをn回適用する関数
// ここでは、関数を引数に取り、ラムダ式（関数オブジェクト）を返す

#include <iostream>
#include <functional>

std::function<double(double)> Fn(int n, std::function<double(double)> f) {
    if (n == 0) {
        return [](double x) { return x; };
    } else {
        auto g = Fn(n-1, f);
        return [=](double x) { return f(g(x)); };
    }
}
    
int main() {
    auto pow = [](double x) { return x * x; };   // 二乗する関数 pow
    auto add = [](double x) { return x + 1; };   // 1加算する関数 add

    std::cout << "「3を二乗」を2回適用：" << Fn(2, pow)(3) << std::endl;
    std::cout << "「3に1加算」を6回適用：" << Fn(6, add)(3) << std::endl;

    return 0;
}

