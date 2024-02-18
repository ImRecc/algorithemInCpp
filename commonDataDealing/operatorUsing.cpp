int basicOp(char op, int val1, int val2) {
  // Your code here
  switch(op)
    {
      case '+':
        return val1+val2;
      case '-':
        return val1-val2;
      case '*':
        return val1*val2;
      case '/':
        if (val2!=0) return val1/val2;
        else throw std::invalid_argument("Division by zero is undefined");
      default:
        throw std::invalid_argument("invalid operator");
      }
}

//like a basic calculator I know, but it's what I never done before hh.
