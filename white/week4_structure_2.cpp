#include <iostream>
#include <vector>

using namespace std;

struct FunctionPart {
 public:
  FunctionPart(char op_val, float el_val) : op(op_val), element(el_val){};
  void Invert() {
    if (op == '+') {
      op = '-';
    } else if (op == '-') {
      op = '+';
    } else if (op == '*') {
      op = '/';
    } else if (op == '/') {
      op = '*';
    }
  }
  float Apply(float input) const {
    if (op == '+') {
      input = input + element;
    } else if (op == '-') {
      input = input - element;
    } else if (op == '*') {
      input = input * element;
    } else if (op == '/') {
      input = input / element;
    }
    return input;
  }

 private:
  char op;
  float element;
};

class Function {
 public:
  Function() = default;

  Function(char op, float element) { function_parts.push_back({op, element}); }
  void AddPart(char op, float element) {
    function_parts.push_back({op, element});
  };

  float Apply(float input) const {
    for (const auto& part : function_parts) {
      input = part.Apply(input);
    }
    return input;
  }

  void Invert() {
    vector<FunctionPart> inv_function_parts;
    for (auto x = function_parts.rbegin(); x != function_parts.rend(); x++) {
      x->Invert();
      inv_function_parts.push_back(*x);
    }
    function_parts = inv_function_parts;
  }

 private:
  vector<FunctionPart> function_parts;
};

// struct Image {
//   double quality;
//   double freshness;
//   double rating;
// };

// struct Params {
//   double a;
//   double b;
//   double c;
// };

// Function MakeWeightFunction(const Params& params, const Image& image) {
//   Function function;
//   function.AddPart('*', params.a);
//   function.AddPart('-', image.freshness * params.b);
//   function.AddPart('+', image.rating * params.c);
//   return function;
// }

// double ComputeImageWeight(const Params& params, const Image& image) {
//   Function function = MakeWeightFunction(params, image);
//   return function.Apply(image.quality);
// }

// double ComputeQualityByWeight(const Params& params, const Image& image,
//                               double weight) {
//   Function function = MakeWeightFunction(params, image);
//   function.Invert();
//   return function.Apply(weight);
// }

// int main() {
//   Image image = {10, 2, 6};
//   Params params = {4, 2, 6};
//   cout << ComputeImageWeight(params, image) << endl;
//   cout << ComputeQualityByWeight(params, image, 52) << endl;
//   return 0;
// }
